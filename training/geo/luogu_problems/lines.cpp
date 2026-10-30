#include <bits/stdc++.h>
using namespace std;
int n,sum,sum2,ans;
double f[701][701],x[701],y[701];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++)//枚举起点
      for (int j=1;j<=n;j++)
    {
        if (i==j) continue;
        f[i][j]=(y[i]-y[j])/(x[i]-x[j]);
    }
    //for (int i=1;i<=n;i++) {for (int j=1;j<=n;j++) cout<<f[i][j]<<" ";cout<<endl;}
    for (int i=1;i<=n;i++)
    {
        sort(f[i]+1,f[i]+n+1);//排序
        sum=0;sum2=0;
        for (int j=3;j<=n;j++)
        {
            if (f[i][j]==f[i][j-1]) sum++,sum2=max(sum,sum2);//计算个数
            else sum=0;
        }
        sum=max(sum,sum2);
        ans=max(ans,sum);
    }
    cout<<ans+2<<endl;
    return 0;
}
