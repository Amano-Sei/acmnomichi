#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char acg[4] = {'A', 'C', 'G', 'T'};
char s[8][6];
int n;
int len[8];
int minans, nxtans;
int ps[8];
int acgnt[4], curacgnt[4];
inline int getleastmore(const int *poi){
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, len[i]-poi[i]);
    memset(acgnt, 0, sizeof(acgnt));
    for(int i = 0; i < n; i++){
        memset(curacgnt, 0, sizeof(curacgnt));
        for(int j = poi[i]; j < len[i]; j++)
            for(int k = 0; k < 4; k++)
                if(s[i][j] == acg[k])
                    curacgnt[k]++;
        for(int k = 0; k < 4; k++)
            acgnt[k] = max(acgnt[k], curacgnt[k]);
    }
    ans = max(ans, acgnt[0]+acgnt[1]+acgnt[2]+acgnt[3]);
    return ans;
}
bool dfs(const int *poi, const int clen){
    int npoi[8];
    bool book;
    int leastmore = getleastmore(poi);
    if(leastmore+clen > minans){
        nxtans = min(nxtans, leastmore+clen);
        return false;
    }
    if(leastmore == 0)
        return true;
    for(int i = 0; i < 4; i++){
        book = false;
        memcpy(npoi, poi, sizeof(npoi));
        for(int j = 0; j < n; j++)
            if(s[j][poi[j]]==acg[i]){
                npoi[j]++;
                book = true;
            }
        if(book && dfs(npoi, clen+1))
            return true;
    }
    return false;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", s[i]);
            len[i]=strlen(s[i]);
        }
        minans = getleastmore(ps);
        nxtans = 40;
        while(!dfs(ps, 0)){
            minans = nxtans;
            nxtans = 40;
        }
        printf("%d\n", minans);
    }
	return 0;
}
