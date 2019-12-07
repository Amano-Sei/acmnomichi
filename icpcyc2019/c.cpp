/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月31日 星期六 15时06分03秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char o[55], cur[55];

int main(){
    int t, n, m;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        scanf("%d%d", &n, &m);
        scanf("%s%s", o, cur);
        n = o[0]-cur[0];
        scanf("%s", cur);
        printf("Case #%d: ", caset);
        for(int i = 0; i < m; i++)
            putchar('A'+((cur[i]-'A'+n+26)%26));
        putchar('\n');
    }
	return 0;
}

