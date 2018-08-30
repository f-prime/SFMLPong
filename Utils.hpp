#ifndef UTILS_H
#define UTILS_H

#define WIDTH 800
#define HEIGHT 600

#include "Paddle.hpp"
#include "Ball.hpp"

void movePaddle(Paddle& paddle);
void moveBall(Ball& ball);
float toRadians(float angle);
void randomAngle(Ball& ball);
void moveAi(Paddle& paddle, Ball& ball);

extern int player_points;
extern int ai_points;

#endif 
