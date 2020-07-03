#include <iostream>
#include <cstdio>
#define LL long long
using namespace std; 

LL myPow_int(LL a, LL b, LL p){
    // return (a^b) MOD p . (use modulo operation to avoid value overflow)
    int res = 1;
    for(;b;b>>=1, a=(a*a)%p){
        if(b&1) res=(res*a)%p;
    }
    return res;
}

double myPow_double(double a, LL b){
    // return a^b .
    if(b<0) a=1/a; b=-b;
    double res = 1.0;
    for(;b;b>>=1, a=(a*a)){
        if(b&1) res=res*a;
    }
    return res;
}
    
int main(){
    LL a, b;
    while(~scanf("%lld %lld", &a, &b)){
        LL res=myPow_int(a, b, 1000000000);
        printf("%lld\n", res);
    }
    return 0;
}

/*
    Problem: return the last 7 digits of the result of 2^1000000000000 .
    Solution: myPow(2, 1000000000000, 10000000)
*/
