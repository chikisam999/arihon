#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[20];

// i == nまで探索したときに、sum == kがtrue or falseを判定する。
// ただし、i to i + 1への推移において、iを使うor使わないの2通りの条件分岐が存在する。
// この条件分岐を再帰関数を用いて記述する。
// どちらの分岐の際にも、結局の所i == nでsum == kがtrue　or falseであるかどうかで
// 返り値をtrueにするかどうかを判定している。
// a[i]を使う使わないでも、trueではない場合は、最後の行のreturn falseでfalseとなる。

bool dfs(int i, int sum){
    // n個決め終わったら、今までの和sumがkと等しいかを返す
    if (i == n) return sum == k;

    // a[i]を使わない場合
    if(dfs(i+1, sum)) return true;

    // a[i]を使う場合
    if (dfs(i+1, sum + a[i])) return true;

    // a[i]を使う使わないにかかわらずkが作れないのでfalseを返す
    return false;
}

void solve(){
    if (dfs(0,0)) printf("Yes\n");
    else printf("No\n");
}

int main(){
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve();
}
