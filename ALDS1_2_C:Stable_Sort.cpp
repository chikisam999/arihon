#include <bits/stdc++.h>
using namespace std;

//グローバル変数としてめんどくさいので、配列を定義
vector<string> s(36,"-1");
vector<string> s_raw(36);

vector<string> BubbleSort(vector<string> C, int N){
    for(int i = 1; i < N; i++){
        for (int j = N - 1; j >= i; j--){
            if(stoi(C.at(j).substr(1)) < stoi(C.at(j-1).substr(1))){
                swap(C.at(j), C.at(j-1));
            }
        }
    }
    for(int i = 0; i < N; i++){
        if (i != N - 1) cout << C.at(i) << " ";
        else cout << C.at(i) << endl;
        }
    
    return C;
}

vector<string> SelectionSort(vector<string> C, int N){
    int minj;
    for(int i = 0; i < N; i++){
        minj = i;
        for (int j = i; j < N; j++){
            if (stoi(C.at(j).substr(1)) < stoi(C.at(minj).substr(1))){
                minj = j;
            }
        }
        swap(C.at(i), C.at(minj));
    }
    for(int i = 0; i < N; i++){
        if (i != N - 1) cout << C.at(i) << " ";
        else cout << C.at(i) << endl;
    }
    return C;
}

void isStable(vector<string> vec_cin,vector<string> vec_sorted, int N){
    vector<string> vec_tmp(36);
    vec_cin = s_raw;
    sort(vec_cin.begin(), vec_cin.end());


    /*
    // 確認でつかいました
    for(int i = 0; i < N; i++){
        cout << vec_cin.at(i) << " ";
    }
    */

    if (vec_sorted == vec_cin) cout << "Stable" << endl;
    else cout << "Not Stable" << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.at(i) = tmp;
        s_raw.at(i) = tmp;
    }

    auto ans1 = BubbleSort(s,n);
    cout << "Stable" << endl;
    if (ans1 == SelectionSort(s,n)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    return 0;
}
