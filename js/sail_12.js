// 부족한 금액 계산하기

function solution(price, money, count) {
    var answer = 0;
    for(let i = 1; i <= count; i++) {
        answer += price * i;
    }
    
    // 횟수에 비례하여 인상되는 요금을 계산하여 합을 구하고, 이 비용이 내가 가진 금액과 비교해준다.
    
    answer = answer - money > 0 ? answer - money : 0;

    return answer;
}

solution(3, 20, 4)