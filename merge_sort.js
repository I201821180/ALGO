/*
 * Javascript implementation for merge sort, complexity O(NlogN)
 */

var merge = function(L, R) {
    var A = L.concat(R);
    L.push(Infinity);
    R.push(Infinity);

    var i = j = 0;
    for (var k = 0; k < A.length; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    return A;
};

var merge_sort = function(A) {
    if (A.length > 1) {
        var q = parseInt(A.length/2);
        var L = A.slice(0, q);
        var R = A.slice(q);
        L = merge_sort(L);
        R = merge_sort(R);
        return merge(L, R);
    } else {
        return A;
    }
};

var A = [3, 41, 52, 26, 38, 57, 9, 49];
console.log("Before sort: " + A.toString())
var B = merge_sort(A)
console.log("After sort: " + B.toString())

