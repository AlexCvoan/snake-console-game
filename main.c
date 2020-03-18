#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


#define MAP_X 10
#define MAP_Y 20

struct SNAKE {
	int x;
	int y;

} tail[40];

struct FRUIT {
	int x;
	int y;
} fruit;

int head_x = 5, head_y = 10;
int direction = 0;
int length = 0, score = 0;
int gameOver = 0;
char map[MAP_X][MAP_Y];


 void render();
 void control();
 void logic();
 void fruit_rand();
 void follow();


 int main()
 {
	 
	 fruit.x = 7;
	 fruit.y = 15;

	 while (!gameOver) {
		 control();
		 fruit_rand();
		 logic();
		 render();
		 Sleep(100);
		 
	 }

	 return 0;
 }

 void render() {
	 int i, j;
	 system("cls");

	 for (i = 0; i <= MAP_X; i++)
		 for (j = 0; j < MAP_Y; j++)
			 map[i][j] = 176;

	 for (i = 0; i <= MAP_X; i++) {
		 map[i][0] = 219;
		 map[i][MAP_Y] = 219;
	 }
	 for (j = 0; j <= MAP_Y; j++) {
		 map[0][j] = 219;
		 map[MAP_X][j] = 219;
	 }

	 
	 map[head_x][head_y] = 233;
		
	 map[fruit.x][fruit.y] = 220;

	 for (i = 0; i < length; i++) {
		 map[tail[i].x][tail[i].y] = 233;
	 }
	 

	 for (i = 0; i <= MAP_X; i++) {
		 printf("\n    ");
		 for (j = 0; j <= MAP_Y; j++)
			 printf("%c", map[i][j]);
	 }
		 printf("\n\n              Score:%d", score);
		 
	 
 }

 void control() {
	 int i;
	 int temp_x, temp_y;
	 int temp1_x, temp1_y;
	 
	 if (GetAsyncKeyState(VK_UP))			direction = 1;
	 else if (GetAsyncKeyState(VK_DOWN))	direction = 2;
	 else if (GetAsyncKeyState(VK_RIGHT))	direction = 3;
	 else if (GetAsyncKeyState(VK_LEFT))	direction = 4;
	 else if (GetAsyncKeyState(VK_RETURN))	direction = 0;

	 temp_x = head_x;
	 temp_y = head_y;

	 if (direction == 1)		head_x--;
	 else if (direction == 2)	head_x++;
	 else if (direction == 3)	head_y++;
	 else if (direction == 4)	head_y--;
	 else if (direction == 0)	{
		 head_x = head_x;
		 head_y = head_y;
	 }
	

	 for (i = 0; i < length; i++) {
		 temp1_x = tail[i].x;
		 temp1_y = tail[i].y;
		 tail[i].x = temp_x;
		 tail[i].y = temp_y;
		 temp_x = temp1_x;
		 temp_y = temp1_y;
		
	 }
		 

	

 }

 void fruit_rand() {
	 int i;
	 srand(time(NULL));
	 
		 if ((fruit.x == head_x) && (fruit.y == head_y)) {

			 for (i = 0; i <= length; i++) {
				 do {
					 fruit.x = rand() % MAP_X;
					 fruit.y = rand() % MAP_Y;
					 if (fruit.x == tail[i].x && fruit.y == tail[i].y)	i = length;
				 } while (fruit.x == 0 || fruit.x == MAP_X || fruit.y == 0 || fruit.y == MAP_Y || (fruit.y == tail[i].y && fruit.x == tail[i].x));
			 }
				 length++;
				 score += 10;
				 tail[length - 1].x = head_x;
				 tail[length - 1].y = head_y - length;

			 
		 
	 }
 }


 void logic() {
	 int i;
	 
	 if (head_x == 0 || head_x == MAP_X || head_y == 0 || head_y == MAP_Y) {
		 gameOver = 1;
		 system("cls");
		 printf("\n\n    GAME OVER!");
		 printf("\n\n Your score was %d",score);
		 Sleep(5000);
	 }

	 for (i = 0; i < length; i++) {
		 if (head_x == tail[i].x&&head_y == tail[i].y) {
			 gameOver = 1;
			 system("cls");
			 printf("\n\n    GAME OVER!");
			 printf("\n\n Your score was %d",score);
			 Sleep(5000);
		 }
	 }
	

 }

	

 

