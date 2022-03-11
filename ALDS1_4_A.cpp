#include <bits/stdc++.h>
using namespace std;

/*Global*/
int S[10005];
int T[505];

int main(){
    int n, q;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> S[i];
        // cout << S[i] << " ";
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> T[i];
        // cout << T[i] << " ";
    }

    // 2重ループで愚直に実行する
    int counter = 0;

    for(int i = 0; i < q; i++){
        for(int j = 0; j < n; j++){
            if(T[i] == S[j]){
                counter++;
                break;
            }
        }
    }

    cout << counter << endl;
}
