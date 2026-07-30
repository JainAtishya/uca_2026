
import java.util.Scanner;

class BitwiseXOR {

    public static int bitXor(int x, int y) {
        int notX = (~x & y);
        int notY = (x & ~y);
        return ~(~notX & ~notY);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        System.out.println(bitXor(num1, num2));

    }

}



/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
