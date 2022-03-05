#include <bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int N){
    int minj;
    int counter = 0;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            counter++;
            swap(A[i], A[minj]);
        }
    }
    for(int i = 0; i < N; i++){
        if(i != N -1) cout << A[i] << " ";
        else cout << A[i] << endl; 
    }
    cout << counter << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    selectionSort(a, n);

    return 0;
}
