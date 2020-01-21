#include <iostream>
using namespace std;

const int MAXSIZE=1003;
int come[MAXSIZE],go[MAXSIZE],stack[MAXSIZE];
int n,m;
int top_p=-1;

bool isPossible()
{
    int curCome=0,curGo=0;
    while(curGo<n)
    {
        if(curCome>=n||come[curCome]>go[curGo])
        {
            if(go[curGo]==stack[top_p])
                --top_p;
            else return false;
        }
        else if(come[curCome]==go[curGo])
        {
            ++curCome;
            ++curGo;
        }
        else if(come[curCome]<go[curGo])
        {
            if(top_p==m-1) return false;
            ++top_p;
            stack[top_p]=come[curCome];
            ++curCome;
        }
        ++curGo;
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>n>>m;
        for(int j=0;j<n;++j)
            come[j]=j;
        for(int j=0;j<n;++j)
            cin>>go[j];
        if(isPossible())
            cout<<"YES\n";
        else cout<<"NO\n";

        top_p=-1;
    }
    return 0;
}
