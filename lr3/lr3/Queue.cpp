#include "Queue.h"

Queue::~Queue()
{
    Node* temp = Head;
    while (temp != nullptr)
    {
        temp = Head->next;
        delete Head;
        Head = temp;
    }
}

void Queue::push(std::string val)//добавление
{
    Node* temp = new Node;
    temp->data = val;

    if (Head != nullptr)
    {
        Tail->next = temp;
        Tail = temp;
    }
    else
    {
        Head = Tail = temp;
    }
}

std::string Queue::pop()//удаление
{
    std::string data = "";
    if (Head != nullptr)
    {
        Node* temp = Head;
        data = Head->data;
        Head = Head->next;
        delete temp;
    }
    else
    {
        throw "Try to pop from an empty queue";
    }
    return data;
}

void Queue::remove(std::string a)//удаление
{
    Node* temp = Head;
    if (Head->data == a)
    {
        pop();
        return;
    }
    while (temp != nullptr && temp->next!=nullptr)
    {
        if (temp->next->data == a)
        {
            Node* temp_next = temp->next;
            temp->next = temp_next->next;
            delete temp_next;
            return;
        }
            temp = temp->next;
    }
}

Node* Queue::find(std::string val)//поиск
{
    Node* temp = Head;
    while (temp != nullptr)
    {
        if (temp->data == val)
            return temp;
        else
            temp = temp->next;
    }
    return nullptr;
}
