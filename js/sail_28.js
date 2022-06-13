// 하샤드 수

function solution(x) {
    let tmp = x, sum = 0;
    while(tmp > 0) {
        sum += tmp % 10;
        tmp = Math.floor(tmp / 10);
    }
    return x % sum == 0 ? true : false;
}

console.log(solution(13));