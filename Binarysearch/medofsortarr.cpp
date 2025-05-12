/*fuckedup question dunno why it exists
    anyway heres the intuition-
    Given two sorted arrays A and B, find a partition such that:
    left side (of both arrays combined) has the same number of elements as the right side (or one extra if total is odd)
All elements on the left side ≤ all elements on the right side
Once you get that, the median is:
Max of the left side if total elements odd
Average of max left & min right if even

You're essentially finding the correct split point where left half's maximum ≤ right half's minimum in a 
combined sorted array without actually merging the two arrays — by cleverly choosing positions in A and B via binary search.
check the edge cases thats where this q becomes hard
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size();
        int n = B.size();
        int st = 0, end = m;

        while (st <= end) {
            int m1 = (st + end) / 2;
            int m2 = (m + n + 1) / 2 - m1;

            // Left parts
            int maxLeftA = (m1 == 0) ? INT_MIN : A[m1 - 1];
            int maxLeftB = (m2 == 0) ? INT_MIN : B[m2 - 1];

            // Right parts
            int minRightA = (m1 == m) ? INT_MAX : A[m1];
            int minRightB = (m2 == n) ? INT_MAX : B[m2];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0)
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                else
                    return max(maxLeftA, maxLeftB);
            }
            else if (maxLeftA > minRightB) {
                end = m1 - 1;
            }
            else {
                st = m1 + 1;
            }
        }

        return 0.0; // Should never reach here if input is valid
    }
};


