import java.util.Scanner;

class CountSignificantReversePairs {
    
    public static int reversePairs(int[] nums) {

        int n = nums.length;
        int[] count = new int[1];
        count[0] = 0;
        helper(nums, 0, n - 1, count);
        return count[0];
        
    }

    public static void helper(int[] nums, int i, int j, int[] count) {

        if(i == j) return;
        int mid = i + (j - i)/2;

        helper(nums, i, mid, count);
        helper(nums, mid + 1, j, count);

        count(nums, i, j, mid, count);
        
        merge(nums, i, j, mid);

    }

    public static void count(int[] nums, int i, int j, int mid, int[] count) {

        int low = i;
        int high = mid + 1;
        while(low <= mid && high <= j) {

            if(nums[low] > (long)2 * nums[high]) {
                count[0] += mid - low + 1;
                high++;
            } else {
                low++;
            }
        }
    }

    public static void merge(int[] nums, int i, int j, int mid) {

        int[] temp = new int[j - i + 1];
        int left = i;
        int right = mid + 1;
        int ind = 0;
        
        while(left <= mid && right <= j) {

            if(nums[left] > nums[right]) {
                temp[ind++] = nums[right++];
            } else {
                temp[ind++] = nums[left++];
            }
        }

        while(left <= mid) {
            temp[ind++] = nums[left++];
        }

        while(right <= j) {
            temp[ind++] = nums[right++];
        }

        ind = 0;

        for(int k = i; k <= j; k++){
            nums[k] = temp[ind++];
        }
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        int ind = 0;
        
        while(n > 0) {
            nums[ind++] = sc.nextInt();
            n--;
        }

        int count = reversePairs(nums);

        System.out.println(count);

    }

}