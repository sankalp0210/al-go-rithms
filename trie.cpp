#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
ll m=1e9+7;
typedef struct Node{
	int flag;
	int count=0;
	struct Node* child[26];
}node;
vector<char> v;
node* make_new_node(){
	node* root=(node*)malloc(sizeof(node));
	for(int i=0;i<26;i++)
		root->child[i]=NULL;
	root->flag=0;
	return root;	
}

void insert(node *root,string word){
	node* temp=root;
	for(int i=0;i<word.length();i++)
	{
		int j=word[i]-'a';
		if(temp->child[j]==NULL)
			temp->child[j]=make_new_node();
		temp=temp->child[j];
	}
	temp->flag=1;
	temp->count++;
}
// void print(node* root){
// 	if(root==NULL)
// 		return;
// 	if(root->flag==1)
// 	{
// 		for(int i=0;i<v.size();i++)
// 			cout<<v[i];
// 		cout<<endl;
// 	}
// 	for(int i=0;i<26;i++)
// 	{	
// 		// cout<<i<<endl;
// 		char a=i+'a';
// 		// cout<<a;
// 		v.pb(a);
// 		print(root->child[i]);
// 	}
// 	v.pop_back();
// 	return;
// }

int search(node *root,string word){
	node* temp=root;
	for(int i=0;i<word.length();i++)
	{
		int j=word[i]-'a';
		if(temp->child[j]==NULL)
			return 0;
		temp=temp->child[j];
	}
	if(temp!=NULL)
		if(temp->flag)
			return 1;
	return 0;
}

int main()
{
	node* root=make_new_node();
	int n,q;
	cin>>n>>q;
	while(n--)
	{
		string s;
		cin>>s;
		insert(root,s);
	}
	// print(root);
	while(q--)
	{
		char s[100];
		cin>>s;
		cout<<search(root,s)<<endl;
	}
	return 0;
}