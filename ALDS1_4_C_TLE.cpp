#include<bits/stdc++.h>
using namespace std;

vector<string> s(1000005);

/*以下の全探索はTLEになる!*/

int main(){
    int n, counter = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        counter++;
        string tmp_q, tmp_s;
        cin >> tmp_q;
        if(tmp_q == "insert"){
            cin >> tmp_s;
            s.at(i) = tmp_s;
        }else{
            int flag = 0;
            cin >> tmp_s;
            for(int j = 0; j < counter; j++){
                if(tmp_s == s.at(j)){
                    flag++;
                }
            }
            if(flag == 0){
                cout << "no" << endl;
            }else{
                cout << "yes" << endl;
            }
        }
    }
}
