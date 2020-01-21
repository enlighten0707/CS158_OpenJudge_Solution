#include <iostream>

using namespace std;

int a[5003] = { 0 };

int dp_data[5003][5003] = { 0 };
int n;
void quickSort(int a[],int low,int high);
int divide (int a[],int low,int high);
int dp(int pos, int k);

int main() {
    int k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin>>a[i];

    quickSort(a,0,n-1);

    cout << dp(0, k);

    return 0;
}

void quickSort(int a[],int low,int high)
{
    if(low>=high)return;
    int mid;
    mid=divide(a,low,high);
    quickSort(a,low,mid);
    quickSort(a,mid+1,high);
}

int divide (int a[],int low,int high)
{
    int k=a[low];
    do
    {
        while(low<high&&a[high]>=k)--high;
        if(low<high)
        {
            a[low]=a[high];
            low++;
        }
        while(low<high&&a[low]<=k)++low;
        if(low<high)
        {
            a[high]=a[low];
            high--;
        }
    }while(low!=high);
    a[low]=k;
    return low;
}

int dp(int pos, int k) {
    if (pos >= n || k <= 0) {
        return 0;
    }
    if (dp_data[pos][k] > 0)
        return dp_data[pos][k];
    int ans1 = dp(pos + 1, k), ans2 = 0, i = pos;
    for (i=pos; i < n; ++i) {
        if (a[i] - a[pos] <= 5)
            ++ans2;
        else
            break;
    }
    ans2 += dp(i, k - 1);
    dp_data[pos][k] = (ans1 < ans2 ? ans2 : ans1);
    return dp_data[pos][k];
}