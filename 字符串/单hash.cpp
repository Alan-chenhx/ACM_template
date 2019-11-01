//超大质数hash
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
ull base=131;
ull a[10010];
char s[10010];
int n,ans=1;
int prime=233317; 
ull mod=212370440130137957ll;
ull hashe(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
    ans=(ans*base+(ull)s[i])%mod+prime;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i]=hashe(s);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i+1])
        ans++;
    }
    printf("%d",ans);
} 