/* https://oj.leetcode.com/problems/sort-colors/
    Two pass sorting:
        1, divide 0s and (1,2)s
        2, divide 1s and 2s
*/

//one pass is possible too
class Solution {
public:
	void sortColors(int A[], int n) {
		int index0 = 0;
		int index2 = n - 1;
		int i = 0;
		while (i <= index2) {  //i走过的地方不是0就是1，把i遇到的0写到index0就可以避免1在0前面出现了
			if (A[i] == 0) { //我们知道交换到前面来的是0
				swap(A[i], A[index0]);
				index0++;
				i++;
			}
			else if (A[i] == 2) { //我们不知道交换到前面来的是0， 1， 2 ？所以i不能动
				swap(A[i], A[index2]);
				index2--;
			}
			else
				i++;
		}
	}
};