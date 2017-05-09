#include <iostream>
#include "Activitat 10 MyStack.h"

 MyStack::MyStack()
{

 }

 MyStack::MyStack(MyStack &ms)
 {

 }

 MyStack:: MyStack(int number, int element)
 {

 }

 MyStack::~MyStack()
{

}

void MyStack::pop()
{
	node*t = s;
	s = s->next;
	delete t;
}

void MyStack::push(int element)
{
	s = new node{ element, s };
}

void MyStack::top()
{

}

void MyStack::size()
{

}

bool MyStack::isEmpty()
{

}