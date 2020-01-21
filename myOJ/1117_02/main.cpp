
#include <iostream>

#include <cstdio>

#include <string>

#include <cstring>

#include <stack>

using namespace std;

const int maxn = 20000;

int fa[maxn];

int son[maxn];

int mark[maxn];

int main()

{

    string str;

    stack<int> s;

    while(getline(cin,str)){

        memset(fa,-1,sizeof(fa));

        memset(son,0,sizeof(son));

        memset(mark,0,sizeof(mark));

        int len = str.length() - 1;

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

                s.push(num);

            }

            else if(str[i] == ')'){

                int num = s.top();

                s.pop();

                fa[num] = s.top();

                son[s.top()]++;

            }

        }

        while(!s.empty()) s.pop();

        for(int i = 1; i < MAX; ++i){

            int MIN = 99999999;

            for(int j = 1; j < MAX; ++j){

                if(mark[j] == 0 && (son[j] == 0 ||(fa[j] == -1 && son[j] == 1)))

                    if(j < MIN)

                        MIN = j;

            }

            // cout<<MIN<<endl;

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

        putchar('\n');

    }

    return 0;

}
