// 짝수와 홀수

function solution(num) {
    let result = '';
    
    if(num % 2 == 0) {
        //짝수
        result = "Even"
    }else {
        //홀수
        result = "Odd"
    }
    return result;
}