/*************************************************************************
    > File Name: hdu1540.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月02日 星期一 11时35分19秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

//因为两天没看线段树了...拿到题有点蒙...
//第一感觉这个线段树存啥，咋写...
//二话不说写个了set的解出来（
//莫名wa了（看评论，发觉多组输入，行吧（

const int maxn = 50005;

int sk[maxn], tot;

int main(){
    int n, m, cx;
    char op[4];
    while(scanf("%d%d", &n, &m) != EOF){
        tot = 0;
        set<int> desp;
        desp.insert(0);
        desp.insert(n+1);
        while(m--){
            scanf("%s", op);
            if(op[0] == 'R')
                desp.erase(sk[--tot]);
            else{
                scanf("%d", &cx);
                if(op[0] == 'D'){
                    desp.insert(cx);
                    sk[tot++] = cx;
                }else{
                    register set<int>::const_iterator it = desp.lower_bound(cx);
                    register int rt = *it;
                    if(rt == cx)
                        puts("0");
                    else{
                        rt -= *(--it)+1;
                        printf("%d\n", rt);
                    }
                }
            }
        }
    }
    return 0;
}

