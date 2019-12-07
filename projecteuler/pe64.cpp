/*************************************************************************
    > File Name: pe64.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月10日 星期日 17时20分32秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

//可以说是hash模板裸题了（
//↑别看这个人现在这么招摇，上午心烦意乱的时候根本没思路
//还是那句话，不要同时考虑过多的东西， 一个功能一个功能地来
//先实现大体步骤，缺什么补什么，思路就会清晰很多
//这里有个疑问，为什么根号的系数总是可以被化简为1，我测试了下最少100w以内都成立
//还有为什么循环节总是从第二位开始，想了下没想明白，感觉需要数论知识？

//2019-11-13 卡66之后发现要求连分数，然后回头来回忆自己当初写的求连分数
//（当然当时我是不知道这是连分数的
//总是1好像我可以证明了，还差一口气，希望吃完饭可以证明

const int maxn = 10003;

struct node{
    long long ca, cb, cc;
    int cs;
}ht[maxn];

int maxi = 0;

long long a[maxn], b[maxn], c[maxn];

long long gcd(long long x, long long y){
    if(x == 0)
        return y;
    return gcd(y%x, x);
}

inline void simpleabc(int ci){
    long long tgcd = gcd(abs(a[ci]), abs(b[ci]));
    tgcd = gcd(tgcd, abs(c[ci]));
    a[ci] /= tgcd;
    b[ci] /= tgcd;
    c[ci] /= tgcd;
}

int gethash(int ci){
    int ans = abs(a[ci])%maxn;
    ans = (ans*103+abs(b[ci]))%maxn;
    ans = (ans*103+abs(c[ci]))%maxn;
    return ans;
}

inline void init(){
    memset(ht, 0, sizeof(ht));
}

int insert(int ci){
    int insertp = gethash(ci);
    while(ht[insertp].cs != 0){
        if(ht[insertp].ca == a[ci] && ht[insertp].cb == b[ci] && ht[insertp].cc == c[ci])
            return ci-ht[insertp].cs;
        insertp = (insertp+1)%maxn;
    }
    ht[insertp] = { a[ci], b[ci], c[ci], ci };
    return 0;
}

int getans(){
    int ans = 0;
    for(int cx = 2; cx <= 10000; cx++){
        int ck = sqrt(cx);
        if(ck*ck == cx)
            continue;
        init();
        a[1] = 1;
        b[1] = -ck;
        c[1] = 1;
        ht[gethash(1)] = { 1, -ck, 1, 1 };
        for(int i = 2; ; i++){
            a[i] = a[i-1]*c[i-1];
            b[i] = -b[i-1]*c[i-1];
            c[i] = a[i-1]*a[i-1]*cx-b[i-1]*b[i-1];
            simpleabc(i);
            ck = (sqrt(cx)*a[i]+b[i])/c[i];
            b[i] -= ck*c[i];
            ck = insert(i);
            if(a[i] != 1)
                printf("look here\n");
            if(ck != 0){
                maxi = max(i, maxi);
                if(ck+1 != i)
                    printf("hakian...%d\n", i);
                //printf("%d %d %d\n", cx, ck, i);
                ans += ck&1;
                break;
            }
        }
    }
    return ans;
}

int main(){
    printf("%d\n", getans());
    printf("%d\n", maxi); 
    return 0;
}

