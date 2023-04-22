#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    char b;
    int a, sum=0,maks=0;
    cin>>a;
    for (int i=0; i<a;i++){
        cin>>b;
        if ( b=='1'){
            sum++;
            if (maks<sum)
                maks=sum;
        }
        else if ( b=='0')
            sum=0;
    }
    cout<<maks;
    return 0;
}

