#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=10005;
const int seed=31;

struct node{
    char name[32];
    int price;
    node* next;
}hashMap[N];

void init(){
    for(int i=0;i<N;++i){
        hashMap[i].price=0;
        hashMap[i].next=NULL;
        strcpy(hashMap[i].name,"");
    }
}
int Key(const char str[]){
    int num=0;
    for(int i=0;str[i]!='\0';++i)
        num=(num*seed+str[i])%N;
    return num;
}

void insert(const char str[]){
    int key=Key(str);
    //printf("%s%s%d\n",str," key : ",key);
    node *p,*q;
    p=&hashMap[key];
    /*
    if(!p->next){
        strcpy(p->name,str);
        return ;
    }
     */
    while(p->next)p=p->next;
    q=new node;
    strcpy(q->name,str);
    q->next=NULL;
    q->price=0;
    p->next=q;
}

void find(const char str[],int a){
    int key=Key(str);
    //printf("%s%s%s%d\n","start find ",str," : ",key);
    node *p=&hashMap[key];

    while(p){
        //printf("%d%s%s\n",p->price,": ",p->name);
        if(!strcmp(p->name,str)){
            p->price+=a;
            //printf("%s%s%d\n",str," : ",p->price);
            break;
        }
        p=p->next;
    }

}
void clear(){
    for(int i=0;i<N;++i){
        node* p;
        node* q;
        if(hashMap[i].price){
            p=&hashMap[i];
            p=p->next;
            while(p){
                q=p->next;
                delete p;
                p=q;
            }
        }
    }
}
/*
void print(){
    for(int j=0;j<N;++j){
        cout<<j<<"----";
        node* p=&hashMap[j];
        while(p){
            cout<<p->name<<" : "<<p->price<<"   ";
            p=p->next;
        }
        cout<<endl;
    }
}*/
int main() {
    int n,day;
    char str[32];
    while(scanf("%d",&n)!=EOF) {
        //hashMap置零
        init();
        //插入n个name
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            insert(str);

        }
        //print();

        scanf("%d", &day);
        int memoryPrice = 0;
        for (int i = 0; i < day; ++i) {
            int rank = 1, a;
            for (int j = 0; j < n; ++j) {
                scanf("%d%s", &a, str);
                if (!strcmp(str, "memory"))
                    memoryPrice += a;
                find(str, a);
            }
            //print();
            node *p;
            //计算排名
            for (int j = 0; j < N; ++j) {
                    p = hashMap[j].next;
                    while (p) {
                        if (p->price > memoryPrice)
                            ++rank;
                        p = p->next;
                    }
            }
            printf("%d\n",rank);
        }
        clear();
    }
    return 0;
}