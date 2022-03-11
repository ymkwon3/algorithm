// 나누어 떨어지는 숫자 배열

function solution(arr, divisor) {
    var answer = [];
    for (const a of arr) {
        if(a % divisor == 0) {
            answer.push(a)
        }
    }
    answer.sort(function(a, b){
        return a - b;
    });
    if(answer.length == 0)
        answer.push(-1);
    return answer;
}

solution([2, 36, 1, 3], 1)