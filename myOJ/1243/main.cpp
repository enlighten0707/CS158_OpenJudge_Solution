#include <iostream>
#include <cstdio>
using namespace std;
const int N=1005;
int a[N],sum[N],tmp[N];

int main() {
    int n,m,opt,l,r,maxx;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sum[0]=a[0];
    for(int i=1;i<n;++i)
        sum[i]=sum[i-1]+a[i];
    while(m--){
        cin>>opt>>l>>r;
        switch(opt){
            case 0:
                double ans;
                if(l==0) ans=(double) sum[r]/(r-l+1);
                else ans=(double) (sum[r]-sum[l-1])/(r-l+1);
                printf("%.2f\n",ans);
                break;
            case 1:
                maxx=0;
                for(int i=l;i<=r;++i){
                    if(a[i]>maxx)
                        maxx=a[i];
                }
                printf("%d\n",maxx);
                break;
            case 2:
                for(int i=l;i<=r;++i)
                    tmp[i]=a[i];
                for(int i=l;i<=r;++i)
                    a[i]=tmp[r-i+l];
                break;
            case 3:
                for(int i=l;i<=r;++i)
                    printf("%d ",a[i]);
                printf("\n");
                break;
            case 4:
                for(int i=l;i<=r;++i){
                    if(a[i]) a[i]--;
                }
                break;
            default:break;
        }
    }
    return 0;
}