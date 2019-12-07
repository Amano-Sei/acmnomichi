/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月24日 星期日 16时29分16秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1000005;

char s[maxn];

void solve(){
    scanf("%s", &s[1]);
    int len = strlen(&s[1]);
    int digit_sum = 0;
    register int cc = 0;
    for(int i = len; i > 0; i--){
        cc += (s[i]-'0')*9;
        digit_sum += (s[i] = cc%10);
        cc /= 10;
    }
    digit_sum += (s[0] = cc);
    int ans = 10-s[len];
    digit_sum -= s[len]-1;
    s[--len]++;
    while(true){
        for(int i = len; i > 0 && s[i] >= 10; i--){
            s[i] -= 10;
            s[i-1]++;
            digit_sum -= 9;
        }
        if(digit_sum <= ans){// && (ans-digit_sum) % 9 == 0){
            //对于dalao们来说一定可以构造出来这点一眼就看出来了（
            //而我想破头终于想到了两边模9同余...
            //然后所有可以取的值是当前的digit_sum+9*k，k最小是0，最大到和为(u+ans)/10
            //只要ans小于等于原数上界就没有问题
            //所以只要关注下界的digit_sum就可以了
            printf("%d\n", ans);
            return;
        }else{
            ans+=10;
            digit_sum++;
            s[len]++;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}

