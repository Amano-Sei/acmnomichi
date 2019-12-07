/*************************************************************************
    > File Name: lightoj1074.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 23时51分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

//本能地抗拒用spfa判负环...所以写成了这样，但是很遗憾，我对于环的理解还不够深刻...
//所以用栈写的那个判负环还存在问题...
//而且还有一个问题，经过n步可达的负环一定会在n次松弛中出现么，越来越觉得这道题或许应该用floyd来写...
//上面这个问题我想应该是会的
//都已经因为不服气写了三种方法了，虽然有一种是错的，但是最后用栈完成的那个我想留待tarjan或者一两天之后再看...
//emmm这里给了自己一个大教训，floyd在有负边的时候不能直接加...要先判断（

const int maxn = 205;
const int inf = 0x3f3f3f3f;

int n;
int bsn[maxn];
int d[maxn][maxn];

void init(){
    memset(d, 0x3f, sizeof(d));
}
bool book[maxn];
void neofloyd(){
    memset(book, 0, sizeof(book));
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k] < inf && d[k][j] < inf && d[i][j] > d[i][k]+d[k][j])
                    d[i][j] = d[i][k]+d[k][j];
    for(int i = 1; i <= n; i++)
        if(d[i][i] < 0 && d[1][i] != inf){
            book[i] = true;
            for(int j = 1; j <= n; j++)
                if(d[i][j] != inf)
                    book[j] = true;
        }
}

int main(){
    int t, m, cu, cv, cw;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        init();
        printf("Case %d:\n", caset);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &bsn[i]);
        scanf("%d", &m);
        while(m--){
            scanf("%d%d", &cu, &cv);
            cw = bsn[cv]-bsn[cu];
            d[cu][cv] =  cw*cw*cw;
        }
        neofloyd();
        scanf("%d", &m);
        while(m--){
            scanf("%d", &cv);
            if(!book[cv] && d[1][cv] != inf && d[1][cv] >= 3)
                printf("%d\n", d[1][cv]);
            else
                printf("?\n");
        }
    }
    return 0;
}

