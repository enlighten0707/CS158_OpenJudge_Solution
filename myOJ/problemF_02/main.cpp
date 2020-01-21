#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=3131;
int a[100002],dp[100002][18];
int n;
struct node{
    int num;
    int cnt;
    node* next;
}hashMap[N];

void init(){
    for(int i=0;i<N;++i){
        hashMap[i].num=0;
        hashMap[i].cnt=0;
        hashMap[i].next=NULL;
    }
}

int Key(int number){
    return (number%N);
}
bool find(int Num,int Cnt){
    int key=Key(Num);
    node *q=&hashMap[key];
    q=q->next;
    while(q){
        if(q->num==Num){
            q->cnt+=Cnt;
            return true;
        }
        else q=q->next;
    }
    return false;
}
int findCnt(int Num){
    int key=Key(Num);
    node *q=&hashMap[key];
    q=q->next;
    while(q){
        if(q->num==Num)
            return q->cnt;
        else q=q->next;
    }
    return 0;
}
void insert(int Num,int Cnt){
    int key=Key(Num);
    node* p=&hashMap[key];
    p=p->next;
    if(!p){
        p=&hashMap[key];
        node *q=new node;
        q->num=Num;
        q->cnt=Cnt;
        q->next=NULL;
        p->next=q;
        return;
    }

    if(!find(Num,Cnt)){
        while(p->next) p=p->next;
        node* q=new node;
        p->next=q;
        q->num=Num;
        q->cnt=Cnt;
        q->next=NULL;
    }

}

void print(){
    for(int i=0;i<N;++i){
        cout<<i<<" : ";
        node *p=&hashMap[i];

        while(p){
            cout<<p->num<<" : "<<p->cnt<<' ';
            p=p->next;
        }
        cout<<endl;
    }
}
void clear(){
    for(int i=0;i<N;++i){
        node *p=&hashMap[i];
        p=p->next;
        node* q;
        while(p){
            q=p->next;
            delete p;
            p=q;
        }
    }
}
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

void makeRmq(){
    for(int j=1;j<=n;j++) dp[j][0]=a[j];
    for(int i=1;i<18;i++){
       for(int j=1;j<=n;j++){
           if(j+(1<<i)-1 <= n){
                dp[j][i]=gcd(dp[j][i-1],dp[j+(1<<i-1)][i-1]);
           }
       }
    }
}

int getGcd(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return gcd(dp[left][k],dp[right-(1<<k)+1][k]);
}

int main(){
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    makeRmq();
    init();

    int l,r,mid;

     for(int i=1;i<=n;++i) {
         int g = dp[i][0], j = i;
         while (j <= n) {
             l = j;
             r = n;
             while (l < r) {
                 mid = (l + r + 1) >> 1;
                 if (getGcd(i, mid) == g) l = mid;
                 else r = mid - 1;
             }
             insert(g, l - j + 1);
             j = l + 1;
             g = getGcd(i, j);
         }
     }

    //print();
    int q;
    scanf("%d",&q);
    int ans;
    for(int i=0;i<q;++i){
        scanf("%d",&x);
        ans=findCnt(x);
        printf("%d\n",ans);
    }
    clear();
    return 0;
}


