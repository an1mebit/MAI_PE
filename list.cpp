#include <iostream>
#include <string>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void popfront();
	void pushback(T data);
	void clear();
	int getsize() { return size; }
	void pushfront(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void popback();

	T& operator[](const int index);

private:


	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data=T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T> *head;
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
	cout << "the program is closed" << endl;
	clear();
}

template<typename T>
void List<T>::popfront()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pushback(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	size++;	
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		popfront();
	}
}

template<typename T>
void List<T>::pushfront(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		pushfront(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		popfront();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::popback()
{
	removeAt(size - 1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List<int> lst;
	string command;
	cout << "Enter help to know commands" << endl;

	cin >> command;
	if (command == "help")
	{
		cout << "list - create list list" << endl << "clear - clear a list" << endl << "add - add a number" << endl;
		cout << "check - check a list" << endl << "delete - delete a number" << endl;
		cout << "rand - add a random number" << endl << "close - close the program" << endl;
	}
	while (command != "close")
	{
		cin >> command;
		if (command == "list")
		{
			cout << "Enter size" << endl;
			int numberscount;
			cin >> numberscount;
			for (int i = 0; i < numberscount; i++)
			{
				lst.pushback(rand() % 10);
			}

			for (int i = 0; i < lst.getsize(); i++)
			{
				cout << lst[i] << " ";
			}
			cout << endl;
		}
		else if (command == "clear")
		{
			lst.clear();
			cout << "list was cleared" << endl;
		}
		else if (command == "add")
		{
			int a, b;
			cout << "enter data and index" << endl;
			cin >> a >> b;
			lst.insert(a, b);
		}
		else if (command == "rand")
		{
			int b;
			cout << "enter index" << endl;
			cin >> b;
			lst.insert(rand()%10, b);
		}
		else if (command == "delete")
		{
			int index;
			cout << "enter index" << endl;
			cin >> index;
			lst.removeAt(index);
		}
		else if (command == "check")
		{
			for (int i = 0; i < lst.getsize(); i++)
			{
				cout << lst[i] << " ";
			}
			if (lst.getsize() == 0)
				cout << "nothing";
			cout << endl;
		}
		else
			cout << "unidentified command" << endl;
	}
	return 0;
}
