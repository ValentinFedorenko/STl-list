#include <iostream>
using namespace std;


template<class T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	
	void pop_front();
	//
	void push_front(T data); //Добавляет элемент в начало списка
	void insert(T data, int index); // Вставляет элемент по указаному индексу
	void removeAt(int index);//Удаляет элемент по указаному индексу
	void pop_back(); //удаляет элемент из конца списка
	//
	void clear();
	int getSize() { return Size; };
	T & operator[](const int count);

private:

	template<class T>
	class Node 
	{
	public:
		Node<T> *pNext;
		T data;

		Node(T data = T(), Node<T> *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;

};

template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<class T>
List<T>::~List()
{
	clear();
}


	

	


template<class T>
void List<T>::clear()
{
	int size = this->getSize();
	for (int i = 0; i < size; i++)
	{
		pop_front();
	}
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *temp = head;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data);
	}
	Size++;
}

template<class T>
void List<T>::push_front(T data)
{
	Node<T> *newNode = new Node<T>(data);
	Node<T> *temp = this->head;
	newNode->pNext = temp;
	this->head = newNode;
	this->Size++;
}

template<class T>
void List<T>::pop_front()
{
	Node<T> *temp = this->head->pNext;
	delete this->head;
	this->head = temp;
	Size--;
}

template<class T>
void List<T>::insert(T data, int index) //вставка элемента по указаному индексу
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data, temp->pNext);
		this->Size++;
	}
	
}

template<class T>
void List<T>::removeAt(int index)//Delete Elements
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *temp = this->head;
		for (int i = 0; i < index-1; i++)
		{
			temp = temp->pNext;
		}
		Node<T> * toDelete = temp->pNext;

		temp->pNext = toDelete->pNext;

		delete toDelete;
		this->Size--;
	}
}


template<class T>
void List<T>::pop_back()//удаляет элемент из конца списка
{
	if (this->head == nullptr)
	{
		cout << "Ваш список пуст!" << endl;
	}
	else
	{
		removeAt(this->getSize() - 1);
	}
}

template<class T>
T & List<T>::operator[](const int count)
{
	int counter = 0;
	Node<T> *temp = this->head;

	while (temp != nullptr)
	{
		if (counter == count)
		{
			return temp->data;
		}
		temp = temp->pNext;
		counter++;
	}
}





int main() 
{
	setlocale(LC_ALL, "ru");
	List<int> list;


	list.push_back(7);
	
	
	list.pop_back();
	
	for (int i = 0; i < list.getSize(); i++)
	{
		cout << list[i] << endl;
	}

}