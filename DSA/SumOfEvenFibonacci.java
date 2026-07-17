import java.util.Scanner;

class SumOfEvenFibonacci {

    public static long sumOfEven(int n){
        long sum = 0;
        long num1 = 2;
        long num2 = 8;
        while(num1 < n){
            sum += num1;
            long num3 = 4*num2 + num1;
            num1 = num2;
            num2 = num3;
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Sum of even fibonacci number till " + n + " is " + sumOfEven(n));
    }
}