/*************************************************************************
    > File Name: pe15.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月23日 星期一 22时30分22秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;
//好久不见catalan number
//这次补了维基百科...果然比那些博主写的内容要好多了...
//短但是让我用最简单的方法初步理解了他的证明
//虽然感觉这个证明有点问题...比如不像是一一对应，是一堆对应一堆

int catalan[101][100];
bool book[21];

void init(){
    catalan[1][0] = 1;
    catalan[1][1] = 2;
    for(int i = 2; i <= 100; i++){
        int cc = 0;
        catalan[i][0] = catalan[i-1][0];
        for(int j = 1; j <= catalan[i][0]; j++){
            catalan[i][j] = catalan[i-1][j] * (4*i-2) + cc;
            cc = catalan[i][j]/10;
            catalan[i][j] %= 10;
        }
        while(cc){
            catalan[i][++catalan[i][0]] = cc%10;
            cc /= 10;
        }
        for(int j = catalan[i][0]; j > 0; j--){
            catalan[i][j] += cc;
            cc = catalan[i][j] % i * 10;
            catalan[i][j] /= i;
        }
        while(!catalan[i][catalan[i][0]])
            catalan[i][0]--;
    }
}

//然后重新看题...哇，这不是Cn 2n么...
//好在简单改下就可以了（
//然后发觉...好像不会超longlong范围...

int main(){
    init();
    for(int i = catalan[20][0]; i > 0; i--)
        printf("%d", catalan[20][i]);
    putchar('\n');
    long long ans = 1;
    for(int i = 21; i <= 40; i++){
        ans = ans*i;
        for(int j = 2; j <= 20; j++)
            if(!book[j] && ans%j == 0){
                book[j] = true;
                ans = ans/j;
            }
    }
    printf("%lld\n", ans);
    long long spans = 2;
    for(int i = 2; i <= 20; i++)
        spans = spans * (4*i-2) / i;
    printf("%lld\n", spans);
    return 0;
}

