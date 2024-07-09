// Write a program to implement Stack using top varying method.

#include <iostream>
#include <stdlib.h>
#include <curses.h> // use conio.h for windows

#define MAXSIZE 5
#define SUCCESS 1
#define FAILED 0
#define STACK_BASE -1

using namespace std;

template <class T, int max_size = MAXSIZE>
class Stack
{
private:
    T stack[max_size];
    int top;
    T item;

public:
    Stack()
    {
        top = STACK_BASE;
    }

    bool isEmpty()
    {
        if (top == STACK_BASE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == max_size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int push()
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
            return FAILED;
        }
        else
        {
            cout << "Enter the item to push: ";
            cin >> item;
            top++;
            stack[top] = item;
            return SUCCESS;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return FAILED;
        }
        else
        {
            item = stack[top];
            top--;
            cout << "Popped: " << item << endl;
            return SUCCESS;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

void menu()
{
    system("clear"); // for windows clear -> cls
    cout << "MAIN MENU" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose your choice: ";
}

int main()
{

    Stack<int> st;

    bool status = true;
    int choice;

    while (status)
    {
        menu();

        cin >> choice;
        
        switch (choice)
        {
        case 1:
            st.push();
            break;

        case 2:
            st.pop();
            getch();
            break;

        case 3:
            st.display();
            getch();
            break;

        case 4:
            status = false;
            break;

        default:
            break;
        }
    }

    return 0;
}