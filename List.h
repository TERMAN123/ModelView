#pragma once
#include "Node.h"
#include <vector>

template<typename T>
class List
{
public:
	List() :
		m_size(0),
		m_first(nullptr),
		m_last(nullptr)
	{

	}

	List(const List<T>& other);
	List<T>& operator=(const List<T>& other);
	~List();

	T& operator[](int index);
	const T& operator[](int index) const;
	const T& at(int index) const;

	void push_back(const T& value);
	void push_front(const T& value);
	T pop_back();
	T pop_front();
	void insert(const T& value, int index);
	List<T>& operator<<(const T& value);

	void remove(int index);
	void removeByValue(const T& value);

	void reverse();

	bool isEmpty() const
	{
		return m_size == 0;
	}

	int size() const
	{
		return m_size;
	}

	const T& first() const
	{
		return *m_first->getData();
	}

	const T& last() const
	{
		return *m_last->getData();
	}

	void clear();

	void print() const
	{
		std::cout << *this << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& output, const List<T>& other)
	{
		Node<T>* tempNode = other.m_first;
		while (tempNode != nullptr)
		{
			output << *tempNode->getData() << "\t";
			tempNode = tempNode->getNext();
		}
		return output;
	}

private:
	void cloneFrom(const List<T>& other);

private:
	int m_size;
	Node<T>* m_first;
	Node<T>* m_last;
};


template<typename T>
List<T>::List(const List<T>& other) :
	m_size(0),
	m_first(nullptr),
	m_last(nullptr)
{
	cloneFrom(other);
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(const T& value)
{
	insert(value, m_size);
}

template<typename T>
void List<T>::push_front(const T& value)
{
	insert(value, 0);
}

template<typename T>
List<T>& List<T>::operator<<(const T& value)
{
	insert(value, m_size);
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != (&other))
	{
		clear();
		cloneFrom(other);
	}
	return *this;
}

template<typename T>
void List<T>::cloneFrom(const List<T>& other)
{
	Node<T>* currentNode = other.m_first;
	Node<T>* prevNode = nullptr;

	while (currentNode != nullptr)
	{
		Node<T>* tempNode = new Node<T>(*currentNode->getData());

		if (prevNode != nullptr)
		{
			tempNode->setPrev(prevNode);
			prevNode->setNext(tempNode);
		}
		else
		{
			m_first = tempNode;
		}
		currentNode = currentNode->getNext();
		prevNode = tempNode;

		if (currentNode == nullptr)
		{
			m_last = tempNode;
		}
	}
	m_size = other.m_size;
}

template<typename T>
T List<T>::pop_back()
{
	if (m_size == 0)
	{
		throw std::out_of_range("list is empaty");
	}
	T data = *m_last->getData();
	remove(m_size-1);
	return data;
}

template<typename T>
T List<T>::pop_front()
{
	if (m_size == 0)
	{
		throw std::out_of_range("list is empaty");
	}
	T data = *m_first->getData();
	remove(0);
	return data;
}

template<typename T>
const T& List<T>::at(int index) const
{
	if (index > (m_size - 1) || index < 0)
	{
		throw std::out_of_range("index out of range");
	}
	else
	{
		return (*this)[index];
	}
}

template<typename T>
const T& List<T>::operator[](int index) const
{
	Node<T>* tempNode = m_first;
	int it = 0;
	while (tempNode != nullptr)
	{
		if (index == it)
		{
			return *tempNode->getData();
		}
		it++;
		tempNode = tempNode->getNext();
	}
	throw std::out_of_range("index out of range");
}

template<typename T>
T& List<T>::operator[](int index)
{
	return const_cast<T&>(static_cast<const List<T>&>(*this)[index]);
}

template<typename T>
void List<T>::insert(const T& value, int index)
{
	if (index < 0 || index > m_size)
	{
		throw std::out_of_range("index out of range");
	}

	Node<T>* newNode = new Node<T>(value);
	if (m_size > 0)
	{
		Node<T>* currentNode = m_first;
		int it = 0;
		while (currentNode != nullptr)
		{
			if (index == 0)
			{
				m_first->setPrev(newNode);
				newNode->setNext(m_first);
				m_first = newNode;
				break;
			}
			else if (index == m_size)
			{
				m_last->setNext(newNode);
				newNode->setPrev(m_last);
				m_last = newNode;
				break;
			}
			else if (index == it)
			{
				Node<T>* prevNode = currentNode->getPrev();
				newNode->setPrev(prevNode);
				prevNode->setNext(newNode);
				newNode->setNext(currentNode);
				currentNode->setPrev(newNode);
				break;
			}
			++it;
			currentNode = currentNode->getNext();
		}
		m_size++;
	}
	else
	{
		m_first = newNode;
		m_last = newNode;
		m_size++;
	}
}

template<typename T>
void List<T>::remove(int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::out_of_range("index out of range");
	}

	if (m_size == 1)
	{
		clear();
	}

	int it = 0;
	Node<T>* removeNode = m_first;
	while (removeNode != nullptr)
	{
		if (index == it)
		{
			if (removeNode->getPrev() == nullptr)
			{
				m_first = removeNode->getNext();
				m_first->setPrev(nullptr);
			}
			else if (removeNode->getNext() == nullptr)
			{
				m_last = removeNode->getPrev();
				m_last->setNext(nullptr);
			}
			else
			{
				Node<T>* nextNode = removeNode->getNext();
				Node<T>* prevNode = removeNode->getPrev();
				nextNode->setPrev(prevNode);
				prevNode->setNext(nextNode);
			}
			delete removeNode;
			m_size--;
			break;
		}
		it++;
		removeNode = removeNode->getNext();
	}
}

template<typename T>
void List<T>::removeByValue(const T& value)
{
	Node<T>* removeNode = m_first;
	int it = 0;
	std::vector<int> removIndexs;
	while (removeNode != nullptr)
	{
		if (*removeNode->getData() == value)
		{
			removIndexs.push_back(it);
		}
		++it;
		removeNode = removeNode->getNext();
	}

	int indexOffset = 0;
	for (int i = 0; i < removIndexs.size(); i++)
	{
		remove(removIndexs[i] - indexOffset);
		indexOffset++;
	}
}

template<typename T>
void List<T>::clear()
{
	if (m_size != 0)
	{
		Node<T>* currentNode = m_first;
		Node<T>* tempNode = nullptr;
		while (currentNode != nullptr)
		{
			tempNode = currentNode->getNext();
			delete currentNode;
			currentNode = tempNode;
		}
		m_size = 0;
		m_first = nullptr;
		m_last = nullptr;
	}
}

template<typename T>
void List<T>::reverse()
{
	Node<T>* curretNode = m_first;
	while (curretNode != nullptr)
	{
		Node<T>* nextNode = curretNode->getNext();
		Node<T>* prevNode = curretNode->getPrev();
		curretNode->setNext(prevNode);
		curretNode->setPrev(nextNode);

		curretNode = nextNode;
	}
	Node<T>* tempNode = m_first;
	m_first = m_last;
	m_last = tempNode;
}