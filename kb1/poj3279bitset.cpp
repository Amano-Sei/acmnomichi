#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
const int maxn = 15;
int cnt, mincnt;
int m, n;
bitset<maxn> pad[maxn], ans[maxn], cans[maxn]; 

bool nextbitset(bitset<maxn> &c){
    for(int i = n-1; i >= 0; i--)
        if(c.test(i)){
            c.reset(i);
        }else{
            c.set(i);
            return true;
        }
    return false;
}

int main(){
    unsigned int tmpdesu;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            scanf("%u", &tmpdesu);
            if(tmpdesu)
                pad[i].set(j);
        }
    bitset<maxn> ntmp ((1<<n)-1), tmp;
    mincnt = m*n+1;
    do{
        for(int i = 1; i < m; i++){
            cans[i] = (pad[i-1] ^ cans[i-1] ^ (cans[i-1]<<1) ^ (cans[i-1] >> 1)) & ntmp;
            if(i > 1)
                cans[i] ^= cans[i-2];
        }
        tmp = (pad[m-1] ^ cans[m-1] ^ (cans[m-1] << 1) ^ (cans[m-1] >> 1)) & ntmp;
        if(m > 1)
            tmp ^= cans[m-2];
        if(tmp.none()){
            cnt = 0;
            for(int i = 0; i < m; i++)
                cnt += cans[i].count();
            if(cnt < mincnt){
                memcpy(ans, cans, sizeof(ans));
                mincnt = cnt;
            }
        }
    }while(nextbitset(cans[0]));
    if(mincnt < m*n+1)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                printf("%u%c", ans[i].test(j), j==n-1?'\n':' ');
    else
        printf("IMPOSSIBLE\n");
	return 0;
}

