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

BSTNode* deleteBST(BSTNode* root, int toDel) {
    if (root == nullptr) {
        cout << "Value not found in the tree" << endl;
        return root;
    }

    if (toDel < root->data) {
        root->Left = deleteBST(root->Left, toDel);
    } else if (toDel > root->data) {
        root->Right = deleteBST(root->Right, toDel);
    } else {
        if (root->Left == nullptr) {
            BSTNode* temp = root->Right;
            free(root);
            return temp;
        } else if (root->Right == nullptr) {
            BSTNode* temp = root->Left;
            free(root);
            return temp;
        } else {
            BSTNode* succ = root->Right;
            while (succ->Left != nullptr) {
                succ = succ->Left;
            }
            root->data = succ->data;
            root->Right = deleteBST(root->Right, succ->data);
        }
    }

    return root;
}


void preOrder(BSTNode* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

void postOrder(BSTNode* root) {
    if (root != nullptr) {
        postOrder(root->Left);
        postOrder(root->Right);
        std::cout << root->data << " ";
    }
}

void inOrder(BSTNode* root) {
    if (root != nullptr) {
        inOrder(root->Left);
        std::cout << root->data << " ";
        inOrder(root->Right);
    }
}

int findMin(BSTNode* node) {
    if (node == nullptr)
        return -1; 

    while (node->Left != nullptr)
        node = node->Left;

    return node->data;
}

int findMax(BSTNode* node) {
    if (node == nullptr)
        return -1;

    while (node->Right != nullptr)
        node = node->Right;

    return node->data;
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

    cout << "Preorder traversal: ";
    preOrder(Root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrder(Root);
    cout << endl;

    cout << "Inorder traversal: ";
    inOrder(Root);
    cout << endl;

    cout << "Minimum value in the tree: " << findMin(Root) << endl;
    cout << "Maximum value in the tree: " << findMax(Root) << endl;


    int toDel;
    cout<<"Enter a value to be deleted"<<endl;
    cin>>toDel;
    deleteBST (Root , toDel);

    cout << "Preorder traversal: ";
    preOrder(Root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrder(Root);
    cout << endl;

    cout << "Inorder traversal: ";
    inOrder(Root);
    cout << endl;

    return 0;
}