#include<bits/stdc++.h>
using namespace std;
// recurciv function
void divide(int a[],int l, int r){
    // // if i see divided output
    // for(int i=l;i<=r;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    if(l<r){
        int mid=(l+r)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
    }
}
int main(){
    // input array
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // function call
    divide(a,0,n-1);

    return 0;
}