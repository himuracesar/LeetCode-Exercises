/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    var start = 0;
    var end = s.length - 1;

    while(start < end)
    {
        var aux = s[start];
        s[start] = s[end];
        s[end] = aux;

        start++;
        end--;
    }
};