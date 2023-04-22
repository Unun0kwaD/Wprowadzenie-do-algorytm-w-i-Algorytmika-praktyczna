#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int euklides(int a, int b)
{
    while(b)
        swap(a %= b, b);
    return a;
}

int main() {
    int t,g,h;
    cin>>t;
    for ( int i; i<t; i++){
        cin>>g>>h;
        cout<<euklides(g,h)<<endl;
    }
        
    return 0;
}