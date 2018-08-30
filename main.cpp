#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utils.hpp"



int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFMLPong");

    Paddle paddle_1(window);
    Paddle paddle_2(window);
    Ball ball(window);

    paddle_1.setPos(50, HEIGHT / 2 - paddle_2.width);
    paddle_2.setPos(WIDTH - (50 + paddle_2.width), HEIGHT / 2 - paddle_2.width);

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Down) {
                    paddle_1.direction = -1;
                } else if(event.key.code == sf::Keyboard::Up) {
                    paddle_1.direction = 1;
                }
            } else if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)
                    paddle_1.direction = 0;
            }            
        }
        window.clear(sf::Color(0,0,0));

        paddle_1.render();   
        paddle_2.render();
        ball.render();
        
        movePaddle(paddle_1);  
        moveBall(ball);
        
        if (paddle_1.collide(ball)) {
            ball.direction *= -1;
        } else if(paddle_2.collide(ball)) {
            ball.direction *= -1;
        }

        window.display();
        window.setFramerateLimit(60);
    }
}
