/*************************************************************************
    > File Name: pe22.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 22时51分39秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char os[10005*24];

struct name{
    char s[24];
}allnames[10005];

bool cmp(const name &a, const name &b){
    return strcmp(a.s, b.s) < 0;
}

int getval(char *s){
    int ans = 0;
    for(int i = 0; s[i]; i++)
        ans += s[i]-'A'+1;
    return ans;
}

int main(){
    FILE *fp = fopen("p022_names.txt", "r");
    if(fp != NULL){
        fscanf(fp, "%s", os);
        fclose(fp);
    }
    int ci = 0;
    int si = 0;
    while(os[ci]){
        ci++;
        for(int i = 0; os[ci] != '\"'; i++, ci++)
            allnames[si].s[i] = os[ci];
        printf("%d %s\n", si, allnames[si].s);
        si++;
        ci += 2;
    }
    long long ans = 0;
    sort(&allnames[0], &allnames[si], cmp);
    for(int i = 0; i < si; i++)
        ans += (i+1)*getval(allnames[i].s);
    printf("%lld\n", ans);
    return 0;
}

