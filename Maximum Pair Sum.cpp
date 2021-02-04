You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.

U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

Q x y, 1 ≤ x < y ≤ N.

You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

// Code..
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
pair<int,int> tree[4*100004];
int arr[100004];
void buildtree(int start, int end, int treeNode)
{
    if(start == end)
    {
        tree[treeNode].first = arr[start];
        tree[treeNode].second = INT_MIN;
        return;
    }
    int mid = (end+start)/2;
    buildtree(start,mid,2*treeNode);
    buildtree(mid+1,end,2*treeNode+1);
    int a = tree[2*treeNode].first;
    int b = tree[2*treeNode].second;
    int c = tree[2*treeNode+1].first;
    int d = tree[2*treeNode+1].second;
    int maxi1 = max(a,c);
    int maxi2 = min(max(a,d),max(b,c));
    tree[treeNode] = {maxi1,maxi2};
	/**
	We need to select top 2 elements out of 4..
	it is done by maxi1 and maxi2..
	**/
    return;
}
void update(int start, int end, int treeNode,int idx, int val)
{
    if(start == end)
    {
        arr[idx] = val;
        tree[treeNode].first = val;
        return;
    }
    int mid = (end+start)/2;
    if(idx > mid)
    	update(mid+1,end,2*treeNode+1,idx,val);
    else if(idx >= start && idx <= mid)
    	update(start,mid,2*treeNode,idx,val);
    int a = tree[2*treeNode].first;
    int b = tree[2*treeNode].second;
    int c = tree[2*treeNode+1].first;
    int d = tree[2*treeNode+1].second;
    int maxi1 = max(a,c);
    int maxi2 = min(max(a,d),max(b,c));
    tree[treeNode] = {maxi1,maxi2};
    return;
}
pair<int,int> que(int start,int end,int left,int right,int treeNode)
{
    if(start > right || left > end)
        return {INT_MIN,INT_MIN};
    if(left <= start && right >= end)
        return tree[treeNode];
    int mid = (end+start)/2;
    pair<int,int> ans1 = que(start,mid,left,right,2*treeNode);
    pair<int,int> ans2 = que(mid+1,end,left,right,2*treeNode+1);
    int maxi1 = max(ans1.first,ans2.first);
    int maxi2 = min(max(ans1.first,ans2.second),max(ans2.first,ans1.second));
    return {maxi1,maxi2};
}
int main() 
{
    fast;
	int n,q; cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    buildtree(0,n-1,1);
    cin>>q;
    while(q--)
    {
        char c; int x,y; cin>>c>>x>>y;
        if(c == 'U')
        {
            x--;
            update(0,n-1,1,x,y);
        }
        else
        {
            x--; y--;
            pair<int,int>p = que(0,n-1,x,y,1);
            cout << p.first + p.second << endl;
        }
    }
    return 0;
}
