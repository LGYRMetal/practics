/*
 * 数组的拷贝
 */
import java.util.Arrays;
public class ArrayCopy {
    public static void main(String[] args) {
        int[] src = {1, 2, 3, 4};
        int[] dest = new int[4];

        for(int i = 0; i < dest.length; i++) {
            System.out.println(dest[i]);
        }

        copy(src, 0, dest, 0, 4);
        for(int i = 0; i < dest.length; i++) {
            System.out.println(dest[i]);
        }
    }

    /*
     * 拷贝数组的数据到另一个数组
     */
    public static void copy(int[] src,  int srcPos,
                            int[] dest, int destPos, int length) {
        for(int i = 0; i < length; i++) {
            dest[destPos++] = src[srcPos++];
        }
    }
}
