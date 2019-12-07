/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月10日 星期日 09时32分38秒
 ************************************************************************/

#include <cstdio>

const int maxn = 100005;

int a[maxn];
int b[maxn];

int main(){
    int t, n;
    int ans, cnt, csum;
    int ci;
    scanf("%d", &t);
    while(t--){
        ci = ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for(int i = 0; i < n; i++){
            csum = cnt = 0;
            while(ci < n && csum < b[i]){
                if(a[ci] != 0)
                    cnt++;
                csum += a[ci++];
            }
            if(csum != b[i]){
                ans = -1;
                break;
            }
            if(cnt > 1 || cnt == 1 && ci-1 != i)
                ans++;
        }
        while(ci < n)
            if(a[ci++] != 0){
                ans = -1;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}

