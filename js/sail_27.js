// 콜라츠 추측

function solution(n) {
    let ans = 0;
    if (n == 1) return ans;
    while(true) {
        if(n % 2 == 0) {
            n /= 2;
        }else {
            n = n * 3 + 1;
        }
        ans++;
        if(n == 1) return ans;
        else if (ans > 500) return -1;
    }
}

console.log(solution(6))