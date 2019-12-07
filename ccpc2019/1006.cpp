/*************************************************************************
    > File Name: 002.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 13时26分34秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;

int n, m;
int lt[maxn], rt[maxn];

void del(int c){
    lt[rt[c]] = lt[c];
    rt[lt[c]] = rt[c];
}

void push_back(int c){
    lt[c] = lt[n+1];
    rt[c] = n+1;
    rt[lt[n+1]] = c;
    lt[n+1] = c;
}

void push_front(int c){
    del(c);
    lt[c] = 0;
    rt[c] = rt[0];
    lt[rt[0]] = c;
    rt[0] = c;
}

int main(){
    int t;
    scanf("%d%d", &n, &m);
    lt[0] = -1;
    rt[0] = n+1;
    lt[n+1] = 0;
    rt[n-1] = n+1;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        push_back(t);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &t);
        push_front(t);
    }
    t = rt[0];
    while(true){
        printf("%d ", t);
        t = rt[t];
        if(t == n+1)
            break;
    }
	return 0;
}

