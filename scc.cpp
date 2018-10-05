#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
vector<int> adj[100001];
vector<int> adjTrans[100001];
stack<int> s;
int vis1[100001];
int vis2[100001];
void dfsft(int n)
{
	vis1[n]=1;
	for(int i=0;i<adj[n].size();i++)
	{
		if(!vis1[adj[n][i]])
			dfsft(adj[n][i]);
	}
	s.push(n);
	return;
}
void dfs(int n)
{
	vis2[n]=1;
	for(int i=0;i<adjTrans[n].size();i++)
	{
		if(!vis2[adjTrans[n][i]])
			dfs(adjTrans[n][i]);
	}
	cout<<n<<" ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int i,n,m;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adjTrans[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis1[i])
			dfsft(i);
	}

	
	while(!s.empty())
	{
		if(!vis2[s.top()])
		{
			dfs(s.top());
			cout<<endl;
		}
		s.pop();
	}
	return 0;
}