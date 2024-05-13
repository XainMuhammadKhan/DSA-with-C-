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