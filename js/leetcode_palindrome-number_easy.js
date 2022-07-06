var isPalindrome = function(x) {
    const xtoArr = x.toString().split("")
    for(let i = 0, j = xtoArr.length - 1; i <= j; i++, j--) {
      if(xtoArr[i] !== xtoArr[j])
        return false;
    }
    return true;
};

isPalindrome(1235321);