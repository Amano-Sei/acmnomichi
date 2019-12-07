/*************************************************************************
    > File Name: 1003.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 14时01分50秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> allnum[26];
int t;
int n, q;
char s[maxn];

void init(){
    for(int i = 0; i < 26; i++)
        allnum[i].clear();
    for(int i = 0; s[i]; i++)
        allnum[s[i]-'a'].push_back(i);
}

int l, r, k;
bool mycmp(int cp){
    if(s[cp+r-l] != s[r-1])
        return false;
    for(int i = l; i < r; i++)
        if(s[++cp] != s[i])
            return false;
    return true;
}

int main(){
    int tsize, cc;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%s", &n, &q, s);
        init();
        while(q--){
            scanf("%d%d%d", &l, &r, &k);
            tsize = allnum[cc=s[l-1]-'a'].size();
            for(int i = 0; i < tsize; i++){
                if(tsize-i < k)
                    break;
                if(mycmp(allnum[cc][i]))
                    if(--k == 0){
                        printf("%d\n", allnum[cc][i]+1);
                        break;
                    }
            }
            if(k)
                printf("-1\n");
        }
    }
	return 0;
}

