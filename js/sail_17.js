// 문자열 다루기 기본

function solution(s) {
    // 테스트케이스중에 "12e1" 같은 경우는 Number()를 썼을때, 12수의 지수승 1인 경우를 표현하여 parseInt(s)를 실행하면 12를 나타낸다. 즉 12e1을 정수로 변환한다면 에러없이 정수로 인지한다.
    if ((s.length == 4 || s.length == 6) && s == parseInt(s))
        return true; 
    return false;
}

console.log(solution("9c8a"))