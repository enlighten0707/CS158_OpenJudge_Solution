#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2005;
int fa[maxn];
int son[maxn];
int mark[maxn];
int stack[maxn];
int top_p=-1;

void push(int x){
    ++top_p;
    stack[top_p]=x;
}
int pop(){
    int ans=stack[top_p];
    --top_p;
    return ans;
}
int top(){return stack[top_p];}
bool isEmpty(){return top_p==-1;}

int main(){
    memset(fa,-1,sizeof(fa));
    memset(son,0,sizeof(son));
    memset(mark,0,sizeof(mark));
    char str[20005];
    cin.getline(str,20005,'\n');
    int len = strlen(str)-1;
    int MAX = -1;
    for(int i = 0; i < len; ++i){
        if(str[i] == '('){
            i++;
            int num = 0;
            while(str[i] >= '0' && str[i] <= '9'){
                num = num * 10 + str[i] - '0';
                i++;
            }
            i--;
            if(num > MAX)
                MAX = num;
            push(num);
        }
        else if(str[i] == ')'){
            int num = pop();
            fa[num] = top();
            son[top()]++;
        }
    }
    while(!isEmpty()) pop();
    for(int i = 1; i < MAX; ++i){
        int MIN = 99999999;
        for(int j = 1; j < MAX; ++j){
            if(mark[j] == 0 && (son[j] == 0 ||(fa[j] == -1 && son[j] == 1)))
                if(j < MIN)
                    MIN = j;
        }
            mark[MIN] = 1;
            if(fa[MIN] == -1){
                for(int j = 1; j <= MAX; ++j)
                    if(mark[j] == 0  && fa[j] == MIN){
                        fa[j] = -1;
                        printf("%d ",j);
                        break;
                    }
            }
            else{
                son[fa[MIN]]--;
                printf("%d ",fa[MIN]);
            }
    }
    return 0;
}

