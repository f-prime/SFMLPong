#include "Utils.hpp"
#include <cmath>
#include <iostream>

int player_points = 0;
int ai_points = 0;

void movePaddle(Paddle &paddle) {
    int p1_x = paddle.pos_x;
    int p1_y = paddle.pos_y;

    if(paddle.direction < 0) {
        int move = p1_y + 10;
        if(move <= HEIGHT - paddle.height)
            paddle.setPos(p1_x, move);
    } else if(paddle.direction > 0) {
        int move = p1_y - 10;
        if(move >= 0)
            paddle.setPos(p1_x, move);
    } 
}

float toRadians(float angle) {
    return (angle * M_PI) / 180;
}

void randomAngle(Ball& ball) {
    int angle = (rand() % 35) + 20;
    int direction = rand() % 100;
    if (direction > 50)
        angle *= -1;
    ball.setAngle(angle);
}

void ai(Paddle& paddle, Ball& ball) {
    if(ball.pos_y > paddle.pos_y) {
        paddle.direction = -1;
        movePaddle(paddle);
    } else if(ball.pos_y < paddle.pos_y) {
        paddle.direction = 1;
        movePaddle(paddle);
    } else {
        paddle.direction = 0;
    }
}

void moveBall(Ball& ball) {
    int move = ball.pos_x + ball.speed * ball.direction;
    if(move > WIDTH || move < 0) {
        if(move > WIDTH) {
            player_points++;
            ball.direction = 1;
        } else {
            ai_points++;
        }
        ball.direction *= -1;
        ball.setAngle(0);        
        ball.setPos(WIDTH / 2, HEIGHT / 2);
        std::cout << player_points << " " << ai_points << "\n";
    }

    if(ball.pos_y > HEIGHT - 10 || ball.pos_y < 0) {
        ball.setAngle(ball.angle * -1);
    }

    float x = ball.speed * cos(toRadians(ball.angle));
    float y = ball.speed * sin(toRadians(ball.angle));
   
    ball.setPos(ball.pos_x + x * ball.direction, ball.pos_y + y);
}
