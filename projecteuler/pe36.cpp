/*************************************************************************
    > File Name: pe36.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月13日 星期日 18时37分51秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//其实直接暴搜所有数就可以了，但是因为想练一下回文数构造...

int dnum[6], dlen;
int bnum[20], blen;
long long ans;

void dfs(int ci){
    if(ci == (dlen+1)/2){
        int cnum = 0;
        for(int i = 0; i < dlen; i++)
            cnum = cnum*10+dnum[i];
        blen = 0;
        int tnum = cnum;
        while(tnum){
            bnum[blen++] = tnum & 1;
            tnum >>= 1;
        }
        for(int i = 0; i < blen/2; i++)
            if(bnum[i] != bnum[blen-1-i])
                return;
        ans += cnum;
        printf("%d\n", cnum);
        return;
    }
    for(int i = 0; i < 10; i++){
        dnum[ci] = dnum[dlen-1-ci] = i;
        dfs(ci+1);
    }
}

void getans(){
    for(dlen = 1; dlen <= 6; dlen++)
        for(int i = 1; i < 10; i++){
            dnum[0] = dnum[dlen-1] = i;
            dfs(1);
        }
}


int main(){
    getans();
    printf("%lld\n", ans);
    return 0;
}

