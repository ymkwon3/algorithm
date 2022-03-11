// 내적

function solution(a, b) {
    var answer = 0;

    for (const i in a) {
        answer += a[i] * b[i];
    }
    
    return answer;
}

solution([1,2,3,4], [-3,-1,0,2]);