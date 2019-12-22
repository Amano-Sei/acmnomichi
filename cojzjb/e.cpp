/*************************************************************************
    > File Name: e.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 15时23分03秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;

int a[maxn], b[maxn];

//int gcd(int ca, int cb){
    //return (cb==0)?ca:gcd(cb, ca%cb);
//}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    for(int i = 2; i <= n/2; i++)
        for(int j = 2; i*j <= n; j++)
            if(b[i*(j-1)] > b[i*j]){
                puts("No");
                return 0;
            }
    //for(int i = n; i > 2; i--)
    //    for(int j = b[i]+1; j <= i; j++){
    //        if(gcd(a[j], i) != 1){
    //            puts("No");
    //            return 0;
    //        }
    //        b[a[j]] = j-1;
    //        a[j-1] = a[j];
    //    }
    puts("Yes");
    return 0;
}

