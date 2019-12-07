/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 17时31分26秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 200005;

char s[maxn];

int main(){
    int t;
    long long ans = 0, tans;
    scanf("%d", &t);
    while(t--){
        bool flag = false;
        scanf("%s", s);
        ans = 0;
        tans = 0;
        for(int i = 0; s[i]; i++){
            if(s[i] == '9' && flag)
                tans++;
            else
                tans = 1;
            if(s[i] != '0')
                flag = true;
            ans += tans;
        }
        printf("%lld\n", ans);
    }
}


