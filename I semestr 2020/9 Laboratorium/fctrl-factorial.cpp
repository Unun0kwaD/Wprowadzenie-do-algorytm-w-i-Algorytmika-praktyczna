#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int a[t];
    for ( int i=0; i<t; i++){
        cin>>a[i];
    }
    for ( int i=0; i<t; i++){
            int l=0;
        for ( int j=5; j<=a[i]; j*=5){
                l+=a[i]/j;
        }
        cout<<l<<endl;
    }
}
