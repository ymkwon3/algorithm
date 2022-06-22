function solution(n) {
    let list = [0, 0, 3, 0, 11, 0];
    if (n == 2)
        return list[2];
    if (n == 4)
        return list[4];
    for (let i = 6; i <= n; i++) {
        if (i % 2 === 1) {
            list.push(0);
        } else {
            list.push((list[2] * list[i - 2] + 2) % 1000000007);
        }
    }

    return list[n];
}

solution(4);

/* 
홀수일경우는 무조건 0??
무엇인가 규칙성이 있을 것 같다 dp로 풀 수 있을듯한?

*/