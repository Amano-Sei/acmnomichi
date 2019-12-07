/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 17时12分46秒
 ************************************************************************/

#include <cstdio>

char s[25][25];

int main(){
    int t, n, m;
    int cx, cy, lx;
    scanf("%d", &t);
    while(t--){
        bool hasout = false;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%s", s[i]);
            bool flag = true;
            for(int j = 0; j < m; j++)
                if(s[i][j] == '.'){
                    flag = false;
                    if(!hasout){
                        hasout = true;
                        cx = i+1;
                        cy = j+1;
                    }
                    break;
                }
            if(flag && hasout){
                hasout = false;
                lx = i+1;
            }
        }
        if(hasout)
            lx = n;
        printf("%d %d %d\n", (lx-cx)/2, (lx+cx)/2, cy);
    }
    return 0;
}

