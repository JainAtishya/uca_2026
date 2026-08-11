
import java.util.PriorityQueue;
import java.util.Scanner;

class RunningMedianInDataStream {

    public static void insert(int num, PriorityQueue<Integer> minHeap, PriorityQueue<Integer> maxHeap) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.offer(minHeap.poll());
        }
    }

    public static float getMedian(PriorityQueue<Integer> minHeap, PriorityQueue<Integer> maxHeap) {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();

        if (minHeapSize == maxHeapSize) {
            return (float) (minHeap.peek() + maxHeap.peek()) / 2;
        } else if (minHeapSize > maxHeapSize) {
            return minHeap.peek();
        } else {
            return maxHeap.peek();
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean isTrue = true;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b, a));

        while (isTrue) {
            char choice = sc.next().charAt(0);
            switch (choice) {
                case 'i':
                    int num = sc.nextInt();
                    insert(num, minHeap, maxHeap);
                    break;
                case 'g':
                    float median = getMedian(minHeap, maxHeap);
                    System.out.println(median);
                    break;
                case 'q':
                    isTrue = false;
                    break;
                default:
                    System.out.println("Enter valid choice either i, g or q");
            }

        }
        sc.close();
    }
}

// Running Median in data stream
// Given a stream of integers, design a consumer that supports the following two operations:
// void insert(int num) – Reads the next number from the stream and stores it in the underlying data structure.
// float getMedian() – Returns the median of all numbers received so far.
// Your goal is to choose a data structure that keeps both operations as efficient as possible.
