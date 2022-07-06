function isPrime(num) {
    if (num === 1)
        return 0;
    if (num === 2 || num === 3) {
        return 1;
    }
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0 && num / i <= 10000000) {
            return num / i;
        }
    }
    return 1;
}

function solution(begin, end) {
    var answer = [];
    for (let i = begin; i <= end; i++) {
        answer.push(isPrime(i))
    }
    return answer;
}

solution(1, 10);