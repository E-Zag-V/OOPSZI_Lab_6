#include <iostream>
#include "../headers/Node.hpp"
#include "../headers/Queue.hpp"

using namespace std;

int main()
{
	int size = 5;
	Queue<int> q(size);

	for (int i = 0; i < size; i++) q.Push(i);

	cout << q << endl;

	system("pause");
	return 0;
}