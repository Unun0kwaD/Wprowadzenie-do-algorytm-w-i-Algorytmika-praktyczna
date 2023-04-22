#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a;
    cin>>a;
    int b[a], c[a][100];
    for (int i=0;i<a;i++){
        cin>>b[i];
        for (int j=0; j<b[i]; j++){
            cin>>c[i][j];
        }
    }
    for (int i=0;i<a;i++){
        for (int j=b[i]; j>0 ; j--){
            cout<<c[i][j-1]<< " ";
        }
        cout<<endl;
    }

}