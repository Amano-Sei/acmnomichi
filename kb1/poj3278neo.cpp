/*************************************************************************
    > File Name: poj3278neo.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 00时21分03秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 200005;
int book[maxn];
int q[maxn];
int head, tail;
int n, k;

bool neoadd(int c){
    if(c == k)
        return true;
    if(!book[c]){
        q[tail++] = c;
        book[c] = true;
    }
    return false;
}

int main(){
    int curs = 0;
    scanf("%d%d", &n, &k);
    if(n == k){
        printf("0");
        return 0;
    }
    int curn, lastn = n;
    q[tail++] = n;
    while(true){
        curn = q[head++];
        if(curn < k){
            if(neoadd(curn+1)){
                printf("%d", curs+1);
                break;
            }
            if(neoadd(curn*2)){
                printf("%d", curs+1);
                break;
            }
        }
        if(curn > 0)
            if(neoadd(curn-1)){
                printf("%d", curs+1);
                break;
            }
        if(curn == lastn){
            curs++;
            lastn = q[tail-1];
        }
    }
	return 0;
}

