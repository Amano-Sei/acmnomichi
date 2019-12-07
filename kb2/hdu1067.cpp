/*************************************************************************
    > File Name: hdu1067.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月13日 星期二 01时34分41秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 6e5+43;

struct node{
    char num[32];
    char bl[4];
    int hash, step;
    node(){}
    node(const node &c):hash(c.hash), step(c.step){
        memcpy(num, c.num, sizeof(num));
        memcpy(bl, c.bl, sizeof(bl));
    }
    
} book[maxn+1], sp, tans;

queue<int> q;
char findbook[48];

int gethash(node &c){
    if(!c.hash){
        for(int i = 0; i < 32; i++)
            c.hash = (c.hash*2+c.num[i]) % maxn;
        c.hash++;
    }
    return c.hash;
}
void push(node &c){
    int ins = gethash(c);
    bool hasins;
    while(book[ins].hash){
        hasins = book[ins].hash==c.hash;
        if(hasins){
            for(int i = 0; i < 32; i++)
                if(book[c.hash].num[i] != c.num[i]){
                    hasins = false;
                    break;
                }
            if(hasins)
                return;
        }
        ins = ins * 10 % maxn;
    }
    book[ins] = node(c);
    q.push(ins);
}

bool checkans(node &c){
    if(gethash(c) == gethash(tans)){
        for(int i = 0; i < 32; i++)
            if(c.num[i] != tans.num[i])
                return false;
        return true;
    }
    return false;
}

void bfs(){
    while(!q.empty()){
        node cur = book[q.front()];
        q.pop();
        memset(findbook, 0, sizeof(findbook));
        //putchar('\n');
        //for(int i = 0; i < 4; i++){
        //    for(int j = 0; j < 8; j++)
        //        printf("%d ", cur.num[i*8+j]);
        //    putchar('\n');
        //}

        for(int i = 0; i < 4; i++)
            if((cur.num[cur.bl[i]-1]+1) % 10 < 8) 
                findbook[cur.num[cur.bl[i]-1]+1] = i+1;
        for(int i = 0; i < 32; i++)
            if(findbook[cur.num[i]]){
                node neo = node(cur);
                neo.hash = 0;
                neo.step++;
                neo.num[cur.bl[findbook[cur.num[i]]-1]] = neo.num[i];
                neo.bl[findbook[cur.num[i]]-1] = i;
                neo.num[i] = 0;
                if(checkans(neo)){
                    printf("%d\n", neo.step);
                    return;
                }else
                    push(neo);
            }
    }
    printf("-1\n");
}

int main(){
    int n, tmp;
    int quo, rem;
    scanf("%d", &n);
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 7; j++)
            tans.num[(i-1)*8+j-1] = i*10+j;
    while(n--){
        memset(book, 0, sizeof(book));
        while(!q.empty())
            q.pop();
        sp.hash = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 1; j <= 7; j++){
                scanf("%d", &tmp);
                sp.num[i*8+j] = (char)tmp;
                quo = sp.num[i*8+j]/10-1;
                rem = sp.num[i*8+j]%10;
                if(rem == 1){
                    sp.num[quo*8] =  sp.num[i*8+j];
                    sp.bl[quo] = i*8+j;
                    sp.num[i*8+j] = 0;
                }
            }
        if(checkans(sp)){
            printf("0\n");
            continue;
        }
        push(sp);
        bfs();
    }
	return 0;
}

