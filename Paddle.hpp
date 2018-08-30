#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.hpp"

class Paddle {
    private:        
        sf::RectangleShape rectangle;
        sf::RenderWindow &window; 
    public:
        int pos_x;
        int pos_y; 
        int direction;
        int speed;
        int height;
        int width;
        

        void setPos(int x, int y);        
        void setSize(int height, int width);
        bool collide(Ball& ball);
        void render();
        Paddle(sf::RenderWindow &window);
};

#endif
