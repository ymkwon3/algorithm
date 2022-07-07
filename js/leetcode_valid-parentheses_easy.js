var isValid = function(s) {
    const stack = [];
    let rec;
    for(let i = 0; i < s.length; i++) {
      if(s[i] === '(' || s[i] === '{' ||  s[i] === '[') {
        stack.push(s[i]);
      }else {
        rec = stack.pop();
        if(rec === undefined || Math.abs(rec.charCodeAt() - s[i].charCodeAt()) > 2) {
          return false
        }
      }
    }
    return stack.length !== 0 ? false : true;
};

isValid("(]")