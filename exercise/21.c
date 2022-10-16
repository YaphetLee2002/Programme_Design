#include<stdio.h>
long int Pow(long int X, int N)
{
    if(N < 0)
        return 1 / X;
    if(N == 0)
        return 1;
    if(N == 1)
        return X % 1000000007;
    if(N % 2)
        return Pow(X * X % 1000000007, N / 2) * X % 1000000007;
    else
        return Pow(X * X % 1000000007, N / 2);
}
int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    long int num = Pow(n, k);
    if(num >= 1000000007)
        num %= 1000000007;
    printf("%ld\n", num);
}
/*
#include <stdio.h>
int main()
{
	long long a=1,b=1,num=1;
	scanf("%lld %lld",&a,&b);
	long long k = 1000000007;
	while(b>0)
	{
		if(b%2!=0) num = num *a %k;
		a=a * a %k;
		b=b/2;
	}
	num %= k;
	printf("%lld\n",num);
}*/