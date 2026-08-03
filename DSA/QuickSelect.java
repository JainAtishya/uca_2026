import java.util.Random;

public class QuickSelect {

    static Random random = new Random();

    public static void quickSelect(int[] arr, int low, int high, int k) {

        if (low >= high) {
            return;
        }

        int pivotIndex = low + random.nextInt(high - low + 1);

        pivotIndex = partition(arr, low, high, pivotIndex);

        if (pivotIndex == k - 1) {
            return;
        }

        if (pivotIndex > k - 1) {
            quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            quickSelect(arr, pivotIndex + 1, high, k);
        }
    }

    public static int partition(int[] arr, int low, int high, int pivotIndex) {

        int pivot = arr[pivotIndex];

        swap(arr, pivotIndex, high);

        int i = low;

        for (int j = low; j < high; j++) {

            if (arr[j] < pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, high);

        return i;
    }

    public static void swap(int[] arr, int i, int j) {

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {

        int[] arr = {10, 4, 5, 8, 6, 11, 26, 3, 1};

        int k = 4;

        quickSelect(arr, 0, arr.length - 1, k);

        System.out.println("Smallest " + k + " elements:");

        for (int i = 0; i < k; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}