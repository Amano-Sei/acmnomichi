/*************************************************************************
    > File Name: dlx.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月14日 星期六 23时17分31秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 9;
const int MaxN = N*N*N + 10;
const int MaxM = N*N*4 + 10;
const int maxnode = MaxN*4 + MaxM + 10;

char g[MaxN];

struct DLX{
    int n, m, size;
    int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
    int H[MaxN], S[MaxM];
    int ansd, ans[MaxN];

    void init(int _n, int _m){
        n = _n;
        m = _m;
        for(int i = 0; i <= m; i++){
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0;
        L[0] = m;
        size = m;
        for(int i = 1; i <= n; i++)
            H[i] = -1;
    }

    void Link(int r, int c){
        ++S[Col[++size] = c];
        Row[size] = r;
        U[size] = c;
        D[size] = D[c];
        U[D[c]] = size;
        D[c] = size;
        if()
    }
}dlx;

void place(int &r, int &c1, int &c2, int &c3, int &c4, int i, int j, int k){
    r = (i*N+j)*N + k;
    c1 = i*N+j+1;
    c2 = N*N + i*N + k;
    c3 = N*N*2 + j*N + k;
    c4 = N*N*3 + (i/3*3 + j/3)*N + k;
}

int main(){
    while(scanf("%s", g) == 1){
        if(strcmp(g, "end") == 0)
            break;
        dlx.init(N*N*N, N*N*4);
        int r, c1, c2, c3, c4;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 1; k <= N; k++)
                    if(g[i*N+j] == '.' || g[i*N+j] == '0'+k){
                        place(r, c1, c2, c3, c4, i, j, k);
                        dlx.link(r, c1);
                        dlx.link(r, c2);
                        dlx.link(r, c3);
                        dlx.link(r, c4);
                    }
    }
	return 0;
}

