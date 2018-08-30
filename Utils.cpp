#include "Utils.hpp"

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

void moveBall(Ball& ball) {
    int move = ball.pos_x + ball.speed * ball.direction;
    if(move > WIDTH || move < 0)
        ball.direction *= -1;
    ball.setPos(ball.pos_x + ball.speed * ball.direction, ball.pos_y);
}
