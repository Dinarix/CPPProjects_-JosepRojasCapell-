#include <iostream>
#include<queue>
#include <vector>
#include <deque>
#include <algorithm>

#include "Practica 8 Deque Queue.h"


int main()
{
	//1

	//1.1
	std::deque<float> prices(10, 10.50);
	//1.2
	prices[9] = 32.43;
	//1.3
	prices.pop_front();
	//1.4
	std::deque<float>pricesCopy(prices);
	//1.5
	pricesCopy.push_front(5.64);
	pricesCopy.push_front(20.3);
	//1.6
	pricesCopy.insert(pricesCopy.begin() + 1, 10.0);
	//1.7
	for (auto it=prices.rbegin(); it != prices.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	//1.8
	for (auto it = pricesCopy.begin(); it != pricesCopy.end(); ++it)
	{
		std::cout << *it << std::endl;
	}



	//2

	//2.1
	std::vector<float>pricesVector(10, 10.5);
	//2.2
	pricesVector[9] = 32.43;
	//2.3
	pricesVector.erase(pricesVector.begin());
	//2.4
	std::vector<float>pricesVector_copy(pricesVector);
	//2.5
	pricesVector_copy.insert(pricesVector_copy.begin(), 5.64);
	pricesVector_copy.insert(pricesVector_copy.begin(), 20.3);
	//2.6
	pricesVector_copy.insert(pricesVector_copy.begin() + 1, 10.0);
	//2.7
	for (auto it = pricesVector.rbegin(); it != pricesVector.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	//2.8
	for (auto it = pricesVector_copy.begin(); it != pricesVector_copy.end(); ++it)
	{
		std::cout << *it << std::endl;
	}


	//3

	std::priority_queue<int>queue(3,3);
	std::priority_queue<int>queue(4, 4);


	std::priority_queue<int> superMergedP(std::priority_queue<int> queue1, std::priority_queue<int> queue2)
	{
		std::priority_queue<int> Merged(queue1);

		while(!Merged)
		

		
	}





	
	return 0;


}