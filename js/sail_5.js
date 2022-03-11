// 문자열을 정수로 바꾸기


function solution(s) {
    let end_idx = 0;
    if(s[0] == '-' || s[0] == '+') {
        end_idx = 1;
    }

    let result = 0, num = 1;
    for(let i = s.length - 1; i >= end_idx; i--, num  *= 10) {
        console.log(s[i] * num)
        result += s[i] * num;
    }
    if(s[0] == '-')
        result *= -1;
    console.log(result)
    console.log(typeof result)
}

solution("-1234")

// function solution(s) {
//     return Number(s);
// }