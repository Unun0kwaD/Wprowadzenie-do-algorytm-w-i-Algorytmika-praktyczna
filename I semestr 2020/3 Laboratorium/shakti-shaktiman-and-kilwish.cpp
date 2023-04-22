#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t,a,i;

int main() {
    cin>>t;
    while (i<t){
        cin>>a;
        if (a%2==0)
            cout<<"Thankyou Shaktiman"<<endl;
        else
           cout<<"Sorry Shaktiman"<<endl;
        i++;
    } 
    return 0;
}
