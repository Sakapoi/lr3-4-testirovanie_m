#pragma once
#include <iostream>
#include <string>

struct Node
{
    std::string data;
    Node* next = nullptr;
};

class Queue
{
private:
    Node* Head = nullptr;
    Node* Tail = nullptr;
public:
    Queue() {};
    ~Queue();
    void push(std::string val);
    std::string pop();
    Node* find(std::string val);
    void remove(std::string a);
    void show()
    {
        Node* temp = Head;                  //Временный указатель на начало списка
        while (temp != nullptr)               //Пока в списке что-то встречается
        {
            std::cout << temp->data << " ";        //Выводим значения из списка на экран
            temp = temp->next;             //Сдвигаем указатель на начало на адрес следующего элемента
        }
        std::cout << std::endl;

    }
};
