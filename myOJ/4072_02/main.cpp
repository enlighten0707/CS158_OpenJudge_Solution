#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=100005;
int Start[N];
int len[N];

int main() {
    int n,m,k,u,v,l;
    scanf("%d%d%d",&n,&m,&k);
    memset(len,0,sizeof(len));
    while(m--){
        scanf("%d%d%d",&u,&v,&l);
        if(len[u]==0||l<len[u]) len[u]=l;
        if(len[v]==0||l<len[v]) len[v]=l;
    }


    if(k==0){
        printf("-1");
        return 0;
    }
    for(int i=0;i<k;++i)
        scanf("%d",&Start[i]);


    //for(int i=1;i<=n;++i) cout<<len[i]<<' ';
    int ans=1000000001;
    for(int i=0;i<k;++i){
        if(len[Start[i]]==0) continue;
        if(len[Start[i]]<ans) ans=len[Start[i]];
    }
    if(ans==1000000001) printf("-1");
    else printf("%d",ans);
    return 0;
}