function solution(n) {
    let list = [0, 1, 2, 3];
    for (let i = 4; i <= n; i++) {
        list.push((list[i - 1] + list[i - 2]) % 1000000007)
    }
    return list[n];
}