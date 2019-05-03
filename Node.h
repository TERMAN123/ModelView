#pragma once

template<typename T>
class Node
{
public:
	Node(const T& data) :
		m_data(new T(data)),
		m_next(nullptr),
		m_prev(nullptr)
	{

	}

	~Node()
	{
		delete m_data;
	}

	void setNext(Node<T>* next)
	{
		m_next = next;
	}

	Node<T>* getNext() const
	{
		return m_next;
	}

	void setPrev(Node<T>* prev)
	{
		m_prev = prev;
	}

	Node<T>* getPrev() const
	{
		return m_prev;
	}

	T* getData() const
	{
		return m_data;
	}

private:
	T* m_data;
	Node<T>* m_next;
	Node<T>* m_prev;
};
