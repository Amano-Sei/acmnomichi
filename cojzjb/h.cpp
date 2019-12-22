/*************************************************************************
    > File Name: h.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月09日 星期一 12时23分52秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int maxn = 100005;

int pre[maxn];
bool book[maxn];
int tot;
int i2c[3];
set<int> lo, le, ro, re;
vector<int> edge[maxn];

int getpre(int x){
    if(pre[x] == 0)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    int n, m, cu, cv;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d", &cu, &cv);
        edge[cu].push_back(cv);
        edge[cv].push_back(cu);
        cu = getpre(cu);
        cv = getpre(cv);
        if(cu != cv)
            pre[cv] = cu;
    }
    for(int i = 1; i <= n; i++){
        cu = getpre(i);
        if(!book[cu]){
            if(tot == 2){
                puts("NO");
                return 0;
            }
            book[cu] = true;
            i2c[tot++] = cu;
        }
        if(edge[i].size()&1){
            if(i2c[0] == cu)
                lo.insert(i);
            else
                ro.insert(i);
        }else{
            if(i2c[0] == cu)
                le.insert(i);
            else
                re.insert(i);
        }
    }
    if(tot == 1){
        if(lo.size() > 4)
            puts("NO");
        else if(lo.size() == 4){
            printf("YES\n%d %d\n", *lo.begin(), *next(lo.begin()));
        }else if(lo.size() == 2){
            cu = *lo.begin();
            if(cu > cv)
                swap(cu, cv);
            printf("YES\n%d %d\n", cu, cv);
            //if(*lo.begin() == 1)
            //    puts("YES\n1 2");
            //else
            //    printf("YES\n1 %d\n", *lo.begin());
        }else
            puts("YES\n1 2");
    }else{
        if(lo.size() > 2 || ro.size() > 2)
            puts("NO");
        else{
            if(lo.size())
                cu = *lo.begin();
            else
                cu = *le.begin();

            if(ro.size())
                cv = *ro.begin();
            else
                cv = *re.begin();
            if(cu > cv)
                swap(cu, cv);
            printf("YES\n%d %d\n", cu, cv);
        }
    }
    return 0;
}

