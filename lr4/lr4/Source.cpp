#include<iostream>
#include"List.h"
#include"stack.h"
#include"Queue.h"

#include <chrono>
#include <ctime>
#include <vector>


int main()
{
	std::vector <std::string> words = { "Getmanoid", "a", "i", "j", "m", "n", "s", "st" };
	std::vector <double> add;
	std::vector <double> del;
	std::vector <double> search;
	int a, b, c;
	for (int i = 0; i < 100; i++)
	{
		Queue q1;
		srand(time(NULL));
		a = rand() % (words.size() - 2) + 1;

		for (int i = 0; i < a; i++)
		{
			q1.push(words[i]);
		}
		
		auto start = std::chrono::high_resolution_clock::now();
		q1.push(words[a + 1]);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> fp_ms = end - start;
		
		add.push_back(fp_ms.count());

		c = rand() % (a);
		start = std::chrono::high_resolution_clock::now();
		q1.remove(words[c]);
		end = std::chrono::high_resolution_clock::now();
		fp_ms = end - start;
		
		del.push_back(fp_ms.count());

		b = rand() % (a);
		start = std::chrono::high_resolution_clock::now();
		q1.find(words[b]);
		end = std::chrono::high_resolution_clock::now();
		fp_ms = end - start;
		
		search.push_back(fp_ms.count());
	}
	std::vector <double> add1;
	std::vector <double> del1;
	std::vector <double> search1;


	for (int i = 0; i < 100; i++)
	{
		Stack s1;
		for (int i = 0; i < a; i++)
		{
			s1.add(words[i]);
		}
		

		auto start = std::chrono::high_resolution_clock::now();
		s1.add(words[a + 1]);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> fp_ms = end - start;
		
		add1.push_back(fp_ms.count());

		start = std::chrono::high_resolution_clock::now();
		s1.del();
		end = std::chrono::high_resolution_clock::now();
		fp_ms = end - start;
		
		del1.push_back(fp_ms.count());


		start = std::chrono::high_resolution_clock::now();
		s1.search(words[b]);
		end = std::chrono::high_resolution_clock::now();
		fp_ms = end - start;
		
		search1.push_back(fp_ms.count());
	}
	double S_add = 0;
	double R_add = 0;
	double S_del = 0;
	double R_del = 0;
	double S_search = 0;
	double R_search = 0;

	for (int i = 0; i < 100; i++)
	{
		S_add += (add1[i] - add[i]) / std::max(add1[i], add[i]);
		S_del += (del1[i] - del[i]) / std::max(del1[i], del[i]);
		S_search += (search1[i] - search[i]) / std::max(search1[i], search[i]);

		R_add += ((add1[i] - add[i]) > 0) ? 1 : 0;
		R_del += ((del1[i] - del[i]) > 0) ? 1 : 0;
		R_search += ((search1[i] - search[i]) > 0) ? 1 : 0;
	}

	std::cout << "S add = " << S_add << std::endl;
	std::cout << "R add = " << R_add << std::endl;
	std::cout << "S del = " << S_del << std::endl;
	std::cout << "R del = " << R_del << std::endl;
	std::cout << "S search = " << S_search << std::endl;
	std::cout << "R search = " << R_search << std::endl;

	std::cout << std::endl;

	return 0;
}