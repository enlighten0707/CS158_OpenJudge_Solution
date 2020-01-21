#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int mat[100][100], degree[100];
int main()
{
    int i, j, k, N, u, K;
    char c;
    stack<int> sk;
    while (scanf("%c", &c) != EOF) {
        while (c == ' ' || c == '\n') {
            if (scanf("%c", &c) != 1) return 0;
        }
        scanf("%d", &u);
        N = 1;
        sk.push(u);
        memset(mat, 0, sizeof(mat));
        while (!sk.empty()) {
            while (scanf("%c", &c) && c ==' ');
            if (c == ')') sk.pop();
            else if (c == '(') {
                scanf("%d", &u);
                mat[sk.top()][u] = 1;
                mat[u][sk.top()] = 1;
                sk.push(u);
                N++;
            }
        }/*
        for (i = 1; i <=  N; i++) {
            for (j = 1; j <= N; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }*/
        priority_queue<int, vector<int>, greater<int> > pq;
        memset(degree, 0, sizeof(degree));
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (mat[i][j]) {
                    degree[i]++;
                }
            }
            if (degree[i] == 1) pq.push(i);
        }
        bool first = true;
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            for (i = 1; i <= N; i++) {
                if (mat[t][i]) {
                    mat[t][i] = 0;
                    mat[i][t] = 0;
                    if(--degree[i] == 1)
                        pq.push(i);
                    if (!first) {
                        printf(" ");
                    }
                    first = false;
                    printf("%d", i);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;

}
