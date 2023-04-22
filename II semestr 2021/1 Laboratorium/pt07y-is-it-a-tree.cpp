#include <iostream>
#include <vector>
using namespace std;
short int l_wierz, l_kraw, a, b, korz;
short int tab[20000][2];
struct wierzch{
    char odw;
    vector <int> syny_id;
};
wierzch drzewo[10001];
short int w_glab(short int id){
     cerr <<"wirzcholek: "<< id<<endl;
    drzewo[id].odw++;
    if (drzewo[id].odw>'2')
        return 0;
    for (int j = 0; j < drzewo[id].syny_id.size(); ++j) {
        if(!w_glab(drzewo[id].syny_id[j]))
            return 0;
        }
    return 1;
    }

int main(){
    cin>>l_wierz>>l_kraw;
    for (int i = 0; i < l_kraw; ++i) {
        cin >> tab[i][0] >> tab[i][1];
       // if (tab[i][0] > tab[i][1])
         //   swap(tab[i][0], tab[i][1]);
    }
    for (int i=0; i < l_kraw; ++i) {
        if (i == 0) {
            korz = tab[i][0];}
        drzewo[tab[i][0]].syny_id.push_back(tab[i][1]);
        drzewo[tab[i][0]].odw = '1';
        drzewo[tab[i][1]].odw = '1';

    }
    /*
    for (int i = korz; i <= l_wierz; ++i) {
        cerr <<"wirzcholek: "<< i<<endl;
        for (int j = 0; j < drzewo[i].syny_id.size(); ++j) {
            cerr << drzewo[i].syny_id[j]<< " ";}
    }
    */
    if (l_wierz==l_kraw+1 &&w_glab(korz))
            cout<<"YES";
    else cout<<"NO";
}