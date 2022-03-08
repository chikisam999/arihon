#include<bits/stdc++.h>
using namespace std;

/*wront answerのままです*/

// Global Params
queue<string> op;
deque<long long> nums;

int main(){
    long long n,itr;
    cin >> n;
    /*入力処理(intもstringで受け取り)_Queueで管理*/
    while(!cin.eof()){
        string tmp;
        cin >> tmp;
        op.push(tmp);
    }

    /*numsに対して数値を命令に沿って格納*/
    while(!op.empty()){
        string tmp;
        tmp = op.front();

        if(tmp == "insert"){
            op.pop();
            long long num = stoi(op.front());
            nums.push_front(num);
            op.pop();
        }else if (tmp == "delete"){
            op.pop();
            long long num = stoi(op.front());
            /*numを探してきてその番号の位置を取得*/
            itr = -1;
            for(int i = 0; i < nums.size(); i++){
                if(itr != -1) break;
                if(nums.at(i) == num){
                    itr = i;
                }
            }
            if(itr != -1){
            /*itr番目を無視してdequeを作り直し泣*/
            deque<long long> nums_t;
            //cout << "nums_t1:" << nums_t.size() << endl;
            long long counter = 0;
            while(!nums.empty()){
                // cout << "Counter:" << counter << endl;
                if(counter != itr){
                nums_t.push_back(nums.front());
                nums.pop_front();
                counter++;
                }else{
                nums.pop_front();
                counter++;
                }
            }
            nums = nums_t;
            //cout << "nums_t2:" << nums_t.size() << endl;
            }
            op.pop();
            
        }else if (tmp == "deleteFirst"){
            op.pop();
            nums.pop_front();
        }else{ // tmp == "deleteLast"
            op.pop();
            nums.pop_back();
        }
    }
    // cout << "sise of nums is : "<< nums.size() << endl;
    /*標準出力*/
    for(int i = 0; i < nums.size(); i++){
        if (i != nums.size() - 1){
            cout << nums.at(i) << " ";
        }else{
            cout << nums.at(i) << endl;
        }
    }
}
