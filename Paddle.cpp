#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Paddle.hpp"
#include <iostream>

void Paddle::setPos(int x, int y) {
    this->pos_x = x;
    this->pos_y = y;
    this->rectangle.setPosition(x, y);
} 

void Paddle::setSize(int height, int width) {
    this->height = height;
    this->width = width;

    this->rectangle.setSize(sf::Vector2f(height, width));
}

void Paddle::render() {
    this->window.draw(this->rectangle);
}

Paddle::Paddle(sf::RenderWindow &window):window(window) {
    this->setSize(10, 50); 
}
