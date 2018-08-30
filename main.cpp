#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Utils.hpp"



int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFMLPong");

    Paddle player(window);
    Paddle ai(window);
    
    ai.speed--;

    Ball ball(window);

    player.setPos(50, HEIGHT / 2 - ai.width);
    ai.setPos(WIDTH - (50 + ai.width), HEIGHT / 2 - ai.width);

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Down) {
                    player.direction = -1;
                } else if(event.key.code == sf::Keyboard::Up) {
                    player.direction = 1;
                }
            } else if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)
                    player.direction = 0;
            }            
        }
        window.clear(sf::Color(0,0,0));

        player.render();   
        ai.render();
        ball.render();
        
        movePaddle(player);  
        moveAi(ai, ball);
        moveBall(ball);
        


        if (player.collide(ball)) {
            if(ball.angle == 0)
                randomAngle(ball);
            else {
                int paddle_middle = player.pos_y + player.height / 2;
                if (ball.pos_y < paddle_middle) {
                    ball.angle = -ball.angle;
                } else if(ball.pos_y > paddle_middle) {
                    ball.angle = ball.angle;
                } else {
                    ball.angle = 0;
                }
            }
            ball.direction *= -1;
        } else if(ai.collide(ball)) {
            if(ball.angle == 0)
                randomAngle(ball);
            ball.direction *= -1;
        }

        window.display();
        window.setFramerateLimit(60);
    }
}
