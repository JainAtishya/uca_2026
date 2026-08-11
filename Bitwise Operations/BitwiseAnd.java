
import java.util.Scanner;

class BitwiseAnd {

    public static int bitAnd(int x, int y) {
        return ~((~x) | (~y));
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        System.out.println(bitAnd(num1, num2));
        sc.close();

    }

}


/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
