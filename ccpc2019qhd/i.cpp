/*************************************************************************
    > File Name: i.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月23日 星期一 17时06分29秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
//被杭电多组输入搞自闭了（（（

using namespace std;

const int maxn = 1e6+5;

int dp[maxn][6];
char s[maxn];
char n2s[11] = "YVGCXZTFDB";
int s2n[128];
char se[10][4] = {"QQQ", "QQW", "QQE", "WWW", "QWW", "WWE", "EEE", "QEE", "WEE", "QWE"};
char forde[2][4];
int len[10][10][6][6];
bool book[3];

void decat(int ci, int i, int ii){
    memset(book, 0, sizeof(book));
    book[ii/2] = true;
    forde[ci][0] = se[i][ii/2];
    ii %= 2;
    if(book[0])
        ii++;
    if(book[1] && ii == 1)
        ii++;
    forde[ci][1] = se[i][ii];
    book[ii] = true;
    if(!book[0]){
        forde[ci][2] = se[i][0];
        return;
    }
    if(!book[1]){
        forde[ci][2] = se[i][1];
        return;
    }
    if(!book[2]){
        forde[ci][2] = se[i][2];
        return;
    }
}

void init(){
    for(int i = 0; i < 10; i++)
        s2n[n2s[i]] = i;
    for(int i = 0; i < 10; i++)
        for(int ii = 0; ii < 6; ii++){
            decat(0, i, ii);
            for(int j = 0; j < 10; j++)
                for(int jj = 0; jj < 6; jj++){
                    decat(1, j, jj);
                    if(strcmp(forde[0], forde[1]) == 0)
                        len[i][j][ii][jj] = 1;
                    else if(forde[0][1] == forde[1][0] && forde[0][2] == forde[1][1])
                        len[i][j][ii][jj] = 2;
                    else if(forde[0][2] == forde[1][0])
                        len[i][j][ii][jj] = 3;
                    else
                        len[i][j][ii][jj] = 4;
                    //printf("%s -> %s = %d\n", forde[0], forde[1], len[i][j][ii][jj]);
                }
        }
}

int main(){
    init();
    while(scanf("%s", s) != EOF){
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < 6; i++)
            dp[0][i] = 4;
        int slen;
        for(slen = 1; s[slen]; slen++)
            for(int ci = 0; ci < 6; ci++)
                for(int cj = 0; cj < 6; cj++)
                    dp[slen][ci] = min(dp[slen][ci], dp[slen-1][cj]+len[s2n[s[slen-1]]][s2n[s[slen]]][cj][ci]);

        printf("%d\n", *min_element(&dp[slen-1][0], &dp[slen][0]));
    }

    return 0;
}

