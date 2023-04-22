#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,p,a,b,maks=0;
short odw[100001];
struct wierzch{
    vector<int> somsiedzi;
    int para=-1;
};
wierzch graf [100001];

bool dfs_kuhn(int v){
    if (odw[v])
        return false;
    odw[v]=1;
    for (int i=0; i<graf[v].somsiedzi.size(); i++){
     //   cerr<<"ide: "<<v<<" "<<graf[v].somsiedzi[i]<<endl;
        if( graf[graf[v].somsiedzi[i]].para==-1 || dfs_kuhn(graf[graf[v].somsiedzi[i]].para) ){
           // cerr<<"lacze: "<<v<<" "<<graf[v].somsiedzi[i]<<endl;
            graf[graf[v].somsiedzi[i]].para=v;
            graf[v].para=graf[v].somsiedzi[i];
            return true;
        }
    }
    return false;
}
void display(){
    for (int i=1; i<=n; i++){
        if (graf[i].para!=-1)
           cerr<<i<<" "<<graf[i].para<<endl;
    }
}
void dispodw(){
    for (int i=1; i<=n+m; i++){
        odw[i]=0;
    }

}
int main() {
    cin>>n>>m>>p;
    for (int i=0; i<p; i++){
        cin>>a>>b;
        graf[a].somsiedzi.push_back(n+b);
        graf[n+b].somsiedzi.push_back(a);
        if (graf[a].para==-1 && graf[n+b].para==-1){
            graf[a].para=n+b;
            graf[n+b].para=a;
            }
    }
   for (int i=1; i<=n+m; i++){
        if (graf[i].para==-1){
            memset(odw,0,n+m+1);
            //dispodw();
            dfs_kuhn(i);
        }
    }
    for (int i=0; i<=n; i++){
        if (graf[i].para!=-1)
            maks++;
    }
    cout<<maks<<endl;
   // display();
    return 0;
}
