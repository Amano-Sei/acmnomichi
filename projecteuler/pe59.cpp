/*************************************************************************
    > File Name: pe59.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月05日 星期二 22时37分04秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 5005;

//这道题好不友好（，我是每个位看了26种情况（（（，发觉最高频出现的字母是空格（
//如果知道char的范围就好了（（（

char s[maxn];
char rs[maxn];
int tot;

void findans(int st){
    for(char i = 'a'; i <= 'z'; i++){
        bool flag = true;
        //printf("====%c====\n", i);
        for(int j = st; j < tot; j+=3){
            char t = rs[j]^i;
            //printf("%d %d %d %c\n", rs[j], i, t, t);
            //if(!(t >= 'a' && t <= 'z' || t >= 'A' && t <= 'Z' || t == ' ' || t == '-' || t == '_' || t >= '\'' && t <= '?')){
            if(t < ' ' || t > 'z'){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d %c\n", st, i);
        }
    }
}

char key[4];

int main(){
    FILE *fp = fopen("p059_cipher.txt", "r");
    fscanf(fp, "%s", s);
    int ci = 0;
    int ans = 0;
    while(s[ci]){
        while(s[ci] >= '0' && s[ci] <= '9')
            rs[tot] = rs[tot]*10+s[ci++]-'0';
        tot++;
        ci++;
    }
    findans(0);
    findans(1);
    findans(2);
    for(key[0] = 'd'; key[0] <= 'e'; key[0]++)
        for(key[1] = 'x'; key[1] <= 'y'; key[1]++)
            for(key[2] = 'p'; key[2] <= 'q'; key[2]++){
                for(int ii = 0; ii < tot; ii++)
                    putchar(rs[ii]^key[ii%3]);
                putchar('\n');
                putchar('\n');
            }
    key[0] = 'e';
    key[1] = 'x';
    key[2] = 'p';
    for(int ii = 0; ii < tot; ii++){
        rs[ii]^=key[ii%3];
        putchar(rs[ii]);
        ans += rs[ii];
    }
    putchar('\n');
    printf("%d\n", ans);
    sort(rs, &rs[tot]);
    printf("%s\n", rs);

    return 0;
}

