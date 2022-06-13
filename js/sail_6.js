// 없는 숫자 더하기

function solution(numbers) {
    // 0~9까지의 없는 수를 구하는 것이고, 각 원소는 중복되지 않기 때문에, 처음 합을 45로 지정할 수 있다.
    let result = 45;

    // 배열에 존재하는 숫자를 빼준다
    for(let i = 0 ; i < numbers.length; i++) {
        result -= numbers[i];
    }
    console.log(result)
    return result;
}

solution([1,2,3,4,6,7,8,0]);