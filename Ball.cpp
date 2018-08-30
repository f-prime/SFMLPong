#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Ball.hpp"

Ball::Ball(sf::RenderWindow& window):window(window) {
    this->ball = sf::RectangleShape(sf::Vector2f(5, 5));
    this->direction = 1;
    this->speed = 5;
    this->angle = 0;
    this->setPos(400, 300);
}

void Ball::setPos(int x, int y) {
    this->pos_x = x;
    this->pos_y = y;

    this->ball.setPosition(x, y);
}

void Ball::setAngle(float angle) {
    this->angle = angle;
}

void Ball::setDirection(int direction) {

}

void Ball::setSpeed(int speed) {

}

void Ball::render() {
    this->window.draw(this->ball);
}
