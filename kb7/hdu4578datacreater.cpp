/*************************************************************************
    > File Name: hdu4578datacreater.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月05日 星期四 18时33分57秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    freopen("indesu", "w", stdout);
    for(int i = 0; i < 10; i++){
        register int n = 70000+random()%30001;
        register int m = 100000;
        printf("%d %d\n", n, m);
        while(m--){
            register int o = (random()%4)+1;
            register int x = (random()%n)+1;
            register int y = (random()%n)+1;
            if(x > y)
                swap(x, y);
            register int z;
            if(o == 4)
                z = (random()%3)+1;
            else
                z = (random()%10000)+1;
            printf("%d %d %d %d\n", o, x, y, z);
        }
    }
    puts("0 0");
    return 0;
}

