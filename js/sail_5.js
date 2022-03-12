// 문자열을 정수로 바꾸기


function solution(s) {
    let end_idx = 0;

    // 부호 여부 체크
    if(s[0] == '-' || s[0] == '+') {
        end_idx = 1;
    }

    // 부호가 아닌 범위까지 자릿 수를 곱하여 정수로 변환
    let result = 0, num = 1;
    for(let i = s.length - 1; i >= end_idx; i--, num  *= 10) {
        console.log(s[i] * num)
        result += s[i] * num;
    }

    // -부호가 있을경우
    if(s[0] == '-')
        result *= -1;
    return result;
}

solution("-1234")

// function solution(s) {
//     return Number(s);
// }