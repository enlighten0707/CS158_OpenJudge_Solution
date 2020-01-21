#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=33;
bool map[N][N];
bool vis[N][N];
int m,n,a,b;
int step[8][2];
int Distance[N][N];
int front=0,rear=0;
struct Position{
    int x;
    int y;
    Position(int xx=0,int yy=0):x(xx),y(yy){}
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

void initStep(){
    step[0][0]=step[1][0]=step[4][1]=step[6][1]=a;
    step[0][1]=step[2][1]=step[4][0]=step[5][0]=b;
    step[2][0]=step[3][0]=step[5][1]=step[7][1]=-a;
    step[1][1]=step[3][1]=step[6][0]=step[7][0]=-b;
}


int main() {
    int opt;
    Position startPos,endPos;
    memset(vis,false, sizeof(vis));
    memset(Distance,0, sizeof(Distance));
    scanf("%d%d",&m,&n);
    scanf("%d%d",&a,&b);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&opt);
            if(opt==0||opt==2) map[i][j]=false;
            else if(opt==1) map[i][j]=true;
            else if(opt==3){
                map[i][j]=true;
                startPos.x=i;
                startPos.y=j;
            }
            else if(opt==4){
                map[i][j]=true;
                endPos.x=i;
                endPos.y=j;
            }
        }
    }
    initStep();
    push(startPos);
    while(!isEmpty()){
        Position cur=pop();
        int i;
        for(i=0;i<8;++i){
            Position update;
            update.x=cur.x+step[i][0];
            update.y=cur.y+step[i][1];
            if(update.x==endPos.x&&update.y==endPos.y){
                Distance[update.x][update.y]=1+Distance[cur.x][cur.y];
                printf("%d",Distance[update.x][update.y]);
                break;
            }
            if(map[update.x][update.y]&&update.x>=0&&update.x<m&&update.y>=0&&update.y<n&&!vis[update.x][update.y]){
                push(update);
                vis[update.x][update.y]=true;
                Distance[update.x][update.y]=1+Distance[cur.x][cur.y];
            }
        }
        if(i!=8) break;
    }
    return 0;
}