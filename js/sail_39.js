// 시저 암호

function solution(s, n) {
    const c = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let ans = "";
    for(let i = 0; i < s.length; i++) {
        if(s[i] == ' ')
            ans += " ";
        else {
            ans += c[c.indexOf(s[i]) + n];
        }
    }
    return ans;
}

console.log(solution("AB", 1));