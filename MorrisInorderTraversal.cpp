/*
L.C- https://leetcode.com/problems/binary-tree-inorder-traversal/
Reference - https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
*/
vector<int> inorderTraversal(TreeNode* root) 
    {
        TreeNode *curr,*pre;
        curr = root;
        vector<int>ans;
        while(curr != NULL)
        {
            /* No left, so print the node and move to right! */
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                /* Find the inorder predecessor of current */
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr)
                {
                    pre = pre->right;
                }
                
                /* Make current as the right child of its inorder  
               predecessor */
                if(pre->right == NULL)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    /* Revert the changes made in the 'if' part to restore  
                       the original tree i.e., fix the right child 
                       of predecessor */
                    pre->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
