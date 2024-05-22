#include <Settings.hpp>
#include <src/Play.hpp>

#include <sstream>

Play::Play() noexcept
    : section{sf::Vector2f(Settings::SECTION4_WIDTH, Settings::SECTION4_HEIGHT)},

    button{
        Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT + 20,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "Play", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) {
        std::stringstream ss{};
                    ss << '1' << '0' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '0' << '0' << '0' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '0' << '1' << '0' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '0' << '1' << '0' << '0' << '0' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '9' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
                    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';

        Environment env{ss, 0, 1, 1, 0};
            for(auto scope : p.top())
            {
                scope->execute(env);
                std::cout << "Position " << env.character.get_i() << " " << env.character.get_j() << std::endl;
            }
        }
    }
{
     section.setPosition(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Yellow);
}

void Play::update(float dt, const sf::Vector2i mouse_posicion) noexcept
{
    button.update(dt, mouse_posicion);
}

void Play::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
    button.render(target);
}