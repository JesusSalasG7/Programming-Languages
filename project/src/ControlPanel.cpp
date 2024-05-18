#include <Settings.hpp>
#include <src/ControlPanel.hpp>

ControlPanel::ControlPanel() noexcept
    : section{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)},
    button1{
        0, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    },
    button2{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    },
    button3{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    },
    button4{
        0, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    },
    button5{
        Settings::MOVE_RIGHT_WIDTH, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    },
    button6{
        Settings::MOVE_RIGHT_WIDTH * 2, Settings::SECTION1_HEIGHT + Settings::MOVE_RIGHT_HEIGHT,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        "move_right"
    }
{
     section.setPosition(0, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Blue);

}

void ControlPanel::update(float dt) noexcept
{

}

void ControlPanel::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
    button1.render(target);
    button2.render(target);
    button3.render(target);
    button4.render(target);
    button5.render(target);
    button6.render(target);
}