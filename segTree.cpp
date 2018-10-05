#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
int tree[200001];
int arr[200001];
void build(int l, int r,int id)
{
	if(l==r)
		tree[id]=arr[l];
	else
	{
		int mid=(l+r)/2;
		build(l,mid,2*id);
		build(mid+1,r,2*id+1);
		tree[id] = tree[2*id] + tree[2*id +1];
	}
	return;
}
void update(int l,int r,int i,int d,int id)
{
	if(i<l || i>r)
		return;
	tree[id]+=d;
	if(l!=r)
	{
		int mid=(l+r)/2;
		update(l,mid,i,d,2*id);
		update(mid+1,r,i,d,2*id+1);
	}
	return;
}
int query(int ql,int qr,int l,int r,int id)
{

	if(qr<l || ql>r)
		return 0;
	if(ql<=l && qr>=r)
		return tree[id];
	int m=(l+r)/2;
	if(qr<=m && ql<l)
		return query(ql,qr,l,m,2*id);
	else if(ql>=m && qr<r)
		return query(ql,qr,m+1,r,2*id +1);
	else
		return query(ql,qr,l,m,2*id) + query(ql,qr,m+1,r,2*id +1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	build(0,n-1,1);
	while(1)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int ind,val;
			cin>>ind>>val;
			int diff=x-arr[ind];
			arr[ind]=x;
			update(0,n-1,ind,diff,1);
		}
		if(x==2)
		{

			int l,r;
			cin>>l>>r;
			int ans=query(l,r,0,n-1,1);
			cout<<ans<<endl;
		}
		else
			break;
	}
	// for(i=1;i<2*n;i++)
	// 	cout<<tree[i]<<endl;
	
	return 0;
}
