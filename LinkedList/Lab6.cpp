#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class Stack
{
private:
    Node<T> *top;
    T item;

public:
    Stack()
    {
        top = NULL;
    }

    void push()
    {
        cout << "Enter a data to push: ";
        cin >> item;
        Node<T> *newNode = new Node<T>;
        newNode->data = item;

        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top != NULL)
        {
            Node<T> *temp = top;
            top = top->next;
            cout << "Popped: " << temp->data << endl;
            delete temp;
        }
        else
        {
            cout << "Stack is Empty" << endl;
        }
    }

    void print()
    {
        Node<int> *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void menu()
{
    cout << "------------------" << endl;
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

    do
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

            break;

        case 3:
            st.print();
            break;

        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}