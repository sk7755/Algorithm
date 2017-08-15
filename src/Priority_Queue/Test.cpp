#include <iostream>
#include "Priority_Queue.h"
#include "Priority_Queue.cpp"

using namespace std;

int mycmp(int& a, int& b)
{
	return a > b;
}

int main()
{
	Priority_Queue<int> q(100000, mycmp);

	while (true)
	{
		int op;
		cin >> op;

		int tmp;
		switch (op)
		{
		case 1: cin >> tmp;
			q.push(tmp);
			break;
		case 2: cout << q.top() << endl;
			q.pop();
			break;
		default:
			;
		}
	}
	return 0;
}