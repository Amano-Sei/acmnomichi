/*************************************************************************
    > File Name: pe32.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月09日 星期三 22时40分23秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tnum[3][6];
//很容易证明，被乘数和乘数的位数和只能为5
//本来想着9^9有点大...这样9^5的话好像很轻松...
int ans;
bool book[10];
int num[10];
bool hasadd[100000];

void dfs(int ci){
    if(ci == 5){
        for(int m = 0; m < 4; m++){
            int a = 0, b = 0;
            for(int i = 0; i <= m; i++)
                a = a*10+num[i];
            for(int i = m+1; i < 5; i++)
                b = b*10+num[i];
            int c = a*b;
            if(hasadd[c])
                continue;
            int tc = c;
            int ti;
            for(ti = 5; !book[tc%10]; ti++, tc/=10){
                num[ti] = tc%10;
                book[num[ti]] = true;
            }
            if(ti == 9 && tc == 0){
                hasadd[c] = true;
                printf("%d * %d = %d\n", a, b, c);
                ans += c;
            }
            for(int j = 5; j < ti; j++)
                book[num[j]] = false;
        }
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(book[i])
            continue;
        num[ci] = i;
        book[i] = true;
        dfs(ci+1);
        book[i] = false;
    }
}

int main(){
    book[0] = true;
    dfs(0);
    printf("%d\n", ans);

    return 0;
}

