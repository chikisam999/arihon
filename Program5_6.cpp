#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    // ベクタの先頭から順番にアクセス
    vector<int>::iterator it;
    for( it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << endl;
}

int main(){
    int N = 4;
    vector<int> v;

    for(int i = 0; i < N; i++ ){
        int x;
        cin >> x;
        v.push_back(x);
    }

    print(v);

    vector<int>::iterator it = v.begin();
    *it = 3; //先頭要素v[0]を3にする。
    it++; // 1つ前に進める。
    (*it)++; // v[1]の要素に1加算する

    print(v);

    return 0;
}
