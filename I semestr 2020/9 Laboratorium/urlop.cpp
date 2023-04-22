#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int a, sum=0,maks=0;
    string ciagz;
    cin>>a;
    cin>>ciagz;
    for (int i=0; i<a;i++){
        if ( ciagz[i]=='S'){
            sum++;
            if (maks<sum)
                maks=sum;
        }
        else if ( ciagz[i]=='P')
            sum=0;
    }
    cout<<maks;
    return 0;
}

