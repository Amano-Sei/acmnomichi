/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 13时16分39秒
 ************************************************************************/

#include <cstdio>

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        while(n%2 == 0)
            n/=2;
        while(n%5 == 0)
            n/=5;
        printf("%s", n==1?"No\n":"Yes\n");
    }
    return 0;
}

