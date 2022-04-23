// 최대공약수와 최소공배수

const gcd = (max, min) => max % min == 0 ? min : gcd(min, max % min);

const lcm = (max, min) => max * min / gcd(max, min);

const solution = (n, m) => n > m ? [gcd(n, m), lcm(n,m)] : [gcd(m, n), lcm(m, n)];

console.log(solution(3, 12));





// function gcd(max, min) {
//     if (max % min === 0) return min;
//     if (max % min !== 0) return gcd(min, max % min);
// }

// function lcm(max, min) {
//     return (max * min) / gcd(max, min);
// }

// function solution(n, m) {
//     return n > m ? [gcd(n, m), lcm(n, m)] : [gcd(m, n), lcm(m, n)];
// }