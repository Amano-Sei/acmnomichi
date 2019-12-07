/*************************************************************************
    > File Name: vj1779.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月20日 星期三 20时08分20秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;

struct Node{
    int a, b;
}node[maxn];

int ans[maxn];
int anslen;
int ca[maxn];
int calen;
int tans[maxn];
int tanslen;

bool cmp(const Node &x, const Node &y){
    return max(x.a*x.b, y.b) < max(y.a*y.b, x.b);
}

int main(){
    int n;
    anslen = 1;
    ans[0] = 0;
    calen = 1;
    scanf("%d", &n);
    scanf("%d%d", &ca[0], &node[0].b);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &node[i].a, &node[i].b);
    sort(node, &node[n], cmp);
    for(int i = 0; i < n; i++){
        long long cc = 0;
        for(int j = calen-1; j >= 0; j--){
            cc = cc*10000+ca[j];
            tans[j] = cc/node[i].b;
            cc %= node[i].b;
        }
        for(tanslen = calen; tanslen > 1 && tans[tanslen-1] == 0; tanslen--);
        if(tanslen > anslen){
            memcpy(ans, tans, sizeof(ans));
            anslen = tanslen;
        }else if(tanslen == anslen){
            for(int j = tanslen-1; j >= 0; j--)
                if(tans[j] > ans[j]){
                    memcpy(ans, tans, sizeof(ans));
                    anslen = tanslen;
                    break;
                }else if(tans[j] < ans[j])
                    break;
        }
        cc = 0;
        for(int j = 0; j < calen; j++){
            cc = cc+ca[j]*node[i].a;
            ca[j] = cc%10000;
            cc /= 10000;
        }
        while(cc){
            ca[calen++] = cc%10000;
            cc /= 10000;
        }
    }
    printf("%d", ans[anslen-1]);
    for(int i = anslen-2; i >= 0; i--)
        printf("%04d", ans[i]);
    putchar('\n');
    return 0;
}

