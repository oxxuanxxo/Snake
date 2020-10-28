#ifndef GLOBALDEF_H
#define GLOBALDEF_H

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define DEFAULTSNAKELENGTH 4

int score;//amount of food eaten
char scoreText[15];//text to display score

//increase score by 
void UpdateScore(int increament);
#endif