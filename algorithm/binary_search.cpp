#include <iostream>
#include <cstdio>
using namespace std;

int binary_search(vector<int> A, int n, int val){
    // binary search the val's position where it first appeared.
    int l=0, r=n-1;
    int mid;
    while(l<=r){
        mid = int((l+r)/2);
        if(A[mid]<val) l=mid+1;
        if(A[mid]>val) r=mid-1;
        if(A[mid]==val){
            while(mid>=0&&A[mid]==val){
                mid--;
            }
            return mid+1;
        }
    }
    return -1;
}

int main(){
    int n, tmp;
    vector<int> A;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    
    int val;
    scanf("%d", &val);
    int res = binary_search(A, n, val);
    printf("%d", res);
    
    return 0;
}
