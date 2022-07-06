function solution(n) {
    let list = [0, 0, 3, 0];
    let a, b, c;


    if (n == 2)
        return list[2];
    for (let i = 4; i <= n; i++) {
        b = 0
        if (i % 2 === 1) {
            list.push(0);
        } else {
            a = list[i - 2] * list[2];
            for (let j = 0; j <= i - 4; j += 2)
                b += 2 * list[j];

            c = 2;
            list.push((a + b + c) % 1000000007);
        }
    }
    return list[n];
}

solution(6);

/* 
홀수일경우는 무조건 0??
무엇인가 규칙성이 있을 것 같다 dp로 풀 수 있을듯한?
f(6) = f(4) * 3 + 2 * f(2) + 2
f(8) = f(6) * 3 + 2 * f(4) + 2 * f(2) + 2
=> f(6) * 3 + 2 * (f(4) + f(2)) + 2 로 줄일 수 있겠음
*/