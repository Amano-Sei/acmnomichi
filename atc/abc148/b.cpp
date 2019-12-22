/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月22日 星期日 21时08分16秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

char s[105], t[105];

int main(){
    int n;
    scanf("%d%s%s", &n, s, t);
    for(int i = 0; i < n; i++){
        putchar(s[i]);
        putchar(t[i]);
    }
    return 0;
}

