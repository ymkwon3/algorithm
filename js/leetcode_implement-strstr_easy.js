/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
 var strStr = function(haystack, needle) {
    let ans = haystack.indexOf(needle)
    console.log(ans)
    return ans;
};

strStr("aaaaa", "bba")