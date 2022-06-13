// x만큼 간격이 있는 n개의 숫자

function solution(x, n) {
    let result = [];
    for(let i = 1; i <= n; i++) {
        result.push(x * i)
    }
    return result;
}

solution(2, 5)