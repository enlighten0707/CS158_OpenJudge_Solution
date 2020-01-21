#include <iostream>
using namespace std;

const int MAXSIZE=1e6;
char ch[MAXSIZE],check[MAXSIZE];
int top_p=-1;
int top_pCheck=-1;

void push(char cur)
{
    ++top_p;
    ch[top_p]=cur;
}

void pop()
{
    if(top_p==-1) return;
    --top_p;
}

void top()
{
    if(top_p==-1) return;
    cout<<ch[top_p]<<'\n';
}

bool isBalance()
{
    if(top_p==-1) return true;
    char curCh;
    int cnt=top_p;
    while(cnt!=-1)
    {
        if(ch[cnt]=='}'||ch[cnt]==']'||ch[cnt]==')')
        {
            ++top_pCheck;
            check[top_pCheck]=ch[cnt];
        }
        else if(ch[cnt]=='{'||ch[cnt]=='['||ch[cnt]=='(')
        {
            if(top_pCheck==-1) return false;
            curCh=check[top_pCheck];
            --top_pCheck;
            if((ch[cnt]=='{'&&curCh!='}')||(ch[cnt]=='['&&curCh!=']')||(ch[cnt]=='('&&curCh!=')'))
                return false;
        }
        --cnt;
    }
    if(top_pCheck!=-1) return false;
    top_pCheck=-1;
    return true;
}

int main() {
    int n;
    cin>>n;
    char cur;
    int choice;
    for(int i=0;i<n;++i)
    {
        cin>>choice;
        switch (choice)
        {
            case 1:
                cin.get();
                cin.get(cur);
                push(cur);
                break;
            case 2:pop();break;
            case 3:top();break;
            case 4:
            {
                if(isBalance())
                    cout<<"YES\n";
                else cout<<"NO\n";
                break;
            }

            default:break;
        }
    }
    return 0;

}