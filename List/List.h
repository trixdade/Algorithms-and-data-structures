#ifndef __LIST_H_
#define __LIST_H_

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class List {
private:
	size_t size;

protected:
	template <typename T>
	struct Node {
		T data;
		Node<T>* next;

		Node() { data = 0; next = nullptr; }
		Node(T value = T(), Node* _next = nullptr) {
			data = value; next = _next;
		}
		bool operator > (const Node &right) const {
			if (data > right.data) return true;
			else return false;
		}
		bool operator < (const Node &right) const {
			if (data < right.data) return true;
			else return false;
		}
	};

	Node<T>* head;

public:
	// constructors and destructors
	List();
	~List(); // PROBLEM

	// methods
	void printList();
	Node<T>* getHead() { return head; }
	int getSize() { return size; }
	bool empty();
	void clear();

	void push_front(T object);
	void push_back(T object);
	void insert(T object);

	void del(T object);
	void pop_front();
	void pop_back();

	void merge(List<T> &lst);
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (size && head != nullptr) {
		pop_front();
	}
}

template<typename T>
void List<T>::merge(List<T> &lst)
{
	List<T> tmp;
	Node<T>* lstHead = lst.head;

	while (head != nullptr && lst.head != nullptr) {
		if (head->data <= lst.head->data) {
			tmp.push_back(head->data);
			head = head->next;
		}
		else {
			tmp.push_back(lst.head->data);
			lst.head = lst.head->next;
		}
	}
	while (lst.head != nullptr) {
		tmp.push_back(lst.head->data);
		lst.head = lst.head->next;
	}
	while (head != nullptr) {
		tmp.push_back(head->data);
		head = head->next;
	}
	lst.head = lstHead;
	*this = tmp;
	tmp.head = NULL; // для того, чтобы локальный деструктор, 
	tmp.size = 0;    // при удалении tmp, не менял значение *this
}

template<typename T>
void List<T>::insert(T object)
{
	if (head == nullptr || head->data > object) {
		push_front(object);
		return;
	}

	Node<T> *curr = head;
	while (curr->next != nullptr && curr->next->data < object && curr->data < object) {
		curr = curr->next;
	}
	Node<T> *newObject = new Node<T>(object);
	newObject->next = curr->next;
	curr->next = newObject;
	size++;
}

template<typename T>
void List<T>::push_front(T object)
{
	head = new Node<T>(object, head);
	size++;
}

template<typename T>
void List<T>::push_back(T object)
{
	if (head == nullptr) {
		head = new Node<T>(object);
	}
	else {
		Node<T>* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new Node<T>(object);
	}
	size++;
}

template<typename T>
void List<T>::del(T object) // объект точно есть в списке
{
	Node<T> *curr = head;
	if (curr->data == object) {
		pop_front();
		return;
	}
	while (curr->next != nullptr && curr->next->data != object) {
		curr = curr->next;
	}
	Node<T> *tmp = curr->next->next;
	delete curr->next;
	curr->next = tmp;
	size--;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *tmp = head;
	head = head->next;
	delete tmp;
	size--;
}

template<typename T>
void List<T>::pop_back()
{
	if (head->next == nullptr) {
		pop_front();
		return;
	}
	Node<T> *curr = head;
	while (curr->next->next != nullptr) {
		curr = curr->next;
	}
	delete curr->next;
	curr->next = nullptr;
	size--;
}

template<typename T>
void List<T>::printList()
{
	Node<T> *curr = head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

template<typename T>
bool List<T>::empty()
{
	if ((head == nullptr) && (size == 0)) return true;
	else return false;
}

#endif 