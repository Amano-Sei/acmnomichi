/*************************************************************************
    > File Name: hdu4614ctltdatacreater.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月11日 星期三 14时03分09秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    freopen("indesu", "w", stdout);
    register int t = 10;
    printf("%d\n", t);
    while(t--){
        register int n = random()%30001+20000;
        register int m = random()%30001+20000;
        printf("%d %d\n", n, m);
        while(m--){
            register int op = random()%2+1;
            register int ca = random()%n;
            register int cb = random()%n;
            if(op == 2)
                if(ca > cb)
                    swap(ca, cb);
            printf("%d %d %d\n", op, ca, cb);
        }
        putchar('\n');
    }
    return 0;
}

