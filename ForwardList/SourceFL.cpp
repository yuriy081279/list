#include<iostream>
using namespace std;
#define tab "\t"
#define BASE_CHECK
//#define COUNT_CHECK

class Element
{
	int Data;
	Element* pNext;
	static unsigned int count;
	

public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class Forwardlist;
	friend Forwardlist operator+(const Forwardlist& left, const Forwardlist& right);
};

unsigned int Element::count = 0;

class Forwardlist
{
	Element* Head;
	unsigned int size;

public:
	Forwardlist() :Head(nullptr)
	{
		cout << "Lconstructor:\t" << this << endl;
	}
	Forwardlist(const Forwardlist& other):Forwardlist()
	{
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
			cout << "CopyConstructor:\t" << endl;
		}*/
		*this = other;
		cout << "CopyConstructor:\t" <<this<< endl;
	}
	~Forwardlist()
	{
		while (Head)pop_front();
		cout << "Ldesstructor:\t" << this << endl;
	}
	Forwardlist& operator=(const Forwardlist& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_front(Temp->Data);
			revers();
			cout << "CopyAssignment:\t" << endl;
		}
		return *this;
	}
	Forwardlist& operator=(Forwardlist&& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		this->Head = other.Head;
		this->size = other.size;
		other.Head=nullptr;
		other.size=0;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	void push_front(int Data)
	{
		//Element* New = new Element(Data);
		//New->pNext = Head;
		//Head = New;
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
		size++;
		
	}

	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head ->pNext==nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
		
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)return push_front(Data);

		if (Index > size)
		{
			cout << "Error: Out of range" << endl;
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext)
			{
				Temp = Temp->pNext;
			}
			//Temp = Temp->pNext->pNext;
			//Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	void erase(int Index)
	{
		if (Index > size)pop_front();
		if (Index == size)pop_back();
		if (Index > size)
		{
			cout << "Error: Out of range" << endl;
			return;
		}
		Element* Temp = Head;		
		for (int i = 0; i < Index-2; i++)
		{				  
			if (Temp->pNext)
			{					  				  
				Temp = Temp->pNext;				  
			}			  
		}			
		Element* erased = Temp->pNext;			
		Temp->pNext = Temp->pNext->pNext;	
		delete erased;		
		size--;
	}
	void revers()
	{
		Forwardlist revers;
				
		
			while (Head)
			{
				revers.push_front(Head->Data);
				pop_front();
			}
			this->Head = revers.Head;
			this->size = revers.size;
			revers.Head = nullptr;
			
	}
			
			
		
	
		
	
	void print()const
	{
		Element* Temp = Head;
		cout << "Head:\t" << Head << endl;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Количество элементов списка:\t  " << size << endl;
		cout << "Общее количество элементов списка:" << Element::count << endl;
	}
	friend Forwardlist operator+(const Forwardlist& left, const Forwardlist& right);
};

Forwardlist operator+(const Forwardlist& left, const Forwardlist& right)
{
	Forwardlist cat = left;
	for(Element* Temp=right.Head; Temp; Temp = Temp->pNext)
	{
		cat.push_back(Temp->Data);		
	}
	return cat;
}
void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK 
	int n;
	cout << "Введите размер списка: "; cin >> n;
	Forwardlist list;
	
	list.push_back(1024);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	//list.push_front(123);
	//list.print();
	//list.pop_back();
	int index;
	/*int value;
	list.print();
	cout << "Введите индекс элемента"; cin >> index;
	cout << "Введите значение элемента"; cin >> value;
	list.insert(index, value);
	list.print();*/
	cout << "Введите индекс удаляемого элемента"; cin >> index;
	list.erase(index);
	list.print();
	//list.revers();
	//list.print();
#endif // BASE CHECK 

#ifdef COUNT_CHECK
	Forwardlist list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	Forwardlist list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);

	list1.print();
	list2.print();

	Forwardlist list3;
	list3 = list1 + list2;
	list3.print();
#endif // COUNT_CHECK

}