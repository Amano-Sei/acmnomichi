/*************************************************************************
    > File Name: pe61.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月07日 星期四 18时38分46秒
 ************************************************************************/

#include <cstdio>
#include <vector>

using namespace std;

//基本思路是预处理确认所有的数字的前两位，分别存在一个vector里面方便搜索
//其实感觉不预处理直接爆搜问题也不大...
//为了确认专门写了一遍不预处理的，结果如我所料（嘛，毕竟数据量很小嘛

vector<int> allp[9];
//vector<int> endwith[9][100];
vector<int> startwith[9][100];
bool book[9];

inline int getpen(int i, int k){
    return ((k-2)*i-k+4)*i/2;
}

void init(){
    for(int k = 3; k <= 8; k++){
        //printf("\n%d:\n", k);
        for(int i = 1; ; i++){
            int t = getpen(i, k);
            if(t >= 10000)
                break;
            else if(t >= 1000){
                //printf("%d ", t);
                startwith[k][t/100].push_back(t);
                //endwith[k][t%100].push_back(t);
                allp[k].push_back(t);
            }
        }
    }
}

int ans;
int stk[10];

void dfs(int ci, int cs, int le){
    if(ci == 6){
        if(cs == le){
            for(int i = 0; i < 6; i++){
                printf("%d ", stk[i]);
                ans += stk[i];
            }
            putchar('\n');
        }
        return;
    }
    for(int k = 3; k < 8; k++)
        if(!book[k] && startwith[k][cs].size()){
            book[k] = true;
            for(int i = 0; i < startwith[k][cs].size(); i++){
                stk[ci] = startwith[k][cs][i];
                dfs(ci+1, startwith[k][cs][i]%100, le);
            }
            book[k] = false;
        }
}

void getans(){
    for(int i = 10; i < 100; i++)
        for(int j = 0; j < startwith[8][i].size(); j++){
            stk[0] = startwith[8][i][j];
            dfs(1, stk[0]%100, i);
        }
}

int tans;

void tdfs(int ci, int cs, int le){
    if(ci == 6){
        if(cs == le){
            for(int i = 0; i < 6; i++){
                printf("%d ", stk[i]);
                tans += stk[i];
            }
            putchar('\n');
        }
        return;
    }
    for(int k = 3; k < 8; k++)
        if(!book[k]){
            book[k] = true;
            for(int i = 0; i < allp[k].size(); i++){
                if(allp[k][i]/100 == cs){
                    stk[ci] = allp[k][i];
                    tdfs(ci+1, allp[k][i]%100, le);
                }
            }
            book[k] = false;
        }
}

void tgetans(){
    for(int i = 0; i < allp[8].size(); i++){
        stk[0] = allp[8][i];
        tdfs(1, stk[0]%100, stk[0]/100);
    }
}


int main(){
    init();
    getans();
    printf("ans: %d\n", ans);
    tgetans();
    printf("tans: %d\n", tans);

    return 0;
}

