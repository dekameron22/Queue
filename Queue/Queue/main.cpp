//
//  main.cpp
//  Queue
//
//  Created by Артем Ткачук on 17.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    class Node
    {
    private:
        T m_value;
        Node *next;
    public:
        Node () : next(nullptr){};
        
        void setValue (T value)
        {
            m_value = value;
        }
        
        T getValue ()
        {
            return m_value;
        }
    };
    
    Node *element;
    Node *head;
    
public:
    Stack() : head(nullptr){};
    ~Stack()
    {
        head = nullptr;
    };
    
    bool isEmpty()
    {
        if (head==nullptr)
        {
            return true;
        }
        return false;
    }
    
    void push_element(T element_to_push)
    {
        if (head == nullptr)
        {
            head->setValue(element_to_push);
            element = head->next;
        }
        element->setValue(element_to_push);
        element = element->next;
    }
    
    void pop()
    {
        delete element;
        Node *p_to_find_last_element = head;
        while (p_to_find_last_element->next)
        {
            ++p_to_find_last_element;
        }
        element = p_to_find_last_element;
    }
    
    T getElementFromStack()
    {
        return *element;
    }
};

template <class T>
class Queue
{
private:
    Stack<T> stack_for_push;
    Stack<T> stack_for_pop;
    
public:
    Queue();
    ~Queue();
    
    void push(T value)
    {
        stack_for_push.push_element(value);
    }
    
    void pop()
    {
        if (stack_for_pop.isEmpty())
        {
            while (!stack_for_push.isEmpty())
            {
                stack_for_pop.push_element(stack_for_push.getElementFromStack);
                stack_for_push.pop();
            }
        }
    }
    
    T getMinimum()
    {
        
    }
};

int main(int argc, const char * argv[])
{

    return 0;
}







































