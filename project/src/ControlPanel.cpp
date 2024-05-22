#include <Settings.hpp>
#include <src/ControlPanel.hpp>

Program Global::program{{Scope{}}};

ControlPanel::ControlPanel() noexcept
    : section{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)},
    button1{
        0, Settings::SECTION1_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
        Settings::font, "turn_right", sf::Color::Green, sf::Color::Yellow, sf::Color::Red 
    },

    button2{
        Settings::BUTTON_WIDTH, Settings::SECTION1_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
        Settings::font, "turn_left", sf::Color::Green, sf::Color::Yellow, sf::Color::Red 
    },
    button3{
        Settings::BUTTON_WIDTH * 2, Settings::SECTION1_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
        Settings::font, "move_forward", sf::Color::Green, sf::Color::Yellow, sf::Color::Red 
    },
    button4{
        0, Settings::SECTION1_HEIGHT + Settings::BUTTON_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
        Settings::font, "repeat_n_times", sf::Color::Green, sf::Color::Yellow, sf::Color::Red 
    },
    button5{
        Settings::BUTTON_WIDTH, Settings::SECTION1_HEIGHT + Settings::BUTTON_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
         Settings::font,"repeat_end", sf::Color::Green, sf::Color::Yellow, sf::Color::Red 
    },
    button6{
        Settings::BUTTON_WIDTH * 2, Settings::SECTION1_HEIGHT + Settings::BUTTON_HEIGHT,
        Settings::BUTTON_WIDTH, Settings::BUTTON_HEIGHT,
        Settings::font, "ready_end", sf::Color::Green, sf::Color::Yellow, sf::Color::Red
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