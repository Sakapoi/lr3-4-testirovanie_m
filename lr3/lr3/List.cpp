#include "List.h"
#include <iostream>

List::Node* List::search(std::string value)
{
	Node* iterator = head;
	while (iterator != nullptr)
	{
		if (iterator->field == value)
			break;
		iterator = iterator->next;
	}
	return iterator;
}

List::Node* List::find_node(std::string value)
{
	
	Node* iterator = head;
	if (iterator==nullptr || iterator->field > value)
		return nullptr;
	while (iterator->next != nullptr)
	{
		if (iterator->next->field > value)
			break;
		iterator = iterator->next;
	}
	return iterator;
}



void List::add(std::string value, Node* node=nullptr)
{
	Node* tmp = new Node;
	tmp->field = value;
	if (node == nullptr || head==nullptr)
	{
		tmp->next = head;
		if (tmp->next != nullptr)
			tmp->next->prev = tmp;
		head = tmp;
		return;
	}
	
	tmp->next = node->next;
	tmp->prev = node;
	node->next = tmp;
}

void List::add(std::string value)
{
	add(value, find_node(value));
}

void List::show_list()
{
	Node* info;
	info = head;
	while (info)
	{
		std::cout << info->field << " ";
		info = info->next;
	}
	std::cout << "\n";
}

void List::del(std::string value)
{
	Node* tmp = search(value);
	if (tmp == nullptr)
		return;
	if (tmp == head)
		head = head->next;
	if(tmp->next!=nullptr)
		tmp->next->prev = tmp->prev;
	if (tmp->prev != nullptr)
		tmp->prev->next = tmp->next;
	delete tmp;
}