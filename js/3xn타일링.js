function solution(n) {
    let list = [0, 0, 3, 0, 11, 0];
    for (let i = 6; i <= n; i++) {
        if (i % 2 === 1) {
            list.push(0);
        } else {
            list.push((list[2] * list[i - 2] + 2) % 1000000007);
        }
    }

    return list[n];
}