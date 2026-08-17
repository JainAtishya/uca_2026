
public class FindNumberReapetedFourTimes {

    public static int findNumber(int[] arr) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : arr) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
        System.out.println(findNumber(arr));
    }
}
