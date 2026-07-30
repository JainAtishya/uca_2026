
class GetNthByte {

    public static int getByte(int x, int n) {
        return (x >> (n * 8)) & 0xFF;
    }

    public static void main(String[] args) {

        System.out.println(Integer.toHexString(getByte(0x12345678, 1)));

    }

}




/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
