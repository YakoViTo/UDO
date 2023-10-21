
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<windows.h>
#include<iostream>
int main() {
printf("*");

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = 4;
	dwPos.Y = 5;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("*");

	dwPos.X = 18;
	dwPos.Y = 8;
	SetConsoleCursorPosition(hCon, dwPos);
	printf("*");


	return 0;
}
