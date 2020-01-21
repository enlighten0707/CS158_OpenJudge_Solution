#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int MAXSIZE=20005,MAXVALUE=2000000000;
int a[MAXSIZE];
int cnt=0;

void Insert(int x){
    int hole=++cnt;
    for(;hole>1;hole/=2){
        if(a[hole/2]>x) a[hole]=a[hole/2];
        else break;
    }
    a[hole]=x;
}

int Find(int x){
    int hole=1,ans=0;
    while(a[hole]!=x)++hole;
    int i=(int)log2(hole),minGap=MAXVALUE;
    for(int j=(1<<i);j<(1<<(i+1))&&j<=cnt;++j){
        if(a[j]>a[hole]&&a[j]-a[hole]<minGap){
            ans=j;
            minGap=a[j]-a[hole];
        }
    }

    if(2*hole<=cnt&&a[2*hole]>a[hole]&&a[2*hole]-a[hole]<minGap) {
        ans = 2 * hole;
        minGap = a[2 * hole] - a[hole];
    }
    if(2*hole+1<=cnt&&a[2*hole+1]>a[hole]&&a[2*hole+1]-a[hole]<minGap) {
        ans = 2 * hole + 1;
        minGap = a[2 * hole + 1] - a[hole];
    }

    return ans;
}
void Decrease(int i,int x){
    a[i]-=x;
    int hole=i,tmp=a[i];
    for(;hole>1;hole/=2){
        if(a[hole/2]>tmp)a[hole]=a[hole/2];
        else break;
    }
    a[hole]=tmp;
}

int main() {
    int m,x,pos;
    char command[10];
    cin>>m;
    for(int i=0;i<m;++i){
        cin.get();
        cin.getline(command,10,' ');
        switch(command[0]){
            case 'i':
                scanf("%d",&x);
                Insert(x);
                break;
            case 'f':
                scanf("%d",&x);
                printf("%d\r",Find(x));
                break;
            case 'd':
                scanf("%d%d",&pos,&x);
                Decrease(pos,x);
                break;
        }
    }
    return 0;
}