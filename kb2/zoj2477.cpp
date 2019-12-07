/*************************************************************************
    > File Name: zoj2477.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月12日 星期一 07时35分12秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int side[4][3][2] = {{{0, 0}, {0, 1}, {0, 2}}, {{0, 2}, {1, 2}, {2, 2}}, {{2, 2}, {2, 1}, {2, 0}}, {{2, 0}, {1, 0}, {0, 0}}};
int adj[6][4][2] = {{{4, 3}, {1, 3}, {5, 3}, {3, 1}}, {{4, 2}, {2, 3}, {5, 0}, {0, 1}}, {{4, 1}, {3, 3}, {5, 1}, {1, 1}}, {{4, 0}, {0, 3}, {5, 2}, {2, 1}}, {{3, 0}, {2, 0}, {1, 0}, {0, 0}}, {{0, 2}, {1, 2}, {2, 2}, {3, 2}}};
int cntans;
int cans[5][2];
char oricube[6][3][3];

void rotate(int fa, int d, char cube[6][3][3]){
    char tmp[6][3][3];
    memcpy(tmp, cube, sizeof(tmp));
    for(int i = 0; i < 4; i++){
        cube[fa][side[i][0][0]][side[i][0][1]] = tmp[fa][side[(i-d+4)%4][0][0]][side[(i-d+4)%4][0][1]];
        cube[fa][side[i][1][0]][side[i][1][1]] = tmp[fa][side[(i-d+4)%4][1][0]][side[(i-d+4)%4][1][1]];
        for(int j = 0; j < 3; j++)
            cube[adj[fa][i][0]][side[adj[fa][i][1]][j][0]][side[adj[fa][i][1]][j][1]] = tmp[adj[fa][(i-d+4)%4][0]][side[adj[fa][(i-d+4)%4][1]][j][0]][side[adj[fa][(i-d+4)%4][1]][j][1]];
    }
}

bool checkcube(const char cube[6][3][3]){
    char cur;
    for(int i = 0; i < 6; i++){
        cur = cube[i][0][0];
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                if(cube[i][j][k] != cur)
                    return false;
    }
    return true;
}

bool dfs(const char cube[6][3][3], int cnt){
    if(checkcube(cube))
        return true;
    if(cnt >= cntans)
        return false;
    char nxtcube[6][3][3];
    for(int i = 0; i < 6; i++){
        cans[cnt][0] = i;
        for(int j = -1; j < 2; j += 2){
            cans[cnt][1] = j;
            memcpy(nxtcube, cube, sizeof(nxtcube));
            rotate(i, j, nxtcube);
            if(dfs(nxtcube, cnt+1))
                return true;
        }
    }
    return false;
}
char getnbchar(){
    char c = getchar();
    while(!isalpha(c))
        c = getchar();
    return c;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                oricube[4][i][j] = getnbchar();
        for(int j = 0; j < 3; j++)
            for(int i = 0; i < 4; i++)
                for(int k = 0; k < 3; k++)
                    oricube[i][j][k] = getnbchar();
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                oricube[5][i][j] = getnbchar();

        for(cntans = 0; cntans < 6; cntans++)
            if(dfs(oricube, 0))
                break;
        if(cntans < 6){
            printf("%d\n", cntans);
            for(int i = 0; i < cntans; i++)
                printf("%d %d\n", cans[i][0], cans[i][1]);
        }else
            printf("-1\n");
    }
	return 0;
}

