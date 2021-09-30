#include "LinkList.h"
#include "Log.h"
#include <iostream>
#define NULL 0
#define Cout std::cout
#define Cin  std::cin

Passenger::Passenger(int pos)
{
    this->setPos(pos);
}

LinkList::LinkList()
{
    m_head = new Passenger;
    m_head->m_next = m_head;//a single circle linked list
}

void LinkList::makeEmpty()
{
    Passenger* current = NULL;
    while (m_head->m_next != m_head) {
        current = m_head->m_next;
        m_head->m_next = current->m_next;
        delete current;
    }
}

int LinkList::Length() const
{
    Passenger* current = m_head->m_next;
    int count = 0;
    while (current != m_head) {
        count++;
        current = current->m_next;
    }
    return count;
}

void LinkList::initList(int number)
{
    Passenger* last = m_head;
    for (int i = 0; i < number; i++)
    {
        Passenger* newNode = new Passenger(i+1);
        last->m_next = newNode;
        last = newNode;
        last->m_next = m_head;
    }
}

void LinkList::Output()
{
    Passenger* current = m_head->m_next;
    if (NULL == current) {
        Log::Warn("The list in the Output function is empty!");
    }

    while (current != m_head)
    {
        Cout << current->m_pos;
        current = current->m_next;
    }
}

Passenger* LinkList::Locate(int i)
{
    if (i < 0) {
        Log::Warn("i is too small in Locate function!");
        return NULL;
    }
    else if (i == 0) {
        return m_head;
    }
    else if (i > this->Length()) {
        Log::Warn("i is too big in Locate function!");
        return NULL;
    }

    Passenger* current = m_head->m_next;
    int count = 1;
    while (current != m_head && count < i) {
        count++;
        current = current->m_next;
    }
    return current;
}

bool LinkList::Remove( Passenger* target, Passenger& x)
{

    Passenger* former = m_head->m_next;
    if (target == NULL || former == NULL) {
        Log::Error("the target and its former is empty in remove function!");
    }

    if (former == target) {//you delete the first object
        m_head->m_next = former->m_next;
        x.m_pos = former->m_pos;;
        //x = former->next 
        //wtf, there is a totally new object created here and it call the construction, so you can use a integer to assign a Passenger object
        delete target;
        return true;
    }

    while ((former->m_next != target) && former != m_head)
    {
        former = former->m_next;
    }
    auto target_temp = former->m_next;

    if (NULL == target_temp || NULL == former) {
        Log::Error("target and its former are NULL in Remove function!");
        return false;
    }
    former->m_next = target_temp->m_next;
    x.m_pos = target_temp->m_pos;
    delete target_temp;

    return true;
}
