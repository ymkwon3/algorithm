// 문자열 다루기 기본

function solution(s) {
    if ((s.length == 4 || s.length == 6) && s == parseInt(s))
        return true; 
    return false;
}

console.log(solution("12e1"))