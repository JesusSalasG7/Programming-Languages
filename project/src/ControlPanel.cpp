#include <Settings.hpp>
#include <src/ControlPanel.hpp>

Program Global::program{{Scope{}}};

ControlPanel::ControlPanel() noexcept
    : section{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)},
    button1{
        0, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "turn_right", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) { 
            p.top().push_back(std::make_shared<TurnRight>()); }
    },

    button2{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "turn_left", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) { 
            p.top().push_back(std::make_shared<TurnLeft>()); 
            } 
    },
    button3{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "move", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) { 
            p.top().push_back(std::make_shared<Move>()); 
            } 
    },
    button4{
        0, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "repeat_n_times", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) { 
            p.push(Scope{}); 
            } 
    },
    button5{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
         Settings::font,"repeat_end", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) {
            if(p.size() == 1){
                    return;
            }
            auto scope = p.top();
            p.pop();
            p.top().push_back(std::make_shared<Loop>(10, scope));
        } 
    },
    button6{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "ready_end", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) { 
            p.top().push_back(std::make_shared<Finish>()); } 
    }
{
     section.setPosition(0, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Blue);
     buttons.push_back(button1);
     buttons.push_back(button2);
     buttons.push_back(button3);
     buttons.push_back(button4);
     buttons.push_back(button5);
     buttons.push_back(button6);

}

void ControlPanel::update(float dt, const sf::Vector2i mouse_posicion) noexcept
{
    for (std::list<Button>::iterator i = buttons.begin(); i != buttons.end(); ++i)
    {
        i->update(dt, mouse_posicion);
    }
}

void ControlPanel::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
    
    for (Button b : buttons)
    {
        b.render(target);
    }
}