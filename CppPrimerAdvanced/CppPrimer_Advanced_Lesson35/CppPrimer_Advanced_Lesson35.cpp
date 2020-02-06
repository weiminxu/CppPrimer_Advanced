#include <iostream>
#include "LinkQueue.h"

using namespace std;

int main()
{
	Queue<int> lq;
	//lq.enqueue(10);
	lq.enqueue(20);
	//cout << lq.getFront() << endl;
	cout << lq.getFront() << endl;
	lq.makeEmpty();
	//cout << lq.getFront() << endl;
	system("pause");
	return 0;
}