/*
Question - https://atcoder.jp/contests/abc061/tasks/abc061_d
Bellman ford calculates the length of shortest path from a source vertex to all other vertex.
Here, we modified it to calculate the length of LONGEST path from source to all other vertex, although we required the distance from source to a specified vertex only.
We did it by simply negating the given weights and not changing anything else!
*/

Solution - 

#include <bits/stdc++.h>
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;

ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}
using namespace std;

ll N,M,x,y,wt; 
vector<pair<ll,ll>> *graph = new vector<pair<ll,ll>>[20000];
ll d[20000];

ll bford()
{
	for(ll i = 0; i < N-1; i++)
	{
		for(ll j = 1; j <= N; j++)
		{
			for(ll t = 0; t < graph[j].size(); t++)
			{
				if(graph[j][t].second + d[j] < d[graph[j][t].first])
				{
					d[graph[j][t].first] = graph[j][t].second+d[j];
				}
			}
		}
	}
	return d[N]; // We require distance from 1st -> Nth vertex and it must be maximum!
}
int main() 
{
	for(ll i = 0; i < 1005; i++)
	{
		d[i] = 10000000000000;
	}
	fast;
	cin>>N>>M;
	for(ll i = 0; i < M; i++)
	{
		cin>>x>>y>>wt;
		graph[x].push_back(make_pair(y,-wt));
	}
	d[1] = 0;
	ll a = bford(); // Calculating 2 times, if answer changes or a != b then we also have a negative cycle!
	ll b = bford();
	if(a == b) cout << -a << endl; // Negating answer as we had earlier negated the weights!
	else cout << "inf" << endl; // Negative cycle is detected!
 	return 0;
}
