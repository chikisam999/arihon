#include<bits/stdc++.h>
using namespace std;

// Global
stack<int> s;

int main(){
    string tmp;
    while(cin >> tmp){
        int op1, op2, ans;
        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
            if(tmp == "+"){
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                ans = op1 + op2;
                s.push(ans);
            }
            else if(tmp == "-"){
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                ans = op2 - op1;
                s.push(ans); 
            }
            else{
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                ans = op2 * op1;
                s.push(ans); 
            }
        }else{
            int tmp_int;
            tmp_int = stoi(tmp);
            s.push(tmp_int);
        }
    }

    cout << s.top() << endl;
}
