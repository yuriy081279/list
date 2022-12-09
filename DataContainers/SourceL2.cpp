using namespace std;
#include<iostream>
#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	Element* pHM;
	
public:
	Element(int Data, Element* pNext = nullptr, Element* pHM = nullptr) :Data(Data), pNext(pNext), pHM(pHM)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{		
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;	
};

class List
{
	Element* Head;
	Element* Tail;
	unsigned int size;

public:
	List() :Head(nullptr), Tail(nullptr), size(0)
	{
		cout << "Lconstructor:\t" << this << endl;
	}
	List(const List& other) :List()
	{		
		*this = other;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~List()
	{		
		cout << "Ldesstructor:\t" << this << endl;
	}
	void push_front(int Data)
	{
		Head = new Element(Data, Head, Tail);
		
		size++;
	}

	void printT()const
	{
		Element* Temp = Head;
		Element* Back = Tail;
		
		cout << "Head:\t" << Head << endl;
		cout << "Tail:\t" << Tail << endl;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
			/*cout << Back << tab << Back->Data << tab << Back->pHM << endl;
			Back = Back->pHM;*/
		}
		while (Back)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
			/*cout << Back << tab << Back->Data << tab << Back->pHM << endl;
			Back = Back->pHM;*/
		}
		cout << "Количество элементов списка:\t  " << size << endl;		
	}
	
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	list.printT();
	list.push_front(10);
	list.printT();
	
}
