#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include <iostream>

bool moving_down = false;
bool moving_up = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");

    Paddle paddle_1(window);
    paddle_1.setPos(10, 10);

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Down) {
                    moving_down = true;
                    moving_up = false;
                } else if(event.key.code == sf::Keyboard::Up) {
                    moving_up = true;
                    moving_down = false;
                }
            } else if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Down)
                    moving_down = false;
                else if(event.key.code == sf::Keyboard::Up)
                    moving_up = false;
            }
        }
        window.clear(sf::Color(0,0,0));

        paddle_1.render();   

        int p1_x = paddle_1.pos_x;
        int p1_y = paddle_1.pos_y;
    
        if(moving_down) {
            paddle_1.setPos(p1_x, p1_y + 10);
        } else if(moving_up) {
            paddle_1.setPos(p1_x, p1_y - 10);
        }
            
        window.display();
        window.setFramerateLimit(60);
    }
}
