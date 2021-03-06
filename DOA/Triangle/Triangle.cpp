// Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//1. State the problem in terms of its size / complexity
/* fra m til n og fra n til m antal stjerner. n*2 kompleksitet */
//2. Find, state and handle the base case (BC).
/* m =< n  */
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* m+1 indtil m == n, derefter m-1 indtil m == m */
//4. Ensure that the RC reaches the BC
//standard helstalsargumentation


void triangle(unsigned int m, unsigned int n)
{
	if (m <= n)
	{
		for (int i = 0; i < m; i++)
		{
			cout << "* ";
		}
		cout << endl;
		triangle(m + 1, n);
		for (int i = 0; i < m; i++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

//1. State the problem in terms of its size / complexity
/* kompleksitet n, vi skal s�ge igennem et array n antal pladser og finde x */
//2. Find, state and handle the base case (BC).
/* ar[i] = x return true else return false */
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* t�l array plads en op indtil den er ar[n] */
//4. Ensure that the RC reaches the BC
//standard helstalsargumentation

bool searchArray(int *ar, int n, int x)
{
	if (n > 0)
	{
		if (*ar == x)
		{
			return true;
		}
		return searchArray(ar + 1, n - 1, x);
	}
	return false;
}

//1. State the problem in terms of its size / complexity
/* Udskrive hvilke sider der er p� hvilke sheets ud fra start page og end page */
//2. Find, state and handle the base case (BC).
/* startpage >= endpage */
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* Startpage < endpage , udskriv startpage, startpage+1 og endpage-1 endpage*/
//4. Ensure that the RC reaches the BC
// standard helstalsargumentation

void bookletPrint(int startPage, int endPage)
{
	if (startPage < endPage)
	{
		cout << "on sheet " << ((startPage / 2) + 1) << " contains pages: " << startPage << ", " << startPage + 1 << ", " << endPage - 1 << ", " << endPage << endl;
		bookletPrint(startPage + 2, endPage - 2);
	}
}

//1. State the problem in terms of its size / complexity
/* vi f�r printet m�nstret, kompleksitet: n */
//2. Find, state and handle the base case (BC).
/* n = 0 */
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/*  */
//4. Ensure that the RC reaches the BC
//standard helstalsargumentation

void pattern(unsigned int n, unsigned int i)
{
	if (n > 0)
	{
		pattern(n / 2, i);
		cout << string(i, ' ');
		for (int i = 0; i < n; i++)
		{
			cout << "* ";
		}
		cout << endl;
		pattern(n / 2, n + i);

	}
}

//1. State the problem in terms of its size / complexity
/* l�ngden af telefonnummeret, k */
//2. Find, state and handle the base case (BC).
/* k = 0, -> cout << strSoFar*/
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* k > 0, foreach c in phone[0] chars, for hver -> Number(str, phoneNumber[1..k]) */
//4. Ensure that the RC reaches the BC
//standard helstalsargumentation


char number[8][4] = { { 'a', 'b', 'c', '\0' }, { 'd', 'e', 'f', '\0' },
{ 'g', 'h', 'i', '\0' }, { 'j', 'k', 'l', '\0' },
{ 'm', 'n', 'o', '\0' }, { 'p', 'q', 'r', 's' },
{ 't', 'u', 'v', '\0' }, { 'w', 'x', 'y', 'z' } };

void Number(string str, int *phoneNr, int size)
{
	if (size > 0)
	{
		if (*phoneNr != 0 && *phoneNr != 1)
		{
			string tmp = str + number[*phoneNr - 2][0];
			Number(tmp, phoneNr + 1, size - 1);

			tmp = str + number[*phoneNr - 2][1];
			Number(tmp, phoneNr + 1, size - 1);

			tmp = str + number[*phoneNr - 2][2];
			Number(tmp, phoneNr + 1, size - 1);

			if (number[*phoneNr - 2][3] != '\0')
			{
				tmp = str + number[*phoneNr - 2][3];
				Number(tmp, phoneNr + 1, size - 1);
			}
		}
		else
		{
			Number(str, phoneNr + 1, size - 1);
		}
	}
	else
	{
		fstream fs;
		fs.open("test.txt", fstream::out | fstream::app);
		fs << str << endl;
		fs.close();
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//triangle opgave
	//triangle(3, 1);

	//searchArray
	/*
	int ar[] = {1, 2, 3, 4, 5, 6, 7};
	cout << searchArray(ar, 3, 4);
	*/

	//Booklet printing
	//bookletPrint(1, 80);

	//make pattern
	//pattern(8, 0);

	fstream fs;
	fs.open("test.txt", fstream::out | fstream::trunc);	
	fs.close();

	int test[] = {3,0,9,5,5,2,6,4 };
	int *test2 = test + 1;

	Number("", test, 8);
	cout << "Done";

	getchar();
	return 0;
}

