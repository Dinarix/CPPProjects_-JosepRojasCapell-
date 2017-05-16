#pragma once

class MyList
{

private:

	struct node
	{
		int info;

		node*next;
		node*previous;
	};

	node*last;
	node*first;

public:

	//constructor

	MyList();

	//Destructor

	~MyList();

	//Funcions

	void push_back();

	void pop_front();

	void pop_back();

	int front();
	
	int back();

	int size();

	


};