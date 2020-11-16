/*
N개의 시험장, 각각의 시험장 i에 A명의 응시자
한 시험장에 한 명의 총감독관만 존재, 부감독관은 상관 없음
총감독관 감시 가능 수 B명
부감독관 감시 가능 수 C명
각 시험장마다 응시생 모두 감시해야함, 필요한 감독관의 수의 최솟값을 구하는 프로그램
!! 범위에 따른 자료형 선택이 매우 중요...
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long minimum(vector<long long> a, int b, int c){ // 각 시험장의 응시수에 따른 감독관의 최소값을 구함
    long long min = 0;
    for(long long i = 0; i < a.size(); i++){
        if((a[i] - b) <= 0){
            min += 1;
        }else{
            min += (long long)ceil(double(a[i] - b) / c) + 1;
        }
    }
    return min;
}

int main(void){
    long long i;
    int b, c;

    scanf("%lld", &i); // 시험장의 개수 입력

    vector<long long> a(i, 0);

    for(int k = 0; k < i; k++){
        scanf("%lld", &a[k]); // 각 시험장의 응시자 수 입력
    }

    scanf("%d %d", &b, &c); // 감독관이 감시할 수 있는 응시자 수 입력

    printf("%lld\n", minimum(a, b, c)); // 결과값 출력
    
    return 0;
}