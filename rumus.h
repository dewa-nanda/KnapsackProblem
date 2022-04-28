#include <iostream>

using namespace std;

class Knapsack{
    private:
        int W;
        int Wt[100];
        int Val[100];
        int Kk;
    public:
        int n;

        void input();
        int max(int , int);
        int proses(int, int[], int[] , int);
        void output();
        Knapsack();
};

Knapsack::Knapsack(){
    cout << "===Selamat Datang di program knapsack===" << endl;
    cout << "Nama : Dewa Putra Hernanda" <<endl;
    cout << "Nim  : 2000018270" <<endl<<endl;

}
void Knapsack::input(){
    cout << "Masukan panjang array : ";
        cin >> n;
    cout << "Masukan panjang total bobot" <<endl;
    for(int i = 0; i < n; i++){
        cout << i+1 << " : ";
            cin >> Wt[i];
    }
    cout << "\nMasukan total keuntungan" <<endl;
    for(int i = 0; i < n; i++){
        cout << i+1 << " : ";
            cin >> Val[i];
    }
    cout << "\nMasukan kapasitas Knapsack : ";
        cin >> Kk;
}

int Knapsack::max(int a,int b){
    return (a > b) ? a : b;
}

int Knapsack::proses(int W, int Wt[], int val[], int n){
    if (n == 0 || W == 0)
        return 0;

    if (Wt[n - 1] > W)
        return proses(W, Wt, val, n - 1);
  
    else
        return max(
            val[n - 1]
                + proses(W - Wt[n - 1], 
                           Wt, val, n - 1),
            proses(W, Wt, val, n - 1));
}

void Knapsack::output(){
    cout << "===Pencarian solusi Optimal Menggunakan Knapsack===" <<endl;
    for(int i = 0; i < n; i++){
        cout << "W" << i+1 << " : " << Wt[i] << " | " << "p" << i+1 << " : " << Val[i] <<endl;
    }
    cout << "Kapasitas knapsack : " << Kk <<endl;
    cout << "Total Keuntungan   : " << proses(Kk, Wt, Val, n) <<endl;
}