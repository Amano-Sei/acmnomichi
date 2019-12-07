/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月08日 星期五 20时05分04秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000005;

char s[maxn];
int st[4];

int main(){
    int t, n;
    int ans;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d%s", &n, s);
        memset(st, -1, sizeof(st));
        for(int i = 0; i < n; i++)
            switch(s[i]){
                case 'p':
                    if(st[0] == -1)
                        st[0] = i;
                    break;
                case 'i':
                    if(st[0] != -1 && st[1] == -1)
                            st[1] = i;
                    break;
                case 'n':
                    if(st[0] != -1 && st[1] != -1 && st[2] == -1)
                        st[2] = i;
                    break;
                case 'k':
                    if(st[0] != -1 && st[1] != -1 && st[2] != -1)
                        st[3] = i;
                    break;
            }
        if(st[3] != -1){
            for(int i = 0; i < 3; i++)
                ans = max(ans, st[i+1]-st[i]-1);
            for(int i = st[2]+1; i < st[3]; i++)
                if(s[i] == 'n')
                    ans = max((st[2]=i)-st[1]-1, ans);
            for(int i = st[1]+1; i < st[2]; i++)
                if(s[i] == 'i')
                    ans = max(i-st[0]-1, ans);
            printf("%d\n", ans);
        }else
            printf("-1\n");
    }
    return 0;
}

