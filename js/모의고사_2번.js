// 날짜가 입력되면 해당 날짜에서부터 98일이 지난 날짜를 출력해주라


function solution(month, day) {
    let m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    day += 98;
    
    while(true) {
        if(month == 13)
            month = 1 ;

        if(day > m[month - 1]) {
            day -= m[month++ - 1];
        }else break;
        
    }
    return `${month}월 ${day}일`;
}

console.log(solution(12, 30))