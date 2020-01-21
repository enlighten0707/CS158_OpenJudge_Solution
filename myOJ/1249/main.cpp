#include <iostream>
using namespace std;

const int MAXSIZE=10000;
struct fraction
{
    int nume;
    int deno;
};

fraction num[MAXSIZE];


int gcb(int a,int b)
{
    if(!b)
        return a;
    else
        return gcb(b,a%b);
}
int divide(int low,int high)
{
    fraction k=num[low];
    while(low<high)
    {
        while(low<high&&num[high].nume*k.deno>num[high].deno*k.nume)--high;
        if(low<high)
        {
            num[low]=num[high];
            ++low;
        }
        while(low<high&&num[low].nume*k.deno<num[low].deno*k.nume)++low;
        if(low<high)
        {
            num[high]=num[low];
            --high;
        }
    }
    num[low]=k;
    return low;
}
void quickSort(int low,int high)
{
    if(low>=high)return ;
    int mid=divide(low,high);
    quickSort(low,mid-1);
    quickSort(mid+1,high);
}



int main() {
    int N;
    cin>>N;
    int k=0;
    for(int i=2;i<=N;++i)
    {
        for(int j=i-1;j>=1;--j)
        {
            if(gcb(i,j)==1)
            {
                num[k].deno=i;
                num[k].nume=j;
                ++k;
            }
        }
    }

    quickSort(0,k-1);

    cout<<"0/1\n";
    for(int i=0;i<k;++i)
        cout<<num[i].nume<<'/'<<num[i].deno<<'\n';
    cout<<"1/1\n";
    return 0;
}


