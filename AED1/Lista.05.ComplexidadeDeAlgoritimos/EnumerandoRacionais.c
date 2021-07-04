#include <stdio.h>
#include <stdlib.h>
 
 
int gcd(int n,int d)
{
    if(n==0)
    {
        return d;
    }
    return gcd(d%n, n);
}
int rationalsEnumeration(int a)
{
    int d,n;
    for(d=1;a>0;d++)
    {
        for(n=0;n<=d;n++)
        {
            if(gcd(n,d)==1)
            {
                if(a==1)
                {
                    printf("%d/%d\n",n,d);
                }
                a--;
            }
        }
    }
    return 0;
}
 
int main()
{
    int a,i;
 
    scanf("%d",&a);
 
    while(a!=0)
    {
        rationalsEnumeration(a);
        scanf("%d",&a);
    }
    return 0;
}