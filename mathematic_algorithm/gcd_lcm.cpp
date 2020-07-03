#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b){
    // return the greatest common divisor.
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    // return the least common multiple.
    return (a*b)/gcd(a, b);
}

int main(){
    int a, b, res;
    while(~scanf("%d%d", &a, &b)){
        res = gcd(a, b);
        printf("%d", res);
    }
    return 0;
}
