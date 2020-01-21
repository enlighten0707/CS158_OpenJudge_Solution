#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

int p,q,mins;
int a[51][51],state ,book[51][51];
int nextStep[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x,int y,int state,int cost)
{
    int tx,ty,k,sum;
    if(x==p&&y==q){
        if(cost<mins)
            mins=cost;
        return ;
    }
    if(cost>mins)
        return ;

    for(k=0;k<=3;k++){
        tx=x+nextStep[k][0];
        ty=y+nextStep[k][1];
        if(tx<0||tx>=6||ty<0||ty>=6)
            continue;
        if(book[tx][ty]==0){
            book[tx][ty]=1;
            sum=a[tx][ty]*state;
            dfs(tx,ty,sum%4+1,cost+sum);
            book[tx][ty]=0;
        }
    }
}

int main(){
    int i,j,startx,starty,n;
    cin>>n;
    while(n--){
        memset(book,0,sizeof(book));
        mins=999999;
        for(i=0;i<6;i++)
            for(j=0;j<6;j++)
                cin>>a[i][j];

        cin>>startx>>starty>>p>>q;
        dfs(startx,starty,1,0);
        cout<<mins<<endl;
    }
    return 0;
}

 

 
