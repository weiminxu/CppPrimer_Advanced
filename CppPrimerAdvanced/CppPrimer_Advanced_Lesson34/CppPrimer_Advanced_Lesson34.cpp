#include <iostream>
#include "OrderQueue.h"

using namespace std;

int main()
{
	//Queue<int> Q(19);
	//Queue<int> q(10);
	//cout << "test order queue!!" << endl;

	Queue<char> q(8);
	q.Push('A');
	q.Push('B');

	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << "*************************" << endl;
	q.Pop();
	cout << q.Front() << endl;
	cout << q.Rear() << endl;

	
	system("pause");
	return 0;
}