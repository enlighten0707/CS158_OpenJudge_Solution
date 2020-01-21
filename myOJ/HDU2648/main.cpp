#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int N=1000007;
const int seed=61;

struct shop{
    int price;
    char name[33];
};

shop shopMap[N][100];
int keyCnt[N];

int Hash(char* str){
    int hash=0;
    while(*str) {
        hash=(hash*seed+(*str-'A'))%N;
        ++str;
    }
    return hash%N;
}

int main() {
    int key;
    char s[35];
    int n,day,x;
    int ans=0,rank;
    for(int i=0;i<N;++i)keyCnt[i]=0;
    while(cin>>n) {
        cin.get();
        for (int i = 0; i < n; ++i) {
            cin.getline(s, 35);
            key = Hash(s);
            shopMap[key][keyCnt[key]].price = 0;
            strcpy(shopMap[key][keyCnt[key]].name, s);
            ++keyCnt[key];
        }
        cin >> day;
        rank = 1;
        for (int i = 0; i < day; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> x;
                cin.get();
                cin.getline(s, 35);
                key = Hash(s) % N;
                for (int k = 0; k < keyCnt[key]; ++k) {
                    if (strcmp(shopMap[key][k].name, s) == 0) {
                        shopMap[key][k].price += x;
                        if (strcmp(s, "memory") == 0)
                            ans = shopMap[key][k].price;
                        break;
                    }
                }
            }

            for (int r = 0; r < N; r++) {
                for (int k = 0; k < keyCnt[r]; k++) {
                    //cout << shopMap[r][k].price << '\n';
                    if (shopMap[r][k].price > ans)rank++;
                }

            }

            cout << rank << '\n';
        }
    }
        return 0;
}
