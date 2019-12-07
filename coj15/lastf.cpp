/*************************************************************************
    > File Name: lastf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 16时53分06秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

//原本思路是@twytch19 dalao的，我看了dalao一天的代码...终于好像看明白了...
//（小声）当然没有经过dalao允许（只是我单方面在看QAQ
//基于反过来两种映射基本上是一样的，修改了dalao的代码
//基本思路是顺过来贪心A，逆过来贪心C/B，能撞到一起就是有解
//同时贪心C/B会得出最小解

//PS:交之前验证了10的排序数，没有问题...应该可以A（嗯...

//想得脑壳疼...终于可以让contest #15告一段落了...

const int maxn = 200005;

int a[maxn];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        register int maxans = n;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(maxans >= i && a[i] < a[i-1])
                maxans = i-1;
        }
        register int minans;
        if(maxans < n){
            minans = n;
            for(int cc = n, cmax = n; minans > 0; minans--){
                if(a[minans] == cc)
                    cc--;
                else if(a[minans] > cmax)
                    break;
                else
                    cmax = a[minans];
            }
        }else
            minans = 0;
        if(minans > maxans)
            puts("-1 -1");
        else
            printf("%d %d\n", minans, maxans);
    }

    return 0;
}

