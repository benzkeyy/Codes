
// Following is a code which gives us the minimum value in a range [L,R] in an array in O(nlogn) time.
// It is done using segment tree concept.
// The queries that can be performed -
u x y -> update at A[x] = y.
q l r -> min value in range [L,R].

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int tree[4*100004];
int arr[100004];
void buildtree(int start, int end, int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (end+start)/2;
    buildtree(start,mid,2*treeNode);
    buildtree(mid+1,end,2*treeNode+1);
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
    return;
}
void update(int start, int end, int treeNode,int idx, int val)
{
    if(start == end)
    {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = (end+start)/2;
    if(idx > mid)
    	update(mid+1,end,2*treeNode+1,idx,val);
    else if(idx >= start && idx <= mid)
    	update(start,mid,2*treeNode,idx,val);
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
    return;
}
int que(int start,int end,int left,int right,int treeNode)
{
    if(start > right || left > end)
        return INT_MAX;
    if(left <= start && right >= end)
        return tree[treeNode];
    int mid = (end+start)/2;
    int ans1 = que(start,mid,left,right,2*treeNode);
    int ans2 = que(mid+1,end,left,right,2*treeNode+1);
    return min(ans1,ans2);
}
int main() 
{
    fast;
    int n,q; cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>arr[i];
    buildtree(0,n-1,1);
    while(q--)
    {
        char c; int x,y; cin>>c>>x>>y;
        if(c == 'u')
        {
            x--;
            update(0,n-1,1,x,y);
        }
        else
        {
            x--; y--;
            cout << que(0,n-1,x,y,1) << endl;
        }
    }
    return 0;
}
