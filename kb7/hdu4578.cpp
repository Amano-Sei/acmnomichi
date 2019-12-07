/*************************************************************************
    > File Name: hdu4578.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月05日 星期三 15时34分17秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const long long mod = 10007;

//我现在无比庆幸自己没有在发觉直接push_down所有标记的情况下可以ac就扔一边这道题
//终于让我发现了，chlz是存在着被add到0的可能性的
//当他被add到0时会误以为没有chlz，但是事实上这里的chlz是有效的
//这与addlz和mullz不同，如果addlz被加到0的话那么addlz就可以当做失效了
//类似的mullz被乘到1的话也是同样的
//但是chlz不同，如果chlz被当做失效了，那么就会导致应该被更新为0的孩子没有更新
//用一个我也不知道怎么形容的说法来说，add和mul是一个过程，但是ch是一个结果
//复数的过程加在一起可以等于什么都没做
//但是结果表示就是这样的结果

//各种意义上来说，虽然我生成了蛮大量的数据的，但是出现了把chlz给add到0的数据真的是蛮lucky的hhh

//然后是补充一下自己的wa的过程，最初版的代码写的很烂，因为开始没想到各种操作重叠度那么大，而且各种wa之后疯狂加括号（虽然这版也是...)，所以重写了这版
//然后我首先论断了添加标记的16种情况，其中ch标记可以覆盖掉任何标记也可以接受任何标记可以说是最强标记了
//出于希望共存的原因，我错误地认为addlz可以吸收mullz，这是最初的错误
//然而虽然并不是不能共存，但是如果同时具有mullz和addlz的话，只能对最后一次更新的标记进行更新，push_down的时候要按顺序push_down，这样其实不见得能提高速度，反而让复杂度上升了一个档次（其实也算不上吧，只是麻烦度上升了）
//所以从设计的角度上让addlz和mullz不能共存（
//然而到了这一步，我已经可以通过hdu讨论板上的数据了（所以第一版wa绝对是哪里写烂了），但是还是wa...
//然后我写了个数据生成器，借助bin神的代码生成答案，在这里出现了我以外的情况，某个节点莫名其妙地sum全部清0了，而且和自己的子节点的和不符
//为了进一步debug(玩)，我写了各种打印函数，终于发觉这个节点的父节点中有一个chlz为2064，sum清0时的操作是add 7943，加起来刚好是10007...然后就有了上面那堆
//emmm现在想来真的是超lucky的说...
//接下来在重置为int版之后去看看dalao们的代码就过吧这道题（

struct node{
    int l, r;
    long long sum[3];
    long long addlz;
    long long mullz;
    long long chlz;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { l, r, 0, 0, 0, 0, 1, -1 };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

inline void push_down_add(int x);

inline void chswitch(int x, long long chlz){
    st[x].chlz = chlz;
    st[x].addlz = 0;
    st[x].mullz = 1;
    register long long xc = st[x].r-st[x].l+1;
    st[x].sum[0] = (chlz*xc)%mod;
    st[x].sum[1] = (chlz*st[x].sum[0])%mod;
    st[x].sum[2] = (chlz*st[x].sum[1])%mod;
}

inline void push_down_ch(int x){
    register long long chlz = st[x].chlz;
    if(chlz >= 0){
        st[x].chlz = -1;
        chswitch(x<<1, chlz);
        chswitch((x<<1)|1, chlz);
    }
}

inline void mulswitch(int x, long long mullz, long long mullz2, long long mullz3){
    if(st[x].l < st[x].r){
        if(st[x].chlz >= 0)
            st[x].chlz = (st[x].chlz*mullz)%mod;
        else{
            push_down_add(x);
            st[x].mullz = (st[x].mullz*mullz)%mod; 
        }
    }
    st[x].sum[0] = (st[x].sum[0] * mullz) % mod;
    st[x].sum[1] = (st[x].sum[1] * mullz2) % mod;
    st[x].sum[2] = (st[x].sum[2] * mullz3) % mod;
}
inline void push_down_mul(int x){
    register long long mullz = st[x].mullz;
    if(mullz != 1){
        st[x].mullz = 1;
        register long long mullz2 = (mullz*mullz)%mod;
        register long long mullz3 = (mullz*mullz2)%mod;
        mulswitch(x<<1, mullz, mullz2, mullz3);
        mulswitch((x<<1)|1, mullz, mullz2, mullz3);
    }
}

inline void addswitch(int x, long long addlz, long long addlz2, long long addlz3){
    if(st[x].l < st[x].r){
        if(st[x].chlz >= 0)
            st[x].chlz = (st[x].chlz+addlz)%mod;
        else{
            push_down_mul(x);
            st[x].addlz = (st[x].addlz+addlz)%mod;
        }
    }
    register long long xc = st[x].r-st[x].l+1;
    st[x].sum[2] = (st[x].sum[2]+((3*st[x].sum[1]*addlz)%mod)+((3*st[x].sum[0]*addlz2)%mod)+((xc*addlz3)%mod))%mod;
    st[x].sum[1] = (st[x].sum[1]+((2*st[x].sum[0]*addlz)%mod)+((xc*addlz2)%mod))%mod;
    st[x].sum[0] = (st[x].sum[0]+((addlz*xc)%mod))%mod;
}

inline void push_down_add(int x){
    register long long addlz = st[x].addlz;
    if(addlz){
        st[x].addlz = 0;
        register long long addlz2 = (addlz*addlz)%mod;
        register long long addlz3 = (addlz2*addlz)%mod;
        addswitch(x<<1, addlz, addlz2, addlz3);
        addswitch((x<<1)|1, addlz, addlz2, addlz3);
    }
}

void printst(int x){
    puts("=========================================");
    puts("=     x     l       r addlz mullz  chlz =");
    printf("= %5d %5d ~ %5d %5lld %5lld %5lld =\n", x, st[x].l, st[x].r, st[x].addlz, st[x].mullz, st[x].chlz);
    puts("=       sum[0]       sum[1]      sum[2] =");
    printf("=       %6lld       %6lld      %6lld =\n", st[x].sum[0], st[x].sum[1], st[x].sum[2]);
    puts("+++++++++++++++++++++++++++++++++++++++++");
}

void pricheck(int x){
    register int lc = x<<1;
    register int rc = lc|1;
    puts("");
    printst(x);
    printst(lc);
    printst(rc);
    puts("");
    if((st[x].addlz!=0)+(st[x].mullz!=1)+(st[x].chlz!=0) > 1){
        printf("WARNING...\n");
        exit(0);
    }
    if((st[lc].addlz!=0)+(st[lc].mullz!=1)+(st[lc].chlz!=0) > 1){
        printf("WARNING...\n");
        exit(0);
    }
    if((st[rc].addlz!=0)+(st[rc].mullz!=1)+(st[rc].chlz!=0) > 1){
        printf("WARNING...\n");
        exit(0);
    }
}

inline void checkdesu(int x){
    register int lc = x<<1;
    register int rc = lc|1;
    for(int i = 0; i < 2; i++)
        if((st[lc].sum[i]+st[rc].sum[i])%mod != st[x].sum[i]){
            printf("WARNING...\n%lld %lld %lld %d\n", st[lc].sum[i], st[rc].sum[i], st[x].sum[i], i);
            pricheck(x);
            exit(0);
        }
}

inline void push_down(int x){
    //pricheck(x);
    push_down_ch(x);
    push_down_mul(x);
    push_down_add(x);
    //checkdesu(x);
}

inline void push_up(int x){
    register int lc = x<<1;
    register int rc = lc|1;
    st[x].sum[0] = (st[lc].sum[0]+st[rc].sum[0])%mod;
    st[x].sum[1] = (st[lc].sum[1]+st[rc].sum[1])%mod;
    st[x].sum[2] = (st[lc].sum[2]+st[rc].sum[2])%mod;
}

void add(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        register long long val2 = (val*val)%mod;
        register long long val3 = (val2*val)%mod;
        addswitch(x, val, val2, val3);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        add(x<<1, l, r, val);
    else if(m < l)
        add((x<<1)|1, l, r, val);
    else
        add(x<<1, l, m, val), add((x<<1)|1, m+1, r, val);
    push_up(x);
}

void mul(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        register long long val2 = (val*val)%mod;
        register long long val3 = (val2*val)%mod;
        mulswitch(x, val, val2, val3);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        mul(x<<1, l, r, val);
    else if(m < l)
        mul((x<<1)|1, l, r, val);
    else
        mul(x<<1, l, m, val), mul((x<<1)|1, m+1, r, val);
    push_up(x);
}

void ch(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        chswitch(x, val);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        ch(x<<1, l, r, val);
    else if(m < l)
        ch((x<<1)|1, l, r, val);
    else
        ch(x<<1, l, m, val), ch((x<<1)|1, m+1, r, val);
    push_up(x);
}

long long query(int x, int l, int r, int p){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].sum[p];
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r, p);
    else if(m < l)
        return query((x<<1)|1, l, r, p);
    else
        return (query(x<<1, l, m, p)+query((x<<1)|1, m+1, r, p))%mod;
}

inline void showstall(int x){
    puts("now show me power...");
    printst(x^1);
    printst(x);
    printst(x<<1);
    printst((x<<1)|1);
    while(x>>=1)
        printst(x);
    puts("powerdesu...");
}

int main(){
    //freopen("indesu", "r", stdin);
    //freopen("outdesu", "w", stdout);
    int n, m;
    int co, cx, cy;
    long long cz;
    while(scanf("%d%d", &n, &m) != EOF && n){
        built(1, 1, n);
        while(m--){
            scanf("%d%d%d%lld", &co, &cx, &cy, &cz);
            //printf("==%d %d %d %lld===\n", co, cx, cy, cz);
            //showstall(58);
            switch(co){
                case 1:
                    add(1, cx, cy, cz);
                    break;
                case 2:
                    mul(1, cx, cy, cz);
                    break;
                case 3:
                    ch(1, cx, cy, cz);
                    break;
                case 4:
                    printf("%lld\n", query(1, cx, cy, cz-1));
                    break;
            }
            //showstall(58);
        }
    }
    return 0;
}

