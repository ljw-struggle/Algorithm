#include <cstdio>
#define MOD 1000000007
using namespace std;

struct Matrix{
    long long matrix[10][10] = {{0}};
};
// (algorithm) std::fill(array, array + 10*10, 0) 


Matrix multiply(Matrix &a,Matrix &b, int n){
    // Implementation of the multiplicative of the matrixes. n is the order of the matrix.
    Matrix res;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            for(int k = 0 ; k < n ; k++)
                res.matrix[i][j] =(res.matrix[i][j]%MOD+a.matrix[i][k]%MOD*b.matrix[k][j]%MOD)%MOD;
    return res;
}

Matrix pow(Matrix base,int index, int n){
    // Fast Power of Matrix. (m is the index, and >= 0.) 
    Matrix res;
    for(int i=0;i<10;i++){
        res.matrix[i][i] = 1;
    }
    while(index)
    {
        if(index&1) res=multiply(res,base,n);
        base=multiply(base,base,n);
        index>>=1;
    }
    return res;
}

int main(){
    // input.
    int index;
    printf("Please input the index: \n");
    scanf("%d",&index);
    
    Matrix base, res;
    // 1\ Get the Base Matrix.
    base.matrix[0][0]=base.matrix[0][1]=base.matrix[1][0]=1;
    // 2\ Matrix Fast Power.
    res=pow(base,index-1, 2);
    
    // output. 
    printf("The result is :");
    if(index==0)
        printf("0 \n");
    if(index==1)
        printf("1 \n");
    if(index>1)
        printf("%lld \n",res.matrix[0][0]%MOD);
    return 0;    
}
