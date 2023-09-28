#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insertionSort(int a[],int n){
    for(int i=0;i< n;i++){
        int x =a[i],pos = i-1;
        while(pos >=0 && x < a[pos] ){
            a[pos+1] =a[pos];
            --pos;
        }
        a[pos +1];
    }
}
int cnt[1000001];
void countingSort(int a[],int n){
    int m =INT_MIN;
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        m= max(m,a[i]);
    }
    for(int i =0 ;i <=m;i++){
        if(cnt[i] !=0){
            for(int j=0; j < cnt[i];j++){
                cout << i << " ";
            }
        }
    }
}
void merger(int a[],int l,int m,int r){
    vector<int> x(a+l,a + m + 1);
    vector<int> y(a + m+ l,a + r + 1);
    int i=0,j=0;
    while (i < x.size() && j <y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];++l;++i;
        }else{
            a[l] = y[j];++l;j++;
        }
    }
    while (i <x.size()){
        a[l] = x[i];l++;i++;
    }
    while (j <y.size()){
        a[l] = y[i];l++;y++;
    }
}
int main(int argc,char *argv[])
{
    int n;cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //insertionSort(a,n);
    //countingSort(a,n);
    // for(auto x:a){
    //     cout << x <<" ";
    // }

}
//1 5 4 3 2 6 9 8 10 7
//1 4 5 3 2 6 9 8 10 7
//1 4 3 5 2 6 9 8 10 7
//1 4 3 2 5 6 9 8 10 7
//1 4 3 2 5 6 8 9 10 7
//1 4 3 2 5 6 8 9 7 10
//1 3 4 2 5 6 8 9 7 10
//1 3 2 4 5 6 8 9 7 10
//1 2 3 4 5 6 8 9 7 10
//1 2 3 4 5 6 8 7 9 10
// 1 2 3 4 5 6