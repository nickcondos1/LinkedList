// Nick Condos
// Compiles with both g++ version 6.3.0 and visual studios/microsoft compiler 19.13.26129

// I left a print statement in the copy/move constructors so you can tell when they're being used
// Comment it out if it gets in the way of testing other menu options


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


template <class T>
class LinkedList
{
	private:
		class Node
		{
			public:
				T data;
				Node* next;

			public:
				Node (T data = NULL, Node *next = NULL) { this->data = data; this->next = next; }
				//Node (const T& val_data, const Node* val_next) : data(val_data), next(val_next) {}
				Node() : data(NULL), next(NULL) {}

		};

	private:
		class Iterator
		{
			public:
				Iterator()
				{
					val = NULL;
				}
				Iterator (Node *n)
				{
					val = n;
				}
				Iterator& operator++() {
					val = val->next;
					return *this;
				}
				Iterator operator++(int) {
					Iterator it(*this);
					val = val->next;
					return it;
				}
				T& operator *()
				{
					return val->data;
				}
				bool operator !=(const Iterator& other)
				{
					return val != other.val;
				}
			private:
				Node *val;
		};

	public:
		Node* head;
		int size;

	public:
		LinkedList();
		LinkedList(const LinkedList<T>& orig); //Copy Constructor
		LinkedList(LinkedList<T>&& rhs); //Move Constructor
		~LinkedList();
		LinkedList<T>& operator = (LinkedList<T>& orig); //Assignment operator overload
		LinkedList<T>& operator = (LinkedList<T>&& orig); //Move assignment operator
		bool operator == (const LinkedList<T>& orig);
		T operator [] (int) const;
		T& operator [] (int index);
		LinkedList<T> operator + (const LinkedList<T>&) const;
		void addFirst(T data);
		void add(int index, T data);
		void addLast(T data);
		int sizeList();
		bool remove(T data);
		T removeIndex(int index);
		bool removeAll(T data); //Remove all occurrences
		void sort();
		void print(ostream& out) const;
		LinkedList<T> testing(LinkedList<T> temp);
		void itTesting(LinkedList<T> temp);


		Iterator begin()
		{
			return Iterator (this->head);
		}
		Iterator end()
		{
			return Iterator(nullptr);
		}


};

template <class T>
LinkedList<T>::LinkedList()
{
	this->head = NULL;
	size = 0;
}

