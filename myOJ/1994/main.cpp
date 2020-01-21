#include <iostream>
using namespace std;

const int MAXSIZE=503;
bool map[MAXSIZE][MAXSIZE];
bool visit[MAXSIZE][MAXSIZE]={false};
int n,m,cnt=0;

struct Position
{
    int x;
    int y;
    Position(int i,int j):x(i),y(j){}
    Position():x(0),y(0){}
};

bool check(Position pos)
{
    int xPos=pos.x,yPos=pos.y;

    if(!map[xPos][yPos])return false;
    if(visit[xPos][yPos]) return false;
    if(xPos<0||xPos>m||yPos<0||yPos>n)//为什么取等时可以？？
        return false;
    return true;
}
void Search(Position pos)
{
    Position updatePos;
    //0,1,2,3 分别对应上下左右
    for(int k=0;k<=3;++k)
    {
        switch(k)
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
        if(!check(updatePos))continue;
        visit[updatePos.x][updatePos.y]=true;
        Search(updatePos);

    }
}

int main() {
    int ch;
    Position pos;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>ch;
            if(ch==0) map[i][j]=true;
            else map[i][j]=false;
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(map[i][j]&&!visit[i][j])
            {
                pos.x=i;pos.y=j;
                visit[i][j]=true;
                Search(pos);
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;
}
