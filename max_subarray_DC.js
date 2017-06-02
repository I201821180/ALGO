/*
 * Find max subarray using divide and conquer method, complexity O(NlogN).
 */
var add = function(a, b) {
    return a + b;
};

find_max_cross_subarray = function(A) {
    var mid = parseInt(A.length/2);
    // Left.
    var max_left_sum = -Infinity;
    var left = 0;
    for (var i = 0; i < mid; i++) {
        var sum = A.slice(i, mid).reduce(add, 0);
        if (sum > max_left_sum) {
            max_left_sum = sum;
            left = i;
        }
    }

    // Right.
    var max_right_sum = -Infinity;
    var right;
    for (var i = mid+1; i <= A.length; i++) {
        var sum = A.slice(mid, i).reduce(add, 0);
        if (sum > max_right_sum) {
            max_right_sum = sum;
            right = i;
        }
    }

    return A.slice(left, right+1);
};

find_max_subarray = function(A) {
    if (A.length <= 1) {
        return A;
    } else {
        var mid = parseInt(A.length/2);
        var left = arguments.callee(A.slice(0, mid));
        var right = arguments.callee(A.slice(mid));
        var middle = find_max_cross_subarray(A);

        var left_sum = left.reduce(add, 0);
        var right_sum = right.reduce(add, 0);
        var middle_sum = middle.reduce(add, 0);

        if (left_sum > right_sum && left_sum > middle_sum) {
            return left;
        } else if (right_sum > left_sum && right_sum > middle_sum) {
            return right;
        } else {
            return middle;
        }
    }
};


A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7];
max_subarray = find_max_subarray(A);
console.log("Max subarray: " + max_subarray.toString());

