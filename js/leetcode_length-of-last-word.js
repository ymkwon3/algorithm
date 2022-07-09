/**
 * @param {string} s
 * @return {number}
 */
 var lengthOfLastWord = function(s) {
    const arr = s.trim().split(/\s+/);
    console.log(arr)
    return arr[arr.length - 1].length
};

lengthOfLastWord("   fly me   to   the moon  ");