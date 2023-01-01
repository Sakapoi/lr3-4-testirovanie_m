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
        Node* temp = Head;                  //��������� ��������� �� ������ ������
        while (temp != nullptr)               //���� � ������ ���-�� �����������
        {
            std::cout << temp->data << " ";        //������� �������� �� ������ �� �����
            temp = temp->next;             //�������� ��������� �� ������ �� ����� ���������� ��������
        }
        std::cout << std::endl;

    }
};
