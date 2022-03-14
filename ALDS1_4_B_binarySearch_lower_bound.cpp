#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int A[1000000], n;

/*lower_boundは指定した値k以上の値を持つイテレータを返す。
*itrで直接値を取得できるため、lower_boundによるitrが、
*itr == kを満たした場合、kが存在することが確かめられる。
てかこれ、バイナリサーチじゃない。*/

int main(){
    cin >> n;
    for( int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int q, k, sum = 0;
    cin >> q;
    for ( int i = 0; i < q; i++){
        scanf("%d", &k);
        // 標準ライブライブラリのlower_boundを使用する。
        if( *lower_bound(A, A + n, k) == k) sum++;
    }

    cout << sum << endl;

    return 0;
}
