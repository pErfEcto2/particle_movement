#pragma once


#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "math.h"


//---------------------------OPERATORS-----------------------------------------
sf::Vector2f operator/(sf::Vector2f const &v, int const &n);

//---------------------------FUNCTIONS-----------------------------------------
sf::Text textInit(sf::Text text, sf::Font &font, int size, sf::Vector2f pos);

sf::Vector2f const getScreenSize();

float clamp(float minn, float maxx, float value);
//----------------------------------Particle CLASS----------------------------------
class Particle {
    private:
        sf::CircleShape circle;
        sf::Color color;
        float t;
    
    public:
        sf::Vector2f pos;
        sf::Vector2f vel;
        int radius;
        float A, B;
        Particle(sf::Vector2f p, sf::Color c, int r, float a, float b);
        void draw(sf::RenderWindow &w);
        float xCoord(float time);
        float yCoord(float time);
        void update();
};


//----------------------------------FPS CLASS----------------------------------
class FPS {
    /*
    This class is used to calculate the FPS in the programm.
    Every 10 frames the FPS is calculated.
    */
    private:
        sf::Clock clock;
        int fps;
        int cnt;

    public:
        FPS();
        ~FPS();
        int getFPS();
};
