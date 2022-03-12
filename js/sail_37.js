// 소수 만들기

function isPrime(num) {
    if(num == 2)
        return true;
    if(num % 2 == 0)
        return false;
    for(let i = 3; i <= Math.sqrt(num); i += 2) {
        if(num % i == 0)
            return false;
    }
    return true;
}

function solution(nums) {
    let cnt = 0;
    for(let i = 0; i < nums.length - 2; i++) {
        for(let j = i + 1; j < nums.length - 1; j++) {
            for(let k = j + 1; k < nums.length; k++) {
                cnt += isPrime(nums[i]+nums[j]+nums[k]) ? 1 : 0;
            }
        }
    }
    return cnt;
}

console.log(solution([1,2,3,4]))