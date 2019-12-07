/*************************************************************************
    > File Name: exeuclid.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月13日 星期三 22时28分17秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

int exgcd(int x, int y, int &xi, int &yi){
    if(x == 0){
        xi = 0;
        yi = 1;
        return y;
    }
    int ans = exgcd(y%x, x, yi, xi);
    xi -= y/x*yi;
    return ans;
}

int main(){
    int x = 5, y = 3;
    int xi, yi;
    int ans = exgcd(x, y, xi, yi);
    printf("%d*%d + %d*%d = %d\n", xi, x, yi, y, ans);
    return 0;
}

