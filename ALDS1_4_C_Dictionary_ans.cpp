#include<stdio.h>
#include<string.h>

#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

// 文字から数値に変換
int getChar(char ch){
    if( ch == 'A' ) return 1;
    else if( ch == 'C') return 2;
    else if( ch == 'G') return 3;
    else if ( ch == 'T') return 4;
    else return 0;
}

// 文字列から数値に変換してkeyを生成する。
long long getKey(char str[]){
    long long sum = 0, p = 1, i;
    for( i = 0; i < strlen(str); i++){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key) { return key % M; }
// h2が0になると、hは更新されずに無限ループになる。
// よってh2 != 0を保障する必要があるために、1を足している。
int h2(int key) { return 1 + (key % (M-1)); }

int find(char str[]){
    long long key, i, h;
    key = getKey(str); // 文字列を数値に変換
    for ( i = 0;; i++){
        h = (h1(key) + i * h2(key)) % M;
        // strcmp関数は引数1,2が文字列として一致した場合にreturn 0 となる。
        if( strcmp(H[h], str) == 0) return 1;
        else if ( strlen(H[h]) == 0) return 0;
    }
    return 0;
}

int insert(char str[]){
    long long key, i, h;
    key = getKey(str); //文字列を数値に変換
    for( i = 0; ; i++){
        h = (h1(key) + i * h2(key)) % M;
        if( strcmp(H[h], str) == 0) return 1;
        // keyとして生成したh番目が空いているときだけ、マップに挿入できる。
        else if(strlen(H[h]) == 0) {
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}

int main(){
    int i, n, h;
    char str[L], com[9];
    for(i=0; i < M; i++) H[i][0] = '\0';
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %s", com, str); // より高速なscanfを使用する

        if(com[0] == 'i'){
            insert(str);
        }else{
            if(find(str)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}
