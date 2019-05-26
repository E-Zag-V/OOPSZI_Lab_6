#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
	T data;
	Node<T> *prev, *next;

public:
	Node();
	Node(T _data);
	Node(T _data, Node<T> *_prev, Node<T> *_next);
	
	T GetData();
	Node<T>* GetPrev();
	Node<T>* GetNext();
	void SetData(T _data);
	void SetPrev(Node<T> *_prev);
	void SetNext(Node<T> *_next);
	friend ostream& operator<< <>(ostream &out, const Node<T> &n);
};

template <typename T>
Node<T>::Node() : data(NULL), prev(nullptr), next(nullptr) {}

template <typename T>
Node<T>::Node(T _data) : data(_data), prev(nullptr), next(nullptr) {}

template <typename T>
Node<T>::Node(T _data, Node<T> *_prev, Node<T> *_next) : data(_data), prev(_prev), next(_next) {}

template <typename T>
T Node<T>::GetData() { return data; }

template <typename T>
Node<T>* Node<T>::GetPrev() { return prev; }

template <typename T>
Node<T>* Node<T>::GetNext() { return next; }

template <typename T>
void Node<T>::SetData(T _data) { data = _data; }

template <typename T>
void Node<T>::SetPrev(Node<T> *_prev) { prev = _prev; }

template <typename T>
void Node<T>::SetNext(Node<T> *_next) { next = _next; }

template <typename T>
ostream& operator<< (ostream &out, const Node<T> &n)
{
	out << "Data: " << n.data << endl;
	out << "Current: " << &n << endl;
	out << "Prev:\t " << n.prev << endl;
	out << "Next:\t " << n.next << endl;

	return out;
}