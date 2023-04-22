#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int a,b,c,heapMIN[1000000],heapMAX[1000000],rozm=0,MAXsize=0,MINsize=0;
long long int suma=0;
using namespace std;
//przywracanie struktury po dodaniu elementu MIN
void push_upMIN(int idx){
    int son=idx;
    int father=idx/2;
    while (father>0 && heapMIN[father]>heapMIN[son]){
        swap(heapMIN[father],heapMIN[son]);
        son=father;
        father=son/2;
    }

}
//dodawanie elementu MIN
void insertMIN(int e){
    ++MINsize;
    heapMIN[MINsize]=e;
    push_upMIN(MINsize);

}
// praywracanie struktury po usunieciu korzenia MIN
void push_downMIN(int idx){
    int father = idx;
    int son = 2*idx;

    while (son<= MINsize){
        if (son<MINsize && heapMIN[son+1]<heapMIN[son]){
            ++son;
        }
        if( heapMIN[son]<heapMIN[father]){
            swap(heapMIN[son],heapMIN[father]);
            father =son;
            son= father*2;
        } else break;
    }

}

//usuwanie i pobieranie 1 elementu MIN
int popMIN(int szuk){
    int i = 1;
    while (szuk!=heapMIN[i]){
        i++;
    }
    int res = heapMIN[i];
    heapMIN[i] = heapMIN[MINsize];
    --MINsize;
    push_downMIN(i);
    return res;
}
int main() {
    cin>>a;
    /*for (int j=0; j<a; j++){
        cin>>b;
        insertMIN(b);}

    for (int j=0; j<a; j++){
        cout<<heapMIN[1]<<" ";
        cin>>c;
        cout<<popMIN(c)<<" ";}*/
    for (int j=0; j<a; j++){
        cin>>b;
        if (b==1){
            cin>>c;
            insertMIN(c);
        }
        else if (b==2){
            cin>>c;
            popMIN(c);
        }

        else if (b==3){
            cout<<heapMIN[1]<<endl;
        }
    }
    return 0;
}
