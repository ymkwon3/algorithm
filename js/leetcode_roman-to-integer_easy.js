var romanToInt = function(s) {
  const symbols = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000};
  let sum = 0;
  let prev = 0, cur;
  for(let i = 0; i < s.length; i++) {
    cur = symbols[s[i]];
    if(prev && cur > prev) {
      sum += cur - 2 * prev;
    }else {
      sum += cur;
    }
    prev = cur;
  }
  console.log(sum)
  return sum;
}

romanToInt('MCMXCIV')