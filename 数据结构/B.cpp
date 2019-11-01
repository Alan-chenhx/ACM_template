#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int maxn[800005],n;

void update(int pos,int num,int node=1,int left=1,int right=n){
	if(left==right && left==pos)
		maxn[node]=num;
	else{
		if(pos<=left+right>>1)
			update(pos,num,node<<1,left,left+right>>1);
		else
			update(pos,num,(node<<1)+1,(left+right>>1)+1,right);
		maxn[node]=max(maxn[node<<1],maxn[(node<<1)+1]);
	}
}

int qmax(int l,int r,int node=1,int left=1,int right=n){
	if(l<=left && right<=r)
		return maxn[node];
	else{
		int ret=0;
		if(l<=left+right>>1)
			ret=qmax(l,r,node<<1,left,left+right>>1);
		if(r>left+right>>1)
			ret=max(qmax(l,r,(node<<1)+1,(left+right>>1)+1,right),ret);
		return ret;
	}
}

int main(){
	char _[1];
	int q,i,j;
	
	while(~scanf("%d%d",&n,&q)){
		memset(maxn,0,sizeof(maxn));
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			update(i,j);
		}
		while(q--){
			scanf("%s%d%d",&_,&i,&j);
			if(_[0]=='U')
				update(i,j);
			else
				printf("%d\n",qmax(i,j));
		}
	}
	
	return 0;
}
