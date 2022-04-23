// 핸드폰 번호 가리기

function solution(phone_number) {
    let result = "";
    for(let i = 0; i < phone_number.length - 4; i++) {
        result += '*';
    }
    result += phone_number.substr(phone_number.length - 4)
    return result
}

solution("01033334444");