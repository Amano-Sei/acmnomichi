/*************************************************************************
    > File Name: pe25.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月02日 星期三 23时10分33秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int fib[10000][1005];

int getans(){
    fib[1][0] = 1;
    fib[1][1] = 1;
    fib[2][0] = 1;
    fib[2][1] = 1;
    for(int i = 3; i < 10000; i++){
        int cc = 0;
        fib[i][0] = fib[i-1][0];
        for(int ci = 1; ci <= fib[i][0]; ci++){
            fib[i][ci] = fib[i-1][ci]+fib[i-2][ci]+cc;
            cc = fib[i][ci]/10;
            fib[i][ci] %= 10;
        }
        while(cc){
            fib[i][++fib[i][0]] = cc%10;
            cc /= 10;
        }
        printf("%d %d\n", i, fib[i][0]);
        if(fib[i][0] >= 1000)
            return i;
    }
    return -1;
}

int main(){
    printf("%d\n", getans());

    return 0;
}


