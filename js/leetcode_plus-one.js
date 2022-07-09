/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  let num = 1;
  for(let i = digits.length - 1; i >= 0; i--) {
    digits[i] += num;
    if(digits[i] === 10) {
      digits[i] = 0;
      num = 1;
      if(i === 0) {
        digits.unshift(1)
      }
    }else {
      num = 0;
    }
  }     
  return digits;
};

plusOne([9, 9, 9]);