/*************************************************************************
    > File Name: pe29.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月06日 星期日 20时34分06秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000;

struct tnum{
    int cpow[104];
    int next;
    tnum(){}
    tnum(int *tcpow, int tnext){
        memcpy(cpow, tcpow, sizeof(cpow));
        next = tnext;
    }
}allnum[10000];

int head[maxn];
int tail;
int opow[104];
int tpow[104];
int maxhash;

int gethash(int *cpow){
    int ans = 0;
    for(int i = 2; i < 100; i++)
        ans = (cpow[i]*i+ans)%maxn;
    maxhash = max(ans, maxhash);
    return ans;
}

void push(){
    int chash = gethash(tpow);
    int ci = head[chash];
    while(ci != -1){
        bool flag = true;
        for(int i = 2; i < 98; i++)
            if(allnum[ci].cpow[i] != tpow[i]){
                flag = false;
                break;
            }
        if(flag)
            return;
        ci = allnum[ci].next;
    }
    allnum[tail] = tnum(tpow, head[chash]);
    head[chash] = tail++;
}

int main(){
    memset(head, -1, sizeof(head));
    for(int i = 2; i <= 100; i++){
        memset(opow, 0, sizeof(opow));
        int ti = i;
        for(int j = 2; j < 98 && j <= ti; j++)
            while(ti%j == 0){
                opow[j]++;
                ti /= j;
            }
        memcpy(tpow, opow, sizeof(tpow));
        for(int j = 2; j <= 100; j++){
            for(int k = 2; k < 98; k++)
                tpow[k] += opow[k];
            push();
        }
    }

    printf("%d\n", tail);
    //printf("%d\n", maxhash);

    return 0;
}

