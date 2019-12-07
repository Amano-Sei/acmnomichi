/*************************************************************************
    > File Name: e.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 16时51分11秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
using namespace std;
const int maxn = 40000005;
int que[maxn], head, tail;

void push(int x){
    que[tail] = x;
    tail = (tail+1)%maxn;
}
int pop(){
    if(head == tail)
        return -1;
    int ans = que[head];
    head = (head+1)%maxn;
    return ans;
}

int main(){
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t ct = clock();
    int t, n, m, q, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &q);
        head = tail = 0;
        push(n);
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j < m; j++)
                push(pop());
            push(i);
        }
        for(int i = 0; i < q; i++){
            scanf("%d", &k);
            k = (tail-k+maxn)%maxn;
            printf("%d\n", que[k]);
        }
    }
    ct = clock()-ct;
    cout << CLOCKS_PER_SEC << endl;
    printf("%lf sc(s)\n", (float)ct/CLOCKS_PER_SEC);
	return 0;
}

