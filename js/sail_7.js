// 음양 더하기

function solution(absolutes, signs) {
    let result = 0;

    for(let i = 0; i < absolutes.length; i++) {
        // absolutes 와 signs의 배열 인덱스를 같이 사용하기 때문에,
        // 각 absolutes를 더해주면서 signs가 false일 경우에만 -로 계산해줌
        result += absolutes[i] * (signs[i] ? 1 : -1);
    }
    return(result)
}

solution([4, 7, 12], [true, false, true])