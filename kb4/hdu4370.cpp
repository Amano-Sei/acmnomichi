/*************************************************************************
    > File Name: hdu4370.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 18时15分35秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 305;

int d[maxn][maxn];

inline void floyd(int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++){
            int t = d[i][k];
            for(int j = 0; j < n; j++)
                if(d[i][j] > t+d[k][j])
                    d[i][j] = t+d[k][j];
        }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &d[i][j]);
        d[0][0] = d[n-1][n-1] = 0x3f3f3f3f;
        floyd(n);
        printf("%d\n", min(d[0][0]+d[n-1][n-1], d[0][n-1]));
    }
    return 0;
}

