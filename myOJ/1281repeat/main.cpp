#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=35;
bool vis[N][N];
int map[N][N],step[8][2];
int m,n,a,b,startX,startY;

struct Position{
    int x;
    int y;
    int distance;
    Position(int xx=0,int yy=0,int d=0):x(xx),y(yy),distance(d){}
};

Position queue[N*N];
int front=0,rear=0;

bool isEmpty(){
    return front==rear;
}
void enQueue(Position pos){
    rear=(rear+1)%(N*N);
    queue[rear]=pos;
}
Position deQueue(){
    front=(front+1)%(N*N);
    return queue[front];
}

void initStep(){
    step[0][0]=step[1][0]=step[4][1]=step[6][1]=a;
    step[0][1]=step[2][1]=step[4][0]=step[5][0]=b;
    step[2][0]=step[3][0]=step[5][1]=step[7][1]=-a;
    step[1][1]=step[3][1]=step[6][0]=step[7][0]=-b;
}

int main() {
    memset(vis,false, sizeof(vis));
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&map[i][j]);
            if(map[i][j]==3){
                startX=i;
                startY=j;
            }
        }
    }
    initStep();
    Position startPos(startX,startY);
    enQueue(startPos);
    while(!isEmpty()){
        Position cur=deQueue();
        vis[cur.x][cur.y]=true;
        for(int i=0;i<8;++i){
            Position next(cur.x+step[i][0],cur.y+step[i][1]);
            if(map[next.x][next.y]==4){
                next.distance=1+cur.distance;
                printf("%d",next.distance);
                return 0;
            }
            if(map[next.x][next.y]!=0&&map[next.x][next.y]!=2&&!vis[next.x][next.y]&&next.x>=0&&next.x<m&&next.y>=0&&next.y<n){
                next.distance=1+cur.distance;
                vis[next.x][next.y]=true;
                enQueue(next);
            }
        }
    }
}