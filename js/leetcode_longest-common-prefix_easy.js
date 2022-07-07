var longestCommonPrefix = function(strs) {
    let minNum = 99999;
    let ans = "";
    let tmp = "";
    for(let i = 0; i < strs.length; i++) {
      if(strs[i].length < minNum)
        minNum = strs[i].length;
    }
    
    for(let i = 0; i < minNum; i++) {
      tmp = strs[0][i];
      for(let j = 0; j < strs.length; j++) {
        if(tmp !== strs[j][i]) {
          return ans;
        }
      }
      ans += tmp;
    }
    return ans;
};

longestCommonPrefix(["flower","flow","flight"])