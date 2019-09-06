/*
 ===============================================================================
 Name        : project2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

#define FIO0DIR (*(volatile unsigned int *)0x2009c000)
#define FIO0PIN (*(volatile unsigned int *)0x2009c014)
#define FIO1DIR (*(volatile unsigned int *)0x2009c020)
#define FIO1PIN (*(volatile unsigned int *)0x2009c034)
#define FIO2DIR (*(volatile unsigned int *)0x2009c040)
#define FIO2PIN (*(volatile unsigned int *)0x2009c054)
#define PINMODE1 (*(volatile unsigned int *)0x4002c044)

#define false 0
#define true 1

struct flag {
	short value;
	short red;
	short green;
};

typedef struct flag flag;

int counter = 0;
flag check[9];
int redWinner = 0;
int greenWinner = 0;

void wait_ticks(unsigned long count);
void initializePorts();
void reset();
int checkStatus();
void redWinnerCount();
void greenWinnerCount();
void resetWinners();

int main(void) {
	initializePorts();

	while (1) {
		if ((((FIO0PIN >> 4) & 0x01) == 0) && (check[0].value == false)
				&& (counter % 2 == 0)) //on pressing pin 38
				{
			FIO0PIN |= (1 << 9); // turn on red, on pin 5
			check[0].value = 1;
			check[0].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO0PIN >> 4) & 0x01) == 0) && (check[0].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 38
				{
			FIO0PIN |= (1 << 16); // turn on green, on pin 14
			check[0].value = 1;
			check[0].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}

		}

		if ((((FIO0PIN >> 5) & 0x01) == 0) && (check[1].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 39
				{
			FIO0PIN |= (1 << 8); // turn on red, on pin 6
			check[1].value = 1;
			check[1].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO0PIN >> 5) & 0x01) == 0) && (check[1].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 39
				{
			FIO0PIN |= (1 << 23); // turn on green, on pin 15
			check[1].value = 1;
			check[1].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO0PIN >> 10) & 0x01) == 0) && (check[2].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 40
				{
			FIO0PIN |= (1 << 7); // turn on red, on pin 7
			check[2].value = 1;
			check[2].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO0PIN >> 10) & 0x01) == 0) && (check[2].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 40
				{
			FIO0PIN |= (1 << 24); // turn on green, on pin 16
			check[2].value = 1;
			check[2].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO0PIN >> 11) & 0x01) == 0) && (check[3].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 41
				{
			FIO0PIN |= (1 << 6); // turn on red, on pin 8
			check[3].value = 1;
			check[3].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO0PIN >> 11) & 0x01) == 0) && (check[3].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 41
				{
			FIO0PIN |= (1 << 25); // turn on green, on pin 17
			check[3].value = 1;
			check[3].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO2PIN >> 5) & 0x01) == 0) && (check[4].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 42 didn't work and moved to 47
				{
			FIO0PIN |= (1 << 0); // turn on red, on pin 9
			check[4].value = 1;
			check[4].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO2PIN >> 5) & 0x01) == 0) && (check[4].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 42
				{
			FIO0PIN |= (1 << 26); // turn on green, on pin 18
			check[4].value = 1;
			check[4].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO2PIN >> 1) & 0x01) == 0) && (check[5].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 43
				{
			FIO0PIN |= (1 << 1); // turn on red, on pin 10
			check[5].value = 1;
			check[5].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO2PIN >> 1) & 0x01) == 0) && (check[5].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 43
				{
			counter++;
			FIO1PIN |= (1 << 30); // turn on green, on pin 19
			check[5].value = 1;
			check[5].green = 1;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO2PIN >> 2) & 0x01) == 0) && (check[6].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 44
				{
			FIO0PIN |= (1 << 18); // turn on red, on pin 11
			check[6].value = 1;
			check[6].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO2PIN >> 2) & 0x01) == 0) && (check[6].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 44
				{
			FIO1PIN |= (1 << 31); // turn on green, on pin 20
			check[6].value = 1;
			check[6].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO2PIN >> 3) & 0x01) == 0) && (check[7].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 45
				{
			FIO0PIN |= (1 << 17); // turn on red, on pin 12
			check[7].value = 1;
			check[7].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO2PIN >> 3) & 0x01) == 0) && (check[7].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 45
				{
			FIO0PIN |= (1 << 2); // turn on green, on pin 21
			check[7].value = 1;
			check[7].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

		if ((((FIO2PIN >> 4) & 0x01) == 0) && (check[8].value == 0)
				&& (counter % 2 == 0)) //on pressing pin 46
				{
			FIO0PIN |= (1 << 15); // turn on red, on pin 13
			check[8].value = 1;
			check[8].red = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 1 !!\n");
				redWinner++;
				redWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}
		if ((((FIO2PIN >> 4) & 0x01) == 0) && (check[8].value == 0)
				&& (counter % 2 != 0)) //on pressing pin 46
				{
			FIO0PIN |= (1 << 3); // turn on green, on pin 22
			check[8].value = 1;
			check[8].green = 1;
			counter++;
			if (checkStatus() == 1) {
				printf("Congratulations player 2 !!\n");
				greenWinner++;
				greenWinnerCount();
				reset();
			}
			if (counter == 9) {
				printf("Game Over!!\n please try again..\n");
				reset();
			}
		}

	}
	return 0;
}

void wait_ticks(unsigned long count) {
	volatile int ticks;
	for (ticks = 0; ticks < count; ticks++) {

	}
}

void initializePorts() {
	FIO0DIR |= (1 << 9); //configure port 9 as output
	FIO0DIR |= (1 << 8); //configure port 9 as output
	FIO0DIR |= (1 << 7); //configure port 9 as output
	FIO0DIR |= (1 << 6); //configure port 9 as output
	FIO0DIR |= (1 << 0); //configure port 9 as output
	FIO0DIR |= (1 << 1); //configure port 9 as output
	FIO0DIR |= (1 << 18); //configure port 9 as output
	FIO0DIR |= (1 << 17); //configure port 9 as output
	FIO0DIR |= (1 << 15); //configure port 9 as output
	FIO0DIR |= (1 << 16); //configure port 9 as output
	FIO0DIR |= (1 << 23); //configure port 9 as output
	FIO0DIR |= (1 << 24); //configure port 9 as output
	FIO0DIR |= (1 << 25); //configure port 9 as output
	FIO0DIR |= (1 << 26); //configure port 9 as output
	FIO1DIR |= (1 << 30); //configure port 9 as output
	FIO1DIR |= (1 << 31); //configure port 9 as output
	FIO0DIR |= (1 << 2); //configure port 9 as output
	FIO0DIR |= (1 << 3); //configure port 9 as output

	FIO0DIR |= (1 << 21); //configure port 9 as output
	FIO0DIR |= (1 << 22); //configure port 9 as output
	FIO2DIR |= (1 << 13); //configure port 9 as output
	FIO2DIR |= (1 << 6); //configure port 9 as output
	FIO2DIR |= (1 << 7); //configure port 9 as output
	FIO2DIR |= (1 << 8); //configure port 9 as output

	FIO0PIN &= ~(1 << 9);
	FIO0PIN &= ~(1 << 8);
	FIO0PIN &= ~(1 << 7);
	FIO0PIN &= ~(1 << 6);
	FIO0PIN &= ~(1 << 0);
	FIO0PIN &= ~(1 << 1);
	FIO0PIN &= ~(1 << 18);
	FIO0PIN &= ~(1 << 17);
	FIO0PIN &= ~(1 << 15);
	FIO0PIN &= ~(1 << 16);
	FIO0PIN &= ~(1 << 23);
	FIO0PIN &= ~(1 << 24);
	FIO0PIN &= ~(1 << 25);
	FIO0PIN &= ~(1 << 26);
	FIO1PIN &= ~(1 << 30);
	FIO1PIN &= ~(1 << 31);
	FIO0PIN &= ~(1 << 2);
	FIO0PIN &= ~(1 << 3);

	FIO0PIN &= ~(1 << 21);
	FIO0PIN &= ~(1 << 22);
	FIO2PIN &= ~(1 << 13);
	FIO2PIN &= ~(1 << 6);
	FIO2PIN &= ~(1 << 7);
	FIO2PIN &= ~(1 << 8);

	FIO2DIR &= ~(1 << 0);
	wait_ticks(0.1);

//	PINMODE1 |= (1 << 2) | (1 << 3); //(3<<4); you can also do PINMODE1 |= (1<<4)|(1<<5) // here 11 is 3
//	wait_ticks(0.1);

	for (int i = 0; i < 9; i++) {
		check[i].value = 0;
		check[i].red = 0;
		check[i].green = 0;
	}

}

void reset() {
	wait_ticks(10000000 / 4); // aprox 7 seconds wait
	FIO0PIN &= ~(1 << 9);
	FIO0PIN &= ~(1 << 8);
	FIO0PIN &= ~(1 << 7);
	FIO0PIN &= ~(1 << 6);
	FIO0PIN &= ~(1 << 0);
	FIO0PIN &= ~(1 << 1);
	FIO0PIN &= ~(1 << 18);
	FIO0PIN &= ~(1 << 17);
	FIO0PIN &= ~(1 << 15);
	FIO0PIN &= ~(1 << 16);
	FIO0PIN &= ~(1 << 23);
	FIO0PIN &= ~(1 << 24);
	FIO0PIN &= ~(1 << 25);
	FIO0PIN &= ~(1 << 26);
	FIO1PIN &= ~(1 << 30);
	FIO1PIN &= ~(1 << 31);
	FIO0PIN &= ~(1 << 2);
	FIO0PIN &= ~(1 << 3);

	for (int i = 0; i < 9; i++) {
		check[i].value = 0;
		check[i].red = 0;
		check[i].green = 0;
	}

	counter = 0;
}

int checkStatus() {

	/*  our grid looks like
	 ===============================================================================

	 8	|	7	|	6
	 ---|-------|-------
	 5	|	4	|	3
	 ---|-------|-------
	 2	|	1	|	0

	 ===============================================================================
	 */

	int gameOver = 0;

	//checking player 1's status horizontally on nodes 0, 1, & 2
	if ((check[0].red == 1) && (check[1].red == 1) && (check[2].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status horizontally on nodes 0, 1, & 2
	if ((check[0].green == 1) && (check[1].green == 1)
			&& (check[2].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status horizontally on nodes 3, 4, & 5
	if ((check[3].red == 1) && (check[4].red == 1) && (check[5].red == 1)) {
		gameOver = 1;
	}
	if ((check[3].green == 1) && (check[4].green == 1)
			&& (check[5].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status horizontally on nodes 6, 7, & 8
	if ((check[6].red == 1) && (check[7].red == 1) && (check[8].red == 1)) {
		gameOver = 1;
	}
	if ((check[6].green == 1) && (check[7].green == 1)
			&& (check[8].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status vertically on nodes 8, 5, & 2
	if ((check[8].red == 1) && (check[5].red == 1) && (check[2].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status vertically on nodes 8, 5, & 2
	if ((check[8].green == 1) && (check[5].green == 1)
			&& (check[2].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status vertically on nodes 7, 4, & 1
	if ((check[4].red == 1) && (check[4].red == 1) && (check[1].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status vertically on nodes 8, 5, & 2
	if ((check[7].green == 1) && (check[4].green == 1)
			&& (check[1].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status vertically on nodes 6, 3, & 0
	if ((check[6].red == 1) && (check[3].red == 1) && (check[0].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status vertically on nodes 8, 5, & 2
	if ((check[6].green == 1) && (check[3].green == 1)
			&& (check[0].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status diagonally on nodes 8, 4, & 0
	if ((check[8].red == 1) && (check[4].red == 1) && (check[0].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status diagonally on nodes 8, 4, & 0
	if ((check[8].green == 1) && (check[4].green == 1)
			&& (check[0].green == 1)) {
		gameOver = 1;
	}

	//checking player 1's status diagonally on nodes 6, 4, & 2
	if ((check[6].red == 1) && (check[4].red == 1) && (check[2].red == 1)) {
		gameOver = 1;
	}
	//checking player 2's status diagonally on nodes 6, 4, & 2
	if ((check[6].green == 1) && (check[4].green == 1)
			&& (check[2].green == 1)) {
		gameOver = 1;
	}
	return gameOver;
}

void redWinnerCount() {
	if (redWinner == 1) {
		FIO0PIN |= (1 << 21); // turn on red, on pin 23
	} else if (redWinner == 2) {
		FIO0PIN |= (1 << 22); // turn on red, on pin 24
	} else {
		FIO2PIN |= (1 << 13); // turn on red, on pin 24
		redWinner = 0;
		resetWinners();
	}
}

void greenWinnerCount() {
	if (greenWinner == 1) {
		FIO2PIN |= (1 << 6); // turn on red, on pin 23
	} else if (greenWinner == 2) {
		FIO2PIN |= (1 << 7); // turn on red, on pin 24
	} else {
		FIO2PIN |= (1 << 8); // turn on red, on pin 24
		greenWinner = 0;
		resetWinners();
	}
}

void resetWinners() {
	wait_ticks(10000000 / 4); // aprox 7 seconds wait
	FIO0PIN &= ~(1 << 21);
	FIO0PIN &= ~(1 << 22);
	FIO2PIN &= ~(1 << 13);
	FIO2PIN &= ~(1 << 6);
	FIO2PIN &= ~(1 << 7);
	FIO2PIN &= ~(1 << 8);
}
