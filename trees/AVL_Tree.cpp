#include <iostream>
#include <stdlib.h>
using namespace std;

struct BSTNode
{
  int data;
  int heightLeft;
  int heightRight;
  BSTNode *left;
  BSTNode *right;
};

int maxHeight(int a, int b)
{
  return a > b ? a : b;
}

BSTNode *shiftLeft(BSTNode *unbalanceNode)
{
  BSTNode *retNode = unbalanceNode->right;
  BSTNode *tmp = retNode->left;
  retNode->left = unbalanceNode;
  unbalanceNode->right = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightRight = 0;
  }
  else
  {
    unbalanceNode->heightRight = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightLeft = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}

BSTNode *shiftRight(BSTNode *unbalanceNode)
{
  BSTNode *retNode = unbalanceNode->left;
  BSTNode *tmp = retNode->right;
  retNode->right = unbalanceNode;
  unbalanceNode->left = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightLeft = 0;
  }
  else
  {
    unbalanceNode->heightLeft = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightRight = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}

BSTNode *insert(BSTNode *root, int data)
{
  if (root == NULL)
  {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->heightLeft = node->heightRight = 0;
    node->left = node->right = NULL;
    return node;
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
    root->heightLeft = maxHeight(root->left->heightLeft, root->left->heightRight) + 1;
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
    root->heightRight = maxHeight(root->right->heightLeft, root->right->heightRight) + 1;
  }
  int balanceFactor = root->heightLeft - root->heightRight;
  if (balanceFactor < -1)
  {
    if (data > root->right->data)
    {
      root = shiftLeft(root);
    }
    else
    {
      root->right = shiftRight(root->right);
      root = shiftLeft(root);
    }
  }
  else if (balanceFactor > 1)
  {
    if (data < root->left->data)
    {
      root = shiftRight(root);
    }
    else
    {
      root->left = shiftLeft(root->left);
      root = shiftRight(root);
    }
  }
  return root;
}

bool search(BSTNode *root, int toSearch)
{
  if (root == NULL)
  {
    return false;
  }
  if (toSearch == root->data)
  {
    return true;
  }
  if (toSearch < root->data)
  {
    return search(root->left, toSearch);
  }
  else if (toSearch > root->data)
  {
    return search(root->right, toSearch);
  }
}

void inOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversial(root->left);
  cout << root->data << " ";
  inOrderTraversial(root->right);
}

void preOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preOrderTraversial(root->left);
  preOrderTraversial(root->right);
}

void postOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversial(root->left);
  postOrderTraversial(root->right);
  cout << root->data << " ";
}

BSTNode *min(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL)
  {
    return root;
  }
  return min(root->left);
}
BSTNode *max(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->right == NULL)
  {
    return root;
  }
  return max(root->right);
}

BSTNode *deleteNode(BSTNode *root, int toDelete)
{
  if (root == NULL)
  {
    cout << "Value not Found !" << endl;
    return root;
  }
  if (toDelete < root->data)
  {
    root->left = deleteNode(root->left, toDelete);
    if (root->left == NULL)
    {
      root->heightLeft = 0;
    }
    else
    {
      root->heightLeft = maxHeight(root->left->heightLeft, root->left->heightRight) + 1;
    }
  }
  else if (toDelete > root->data)
  {
    root->right = deleteNode(root->right, toDelete);
    if (root->right == NULL)
    {
      root->heightRight = 0;
    }
    else
    {
      root->heightRight = maxHeight(root->right->heightLeft, root->right->heightRight) + 1;
    }
  }
  else
  {
    if (root->left == NULL)
    {
      BSTNode *tmp = root->right;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    else if (root->right == NULL)
    {
      BSTNode *tmp = root->left;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    else
    {
      BSTNode *tmp = min(root->right);
      root->data = tmp->data;
      root->right = deleteNode(root->right, tmp->data);
    }
  }
  // Update height of current node
  root->heightLeft = root->left ? maxHeight(root->left->heightLeft, root->left->heightRight) + 1 : 0;
  root->heightRight = root->right ? maxHeight(root->right->heightLeft, root->right->heightRight) + 1 : 0;

  // Check balance factor and perform rotations if necessary
  int balanceFactor = root->heightLeft - root->heightRight;
  if (balanceFactor < -1)
  {
    if (toDelete > root->right->data)
    {
      root = shiftLeft(root);
    }
    else
    {
      root->right = shiftRight(root->right);
      root = shiftLeft(root);
    }
  }
  else if (balanceFactor > 1)
  {
    if (toDelete < root->left->data)
    {
      root = shiftRight(root);
    }
    else
    {
      root->left = shiftLeft(root->left);
      root = shiftRight(root);
    }
  }
  return root;
}

int main()
{
  BSTNode *root = NULL;
  int choice, val;

  do
  {
    cout << "\nBinary Search Tree Operations" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Element" << endl;
    cout << "3. Search Element" << endl;
    cout << "4. Inorder Traversal" << endl;
    cout << "5. Preorder Traversal" << endl;
    cout << "6. Postorder Traversal" << endl;
    cout << "7. Find Minimum" << endl;
    cout << "8. Find Maximum" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter value to insert: ";
      cin >> val;
      root = insert(root, val);
      break;
    case 2:
      cout << "Enter value to delete: ";
      cin >> val;
      root = deleteNode(root, val);
      break;
    case 3:
      cout << "Enter value to search: ";
      cin >> val;
      if (search(root, val))
        cout << "Value found in tree" << endl;
      else
        cout << "Value not found in tree" << endl;
      break;
    case 4:
      cout << "Inorder Traversal: ";
      inOrderTraversial(root);
      cout << endl;
      break;
    case 5:
      cout << "Preorder Traversal: ";
      preOrderTraversial(root);
      cout << endl;
      break;
    case 6:
      cout << "Postorder Traversal: ";
      postOrderTraversial(root);
      cout << endl;
      break;
    case 7:
      if (root == NULL)
        cout << "Tree is empty" << endl;
      else
        cout << "Minimum value: " << min(root)->data << endl;
      break;
    case 8:
      if (root == NULL)
        cout << "Tree is empty" << endl;
      else
        cout << "Maximum value: " << max(root)->data << endl;
      break;
    case 9:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
    }
  } while (choice != 9);

  return 0;
}
