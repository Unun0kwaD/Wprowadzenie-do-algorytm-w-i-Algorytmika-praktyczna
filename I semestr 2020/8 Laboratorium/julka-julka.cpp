#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string dodawanie(string a, string b){
    string res ="";
    int carry= 0, i;
    for(i=0;i<max(a.size(),b.size());i++){
        int tmp = 0;
        if(i<a.size()){
            tmp+=a[i]-'0';
        }
        if(i<b.size()){
            tmp+=b[i]-'0';
        }
        tmp+= carry;
        carry= tmp/10;
        res += (tmp%10) + '0';
    }
    if(carry > 0) {
        res += carry + '0';
    }
    return res;
}

string odejmowanie (string a, string b){
    string res ="";
    int carry= 0, i;
    for(i=0;i<max(a.size(),b.size());i++){
        int tmp = 0;
        if(i<a.size()){
            tmp+=a[i]-'0';
        }
        if(i<b.size()){
            tmp-=b[i]-'0';
        }
        tmp-= carry;
        if (tmp<0){
            tmp+=10;
            carry=1;
        }
        else carry=0;
        res += (tmp%10) + '0';
    }
    if(carry > 0) {
        res += '9'- carry+1;
    }
    if (res[res.length()-1]=='0'){
        res=res.substr(0,res.size()-1);

        }
    return res;

}
string mnozenie(int a, string b){
    reverse(b.begin(), b.end());
    string g=b;
    while (a!=1){
        g=dodawanie(g,b);
        a--;
        //cout<<;
    }
     reverse(g.begin(), g.end());
    return g;
}

string dzielenie_na_2(string a){
    string res ="";
    int carry= 0, i;
    for(i=0;i<a.size();i++){
        if ((a[i]-'0')%2==0){
            a[i]='0'+(a[i]-'0')/2;
            if (carry!=0 ){
                if (carry+a[i]>'9'){
                    carry='9'-a[i]-carry;
                    a[i]='9';
                }
                else{
                    a[i]+=carry;
                    carry=0;
                }

            }
        }
        else{
            a[i]='0'+(a[i]-'1')/2;
            if (carry!=0 ){
                if (carry+a[i]>'9'){
                    carry='9'-a[i]-carry;
                    a[i]='9';
                }
                else{
                    a[i]+=carry;
                    carry=0;
                }

            }
            carry+=5;
        }

    }
    reverse(a.begin(), a.end());
    if (a[a.length()-1]=='0')
        a=a.substr(0,a.size()-1);
        reverse(a.begin(), a.end());
    return a;

}

int main() {
    string a,b,k,n;
    int t=10;
    while(t--){
    cin>>a>>b;
    if (a=="0"){
        cout<<a<<endl;
        cout<<0;}
    else if (a==b){
        cout<<b<<endl;
        cout<<0;
    }
    else{
       reverse(a.begin(), a.end());
       reverse(b.begin(), b.end());
    k=dodawanie(a,b);
       reverse(k.begin(), k.end());
    k=dzielenie_na_2(k);
        reverse(k.begin(), k.end());
    n=odejmowanie(a,k);
        reverse(k.begin(), k.end());
        reverse(n.begin(), n.end());
    int j=0;
    while (k[j]=='0'){
        j++;
        }
    while (k.length()>j){
        cout<<k[j];
        j++;
        }
        cout<<endl;
    int i=0;
    while (n[i]=='0'){
        i++;
        }
    while (n.length()>i){
        cout<<n[i];
        i++;
        }
        cout<<endl;
    }
    }
    return 0;
}
