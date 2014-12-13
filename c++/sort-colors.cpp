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
		while (i <= index2) {  //i�߹��ĵط�����0����1����i������0д��index0�Ϳ��Ա���1��0ǰ�������
			if (A[i] == 0) { //����֪��������ǰ��������0
				swap(A[i], A[index0]);
				index0++;
				i++;
			}
			else if (A[i] == 2) { //���ǲ�֪��������ǰ��������0�� 1�� 2 ������i���ܶ�
				swap(A[i], A[index2]);
				index2--;
			}
			else
				i++;
		}
	}
};