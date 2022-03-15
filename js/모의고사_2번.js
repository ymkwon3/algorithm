function solution(month, day) {
    let m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    day += 98;
    while(true) {
        if(month > 12) {
            month = 1;
            continue;
        }
        if (day > m[month - 1]){
            day -= m[month++ - 1];
        } else break;
    }
    return `${month}월 ${day}일`
}

console.log(solution(12, 31))