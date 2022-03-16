function solution(n) {
    let sum = n;
    if (n == 1) return sum;
    for(let i = 1; i <= Math.ceil(n/2); i++) {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

console.log(solution(1))

//http://haah.kr/2017/06/12/rest-the-big-lie/