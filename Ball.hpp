#ifndef BALL_H
#define BALL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ball {
    private:
        sf::RectangleShape ball;
        sf::RenderWindow& window;
    public:
        int pos_x;
        int pos_y;
        float angle;
        int direction;
        int speed;
        
        void setPos(int x, int y);
        void changeAngle(float angle);
        void setDirection(int direction);
        void setSpeed(int speed);
        void render();
        Ball(sf::RenderWindow& window);
};

#endif
