// 2016년

function solution(a, b) {
    let days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    let week = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]
    let day = 0;
    for(let i = 0; i < a - 1; i++) {
        day += days[i];
    }
    day += b;
    console.log(week[day % 7])
    return week[day % 7];
}

solution(1, 7);