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

}
int Key(const char str[]){
    int num=0;
    for(int i=0;str[i]!='\0';++i)
        num=(num*seed+str[i])%N;
    return num;
}

void insert(const char str[]){
    int key=Key(str);
    if(!hashMap[key]){
        hashMap[key]=new node;
        hashMap[key]->price=0;
        hashMap[key]->next=NULL;
        strcpy(hashMap[key]->name,str);
    }
    else{
        node* p=hashMap[key];
        while(p->next)p=p->next;
        node* q=new node;
        q->next=NULL;
        q->price=0;
        strcpy(q->name,str);
        p->next=q;
    }
}

void find(const char str[],int a){
    int key=Key(str);
    if(!strcmp(hashMap[key]->name,str)){
        hashMap[key]->price+=a;
        return ;
    }
    node *p=hashMap[key]->next;
    while(p){
        if(!strcmp(p->name,str)){
            p->price+=a;
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
int main() {
    int n,day;
    char str[32];
    while(scanf("%d",&n)!=EOF) {
        //hashMap置零
        init();
        //插入n个name
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            //printf("%s\n",str);
            insert(str);
        }

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
            node *p;
            //计算排名
            for (int j = 0; j < N; ++j) {
                if (hashMap[j].price) {
                    p = &hashMap[j];
                    while (p) {
                        if (p->price > memoryPrice)
                            ++rank;
                        p = p->next;
                    }
                }
            }
            printf("%d\n",rank);
        }
        clear();
    }
    return 0;
}