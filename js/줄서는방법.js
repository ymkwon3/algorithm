function solution(n, k) {
    // 총 개수 구하기
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact *= i;
    }
    //
    console.log(k / (n - 1), k % (n - 1))
    return 0
}

solution(3, 6);

/* 
1 2 3 4 5 6 3의 팩토리얼
0 1 2 3 4 5 를 n-1로 각 자리수를 나눴을때의 math.floor 값의 + 1
1 1 2 2 3 3

다음 자리가 계속 몇번째인지? */