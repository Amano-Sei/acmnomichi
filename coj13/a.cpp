/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 20时00分43秒
 ************************************************************************/

#include <cstdio>

const int maxn = 100005;

char s[maxn];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i++)
        if(s[i] == 'G')
            ans++;
    printf("%d\n", ans);
    return 0;
}

