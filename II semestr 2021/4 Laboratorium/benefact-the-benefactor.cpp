#include <iostream>
#include <vector>
using namespace std;
short int l_wierz=0, l_kraw, a=0, b=0,c=0, ost_lisc,t;
int maxlength=0;
//short int tab[20000][2];
struct wierzch{
    vector <short int> syny_id;
    vector <short int> length;
};
wierzch drzewo[10001];
short int w_glab(short int id, int glebokosc,int ost_odwiedzony,int tura){
    for (int j = 0; j < drzewo[id].syny_id.size(); ++j) {
        if (drzewo[id].syny_id[j]!=ost_odwiedzony)
            w_glab(drzewo[id].syny_id[j],glebokosc+drzewo[id].length[j],id,tura);
        }
    if (drzewo[id].syny_id.size()==1){
        if (glebokosc>maxlength)
            maxlength=glebokosc;
        if (tura ==0)
            w_glab(id,0,-1,1);
    }
    return 0;
    }
int main(){
    cin>>t;
    while(t--){
        maxlength=0;
        for (int i=0;i<=l_wierz;i++){
            drzewo[i].syny_id.clear();
            drzewo[i].length.clear();
        }
        cin>>l_wierz;
        for (int i = 0; i < l_wierz-1; ++i) {
            cin >> a >> b >> c;
            drzewo[a].syny_id.push_back(b);
            drzewo[b].syny_id.push_back(a);
            drzewo[a].length.push_back(c);
            drzewo[b].length.push_back(c);
            if (drzewo[a].syny_id.size() == 1) {
                ost_lisc = a;
            }
            else if (drzewo[b].syny_id.size() == 1) {
                ost_lisc = b;
            }
    }
    w_glab(ost_lisc,0,-1,0);
    cout<<maxlength<<endl;
    }
}
