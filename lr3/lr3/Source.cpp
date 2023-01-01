#include<iostream>
#include"List.h"
#include"stack.h"
#include"Queue.h"


int main()
{
	Stack s1;
	s1.add("Getmanoid");
	s1.add("a");
	s1.add("i");
	s1.add("j");
	s1.add("m");
	s1.add("n");
	s1.add("s");
	s1.add("st");

	s1.show_stack();

	std::cout << s1.search("a") << std::endl;
	std::cout << s1.search("j") << std::endl;
	std::cout << s1.search("n") << std::endl;
	std::cout << s1.search("s") << std::endl;

	s1.del();
	s1.show_stack();


	Queue q1;
	q1.push("Getmanoid");
	q1.push("a");
	q1.push("i");
	q1.push("j");
	q1.push("m");
	q1.push("n");
	q1.push("s");
	q1.push("st");

	q1.show();


	std::cout << "find: " << q1.find("a")->data << std::endl;
	std::cout << "find: " << q1.find("j")->data << std::endl;
	std::cout << "find: " << q1.find("n")->data << std::endl;
	std::cout << "find: " << q1.find("s")->data << std::endl;

	q1.pop();
	q1.show();



	List l1;
	l1.add("Getmanoid");
	l1.add("a");
	l1.add("i");
	l1.add("j");
	l1.add("m");
	l1.add("n");
	l1.add("s");
	l1.add("st");

	l1.show_list();

	std::cout << l1.search("a") << std::endl;
	std::cout << l1.search("j") << std::endl;
	std::cout << l1.search("n") << std::endl;
	std::cout << l1.search("s") << std::endl;

	l1.del("a");
	l1.show_list();

	return 0;
}
