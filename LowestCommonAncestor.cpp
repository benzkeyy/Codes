/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
There is also a trivial method in which we generate the path of both the given nodes and then simply find the first matching, but here we will implement the O(n) algorithm!
*/


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
      if(root == NULL) return NULL;
      if(p == root || q == root) return root;

      TreeNode* left = lowestCommonAncestor(root->left,p,q);
      TreeNode* right = lowestCommonAncestor(root->right,p,q);

      if(left == NULL && right == NULL) return NULL;
      if(left != NULL && right != NULL) return root;

      if(left == NULL)
        return right;
      else
        return left;
}
