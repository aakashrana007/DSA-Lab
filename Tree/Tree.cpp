#include <iostream>

#define INSERT 1
#define PREORDER 2
#define INORDER 3
#define POSTORDER 4
#define _EXIT 5

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        data = key;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node *insertRecursive(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }

        if (key <= node->data)
        {
            node->left = insertRecursive(node->left, key);
        }
        else
        {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    void preorderRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        else
        {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void inorderRecursive(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void postorderRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        else
        {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int key)
    {
        root = insertRecursive(root, key);
    }

    void preorder()
    {
        preorderRecursive(root);
    }

    void inorder()
    {
        inorderRecursive(root);
    }

    void postorder()
    {
        postorderRecursive(root);
    }
};

void menu()
{
    cout << "Main Menu: " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Preorder" << endl;
    cout << "3. Inorder" << endl;
    cout << "4. Postorder" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter the choice: ";
}

int main()
{
    BST tree;
    int data;
    int status = true;
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case INSERT:
            cout << "Enter a data to enter: ";
            cin >> data;
            tree.insert(data);
            break;
        case PREORDER:
            tree.preorder();
            break;
        case INORDER:
            tree.inorder();
            break;
        case POSTORDER:
            tree.postorder();
            break;
        case _EXIT:
            status = false;
            break;
        default:
            break;
        }

        cout << endl << endl;
    }while(status);
}