#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<int> gl[10005];
int d[10005],an[10005][20];

void init(int u){
	for(int i=1;i<=logb(d[u]);i++)
		an[u][i]=an[an[u][i-1]][i-1];
	
	for(int i=0;i<gl[u].size();i++){
		int &v=gl[u][i];
		if(an[u][0]!=v){
			an[v][0]=u;
			d[v]=d[u]+1;
			init(v);
		}
	}
}

int lca(int u,int v){
	if(d[u]<d[v])
		swap(u,v);
	
	for(int i=logb(d[u]);i>=0;i--)
		if(d[an[u][i]]>=d[v])
			u=an[u][i];
	
	if(u==v)
		return u;
	
	for(int i=logb(d[u]);i>=0;i--)
		if(an[u][i]!=an[v][i]){
			u=an[u][i];
			v=an[v][i];
		}
	
	return an[u][0];
}

int main(){
	int n,q,i;
	
	cin>>n>>q;
	for(i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		gl[u].push_back(v);
		gl[v].push_back(u);
	}
	
	init(1);
	
	for(i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<d[u]+d[v]-(d[lca(u,v)]<<1)<<endl;
	}
	
	return 0;
}
