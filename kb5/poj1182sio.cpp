#include <cstdio>
int pre[50005];
int w[50005];
char buf[1280000];
int ci;
int Read(){
    while(buf[ci]<'0'||buf[ci]>'9')
        ci++;
    int ans = buf[ci++]-'0';
    while(buf[ci]>='0'&&buf[ci]<='9')
        ans = ans*10+buf[ci++]-'0';
    return ans;
}
int getpre(int x){
    if(pre[x] == 0)
        return x;
    int tx = getpre(pre[x]);
    w[x] = (w[x]+w[pre[x]])%3;
    return pre[x] = tx;
}
int main(){
    fread(buf, 1, 1280000, stdin);
    int ans = 0;
    int n = Read();
    int k = Read();
    while(k--){
        register int co = Read();
        register int cx = Read();
        register int cy = Read();
        if(cx > n || cy > n || co==2&&cx==cy){
            ans++;
            continue;
        }
        register int tx = getpre(cx);
        register int ty = getpre(cy);
        if(tx != ty){
            pre[tx] = ty;
            w[tx] = (w[cy]-w[cx]-co+4)%3;
        }else if((w[cx]+co-1)%3 != w[cy])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

