/*************************************************************************
    > File Name: hdu3974pre.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月04日 星期三 16时19分28秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50005;

int pre[maxn];
int ct[maxn], cj[maxn];

int main(){
    int t, n, cu, cv;
    char op[12];
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        printf("Case #%d:\n", caset);
        scanf("%d", &n);
        memset(pre, -1, sizeof(pre));
        memset(ct, 0, sizeof(ct));
        for(int i = 1; i < n; i++){
            scanf("%d%d", &cu, &cv);
            pre[cu] = cv;
        }
        scanf("%d", &n);
        register int tt = 0;
        while(n--){
            scanf("%s%d", op, &cu);
            if(op[0] == 'C'){
                register int mt = 0;
                register int mj = -1;
                while(cu != -1){
                    if(ct[cu] > mt){
                        mt = ct[cu];
                        mj = cj[cu];
                    }
                    cu = pre[cu];
                }
                printf("%d\n", mj);
            }else{
                scanf("%d", &cv);
                cj[cu] = cv;
                ct[cu] = ++tt;
            }
        }
    }
    return 0;
}
