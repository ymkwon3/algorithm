const n = 3;
const m = 12;
solution(n, m);
function gcd(max, min) {
  if (max % min === 0) return min;
  if (max % min !== 0) return gcd(min, max % min);
}

function lcm(max, min) {
  return (max * min) / gcd(max, min);
}

function solution(n, m) {
  return n > m ? [gcd(n, m), lcm(n, m)] : [gcd(m, n), lcm(m, n)];
}
