import java.util.Scanner;

class Base64Encoding {

    static final String BASE64 =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    public static String encode(String input) {

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < input.length(); i += 3) {

            int b1 = input.charAt(i);
            int b2 = 0;
            int b3 = 0;

            if (i + 1 < input.length()) {
                b2 = input.charAt(i + 1);
            }

            if (i + 2 < input.length()) {
                b3 = input.charAt(i + 2);
            }

            int first = b1 >> 2;

            int second = ((b1 & 3) << 4) | (b2 >> 4);

            int third = ((b2 & 15) << 2) | (b3 >> 6);

            int fourth = b3 & 63;

            result.append(BASE64.charAt(first));
            result.append(BASE64.charAt(second));

            if (i + 1 < input.length()) {
                result.append(BASE64.charAt(third));
            } else {
                result.append('=');
            }

            if (i + 2 < input.length()) {
                result.append(BASE64.charAt(fourth));
            } else {
                result.append('=');
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();

        System.out.println(encode(input));

        sc.close();
    }
}