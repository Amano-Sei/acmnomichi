/*************************************************************************
    > File Name: pe42.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月19日 星期六 22时04分15秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2005;

char s[maxn*30];

bool istri[20*36+10];
void init(){
    for(int i = 1; i*(i+1)/2 <= 20*36; i++)
        istri[i*(i+1)/2] = true;
}

int main(){
    int ans = 0;
    init();
    FILE *fp = fopen("p042_words.txt", "r");
    fscanf(fp, "%s", s);
    int ci = 0;
    while(s[ci]){
        if(s[ci] == '"' || s[ci] == ','){
            ci++;
            continue;
        }
        int cans = 0;
        while(s[ci] != '"')
            cans += s[ci++]-'A'+1;
        if(istri[cans])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

