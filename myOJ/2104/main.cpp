#include <iostream>
#include <cstring>
using namespace std;

const int MOVE=500;
const int MAXSIZE=1004;
const int MAXQUEUE=1000000;
bool map[MAXSIZE][MAXSIZE]={true};
int Distance[MAXSIZE][MAXSIZE]={10000};
bool vis[MAXSIZE][MAXSIZE]={false};


struct Position
{
    int x;
    int y;
    Position(int i,int j):x(i),y(j){}
    Position():x(0),y(0){}
};

class Queue
{
private:
    Position* elem;
    int front,rear;
public:
    Queue();
    ~Queue();
    bool isEmpty()const;
    void push(const Position& x);
    Position pop();
};

Queue::Queue() {
    elem=new Position[MAXQUEUE];
    front=rear=0;}
Queue::~Queue() {delete []elem;}
bool Queue::isEmpty() const {return front==rear;}
void Queue::push(const Position &x) {
    rear=(rear+1)%MAXQUEUE;
    elem[rear]=x;
}
Position Queue::pop() {
    front=(front+1)%MAXQUEUE;
    return elem[front];
}

int main() {
    memset(vis,false, sizeof(vis));
    Distance[MOVE][MOVE]=0;
    Position startPos(MOVE,MOVE);
    int endX,endY,N,tmpX,tmpY;
    cin>>endX>>endY>>N;

    for(int i=0;i<N;++i)
    {
        cin>>tmpX>>tmpY;
        map[tmpX+MOVE][tmpY+MOVE]=false;
    }
    Queue queue;
    queue.push(startPos);

    while(!queue.isEmpty())
    {
        Position pos=queue.pop();
        vis[pos.x][pos.y]=true;
        Position updatePos;
        int k;
        for(k=0;k<4;++k)
        {
            //0,1,2,3 分别对应上下左右
            switch (k)
            {
                case 0:
                    updatePos.x=pos.x;
                    updatePos.y=pos.y-1;break;
                case 1:
                    updatePos.x=pos.x;
                    updatePos.y=pos.y+1;break;
                case 2:
                    updatePos.x=pos.x-1;
                    updatePos.y=pos.y;break;
                case 3:
                    updatePos.x=pos.x+1;
                    updatePos.y=pos.y;break;
                default:break;
            }
            if(updatePos.x==endX+MOVE&&updatePos.y==endY+MOVE) {
                Distance[updatePos.x+MOVE][updatePos.y+MOVE]=1+Distance[pos.x + MOVE][pos.y + MOVE];
                cout<<Distance[updatePos.x+MOVE][updatePos.y+MOVE];
                break;
            }
            if(!vis[updatePos.x][updatePos.y]&&map[updatePos.x+MOVE][updatePos.y+MOVE]&&
            updatePos.x>=0&&updatePos.x<MAXSIZE&&updatePos.y>=0&&updatePos.y<MAXSIZE) {
                vis[updatePos.x+MOVE][updatePos.y+MOVE]=true;
                Distance[updatePos.x + MOVE][updatePos.y + MOVE] = Distance[pos.x + MOVE][pos.y + MOVE] + 1;
                queue.push(updatePos);
            }
        }
        if(k!=4)break;
    }

    return 0;
}
