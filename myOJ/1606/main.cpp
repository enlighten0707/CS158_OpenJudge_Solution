#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[55][55];
bool vis[55][55];
int n,m;
int tmp[55][55],ans[55][55];
int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<4;++i){
        int nx=x+step[i][0];
        int ny=y+step[i][1];
        if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]==0) continue;
        if(!vis[nx][ny]){
            map[nx][ny]=1;
            dfs(nx,ny);
        }
    }
}


int main() {
    char opt;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%c",&opt);
            if(opt=='.') map[i][j]=1;
            else if(opt=='#') map[i][j]=0;
            else if(opt=='?') map[i][j]=2;
        }
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(map[i][j]==1||map[i][j]==2){
                for(int k=0;k<n;++k){
                    for(int l=0;l<m;++l)
                        tmp[k][l]=map[k][l];
                }
                memset(vis,false,sizeof(vis));
                dfs(i,j);
                bool f=true;

                for(int k=0;k<n;++k){
                    for(int l=0;l<m;++l)
                        cout<<tmp[k][l];
                    cout<<endl;
                }
                cout<<endl;

                for(int k=0;k<n;++k){
                    for(int l=0;l<m;++l){
                        if(tmp[k][l]==1&&!vis[k][l]){
                            f=false;
                            break;
                        }
                    }
                }
                if(cnt==0&&f){
                    for(int k=0;k<n;++k){
                        for(int l=0;l<m;++l)
                            ans[k][l]=tmp[k][l];
                    }
                    ++cnt;
                }
                else if(cnt!=0&&f){
                    for(int k=0;k<n;++k){
                        for(int l=0;l<m;++l){
                            if(ans[k][l]!=tmp[k][l]){
                                printf("Ambiguous");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if(cnt==0) printf("Impossible");
    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(map[i][j]==0||map[i][j]==2) printf("#");
                else if(map[i][j]==1)  printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}