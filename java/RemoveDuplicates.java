/**
 * Created by sooglejay on 16/1/12.
 */
public class RemoveDuplicates {
    public static void main(String[] args) {
        System.out.print(removeDuplicates(new int[]{1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4
        }));

    }

    /***
     * 使用两个下标,i,j,i做遍历,j做新数组长度
     * @param nums
     * @return
     */
    public static int removeDuplicates(int[] nums) {
        int n;
        if ((n = nums.length) < 1) {
            return n;
        }
        int j = 0;
        int num = 0;
        for (int i = 1; i < n; i++) {
            if (nums[j] == nums[i]) {
                num++;
                if (num < 2) {//超过两个就不管了,
                    nums[++j] = nums[i];
                }
            } else {//把剩下的都往前面搬
                nums[++j] = nums[i];
                num = 0;
            }
        }
        return j + 1;
    }
}
