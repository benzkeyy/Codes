You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

//Code
#include<bits/stdc++.h>
using namespace std;
struct node
{
  	int maxsum;
    int sum;
    int bps;
    int bss;
};
int arr[50005];
node tree[3*50005];
void buildtree(int start, int end, int treeNode)
{
    if(start == end)
    {
        tree[treeNode].maxsum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].bps = arr[start];
        tree[treeNode].bss = arr[start];
        return;
    }
    int mid = (end+start)/2;
    buildtree(start,mid,2*treeNode);
    buildtree(mid+1,end,2*treeNode+1);
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    tree[treeNode].sum = left.sum + right.sum;
    tree[treeNode].bps = max(left.bps,left.sum + right.bps);
    tree[treeNode].bss = max(right.bss,right.sum + left.bss);
    tree[treeNode].maxsum = max({left.maxsum,right.maxsum,left.bss+right.bps});
    return;
}
node que(int start,int end,int l,int r,int treeNode)
{
    if(start > r || l > end)
        return {-16000,-16000,-16000,-16000};
    if(l <= start && r >= end)
        return tree[treeNode];
    int mid = (end+start)/2;
    node left = que(start,mid,l,r,2*treeNode);
    node right = que(mid+1,end,l,r,2*treeNode+1);
    node res;
    res.sum = left.sum + right.sum;
    res.bps = max(left.bps,left.sum + right.bps);
    res.bss = max(right.bss,right.sum + left.bss);
    res.maxsum = max({left.maxsum,right.maxsum,left.bss+right.bps});
    return res;
}
int main() 
{
	  ios_base::sync_with_stdio(false); 
	  cin.tie(0); 
	  cout.tie(0);
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    buildtree(0,n-1,1);
    int q; cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b; a--; b--;
        cout << que(0,n-1,a,b,1).maxsum << endl;
    }
}
