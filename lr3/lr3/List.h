#pragma once
#include<string>
class List 
{
private:
	struct Node
	{
		std::string field; // ���� ������
		Node* next=nullptr; // ��������� �� ��������� �������
		Node* prev=nullptr; // ��������� �� ���������� �������
	};
	Node* head = nullptr;
	void add(std::string value, Node* node);
public:
	List() {};
	~List() {};
	void add(std::string value);
	Node* find_node(std::string value);
	Node* search(std::string value);
	void del(std::string value);
	void show_list();
};