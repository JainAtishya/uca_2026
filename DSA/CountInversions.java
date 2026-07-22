
import java.util.Scanner;

public class CountInversions {

    public static int countInversions(int[] nums) {
        
        int n = nums.length;
        int[] count = new int[1];
        mergeSort(nums, 0, n - 1, count);

        return count[0];

    }

    public static void mergeSort(int[] nums, int i, int j, int[] count) {

        if(i >= j) return;

        int mid = i + (j - i)/2;

        mergeSort(nums, i, mid, count);
        mergeSort(nums, mid + 1, j, count);
        merge(nums, i, mid, j, count);

    }

    public static void merge(int[] nums, int i, int mid, int j, int[] count) {

        int[] temp = new int[j - i + 1];
        int left = i;
        int right = mid + 1;
        int ind = 0;
        
        while(left <= mid && right <= j) {

            if(nums[left] > nums[right]) {
                count[0] += mid - left + 1;
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

        int count = countInversions(nums);

        System.out.println(count);

    }

}