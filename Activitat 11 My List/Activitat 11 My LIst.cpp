#include <iostream>
#include <list>
#include "Activitat 11 My List.h"
// BernatRiuPuyal

//Constructor

MyList::MyList()
{
	first= nullptr;
	last= nullptr;	
}

//Destructor

MyList::~MyList()
{

	for (auto it = first; it!=last; it++)
	{
		delete it;
	}
}



//Funcions

void MyList::push_back()
{

}

void MyList::pop_front()
{

}

void MyList::pop_back()
{
	for (auto it = first; it != last; it++)
	{
		if (it == last - 1)
		{
			delete it;
		}
	}
}

int  MyList::front()
{
	return(int)first;
}

int MyList::back()
{
	return (int)last;
}

int MyList::size()
{
	int size = 0;

	for (auto it = first; it != last; it++)
	{
		size++;
	}

	return size;
}