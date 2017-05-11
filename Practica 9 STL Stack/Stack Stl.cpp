#include <iostream>
#include <stack>
#include <queue>
#include "Stack Stl.h"



int main()
{

	std::stack<int> element1({ 1,2,3 });
	std::stack<int> element2({ 1,2,3, 4, 5});
	std::stack<char> charelement({ '(', ')' });

	std::stack<int> 	sm = superMerge(element1, element2);

	auto ph = putHat(element1, element2);
	auto ttq = transformToQ(element1);
	auto bp = balancedP(charelement);
	auto ih = isHat(element1, element2);




	return 0;
}


std::stack<int> superMerge(std::stack<int> el1, std::stack<int> el2)
{

	std::stack<int> merged;
	std::stack<int> orderedMerged;

	while (!el2.empty() || !el1.empty())
	{
		if (!el2.empty() && el1.top() <= el2.top())
		{
			merged.push(el2.top());
			el2.pop();
		}
		else
		{
			merged.push(el1.top());
			el1.pop();
		}
	}

	while (!merged.empty())
	{
		orderedMerged.push(merged.top());
		merged.pop();
	}

	return orderedMerged;
}


std::stack<int> putHat(std::stack<int> el1, std::stack<int> el2)
{
	
	std::stack<int> orderedel1;

	while (!el1.empty())
	{
		orderedel1.push(el1.top());
		el1.pop();
	}
	

	while (!orderedel1.empty())
	{
		
		el2.push(orderedel1.top());
		orderedel1.pop();
	}



	return el2;

}

std::queue<int> transformToQ(std::stack<int> el1)
{

	std::queue<int>result;

	while (!el1.empty())
	{
		result.push(el1.top());
		el1.pop();

	}

	return result;
}

bool balancedP(std::stack<char>el1)
{
	int right = 0;
	int left = 0;

	while (!el1.empty())
	{
		if (el1.top() == '(')
		{
			left++;
		}
		else
		{
			right++;
		}
		el1.pop();
	}
	
	return right == left;
}

bool isHat(std::stack<int>el1, std::stack<int>el2)
{
	int iguals = 0;

	while (!el1.empty())
	{
		if (el1.top() == el2.top())
		{
			iguals++;
			el1.pop();
			el2.pop();
		}

		else 
		{
			el1.pop();
			el2.pop();
		}
	}

	if (iguals == sizeof el1)
	{
		return true;
	}

	else
	{
		return false;
	}
}