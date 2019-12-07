/*************************************************************************
    > File Name: hdu1560bfs.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月12日 星期一 02时48分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1679616;

struct node{
    int cpoi[8];
    int clen;
    node(){}
    node(int *poi, int clen):clen(clen){
        memcpy(cpoi, poi, sizeof(cpoi));
    }
} q[maxn];

bool book[maxn];
char acg[5] = "ACGT";
char s[8][6];
int head, tail;
int n;
int lasthash;

int gethash(int *poi){
    int ans = poi[0];
    for(int i = 1; i < n; i++)
        ans = ans*6+poi[i];
    return ans;
}

void bfs(){
    bool cando;
    head = tail = 0;
    int cpoi[8] = {0}, nhash, nlen;
    memset(book, 0, sizeof(book));
    q[tail++] = node(cpoi, 0);
    while(head != tail){
        node cur = q[head++];
        for(int i = 0; i < 4; i++){
            cando = false;
            memcpy(cpoi, cur.cpoi, sizeof(cpoi));
            for(int j = 0; j < n; j++)
                if(s[j][cur.cpoi[j]] == acg[i]){
                    cando = true;
                    cpoi[j]++;
                }
            if(cando && !book[nhash=gethash(cpoi)]){
                nlen = cur.clen+1;
                if(nhash == lasthash){
                    printf("%d\n", nlen);
                    return;
                }
                book[nhash] = true;
                q[tail++] = node(cpoi, nlen);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        lasthash = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", s[i]);
            lasthash = lasthash*6+strlen(s[i]);
        }
        bfs();
    }
	return 0;
}
