#pragma once

template <typename T>
class AbstractQueue
{
public:
	virtual int GetSize() = 0;
	virtual void Push(const T &element) = 0;
	virtual Node<T> Pop() = 0;
	virtual Node<T> Peek() = 0;
};