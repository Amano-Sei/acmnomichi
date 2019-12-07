/*************************************************************************
    > File Name: pe60.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月06日 星期三 09时01分41秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int maxn = 2173609;
//首先借助原有的四个数据找出一个解，然后跑出这个范围内的所有质数开始爆搜剪枝（然而这个做法oj肯定会t...
//借助cnt可以看到实际上只循环了38880914次，所以性能限制应该是在isp上（
//换成long long后发觉自己里面有一个溢出（捂脸），而且用map并没有什么明显改善
//然后写完才发觉这道题是20%难度的（捂脸，难怪让我感觉好有难度QAQ如果知道这道题是20%我还能这么顺利么(

vector<int> allp;
map<long long, bool> desup;

int nums[5];
int tens[5];
//long long cnt;

bool isp(long long x){
    //if(desup.count(x))
    //    return desup[x];
    for(long long i = 2; i*i < x; i++)
        if(x%i == 0)
            return false;
            //return desup[x]=false;
    return true;
    //return desup[x]=true;
}

int gettens(int x){
    int ans = 1;
    while(x){
        ans *= 10;
        x /= 10;
    }
    return ans;
}

void init(){
    for(int i = 2; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                //desup[i] = flag = false;
                break;
            }
        if(flag){
            //desup[i] = true;
            allp.push_back(i);
        }
    }
}

int minans = maxn;

void dfs(int ci, int st, int cans){
    if(ci == 5){
        for(int i = 0; i < 5; i++)
            printf("%d ", nums[i]);
        printf("with sum = %d\n", cans);
        minans = min(minans, cans);
    }
    for(int i = st; i < allp.size() && allp[i] < minans-cans; i++){
        //cnt++;
        nums[ci] = allp[i];
        tens[ci] = gettens(nums[ci]);
        bool flag = true;
        for(int j = 0; j < ci; j++)
            if(!isp(nums[ci]*tens[j]+nums[j]) || !isp(nums[j]*tens[ci]+nums[ci])){
                flag = false;
                break;
            }
        if(flag)
            dfs(ci+1, i+1, cans+nums[ci]);
    }
}

int main(){
    init();
    dfs(0, 1, 0);
    printf("%d\n", minans);
    //printf("%lld\n", cnt);
    return 0;
}

