#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "lib.hpp"
#include "iostream"
#include "map"
#include "string"


int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Movement", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    sf::Event event;
    
    std::srand(time(0));

    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
        window.close();
        exit(1);
    }

    std::map<std::string, bool> keys = {
        {"clear", true}
    };

    // initialize all texts
    std::vector<sf::Text> texts;
    texts.push_back(textInit(sf::Text(), font, 20, sf::Vector2f(10, 10)));
    texts.push_back(textInit(sf::Text(), font, 20, sf::Vector2f(10, 30)));
    texts.push_back(textInit(sf::Text(), font, 20, sf::Vector2f(1200, 10)));

    FPS fps;

    int R = 2;
    int A = 30;
    int B = 1;
    sf::Vector2f pos = getScreenSize() / 2;

    Particle part(pos, sf::Color::White, R, A, B);

    sf::Keyboard keyboard;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.type == sf::Event::Closed or keyboard.isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }

                if (keyboard.isKeyPressed(sf::Keyboard::C)) keys["clear"] = !keys["clear"];

                if (keyboard.isKeyPressed(sf::Keyboard::R)) {
                    part.A = A;
                    part.B = B;
                    part.pos = pos;
                    window.clear();
                }
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (keyboard.isKeyPressed(sf::Keyboard::LControl)) {
                    part.A = part.A + event.mouseWheelScroll.delta * 2;
                }

                else {
                    part.B = part.B + event.mouseWheelScroll.delta * 0.1;
                }
            }
        }

        part.update();

        texts[0].setString("A: " + std::to_string(part.A));
        texts[1].setString("B: " + std::to_string(part.B));
        texts[2].setString("FPS: " + std::to_string(fps.getFPS()));

        if (keys["clear"]) window.clear();

        for (sf::Text &text: texts) {
            window.draw(text);
        }

        part.draw(window);

        window.display();
    }
    return 0;
}
