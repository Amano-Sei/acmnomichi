/*************************************************************************
    > File Name: pe47.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月24日 星期四 23时11分30秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 10000005;

vector<int> allp;

void findans(){
    int anscnt = 0;
    for(int i = 2; ; i++){
        bool flag = true;
        int t = i;
        int cnt = 0;
        for(int j = 0; j < allp.size() && allp[j] <= t; j++){
            int v = allp[j];
            if(t % v == 0){
                cnt++;
                while(t % v == 0)
                    t /= v;
            }
        }
        if(cnt == 0)
            allp.push_back(i);
        if(cnt == 4){
            anscnt++;
            if(anscnt == 4){
                printf("%d\n", i-3);
                return;
            }
        }else
            anscnt = 0;
    }
}

int main(){
    findans();

    return 0;
}

