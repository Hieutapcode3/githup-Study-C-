#include <bits/stdc++.h>

using namespace std;


int partition(int a[],int l,int r){
    int pivot= a[r];
    int i = l-1;
    for(int j= l; j<r;j++){
        if( a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    ++i;
    swap(a[i],a[r]);
    return i;
}
void quicksort(int a[],int l,int r){
    if(l >= r) return;
    int p =partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}
int main(int argc,char *argv[])
{
    int a[1000],n;cin >>n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i] = rand() % 10;
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] <<" ";
    }
}
