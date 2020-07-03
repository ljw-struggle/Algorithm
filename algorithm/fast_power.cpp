#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;

LL myPow(LL a, LL b, LL p){
    int res = 1;
    for(;b;b>>=1, a=(a*a)%p){
        if(b&1) res = (res*a)%p;
    }
    return res;
}

int main(){
    LL res;
    res = myPow(2, 100000000, 10000000);
    printf("%lld", res);
    return 0;
}
