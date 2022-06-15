function solution(n) {
    let list = [0, 1, 2, 3];
    let value = 0;
    for (let i = 4, j = 0; i <= n; i++, j++) {
        value = list[i - 1] - 1;
        value = value * 2 - 2 ** j;
        if (i % 2 === 0) {
            //n이 짝수일 경우
            value += 2;
        } else {
            //n이 홀수일 경우
            value += 1;
        }
        list.push(value)
    }
    return list[n];
}

solution(5)