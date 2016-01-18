public class Solution {
    public int[] plusOne(int[] digits) {
      int length = digits.length;
        int sum;
        int one = 1;//plus one, it contains carry as well
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = length - 1; i >= 0; i--) {//from end to top
            sum = one + digits[i];//add the number i level digit with the carry
            one = sum / 10;//get the new carry
            map.put(i, sum % 10);//put the finally new digit to map
        }
        if (one > 0) {
            int[] ret = new int[map.size() + 1];
            ret[0] = one;
            for (int j = 0; j < map.size(); j++) {
                ret[j+1] = map.get(j);
            }
            return ret;
        } else {
            int[] ret = new int[map.size()];
            for (int j = 0; j < map.size(); j++) {
                ret[j] = map.get(j);
            }
            return ret;
        }


    }
}