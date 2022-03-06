#include <bits/stdc++.h>
using namespace std;

// Global
queue<int> qi;
queue<string> qs;

int main(){
    int n,q,timer;
    cin >> n >> q;
    timer = 0;

    for(int i = 0; i < n; i++){
        int tmp_int;
        string tmp_str;
        cin >> tmp_str >> tmp_int;
        qs.push(tmp_str);
        qi.push(tmp_int);
    }

    while(!qs.empty() && !qi.empty()){
        int exe;
        string process;
        exe = qi.front();
        process = qs.front();
        qi.pop();
        qs.pop();
        if(exe - q > 0){ // まだ処理途中の時
            exe -= q;
            qi.push(exe);
            qs.push(process);
            timer += q;
        }else{ //処理が完了する場合
            timer += exe;
            cout << process << " " << timer << endl;
        }
    }

    /*
    // 標準入力のチェック用print
    for(int i = 0; i < n; i++){
        cout << qs.front() << " ";
        qs.pop()
        cout << qi.front() << endl; 
    }
    */
    
    return 0;
}
