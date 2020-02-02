#include <iostream>
#include "Queue.h"
#include "GeneralQueue.h"
#include <string>

using namespace std;

int main()
{
	/*Queue q;
	q.push(0);
	q.push(3);
	q.push(5);
	q.push(7);
	cout << q.getlength() << endl;
	q.print();*/

	GeneralQueue<string> gq;
	gq.push("hello");
	gq.push(" template");
	gq.push(" and");
	gq.push(" general");
	gq.push(" programming!");
	gq.print();

	return 0;
}