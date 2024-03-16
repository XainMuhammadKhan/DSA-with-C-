#include <iostream>
#include <cstdlib>
using namespace std;

struct BSTNode
{
    int data;
    struct BSTNode *Right;
    struct BSTNode *Left;
};

struct BSTNode *insert(BSTNode *node, int value)
{
    if (node == NULL)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->data = value;
        newNode->Left = newNode->Right = NULL;
        return newNode;
    }

    if (value < node->data)
    {
        node->Left = insert(node->Left, value);
    }
    else
    {
        node->Right = insert(node->Right, value);
    }

    return node; // Return the modified node
}

void Search(BSTNode *node, int value)
{
    if (node == NULL)
    {
        cout << "Tree is empty. Cannot search." << endl;
        return;
    }

    if (value == node->data)
    {
        cout << "Value found in the tree." << endl;
        return;
    }

    if (value < node->data)
    {
        Search(node->Left, value);
    }
    else
    {
        Search(node->Right, value);
    }
}

int main()
{
    BSTNode *Root = NULL;
    Root = insert(Root, 10);
    Root = insert(Root, 5);
    Root = insert(Root, 15);
    Root = insert(Root, 3);
    Root = insert(Root, 7);

    int value;
    cout << "Enter a number to be searched in the tree: ";
    cin >> value;
    Search(Root, value);

    return 0;
}