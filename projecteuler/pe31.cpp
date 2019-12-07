/*************************************************************************
    > File Name: pe31.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月08日 星期二 20时31分49秒
 ************************************************************************/

#include <cstdio>

int pens[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int ans, csum;

void dfs(int ci){
    if(ci == 8){
        if(csum == 200)
            ans++;
        return;
    }
    int maxc = (200-csum)/pens[ci];
    dfs(ci+1);
    for(int i = 1; i <= maxc; i++){
        csum+=pens[ci];
        dfs(ci+1);
    }
    csum -= pens[ci]*maxc;
}

int main(){
    dfs(0);
    printf("%d\n", ans);

    return 0;
}

