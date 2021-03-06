#include<bits/stdc++.h>
using namespace std;

/*これは与えられた荷物を順番にトラックに詰むことを条件に加味していないのでNGです*/

int main(){
    /* 荷物の個数n個、トラックの台数 k台 */
    int n, k;
    vector<int> w;
    cin >> n >> k;
    /* i番目の荷物の重量w[i]を入力 */
    for( int i = 0; i < n; i++ ){
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
    }
    /*トラックに詰んだ荷物の重さを配列で管理する*/
    vector<int> truck(k);

    /*配列wをソートする*/
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    /*とりあえずでかい順にトラックに積み込みます。*/
    for(int i = 0; i < k; i++){
        auto max = max_element(w.begin(), w.end());
        truck.at(i) = *max;
        // cout << truck.at(i) << " ";
        w.erase(max);
    }

    /*重さが最小のトラックに、一番重い荷物をぶち込みつづける*/
    while(!w.empty()){
        auto max_load = max_element(w.begin(), w.end());
        auto min_truck = min_element(truck.begin(), truck.end());
        *min_truck += *max_load;
        w.erase(max_load);
    }
    /*
    for(int i = 0; i < k; i++){
        cout << truck.at(i) << " ";
    }
    */

    /*答えを出力する。積載量が最大のトラックが出力*/
    auto P = max_element(truck.begin(), truck.end());
    cout << *P << endl;
}
