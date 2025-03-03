#include <iostream>
using namespace std;


int** allouerMatrice(int n, int m){
    int** matrice= new int*[n];
    for (int i=0;i<n;i++){
        matrice[i]= new int[m];
    }
    return matrice;
}

void initialiserMatrice(int** matrice,int n ,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << "entrer la valeur de matrice["<<i<<"]["<<j<<"] : ";
            cin >> matrice[i][j];
        }

    }
}
void printMatrice(int** matrice,int n ,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<matrice[i][j]<<" ";
        }
        cout<<endl;
    }
}

int** transposerMatrice(int** matrice,int n ,int m){
    int** mat_tr= allouerMatrice(m,n);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            mat_tr[j][i]=matrice[i][j];
        }
    }
    return mat_tr;
}

void libererMatrice(int** matrice,int n ,int m){
    for(int i=0;i<n;i++){
        delete[] matrice[i];
    }
    delete[] matrice;

}
int main(){
    int n,m;
    cout<<"entrer la valeur de n : ";
    cin >>n;
    cout<<"entrer la valeur de m : ";
    cin >>m;
    int** matrice= allouerMatrice(n,m);
    initialiserMatrice(matrice,n,m);
    cout<<"matrice initiale: "<<endl;
    printMatrice(matrice,n,m);
    int** transpose=transposerMatrice(matrice,n,m);
    cout<<"matrice transpose: "<<endl;
    printMatrice(transpose,m,n);
    // Libération de la mémoire
    libererMatrice(matrice, n, m);
    libererMatrice(transpose, m, n);  // Libérer aussi la matrice transposée


    return 0;
}