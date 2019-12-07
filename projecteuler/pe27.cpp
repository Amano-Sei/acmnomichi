/*************************************************************************
    > File Name: pe27.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月05日 星期六 05时52分35秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2001005;

bool isp[maxn];
int allpq[maxn], tail;

void init(){
    isp[2] = true;
    allpq[tail++] = 2;
    for(int i = 3; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < tail && allpq[j]*allpq[j] <= i; j++)
            if(i%allpq[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            isp[i] = true;
            allpq[tail++] = i;
        }
    }
}

int calc(int n, int a, int b){
    return n*n+a*n+b;
}

int getans(){
    int ans = 0, cmax = 0;
    for(int ca = -999; ca < 1000; ca++)
        for(int bi = 0, cb = allpq[bi]; cb <= 1000; bi++, cb=allpq[bi]){
            int clen = 0, ccalc;
            while((ccalc=calc(clen, ca, cb))>0 && isp[ccalc])
                clen++;
            if(cmax <= clen){
                //printf("%d %d\n", ca, cb);
                cmax = clen;
                ans = ca*cb;
            }
        }
    return ans;
}

int main(){
    init();
    printf("%d\n", getans());
    return 0;
}

