#include<iostream>
#include<algorithm>
using namespace std;

/*distanceとlower_boundの使用方法を学びましょう。
lower_boundが返すのはイテレータです。*/

int main(){
    int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int *pos;
    int idx;

    //lower_bound(開始点, 終了店, ここで指定した値以上の最初の要素の位置をイテレータとして出力する。)
    pos = lower_bound(A, A + 14, 3);
    idx = distance(A, pos);
    cout << "A[" << idx << "] = " << *pos << endl; // A[5] = 4

    pos = lower_bound(A, A + 14, 2);
    idx = distance(A, pos);
    cout << "A[" << idx << "] = " << *pos << endl; // A[2] = 2

    return 0;
}
