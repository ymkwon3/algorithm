// 숫자 문자열과 영단어

function solution(s) {
    const numbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    let str = s;
    for(let i = 0; i < numbers.length; i++) {
        str = str.split(numbers[i]).join(i)
    }
    return parseInt(str);
}

console.log(solution("one4seveneightonetwo"));