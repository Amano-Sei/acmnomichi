/*************************************************************************
    > File Name: poj2240.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月25日 星期三 11时02分04秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 35;

char names[maxn][50];
char cname[50];
int n;
double d[maxn][maxn];

bool floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][j] < d[i][k]*d[k][j])
                    d[i][j] = d[i][k]*d[k][j];
    for(int i = 0; i < n; i++)
        if(d[i][i] > 1.0)
            return true;
    return false;
}

int main(){
    int m, caset = 0;
    int cu, cv;
    double trate = 0;
    while(scanf("%d", &n) != EOF && n){
        memset(d, 0, sizeof(d));
        for(int i = 0; i < n; i++)
            scanf("%s", names[i]);
        scanf("%d", &m);
        while(m--){
            scanf("%s", cname);
            for(int i = 0; i < n; i++)
                if(strcmp(cname, names[i]) == 0){
                    cu = i;
                    break;
                }
            scanf("%lf", &trate);
            scanf("%s", cname);
            for(int i = 0; i < n; i++)
                if(strcmp(cname, names[i]) == 0){
                    cv = i;
                    break;
                }
            d[cu][cv] = trate;
        }
        printf("Case %d: %s\n", ++caset, floyd()?"Yes":"No");
    }
}

