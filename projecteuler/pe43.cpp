/*************************************************************************
    > File Name: pe43.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月20日 星期日 22时56分15秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pn[7] = { 2, 3 ,5, 7, 11, 13, 17 };
int cnum[10];
bool book[10];
long long ans;

void dfs(int ci){
    if(ci == 10){
        for(int i = 0; i < 7; i++)
            if((cnum[i+1]*100+cnum[i+2]*10+cnum[i+3])%pn[i] != 0)
                return;
        long long tnum = 0;
        for(int i = 0; i < 10; i++)
            tnum = tnum*10+cnum[i];
        ans += tnum;
        printf("%lld\n", tnum);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(book[i])
            continue;
        book[i] = true;
        cnum[ci] = i;
        dfs(ci+1);
        book[i] = false;
    }
}

int main(){
    dfs(0);
    printf("%lld\n", ans);

    return 0;
}

