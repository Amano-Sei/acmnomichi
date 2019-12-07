/*************************************************************************
    > File Name: hdu1067rebuild.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月02日 星期一 21时26分38秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5e5+41;

struct node{
    char num[32];
    int bl[4];
    int sp;
    int hash;
    node(){
        hash = 0;
    }
    node(int *cnum){
        //memcpy(num, cnum, sizeof(num));
        int bli = 0;
        for(int i = 0; i < 32; i++)
            if(!(num[i] = cnum[i]))
                bl[bli++] = i;
        hash = 0;
    }
    node(const node &c){
        memcpy(num, c.num, sizeof(num));
        memcpy(bl, c.bl, sizeof(bl));
        hash = c.hash;
        sp = c.sp;
    }
}an[maxn+1];
int q[maxn];
int head, tail;
int book[50];
int sdd[32] = {11, 12, 13, 14, 15, 16, 17, 0, 21, 22, 23, 24, 25, 26, 27, 0, 31, 32, 33, 34, 35, 36, 37, 0, 41, 42, 43, 44, 45, 46, 47, 0};
node endgame = node(sdd);

int gethash(node &c){
    if(c.hash == 0){
        for(int i = 0; i < 32; i++)
            c.hash = (c.hash*2+c.num[i])%maxn;
        c.hash++;
    }
    return c.hash;
}

bool checkequal(node &a, node &b){
    if(gethash(a) != gethash(b))
        return false;
    for(int i = 0; i < 32; i++)
        if(a.num[i] != b.num[i])
            return false;
    return true;
}

bool push(node &c){
    int ini = gethash(c);
    while(an[ini].hash){
        if(checkequal(an[ini], c))
            return false;
        ini = ini * 4 % maxn;
    }
    an[ini] = node(c);
    q[tail++] = ini;
    return true;
}

void bfs(){
    while(head != tail){
        node cur = node(an[q[head++]]);
        memset(book, 0, sizeof(book));
        for(int i = 0; i < 4; i++)
            book[cur.num[cur.bl[i]-1]+1] = i+1;
        for(int i = 0; i < 32; i++){
            int tn = cur.num[i];
            if(book[tn]){
                node neo = node(cur);
                neo.num[cur.bl[book[tn]-1]] = tn;
                neo.bl[book[tn]-1] = i;
                neo.num[i] = 0;
                neo.sp++;
                neo.hash = 0;
                if(checkequal(neo, endgame)){
                    printf("%d\n", neo.sp);
                    return;
                }
                push(neo);
            }
        }
    }
    printf("-1\n");
}

int main(){
    int n, tt;
    scanf("%d", &n);
    while(n--){
        node st = node();
        head = tail = 0;
        memset(an, 0, sizeof(an));
        for(int i = 0; i < 4; i++)
            for(int j = 1; j <= 7; j++){
                scanf("%d", &tt);
                if(tt % 10 == 1){
                    st.num[tt/10*8-8] = tt;
                    st.bl[tt/10-1] = i*8+j;
                    tt = 0;
                }
                st.num[i*8+j] = tt;
            }
        st.sp = 0;
        if(checkequal(st, endgame)){
            printf("0\n");
            continue;
        }
        push(st);
        bfs();
    }
	return 0;
}

