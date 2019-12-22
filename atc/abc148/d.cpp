/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月22日 星期日 21时15分29秒
 ************************************************************************/

#include <cstdio>

int main(){
    int ca = 1, n, ta;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ta);
        if(ta == ca)
            ca++;
    }
    if(ca == 1)
        puts("-1");
    else
        printf("%d\n", n-ca+1);
    return 0;
}

