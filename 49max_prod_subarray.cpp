#include <iostream>
using namespace std;

int max_prod(const int * ptr, int size){
    int mpro = ptr[0], rpro = ptr[0];
    
    for(int i = 0;i<size;i++){
        int cpro = ptr[i];
        for(int j = i+1;j<size;j++){
            cpro = cpro * ptr[j];
            if(cpro > mpro && cpro > ptr[i]){
                mpro = cpro;
            }
        }
        if(mpro > rpro)
        rpro = mpro;
    }
    return rpro;
}

/*  Kadane's method           O(n)
“Kadane for PRODUCT” (max product subarray)
Products flip sign, so track both max and min ending at i:
If x is negative, swap max_here and min_here.
Then:
max_here = max(x, max_here * x)
min_here = min(x, min_here * x)
ans = max(ans, max_here)
A zero naturally resets (since x=0 → both become 0; next step may restart at next element).

int maxProduct(const int* a, int n){
    int max_here = a[0], min_here = a[0], ans = a[0];
    for(int i=1;i<n;++i){
        int x = a[i];
        if (x < 0) { int t = max_here; max_here = min_here; min_here = t; }
        max_here = (x > max_here * x) ? x : max_here * x;
        min_here = (x < min_here * x) ? x : min_here * x;
        if (max_here > ans) ans = max_here;
    }
    return ans;
}  */

int main() {
int arr[] = {1,2,4,-4,0,-1,9,5,2};
int size = sizeof(arr)/sizeof(arr[0]);
 cout<<max_prod(arr,size);
    return 0;
}