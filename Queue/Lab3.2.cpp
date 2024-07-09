// Queue Implementation using array

// 2. Head fixed & Tail Vary

#include <iostream>

#define FAILED 0
#define SUCCESS 1

using namespace std;

template <class T, int max_size = 5>
class Queue
{
private:
    T queue[max_size];
    T item;
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    int enqueue()
    {
        if (rear == max_size - 1)
        {
            cout << "QUEUE is FULL" << endl;
            return FAILED;
        }
        else
        {
            cout << "Enter the data to enqueue: ";
            cin >> item;
            rear++;
            queue[rear] = item;
            return SUCCESS;
        }
    }

    int dequeue()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return FAILED;
        }
        else
        {
            item = queue[front];
            cout << "Dequeued: " << item << endl;

            for (int i = 0; i < rear; i++)
            {
                queue[i] = queue[i + 1];
            }

            rear--;
            return SUCCESS;
        }
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
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