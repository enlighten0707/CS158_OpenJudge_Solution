#include <iostream>
using namespace std;

const int MAXSIZE=1003;
int go[MAXSIZE],stack[MAXSIZE];
int n,m;
int pos=0,top_p=-1;

bool isPossible()
{
    pos=0;
    int i=0;
    while(i<n)
    {
        if(go[i]==pos)
        {
            ++pos;++i;
        }
        else if(go[i]<pos)
        {
            if(top_p==-1)return false;
            if(go[i]!=stack[top_p])return false;
            ++i;
            --top_p;
        }
        else
        {
            ++top_p;
            if(top_p==m) return false;
            stack[top_p]=pos;
            ++pos;
        }
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
            cin>>go[j];
        if(isPossible())
            cout<<"YES\n";
        else cout<<"NO\n";
        top_p=-1;
    }
    return 0;
}
