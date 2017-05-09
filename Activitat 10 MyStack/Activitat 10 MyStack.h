#pragma once

class MyStack
{
private:

	struct node
	{
		int info;
		node *next;
	};

	node *s;

	MyStack::~MyStack();

public:

	 MyStack();

	 MyStack(MyStack &ms);

	 MyStack(int number, int element);


	void pop();

	void push(int element);

	void top();

	void size();

	bool isEmpty();


};