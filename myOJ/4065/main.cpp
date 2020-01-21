#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=305;

int map[N][N];
int Distance[N][N];
bool vis[N][N];

int front=0,rear=0;

int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct Position{
    int x;
    int y;
    int t;
    Position(int xx=0,int yy=0,int tt=0):x(xx),y(yy),t(tt){}
};

Position queue[N*N];
bool isEmpty(){
    return front==rear;
}
Position pop(){
    front=(front+1)%(N*N);
    return queue[front];
}
void push(Position x){
    rear=(rear+1)%(N*N);
    queue[rear]=x;
}


int main() {
    int n,m,startX=0,startY=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&map[i][j]);
            if(map[i][j]==2){
                startX=i;
                startY=j;
            }
        }
    }
    Position startPos(startX,startY,6);
    bool f=false;
    push(startPos);
    map[startX][startY]=true;
    while(!isEmpty()){
        Position cur=pop();
        if(cur.t==0) continue;
        if(map[cur.x][cur.y]==4) {
            cur.t=6;
            map[cur.x][cur.y]=0;
        }
        int i;
        for(i=0;i<4;++i){
            Position update;
            update.x=cur.x+step[i][0];
            update.y=cur.y+step[i][1];
            update.t=cur.t-1;

            if(map[update.x][update.y]==0) continue;

            if(map[update.x][update.y]==3){
                Distance[update.x][update.y]=1+Distance[cur.x][cur.y];
                printf("%d",Distance[update.x][update.y]);
                f=true;
                break;
            }
            if(map[update.x][update.y]&&update.x>=0&&update.x<m&&update.y>=0&&update.y<n&&!vis[update.x][update.y]){

                push(update);
                vis[update.x][update.y]=true;
                Distance[update.x][update.y]=1+Distance[cur.x][cur.y];
            }
        }
        if(i!=4)
            break;
    }
    if(!f) printf("%d",-1);
    return 0;
}