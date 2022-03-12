// 나누어 떨어지는 숫자 배열

function solution(arr, divisor) {
    var answer = [];
    for (let i = 0 ; i < arr.length; i++) {
        if(arr[i] % divisor == 0) {
            answer.push(arr[i])
        }
    }
    answer.sort(function(a, b){
        return a - b;
    });
    if(answer.length == 0)
        answer.push(-1);
    return answer;
}

console.log(solution([3, 2, 6], 10))