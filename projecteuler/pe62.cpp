/*************************************************************************
    > File Name: pe62.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月08日 星期五 09时02分01秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1000003;

//本来想懒省事用map来做（
//发觉自己对string不熟做起来不见得比本来方便（
//一道很普通的hash表

struct Node{
    int nums[10];
    long long lowi;
    long long lownum;
    int cnt;
}node[maxn];

bool book[6];
int bc[10];
int getbc(long long x){
    memset(bc, 0, sizeof(bc));
    while(x){
        bc[x%10]++;
        x/=10;
    }
}
int getbchash(){
    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans = (ans*41+bc[i])%maxn;
    return ans;
}
void insert(long long ci, long long x){
    getbc(x);
    int insertp = getbchash();
    while(node[insertp].lownum){
        bool flag = true;
        for(int i = 0; i < 10; i++)
            if(node[insertp].nums[i] != bc[i]){
                flag = false;
                break;
            }
        if(flag){
            node[insertp].cnt++;
            if(!book[node[insertp].cnt]){
                book[node[insertp].cnt] = true;
                printf("%d %lld %lld\n", node[insertp].cnt, node[insertp].lowi, node[insertp].lownum);
            }
            return;
        }
        insertp++;
    }
    for(int i = 0; i < 10; i++)
        node[insertp].nums[i] = bc[i];
    node[insertp].lowi = ci;
    node[insertp].lownum = x;
    node[insertp].cnt = 1;
}

void getans(){
    for(long long i = 1; !book[5]; i++){
        insert(i, i*i*i);
        if(book[5])
            printf("%lld\n", i);
        //printf("%lld\n", i);
    }
}

int main(){
    getans();
}

