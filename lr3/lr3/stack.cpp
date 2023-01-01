#include"stack.h"
#include<iostream>
#define stas std

void Stack::add(std::string value)
{
    Node* p=new Node;

    
    p->item = value;
    p->next = top; // p указывает на 1-й элемент

    top = p;
}

bool Stack::search(std::string value)
{
    Node* iterator = top;
    while (iterator != nullptr)
    {
        if (iterator->item == value)
            break;
        iterator = iterator->next;
    }
    return iterator!=nullptr;
}
void Stack::del()
{
    if (top == nullptr)
        return;

    Node* p2; // дополнительный указатель
    std::string item;
    item = top->item;

    p2 = top;
    top = top->next;

    // Освободить память, выделенную под 1-й элемент
    delete p2;
}

void Stack::show_stack()
{
    if (top == nullptr)
        std::cout << "stack is empty." << std::endl;
    else
    {
        Node* p; // дополнительный указатель
        p = top;
        while (p != nullptr)
        {
            stas::cout << p->item << " ";
            p = p->next;
        }
        std::cout << stas::endl;
    }
}