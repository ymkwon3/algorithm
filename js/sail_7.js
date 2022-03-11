// 음양 더하기

function solution(absolutes, signs) {
    let result = 0;
    for(const i in absolutes) {
        result += absolutes[i] * (signs[i] ? 1 : -1);
    }
    console.log(result)
    return(result)
}

solution([4, 7, 12], [true, false, true])