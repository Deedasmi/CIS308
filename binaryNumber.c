/**********************************************

* Name: Richard Petrie                        *

* Date: 9/5/14                                *

* Assignment: Project 1: Binary counting      *

***********************************************

* This program takes a number and counts to   *
* that number in binary.                      *

***********************************************/

#include <stdio.h>
//Declarations
int biggestPowe2(int);
void printBinary(int, int);

int main() {
	//Initialize
	int decimal= 0; int power2; int i;

	//Get number from user. Repeat until positive number.
	do {
		printf("Enter a positive number to be counted to: ");
		scanf("%d", &decimal);
		//printf("\n"); //move to new line. Just so I don't forget later.
	} while ( decimal < 1);
	//Initial value
	//power2 = biggestPower2(decimal);
	//printf("Power is %d",power2); //tempory testing statement
	printBinary(decimal, biggestPower2(decimal));
}

int biggestPower2(int decimal) {
	//if at the bottom of the math, fall out of recursion
	if( decimal > 1) {
		//Due to the way C handles integers and decimals (for all intents and purposes, always rounds down)
		//we can simply divide by 2 a power2 number of times, and we'll be left with 1.
		//This power2 number + 1 will be the number of binary bits required.
		decimal = 1 + biggestPower2(decimal / 2);
	}
	return decimal; //returns the power
}

void printBinary(int decimal, int power2) {
	int i = 1;
	if (decimal > 0) { //stop recursing at 0
		printBinary(decimal - 1, biggestPower2(decimal - 1));
	}
	//convert to binary
	printf("%d\n",decimal);
	for ()
}