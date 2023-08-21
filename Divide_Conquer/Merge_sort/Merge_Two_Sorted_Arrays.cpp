#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int m,int r){
    // define two copy array size and array.
    int leftSize = m-l+1;
    int rightSize = r-m;
    int L[leftSize],R[rightSize];

    // Two copy array L and R. where perfrom merge.
    int k=0;
    for(int i=l;i<=m;i++){
        L[k]=a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++){
        R[k]=a[i];
        k++;
    }

    // merge two sortest subarray
    int i=0,j=0;
    int cur=l;
    while(i<leftSize && j<rightSize){
        if(L[i] <= R[j]){
            a[cur]=L[i];
            i++;
        }
        else {
            a[cur]=R[j];
            j++;
        }
        cur++;
    }

    // if extra value have on any array base of privous (while) condition.
    // Then extra value add result array.
    while(i<leftSize){
        a[cur]=L[i];
        i++;
        cur++;
    }

    while(j<rightSize){
        a[cur]=R[j];
        j++;
        cur++;
    }
}
int main(){
    // input size and array.
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //function call.
    merge(a,0,3,n-1);

    // print sorted array.
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}