#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[6][6];
bool vis[6][6];
int mins=9999999;
int n,startX,startY,endX,endY;
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y,int state,int cost){
    if(cost>=mins) return;//如果已经非最优解，直接返回
    if(x==endX&&y==endY){
        mins=cost;
        return ;
    }
    for(int i=0;i<4;++i){
        int nx,ny;
        nx=x+step[i][0];
        ny=y+step[i][1];
        if(vis[nx][ny]) continue;//保证节点未被访问过
        if(nx<0||nx>=6) continue;//边界条件检查
        if(ny<0||ny>=6) continue;
        int tmp=map[nx][ny]*state;
        vis[nx][ny]=true;
        dfs(nx,ny,(tmp%4)+1,cost+tmp);//这里不能直接改值，而只是将这种状态传递到子状态中
        vis[nx][ny]=false;//从子情况出来后需要还原状态，因为每个孩子的分支状态时相互独立的
    }
}

int main() {

    scanf("%d",&n);
    while(n--){
        memset(vis,false, sizeof(vis));
        for(int i=0;i<6;++i){
            for(int j=0;j<6;++j)
                scanf("%d",&map[i][j]);
        }
        scanf("%d%d%d%d",&startX,&startY,&endX,&endY);
        dfs(startX,startY,1,0);
        printf("%d\n",mins);
    }
    return 0;
}