#include <iostream>

#define SUCCESS 1
#define FAILED 0

using namespace std;

template <class T, int max_size = 5>
class Queue
{
private:
    int front, rear;
    T item;
    T queue[max_size];

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isFull()
    {
        if (front == (rear + 1) % max_size)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }
    int enqueue()
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return FAILED;
        }
        else
        {
            if (front == -1)
            {
                rear = 0;
                front = 0;
            }
            else
            {
                rear = (rear + 1) % max_size;
            }
            cout << "Enter the data to enqueue: ";
            cin >> item;
            queue[rear] = item;
            return SUCCESS;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return FAILED;
        }
        else
        {
            item = queue[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % max_size;
            }
            cout << "Dequeued: " << item << endl;
            return SUCCESS;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            if (front > rear)
            {
                for (int i = front; i < max_size; i++)
                {
                    cout << queue[i] << " ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << queue[i] << " ";
                }
            }
            else
            {
                for(int i = front; i <= rear; i++){
                    cout << queue[i] << " ";
                }
            }
            cout << endl;
        }
    }
};

void menu()
{
    cout << "-------------------------------------" << endl;
    cout << "Main Menu: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose your choice: ";
}

int main()
{
    Queue<int, 6> q;
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (choice != 4);
}