/*************************************************************************
    > File Name: pe28.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月05日 星期六 23时12分39秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int num[maxn][maxn];
int step[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

int main(){
    //int n = 1001;
    int n = 9;
    int cx = n/2, cy = n/2;
    int cnum = 0;
    num[cx][cy] = ++cnum;
    for(int i = 1; i <= n/2; i++){
        cx++;
        cy--;
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 2*i; k++){
                cx += step[j][0];
                cy += step[j][1];
                num[cx][cy] = ++cnum;
            }
    }

    long long ans = -1;
    for(int i = 0; i < n; i++)
        ans += num[i][i]+num[i][n-1-i];
    printf("%lld\n", ans);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%2d ", num[j][i]);
        putchar('\n');
    }

    return 0;
}
                

