/*
 * JS implementation for insertion sort, complexity O(n^2)
 */
insertion_sort = function(A) {
    for (j = 1; j < A.length; j++) {
        var key = A[j];
        var i = j - 1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;
    }
};

var A = [3, 41, 52, 26, 38, 57, 9, 49];
console.log("Before sort: " + A.toString())
insertion_sort(A)
console.log("After sort: " + A.toString())

