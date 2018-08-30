#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Utils.hpp"

void Paddle::setPos(int x, int y) {
    this->pos_x = x;
    this->pos_y = y;
    this->rectangle.setPosition(x, y);
} 

bool Paddle::collide(Ball& ball) {

    // Checks if ball is inside of paddle

    int topleft_x = this->pos_x;
    int topright_x = this->pos_x + this->width;    
    int bottom_y = this->pos_y + this->height;
    int top_y = this->pos_y;

    int ball_x = ball.pos_x;
    int ball_y = ball.pos_y;

    return 
        (ball_x >= topleft_x && ball_x <= topright_x && ball_y >= top_y && ball_y <= bottom_y) || // Left Paddle
        (ball_x <= topleft_x && ball_x >= topright_x && ball_y >= top_y && ball_y <= bottom_y); // Right Paddle 
}

void Paddle::setSize(int height, int width) {
    this->height = height;
    this->width = width;

    this->rectangle.setSize(sf::Vector2f(width, height));
}

void Paddle::render() {
    this->window.draw(this->rectangle);
}

Paddle::Paddle(sf::RenderWindow &window):window(window) {
    this->setSize(50, 10); 
}
