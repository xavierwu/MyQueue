#include "Queue.h"
#include <iostream>

int main ()
{
	Queue<int, 10> q;
	for (int i = 0; i < 10; ++i)
		q.push (i);
	int tmp = 0;
	while (!q.empty ()) {
		q.front (tmp);
		q.pop ();
		std::cout << tmp << std::endl;
	}

	return 0;
}