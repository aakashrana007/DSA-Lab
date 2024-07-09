// Write a program to implement Stack using bottom varying method.

#include <ncurses.h>
#include <iostream>

#define MAX_SIZE 5
#define FAILED 0
#define SUCCESS 1

using namespace std;

template <class T, int max_size = MAX_SIZE>
class Stack
{
private:
    int Bos;
    T item;
    T stack[max_size];

public:
    Stack()
    {
        Bos = 0;
    }

    bool isEmpty()
    {
        if (Bos == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (Bos == max_size)
            return true;
        return false;
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
            cout << "Enter the data to push: ";
            cin >> item;

            for (int i = Bos; i > 0; i--)
            {
                stack[i] = stack[i - 1];
            }
            stack[0] = item;
            Bos++;
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
            item = stack[0];
            cout << "Popped: " << item << endl;
            Bos--;

            for (int i = 0; i < Bos; i++)
            {
                stack[i] = stack[i + 1];
            }

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
            cout << "Stack Content: " << endl;
            for (int i = Bos-1; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

void menu()
{
    // system("clear"); // for windows clear -> cls

    cout << endl << "-----------------------------------------------------------" << endl;
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
    system("clear");
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
