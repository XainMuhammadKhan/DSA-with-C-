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

    return node; 
}




void postOrder(BSTNode* node1, BSTNode* node2) {
    if (node1 != nullptr && node2 != nullptr) {
        postOrder(node1->Left, node2->Left);
        postOrder(node1->Right,node1->Right);
        cout << node1->data << " " << node2->data << " "<< endl;
            }
}

void preOrder(BSTNode* node1, BSTNode* node2) {
    if (node1 != nullptr && node2 != nullptr) {
        preOrder(node1->Left, node2->Left);
        preOrder(node1->Right,node1->Right);
        cout << node1->data << " " << node2->data << " "<< endl;
    }
}

void EqualityCheck(BSTNode *node1, BSTNode *node2,int itrRange){
    if (node1 != nullptr && node2 != nullptr) {
        if (node1->Left == node2->Left && node1->Right == node2->Right)
        {   postOrder(node1->Left, node2->Left);
            postOrder(node1->Right,node1->Right);
            cout << node1->Left << endl;
            cout << node2->Left << endl;
            cout << node1->Right << endl;
            cout << node2->Right << endl;
            cout<<"Left nodes of both trees are equal so are the right nodes. Hence the BST's are equal." << endl;

        }
        else if (node1->Left != node2->Left && node1->Right != node2->Right){
            postOrder(node1->Left, node2->Left);
            postOrder(node1->Right,node1->Right);
            cout << node1->Left << endl;
            cout << node2->Left << endl;
            cout << node1->Right << endl;
            cout << node2->Right << endl;
            cout<<"Left nodes of both trees are not so are the right nodes. Hence the BST's aren't equal." << endl;
        }
        
        
        
    }
}

void structur(BSTNode*node1, BSTNode*node2){
    if (node1==node2) {
        cout<<"Equal structure"
    }
    
}






int main()
{   int n1,n2,i;
cout << "Enter the iteration" << endl;
cin>>i;

    BSTNode *node1 = NULL;
    BSTNode *node2 = NULL;
    for (i; i < 8; i++)
    {
        cout << "Enter the root value: ";
        cin >> n1;
        node1 = insert(node1, n1);
        cout << "Enter the root value: ";
        cin >> n2;
        node2 = insert(node2, n2);
    }
    
    EqualityCheck(node1, node2,i);
    
    cout << "Postorder traversal: ";
    postOrder(node1, node2);
    cout << endl;
    cout << "Preorder traversal: ";
    preOrder(node1, node2);
    cout << endl;

    structur(node1,node2)

    
    return 0;
}