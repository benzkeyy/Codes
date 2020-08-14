#include <bits/stdc++.h>
using namespace std;


int timer = 0;
struct Node
{
	int val;
	Node* left;
	Node* right;
};
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->val = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
int burnTreeUtil(Node* root, int target, queue<Node*>&q)
{
	if(root == NULL)
		return 0;	
	if(root->val == target)
	{
		cout << root->val << endl;
		if(root->left != NULL)
			q.push(root->left);
		if(root->right != NULL)
			q.push(root->right);
		return 1;
	}
	int a = burnTreeUtil(root->left,target,q);
	if(a == 1)
	{
		int t = q.size(); timer++;
		while(t--)
		{
			Node* temp = q.front();
			q.pop();
			cout << temp->val << ",";
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		if(root->right != NULL)
			q.push(root->right);
		cout << root->val << endl;
		return 1;
	}
	int b = burnTreeUtil(root->right,target,q);
	if(b == 1)
	{
		int t = q.size(); timer++;
		while(t--)
		{
			Node* temp = q.front();
			q.pop();
			cout << temp->val << ",";
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		if(root->left != NULL)
			q.push(root->left);
		cout << root->val << endl;
		return 1;
	}
	return 0;
}
void burnTree(Node* root, int target)
{
	queue<Node*>q;	
	int p = burnTreeUtil(root,target,q);
	if(p == 0) cout << "No target node" << endl;
	while(!q.empty())
	{
		int t = q.size(); timer++;
		while(t--)
		{
			Node* temp = q.front();
			q.pop();
			if(t != 0) cout << temp->val << ",";
			else cout << temp->val;
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		cout << endl;
	}
	return;
}
int main()
{  
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->right = newNode(6);
  	root->right->right->right = newNode(9);
  	root->right->right->right->right = newNode(10);
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(8);
    root->left->right->left = newNode(7); 
    int targetNode = 8; 
    burnTree(root, targetNode); 
    cout << "\nTime to burn the tree\n" << timer << endl;
 	  return 0;
}
