/*************************************************************************
    > File Name: 003.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 13时42分45秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char ans[10][1024][1025];
int len[10];

int main(){
    strcpy(ans[0][0], "CC");
    strcpy(ans[0][1], "PC");
    len[0] = 2;
    for(int i = 1; i < 10; i++){
        len[i] = len[i-1] << 1;
        for(int j = 0; j < len[i-1]; j++){
            strcpy(ans[i][j], ans[i-1][j]);
            strcpy(&ans[i][j][len[i-1]], ans[i-1][j]);
        }
        for(int j = len[i-1], p = 0; p < len[i-1]; j++, p++){
            for(int k = 0; k < len[i-1]; k++)
                ans[i][j][k] = (ans[i-1][p][k] > 'C'?'C':'P');
            strcpy(&ans[i][j][len[i-1]], ans[i-1][p]);
        }
    }
    int t, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &k);
        for(int i = 0; i < len[k-1]; i++)
            printf("%s\n", ans[k-1][i]);
    }
	return 0;
}

