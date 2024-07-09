// Write a program to implement postfix evaluation using stack.


#include <iostream>

using namespace std;

#define MAX_SIZE 20

class Postfix
{
public:
    char post[MAX_SIZE];
    float stack[MAX_SIZE];
    int top;
    float item;

    Postfix()
    {
        top = -1;
    }

    void push(float data)
    {
       
            top++;
            stack[top] = data;
    }

    float pop()
    {

        item = stack[top];
        top--;
        return item;
    }
};

int main()
{
    Postfix p;
    cout << "Enter the postfix string: ";
    cin >> p.post;
    float first_op, second_op;
    float result;

    for (int i = 0; p.post[i] != '\0'; i++)
    {

        switch (p.post[i])
        {

        case '+':
            second_op = p.pop();
            first_op = p.pop();
            result = first_op + second_op;
            p.push(result);
            break;

        case '-':
            second_op = p.pop();
            first_op = p.pop();
            result = first_op - second_op;
            p.push(result);
            break;

        case '/':
            second_op = p.pop();
            first_op = p.pop();
            result = first_op / second_op;
            p.push(result);
            break;

        case '*':
            second_op = p.pop();
            first_op = p.pop();
            result = first_op * second_op;
            p.push(result);     
            break;

        default:
            p.push(p.post[i] - '0');
            break;
        }
    }

    cout << "Result: " << p.stack[p.top] << endl;
}
