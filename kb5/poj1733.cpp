/*************************************************************************
    > File Name: poj1733.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月10日 星期日 11时28分21秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//本来想离散化，但是发觉离散化完之后想映射回来还是要用map，所以干脆直接用map写并查集好了
//然而现实是，性能极差...
//所以依次尝试下其他各种离散化什么的

map<int, int> pre;
map<int, int> w;

int getmyw(int x){
    if(w.count(x) == 0)
        return 0;
    return w[x];
}

int getpre(int x){
    if(pre.count(x) == 0)
        return x;
    int tx = getpre(pre[x]);
    w[x] ^= getmyw(pre[x]);
    return pre[x] = tx;
}

int main(){
    int n, m, cu, cv;
    char cs[10];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%s", &cu, &cv, cs);
        cu--;
        int tu = getpre(cu);
        int tv = getpre(cv);
        if(tu != tv){
            pre[tu] = tv;
            w[tu] = getmyw(cu)^getmyw(cv)^(cs[0]=='o');
        }else if((getmyw(cu)^getmyw(cv)) != (cs[0]=='o')){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", m);
    return 0;
}

