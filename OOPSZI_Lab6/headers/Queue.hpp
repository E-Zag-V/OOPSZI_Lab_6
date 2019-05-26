#pragma once
#include "Node.hpp"
#include "AbstractQueue.hpp"

template <typename T>
class Queue : public AbstractQueue<T>
{
private:
	int size, pos;
	Node<T> *arr;

public:
	Queue(int _size);

	virtual int GetSize() override;
	virtual void Push(const T &element) override;
	virtual Node<T> Pop() override;
	virtual Node<T> Peek() override;

	friend ostream& operator<< <>(ostream &out, const Queue<T> &q);
};

template <typename T>
Queue<T>::Queue(int _size)
{
	pos = 0;
	size = _size;
	arr = new Node<T>[size];
}

template <typename T>
int Queue<T>::GetSize() { return size; }

template <typename T>
void Queue<T>::Push(const T &element)
{
	if (pos == 0)
	{
		arr[pos] = Node<T>(element);
		arr[pos].SetPrev(&arr[pos]); arr[pos].SetNext(&arr[pos]);
		pos++;
	}
	else
	{
		arr[pos] = Node<T>(element, &arr[pos - 1], NULL);
		arr[pos].SetNext(&arr[0]);
		arr[pos - 1].SetNext(&arr[pos]); arr[0].SetPrev(&arr[pos]);
		pos++;
	}
}

template <typename T>
Node<T> Queue<T>::Pop() 
{
	for (int i = 0; i < size - 1; i++)
	{
		Node<T> tmp(arr[i + 1].GetData());
		tmp.SetPrev(arr[i].GetPrev());
		tmp.SetNext(arr[i].GetNext());
		arr[i] = tmp;
	}

	Node<T> tmp = arr[pos];
	pos--;

	return tmp;
}


template <typename T>
Node<T> Queue<T>::Peek()
{ 
	return arr[0];
}

template <typename T>
ostream& operator<< (ostream &out, const Queue<T> &q)
{
	Node<T> *tmp;

	for (int i = 0; i < q.pos; i++)
	{
		tmp = &q.arr[i];

		out << "Data: " << tmp->GetData() << endl;
		out << "Current: " << tmp << endl;
		out << "Prev:\t " << tmp->GetPrev() << endl;
		out << "Next:\t " << tmp->GetNext() << endl;
		out << endl;
	}

	return out;
}