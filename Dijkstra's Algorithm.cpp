/*
Following is basically the implementation of Dijkstra's Algorithm.
Complexity - O(N + Mlog(N)) .. this is because of using multiset DS as min-priority queue!
*/

vector < pair<ll,ll> > v[1000001];
bool visited[1000001];
ll dist[1000001];
ll N,M,x,y,z;
void initialize()
{
	for(ll i = 0; i < 1000001; i++)
	{
		visited[i] = false;
		dist[i] = 1e9;
	}
}
void dijkstra()
{
	initialize();
	dist[1] = 0;
	multiset< pair<ll,ll> > s; // acts as min-priority queue.
	s.insert({0,1});
	while(!s.empty())
	{
		pair <ll,ll> p = *s.begin();
		s.erase(s.begin());
		ll tt = p.second;
		if(visited[tt]) 
				continue;
				            
        visited[tt] = true;
        
        for(ll i = 0; i < v[tt].size(); i++)
		{
            ll w = v[tt][i].first; ll e = v[tt][i].second;
            
            if(dist[tt] + w < dist[e])
			{         
                dist[e] = dist[tt] + w;
                s.insert({dist[e],  e}); 
        	}
		}
	}
	for(ll i = 2; i <= N; i++)
	{
		cout << dist[i] << " ";
	}	
}
int main() 
{		
	cin>>N>>M; // N - nodes, M - edges..
	while(M--)
	{
		cin>>x>>y>>z;
		v[x].pb(make_pair(z,y)); // v -> weight,edge..
	}
	dijkstra();
	return 0;
}
