// Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

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
/* kompleksitet n, vi skal søge igennem et array n antal pladser og finde x */
//2. Find, state and handle the base case (BC).
/* ar[i] = x return true else return false */
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* tæl array plads en op indtil den er ar[n] */
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
/* Udskrive hvilke sider der er på hvilke sheets ud fra start page og end page */
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
/* vi får printet mønstret, kompleksitet: n */
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
		pattern(n/2, i);
		cout << string(i, ' ');
		for (int i = 0; i < n; i++)
		{
			cout << "* ";
		}
		cout << endl;
		pattern(n/2, n + i);
		
	}
}

//1. State the problem in terms of its size / complexity
/* længden af telefonnummeret, k */
//2. Find, state and handle the base case (BC).
/* k = 0, -> cout << strSoFar*/
//3. Find, state and handle the recursive case (RC)and ensure progress towards the BC
/* k > 0, foreach c in phone[0] chars, for hver -> Number(str, phoneNumber[1..k]) */
//4. Ensure that the RC reaches the BC
//standard helstalsargumentation




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
	pattern(8, 0);

	getchar();
	return 0;
}

