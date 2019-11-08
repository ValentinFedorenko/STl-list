#include <iostream>
using namespace std;


template<class T>
class List
{
public:
	List();
	~List();

	void push_back(T data); //Добавляет элемент в конец списка
	void push_front(T data); //Добавляет элемент в начало списка
	void pop_front(); //Удаляет элемент из начала списка
	void pop_back(); //удаляет элемент из конца списка
	void insert(T data, int index); // Вставляет элемент по указаному индексу
	void removeAt(int index);//Удаляет элемент по указаному индексу
	void clear(); //Очищает весь список 
	int getSize() { return Size; }; //Возвращает колличество элементов
	T & operator[](const int count); //Перегруженый оператор квадратных скобок

private:
	template<class T>
	class Node //Встроенный класс 
	{
	public:
		Node<T> *pNext; //Указатель на следующий элемент
		T data; //Данные одного узла

		Node(T data = T(), Node<T> *pNext = nullptr)//Конструктор с параметрами по умолчанию
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;//Колличество нод в списке
	Node<T> *head;//Указатель на первый элемент, что-бы была возможность идти по массиву

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
	clear();//После выхода из зоны видимости деструктор уничтожает все данные, что-бы не было утечки
}


	

	


template<class T>
void List<T>::clear()
{
	int size = this->getSize();//Узнаем колличество всех элементов и начиная с первого очищаем весь массив 
	for (int i = 0; i < size; i++)
	{
		pop_front();
	}
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)//Проверяем есть ли в нашем массиве первый элемент
	{
		head = new Node<T>(data);//Если нету создаем первый элемент
	}
	else
	{
		Node<T> *temp = head;//Временная переменная для передвижения по списку
		while (temp->pNext != nullptr)//Находим последний элемент
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data);//Создаем новый элемент в конце
	}
	Size++;//Увеличиваем колличество нод в списке
}

template<class T>
void List<T>::push_front(T data)
{
	Node<T> *newNode = new Node<T>(data);//Создаем новый объект
	Node<T> *temp = this->head;//Сохраняем данные из хеда в объект темп
	newNode->pNext = temp;//В указатель на следующий элемент указываем наш бывший первый элемент
	this->head = newNode;//Записываем в первый элемент наш новый объект
	this->Size++;//Увеличиваем колличество нод
}

template<class T>
void List<T>::pop_front()//Удаляет элемент из начала списка
{
	Node<T> *temp = this->head->pNext;//Временный объект в который сохранился указатель на следующий элемент
	delete this->head;//Удаляем указатель на первый элемент 
	this->head = temp;//Записываем в хед следующий элемент
	Size--;//Уменьшаем количество элементов списка
}

template<class T>
void List<T>::insert(T data, int index) //вставка элемента по указаному индексу
{
	if (index == 0)//Если вставляем в начало, тогда вызываем метод push_front
	{
		push_front(data);
	}
	else
	{
		Node<T> *temp = head;//Временная переменная для передвижения по списку
		for (int i = 0; i < index - 1; i++)//Находим предыдущий элемент 
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data, temp->pNext);//Создаем новую ноду с указателем на следующий элемент, и перезаписываем прошлый указатель
		this->Size++;//Увеличиваем количество
	}
	
}

template<class T>
void List<T>::removeAt(int index)//Удаляем элемент по указаному индексу
{
	if (index == 0)//если удаляем первый элемент то вызываем метод pop_front
	{
		pop_front();
	}
	else
	{
		Node<T> *temp = this->head;//Временная переменная для передвижения по списку
		for (int i = 0; i < index-1; i++)//Находим предыдущий элемент 
		{
			temp = temp->pNext;
		}
		Node<T> * toDelete = temp->pNext;//Создаем новую ноду и присваиваем ей указатель на следующий элемент

		temp->pNext = toDelete->pNext;//В указатель присваиваем указатель следующего элемента

		delete toDelete;//Удаляем указатель, что бы не было утечки 
		this->Size--;//Уменьшаем количество элементов списка
	}
}


template<class T>
void List<T>::pop_back()//удаляет элемент из конца списка
{
	if (this->head == nullptr)//проверяем есть ли вообще элементы в списке
	{
		cout << "Ваш список пуст!" << endl;
	}
	else
	{
		removeAt(this->getSize() - 1);//Удаляем последний элемент
	}
}

template<class T>
T & List<T>::operator[](const int count)
{
	int counter = 0;
	Node<T> *temp = this->head;

	while (temp != nullptr)//Проверяем на конец списка
	{
		if (counter == count)//Если наш индекс сходиться с указаным в скобках числом тогда возвращаем данные
		{
			return temp->data;
		}
		temp = temp->pNext;//Переходим на следующую ноду
		counter++;
	}
}





int main() 
{
	setlocale(LC_ALL, "ru");
	List<int> list;

	//название методов такое же как в оригинале билиотеки STL

}