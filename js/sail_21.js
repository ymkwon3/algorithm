// 이상한 문자 만들기

function solution(s) {
    let answer = "";
    for(let i = 0, index = 0; i < s.length; i++) {
        if(s[i] == ' ') {
            answer += ' ';
            index = 0;
        }else {
            if(index % 2 == 0) {
                answer += s[i].toUpperCase();
            }else {
                answer += s[i].toLowerCase();
            }
            index++;
        }
    }
    return answer;
}

solution(" try  hello   world ");