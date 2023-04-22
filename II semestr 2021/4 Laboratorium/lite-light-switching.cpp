#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char drzewo_sum[262145];
int przedzial[262145][2];
int l_podzielnych[262145];
int N,N2,Q,t,a,b; //n liczba lisci (z pustymi)
/*
struct node{
    int id;
    pair<int,int> przedzial;
    int l_podzielnych_w_przedziale;
    int suma;
    node* father; // podziel id na 2
    node* lson; // id razy 2
    node* rson; // id razy 2 +1
};*/
int najb_pot_2(int n){
    int out=1;
    while (n>out)
        out*=2;
    return out;
}
void inicjalizacja(){
   // cerr<<"inicjalizacja"<<endl;
    for (int i=N; i<(2*N); i++){
        //cerr<<"inicjalizacja1"<<endl;
        drzewo_sum[i]=0;
        przedzial[i][0]=i-N+1;
        przedzial[i][1]=i-N+1;
        l_podzielnych[i]=0;
     //   cerr<<i<<" "<<przedzial[i][0]<<" "<<przedzial[i][1]<<endl;
    }
    //cerr<<"inicjalizacja2"<<endl;
    for(int i=N-1; i>0; i--){
        drzewo_sum[i]=0;
        przedzial[i][0]=przedzial[i*2][0];
        przedzial[i][1]=przedzial[i*2+1][1];
        l_podzielnych[i]=0;
      //  cerr<<i<<" "<<przedzial[i][0]<<" "<<przedzial[i][1]<<endl;
    }
}
int quest(int id, int x, int y){
    int out=0;
    //cerr<<"quest"<<endl;
    if (przedzial[id][0]==x && przedzial[id][1]==y)
        return l_podzielnych[id];
    if (przedzial[id*2][1]>=x)
        out+=quest(id*2,x,min(przedzial[id*2][1],y));
    if (przedzial[id*2+1][0]<=y)
        out+=quest(id*2+1,max(przedzial[id*2+1][0],x),y);
    return out;
}
void display(){
    cerr<<"display"<<endl;
    for (int i=0; i<2*N; i++){
        cerr<<i<<" :{"<<przedzial[i][0]<<", "<<przedzial[i][1]<<" } suma:"<<drzewo_sum[i]<<" l_podzielnych:"<<l_podzielnych[i]<<endl;
    }
}
void update(int x,int y){
    for (int i=x; i<=y; i++){
        //cerr<<"upadate:"<<i<<"x:"<<x<<"y:"<<y<<endl;
        l_podzielnych[i]=l_podzielnych[i*2]+l_podzielnych[i*2+1];
    }
    if(przedzial[x][1]!=0 && przedzial[y][1]!=N)
    update(x/2,y/2);
    else
        l_podzielnych[1]=l_podzielnych[2]+l_podzielnych[3];
}
void addone(int x, int y){
    //int first=-1,last;
    for (int i=N+x; i<=N+y; i++){
        //cerr<<"++"<<endl;
        if (l_podzielnych[i]){
            l_podzielnych[i]=0;
        }
        else
            l_podzielnych[i]=1;
    }
    update((N+x)/2,(N+y)/2);
}
int main() {
    cin>>N2>>Q;
    N=najb_pot_2(N2);
    //cerr<<N<<endl;
    inicjalizacja();
    //display();
    while (Q--){
        cin>>t>>a>>b;
        if(t){
            cout<<quest(1,(a),(b))<<endl;
            //display();
            //in_depth(a,b);
            //zwrocenie ile liczb jest podzilna przez 3
        }
        else{
            addone(a-1,b-1);
            //display();
            // dodanie o 1 na przedziale
        }
    }
    return 0;
}
