#include <Settings.hpp>
#include <src/ControlPanel.hpp>

ControlPanel::ControlPanel() noexcept
    : section{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)},
    button1{
        0, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "turn_right"
    },
    button2{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "turn_left"
    },
    button3{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_forward"
    },
    button4{
        0, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_back"
    },
    button5{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "ready_flag"
    },
    button6{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "ready_end"
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

void ControlPanel::update(float dt) noexcept
{

}

void ControlPanel::on_click(sf::Vector2i mouse_posicion) noexcept
{
    for (Button b : buttons)
    {
        if (b.on_click(mouse_posicion))
        {
            // botón 
        }
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