template <class T>
void LinkedList<T>::itTesting(LinkedList<T> temp)
{
	Iterator i;
	for (i = temp.begin(); i != temp.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "\nIterator worked" << endl;
}

template <class T>
ostream& operator << (ostream& out, const LinkedList<T> &list);

template <class T>
ostream& operator << (ostream& out, const LinkedList<T> &list)
{
	list.print(out);
	return out;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T>&& orig)
{
	this->size = 0;
	this->head = nullptr;

	this->size = orig.size;
	this->head = orig.head;

	orig.size = 0;
	orig.head = nullptr;

	cout << "Move assignment operator called" << endl;

	return *this;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& rhs) :
head(nullptr), size(0)
{
	this->size = rhs.size;
	this->head = rhs.head;

	rhs.size = 0;
	rhs.head = nullptr;
	cout << "Move constructor called" << endl;
}

template <class T>
LinkedList<T> LinkedList<T>::testing(LinkedList<T> temp)
{
	return temp;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& orig)
{
	Node* cur;

	this->head = new Node(orig.head->data);
	this->size++;
	for (cur = orig.head->next; cur != NULL; cur = cur->next)
	{
		this->addLast(cur->data);
	}
	cout << "copy constructor called" << endl;
}

template <class T>
void LinkedList<T>::sort()
{
		if (this->size > 1)
			{
				Node* start;
				Node* search;
				Node* min;

				T temp;

				for (start = this->head; start != NULL; start = start->next)
				{
					min = start;

					for (search = start->next; search != NULL; search = search->next)
					{
						if (min->data > search->data)
							min = search;
					}
					temp = min->data;
					min->data = start->data;
					start->data = temp;
				}
			}

}

template <class T>
bool LinkedList<T>::removeAll(T data)
{
	int i = 0;
	while (remove(data))
	{
		i++;
		remove(data);
	}
	if (i == 0)
		return false;
	else
		return true;
}

template <class T>
T LinkedList<T>::removeIndex(int index)
{
	if (index < 0 || index >= this->size)
		throw out_of_range ("Index out of range");

	Node* cur = this->head;
	Node* prev = NULL;

	for (int i = 0; i < index; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
	{
		this->head = this->head->next;
		this->size--;
	}
	else
	{
		prev->next = cur->next;
		this->size--;
	}
	return cur->data;

}

template <class T>
bool LinkedList<T>::remove(T data)
{
	Node* cur;
	Node* prev = NULL;

	for (cur = this->head; cur != NULL; cur = cur->next)
	{
		if (cur->data == data)
		{
			if (prev == NULL)
			{
				this->head = this->head->next;
				this->size--;
				return true;
			}
			else {
			prev->next = cur->next;
			this->size--;
			return true;
			}
		}
		prev = cur;
	}
	return false;
}

template <class T>
void LinkedList<T>::add(int index, T data)
{
	if (index < 0 || index > this->size)
		throw out_of_range ("Index out of range");

	if (index == 0) {
		this->addFirst(data);
	return;
	}

	Node* cur;
	int i = 1;
	for (cur = this->head; cur != NULL; cur = cur->next)
	{
		if (i == index) {
			cur->next = new Node(data, cur->next);
			this->size++;
		}
		i++;
	}

}

template <class T>
LinkedList<T> LinkedList<T>::operator + (const LinkedList<T>& right) const
{
	LinkedList<T> result;

	Node* cur;
	Node* rcur;

	for (cur = this->head; cur != NULL; cur = cur->next)
	{
		result.addLast(cur->data);
	}

	for (rcur = right.head; rcur != NULL; rcur = rcur->next)
	{
		result.addLast(rcur->data);
	}

	return result;
}

template <class T>
T& LinkedList<T>::operator [] (int index) //one[5] = 2; SETTER
{
	Node *cur = this->head;

	for(int i = 0; i < index; i++)
	{
		cur = cur->next;
	}

	return cur->data;
}

template <class T>
T LinkedList<T>::operator [] (int num) const // int number = one[5]; GETTER
{
	T value;
	Node* cur;

	int i = 0;
	for (cur = this->head; cur != NULL; cur = cur->next)
	{
		if (i == num)
			value = cur->data;
		i++;

	}
	return value;


}
template <class T>
bool LinkedList<T>::operator == (const LinkedList<T>& orig)
{
	Node* cur;
	Node* temp = this->head;

	for (cur = orig.head; cur != NULL; cur = cur->next)
	{
		if (temp->data != cur->data)
			return false;
		if (temp == NULL)
			return false;

		temp = temp->next;
	}

	return true;
}

template <class T>
int LinkedList<T>::sizeList()
{
	return this->size;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
	if (this->size == 0)
	{
		this->addFirst(data);
	}
	else
	{
		Node* cur = this->head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = new Node(data, cur->next);
	}
	this->size++;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T>& orig)
{
	Node* cur;
	for(cur = orig.head; cur != NULL; cur = cur->next)
	{
		this->addLast(cur->data);
	}

	this->size--;
	return *this;
}

template<class T>
void LinkedList<T>::print(ostream& out) const
{
	Node *cur;
	for (cur = this->head; cur != NULL; cur = cur->next)
	{
		out << cur->data << " ";
	}
	out << endl;
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
	this->head = new Node(data, this->head);
	this->size++;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node* temp = this->head;
	Node* cur = NULL;

	while (temp)
	{
		cur = temp;
		temp = temp->next;
		delete(cur);
	}

	this->head = NULL;

	//cout << "Destructor called" << endl;
}

#endif



