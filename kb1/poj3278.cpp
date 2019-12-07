/*************************************************************************
    > File Name: poj3278.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月05日 星期一 18时14分22秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node{
    int x, c;
    Node(int x, int c) : x(x), c(c){}
    Node(){}
}node;

const int maxn = 200005;
int n, k;
bool book[maxn];
queue<node> q;

bool checkbound(const node &c){
    return c.x >= 0 && (c.x < k*2 || c.x < n) && !book[c.x];
}

int main(){
    scanf("%d%d", &n, &k);
    if(n == k){
        printf("0");
        return 0;
    }
    book[n] = true;
    node cur;
    q.push(node(n, 0));
    while(!q.empty()){
        cur = q.front();
        q.pop();
        cur.c++;
        cur.x += 1;
        if(checkbound(cur)){
            if(cur.x == k){
                printf("%d", cur.c);
                return 0;
            }
            book[cur.x] = true;
            q.push(cur);
        }
        cur.x -= 2;
        if(checkbound(cur)){
            if(cur.x == k){
                printf("%d", cur.c);
                return 0;
            }
            book[cur.x] = true;
            q.push(cur);
        }
        cur.x = cur.x*2+2;
        if(checkbound(cur)){
            if(cur.x == k){
                printf("%d", cur.c);
                return 0;
            }
            book[cur.x] = true;
            q.push(cur);
        }
    }
	return 0;
}

