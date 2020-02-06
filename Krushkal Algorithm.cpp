/* Krushkal's Algorithm done using Disjoint-set union data structures or DSU.
N - no of nodes, M - no of edges, then we provide -> (x,y) edge with z -> weight! */

#include <bits/stdc++.h>

#define ll long long
using namespace std;


pair<ll, pair<int,int> > p[100005];
ll arr[100005];
ll x,y,z,N,M;

void initialize()
{
	for(int i = 1; i < 100005; i++)
		arr[i] = i;
}
int root(int x)
{
	while(arr[x] != x)
	{
		arr[x] = arr[arr[x]]; // collapsing find!
		x = arr[x];
	}
	return x;
}
void uni(int x, int y)
{
	int p = root(x); int q = root(y);
	arr[p] = arr[q];
}
void krushkal( pair<ll, pair<int,int> >p[] )
{
	ll acost=0,cost; int x,y;
	for(int i = 1; i <= M; i++)
	{
		x = p[i].second.first; y = p[i].second.second;
		cost = p[i].first;
		if(root(x) != root(y))
			acost += cost,uni(x,y);
	}
	cout << acost << endl;
}
int main()
{
	fast;
	initialize();
	cin>>N>>M;
	for(int i = 1; i <= M; i++)
	{
		cin>>x>>y>>z;
		p[i] = make_pair(z,make_pair(x,y));
	}
	sort(p+1,p+M+1);
	krushkal(p);
   	return 0;
} 
