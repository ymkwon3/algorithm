// 없는 숫자 더하기

function solution(numbers) {
    let result = 45;

    for(const n of numbers) {
        result -= n;
    }
    console.log(result)
    return result;
}

solution([1,2,3,4,6,7,8,0]);