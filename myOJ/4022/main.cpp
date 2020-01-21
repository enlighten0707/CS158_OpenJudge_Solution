#include <iostream>
using namespace std;

int main() {
    long long n;
    long long cnt=0;
    int day;
    cin>>day>>n;
    long long tmp=n;
    while(n>0)
    {
        if(day==6||day==0)
            ++cnt;
        day=(day+1)%7;
        --n;
    }
    long long res=250*(tmp-cnt);
    cout<<res;
    return 0;
}