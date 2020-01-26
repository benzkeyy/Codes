
// Following is a code which gives us the minimum value in a range [L,R] in an array in O(nlogn) time.
// It is done using segment tree concept.
// The queries that can be performed -
u x y -> update at A[x] = y.
q l r -> min value in range [L,R].

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int tree[1000002];
int arr[1000002];

void build(int pos, int low, int high)
{
	if(low == high)
	{
		tree[pos] = arr[low];
		return;
	}
	int mid = low + (high-low)/2;
	build(2*pos,low,mid);
	build(2*pos+1,mid+1,high);
	tree[pos] = min(tree[2*pos],tree[2*pos+1]);
}
void update(int pos, int low, int high,int index, int val)
{
	if(low == high)
	{
		arr[index] = val;
		tree[pos] = val;
	}
	else
	{
		int mid = low + (high-low)/2;
		if(low <= index && index <= mid)
        {
            update(2*pos, low, mid, index, val);
        }
        else
        {
            update(2*pos+1, mid+1, high, index, val);
        }
        tree[pos] = min(tree[2*pos],tree[2*pos+1]);
	}
}
int query(int pos, int low,int high, int l, int r)
{
	if(l > high || r < low)
	{
		return INT_MAX;
	}
	if(l <= low && r >= high)
	{
		return tree[pos];
	}
	
	int mid = low + (high-low)/2;
	return min(query(2*pos,low,mid,l,r),query(2*pos+1,mid+1,high,l,r));
}
int main()
{
	fast;
	//memset(arr,0,sizeof(arr));
	//memset(tree,0,sizeof(tree));
	ll N,l,r,Q;
	char c;
	cin>>N>>Q;
	for(ll i = 1; i <= N; i++) cin>>arr[i];
	build(1,1,N-1); // Building the segment tree!
	while(Q--)
	{
		cin>>c>>l>>r;
		if(c == 'q')
		{
			cout << query(1,1,N-1,l,r) << endl;
		}
		else if(c == 'u')
		{
			update(1,1,N-1,l,r);
		}
	}
	return 0;
}
