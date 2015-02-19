#include "stdafx.h"
#include <iostream>

using namespace std;

//There is three arguments so we always know which peg is the spare one so we can know which one to put disks on
void Hanoi(int n, int source, int dest, int spare)
{
	//This is the base case. We get to here when we are operating on the smallest possible disk.
	if (n == 0)
	{
		cout << "Move disk " << n << " from peg " << source << " to peg " << dest << endl;
	}
	else
	{
		//Move all disks smaller than this one over to the spare.
		//So if n (diskSize) is 5, we move 4 disks to the spare. This leaves us with 1 disk
		//on the source peg.		
		//We are now using the dest peg as the spare peg. This causes each recursion to ping-pong
		//the spare and dest pegs.
		Hanoi(n - 1, source, spare, dest);

		//Move the remaining disk to the destination peg.
		cout << "Move disk " << n << " from peg " << source << " to peg " << dest << endl;

		//Move the disks we just moved to the spare back over to the dest peg.
		Hanoi(n - 1, spare, dest, source);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Hanoi(3,1,3,2);


	cin.get();
}

