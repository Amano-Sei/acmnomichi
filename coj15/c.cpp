/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 20时09分53秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 505;

int a[maxn];
bool book[maxn];

int main(){
    int t, n;
    int cnt, cmax, cmin, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(book, 0, sizeof(book));
        ans = cmin = cmax = cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            book[a[i]] = true;
            if(cmin > 0){
                if(a[i] != cmin)
                    cnt = 3;
                else{
                    for(cmin = cmin+1; book[cmin] && cmin < cmax; cmin++);
                    if(cmin == cmax)
                        cmin = 0;
                }
            }
            if(cnt < 3){
                if(a[i-1] < a[i]){
                    if(cnt == 0)
                        ans++;
                }else{
                    cmax = max(cmax, a[i-1]);
                    for(int j = 1; j < a[i]; j++)
                        if(!book[j]){
                            cnt = 3;
                            break;
                        }
                    if(cnt < 3){
                        for(cmin = a[i]+1; cmin < cmax && book[cmin]; cmin++);
                        if(cmin == cmax)
                            cmin = 0;
                        cnt++;
                    }
                }
            }
        }
        switch(cnt){
            case 0:
            case 1:
                printf("0 %d\n", ans);
                break;
            case 2:
                printf("%d %d\n", ans, ans);
                break;
            case 3:
                puts("-1 -1");
                break;
        }
    }
    return 0;
}

