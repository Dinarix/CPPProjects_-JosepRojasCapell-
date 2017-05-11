#include <iostream>
#include <list>
#include "Activitat 10 List.h"


int main()
{
	std::list<int> element1({ 0,1,2 });
	std::list<int> element2({ 3,4,5 });
	std::list<int> element3({ 1,2,1,3 });
	std::list<int> element4({ 1,2,3,3,2,1 });

	superMerge(element1, element2);
	change(element1);
	getElementPos(element1, 1);
	removeElement(element1, 2);
	removeDuplicates(element3);
	palindrome(element4);



	return 0;
}

std::list<int> superMerge(std::list<int> el1, std::list<int> el2)
{
	std::list<int> ordenada;

	while (!el1.empty() || !el2.empty())
	{
		while (!el1.empty() && !el2.empty())
		{

			if (el1.front() < el2.front())
			{
				ordenada.push_front(el1.front());
				el1.pop_front();
			}

			else if (el2.front() < el1.front())
			{

				ordenada.push_front(el2.front());
				el2.pop_front();
			}
		}

		if (el1.empty())
		{
			ordenada.push_front(el2.front());
			el2.pop_front();
		}

		else
		{
			ordenada.push_front(el1.front());
			el1.pop_front();
		}
	}

	return ordenada;

}

std::list<int> change(std::list<int> el1)
{
	int first = el1.front();
	int last = el1.back();

	el1.front() = last;
	el1.back() = first;

	return el1;
}

int getElementPos(std::list<int> el1, int pos)
{
	int count = 0;
	
	if (pos > el1.size())
	{
		std::cout << "La llista no te prous elements";
	}

	else {


		while (count != pos)
		{
			el1.pop_front();
			count++;
		}
	}
	
	return el1.front();
}

std::list<int> removeDuplicates(std::list<int> el1)
{
	std::list<int>::iterator it, it1;
	it = el1.begin();

	for (int i = 0; i < el1.size(); i++)
	{
		it1 = el1.begin();
		for (int j = 0; j < el1.size(); j++)
		{
			if (*it == *it1 && i != j)
			{
				it1 = el1.erase(it1);
			}
			else
			{
				it1++;
			}
		}
		it++;
	}
	return el1;
}

std::list<int> removeElement(std::list<int> el1, int remove)
{
	std::list<int>::iterator it;

	for (it=el1.begin(); it != el1.end(); it++)
	{
		if (*it == remove)
		{
			el1.remove(*it);
			break;
		}
	}

	return el1;
}

bool palindrome(std::list<int> el1)
{
	while (el1.size() > 1)
	{
		if (el1.front() == el1.back())
		{
			el1.pop_front();
			el1.pop_back();
		}

		else
		{
			return false;
		}
	}

	return true;
}