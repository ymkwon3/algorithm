function solution(checkin, checkout) {
    let sum = 0;
    for(let i = 0; i < checkin.length; i++) {
        // 새벽 5시이거나 넘어갈 경우 24 + 5
        if(checkout[i] >= 29)
        // 체크아웃을 깜빡한 것으로 간주하여 21시로 처리
            checkout[i] = 21;
        sum += checkout[i] - checkin[i];
    }
    return sum;
}

console.log(solution([9, 9, 9, 9, 7, 9, 8], [23, 23, 30, 28, 30, 23, 23]))