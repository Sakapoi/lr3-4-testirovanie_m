#pragma once
#include<string>
class Stack
{
private:
	struct Node
	{
		std::string item;
		Node * next;
	};
	Node* top=nullptr; // ��������� �� ������� �����

public:
	Stack() {};
	~Stack() {};
	void add(std::string value);
	bool search(std::string value);
	void del();
	void show_stack();
};


