#include <stdio.h>
using namespace std;

// 線形探索
int search(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    while(A[i] != key) i++;
    return i != n;
    // iが最後の番兵nに到達してしまったら値が存在しない。
    // i != nがfalseとなる。（一致無し)
}

int main(){
    int i, n, A[10000 + 1], q, key, sum = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        if (search(A, n, key)) sum++;
    }
    printf("%d\n", sum);

    return 0;
}
