var isPalindrome = function(x) {
    const xtoArr = x.toString().split("")
    console.log(xtoArr)
    for(let i = 0, j = xtoArr.length - 1; i <= j; i++, j--) {
      console.log(xtoArr[i], xtoArr[j]);
    }
};

isPalindrome(1235321);