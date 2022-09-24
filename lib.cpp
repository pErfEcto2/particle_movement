#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "math.h"
#include "lib.hpp"


//---------------------------OPERATORS-----------------------------------------
sf::Vector2f operator/(sf::Vector2f const &v, int const &n) {
    return sf::Vector2f(v.x / n, v.y / n);
}

//------------------------------------FUNCTIONS------------------------------------
sf::Text textInit(sf::Text text, sf::Font &font, int size, sf::Vector2f pos) {
    /*
    This finstions initializes a text Particle.
    */
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos);
    return text;
}

sf::Vector2f const getScreenSize() {
    return sf::Vector2f(sf::VideoMode::getDesktopMode().width,
                        sf::VideoMode::getDesktopMode().height);
}

float clamp(float minn, float maxx, float value) {
    return std::min(maxx, std::max(minn, value));
}
//----------------------------------Particle CLASS----------------------------------
Particle::Particle(sf::Vector2f p, sf::Color c, int r, float a, float b) {
    pos = p;
    color = c;
    radius = r;
    t = 0.0;
    A = a;
    B = b;
    vel = sf::Vector2f(0, 0);
    circle.setRadius(radius);
    circle.setPosition(pos);
    circle.setFillColor(color);
    circle.setOrigin(radius / 2, radius / 2);
}

void Particle::draw(sf::RenderWindow &w) {
    w.draw(circle);
}

float Particle::xCoord(float time) {
    return A * std::sin(B * time);
}

float Particle::yCoord(float time) {
    return A * std::sin(B * time);
}

void Particle::update() {
    pos += vel;
    circle.setPosition(pos);

    pos = sf::Vector2f(xCoord(t), yCoord(t)) + (getScreenSize() / 2);

    if (A != 0 && B != 0) t += 0.1;
}


//-------------------------------FPS CLASS---------------------------------------
FPS::FPS() {
    cnt = 0;
    fps = 0;
}

FPS::~FPS() {}

int FPS::getFPS() {
    cnt += 1;
    if (cnt % 10 == 0) {
        fps = 10.f / (clock.restart().asSeconds());
        cnt = 0;
    }
    return fps;
}
