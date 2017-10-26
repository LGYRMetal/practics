/*
 * 数组的拷贝
 */
import java.util.Arrays;
public class ArrayCopy {
    public static void main(String[] args) throws Exception {
        int[] src = {1, 2, 3, 4};
        int[] dest = new int[4];
        //String[] src = {"a", "b", "c", "d"};
        //String[] dest = new String[4];

        for(int i = 0; i < dest.length; i++) {
            System.out.println(dest[i]);
        }

        //String[] s = new String[1];
        copy(src, 0, dest, 0, 4);
        for(int i = 0; i < dest.length; i++) {
            System.out.println(dest[i] * 10);
            //System.out.println(dest[i] + "~");
        }
    }

    /*
     * 拷贝数组的数据到另一个数组
     */
    /*
    public static void copy(int[] src,  int srcPos,
                            int[] dest, int destPos, int length) {
        for(int i = 0; i < length; i++) {
            dest[destPos++] = src[srcPos++];
        }
    }
    */

    public static void copy(Object src, int srcPos,
                            Object dest, int destPos, int length)
        throws Exception {
        if(!src.getClass().isArray() || !dest.getClass().isArray()) {
            throw new ArrayStoreException("传入的源和目的应该是数组");
        }

        switch(src.getClass().getName()) {
            case "[B":
                for(int i = 0; i < length; i++) {
                    ((byte[])dest)[destPos++] = ((byte[])src)[srcPos++];
                }
                break;
            case "[S":
                for(int i = 0; i < length; i++) {
                    ((short[])dest)[destPos++] = ((short[])src)[srcPos++];
                }
                break;
            case "[I":
                for(int i = 0; i < length; i++) {
                    ((int[])dest)[destPos++] = ((int[])src)[srcPos++];
                }
                break;
            case "[J":
                for(int i = 0; i < length; i++) {
                    ((long[])dest)[destPos++] = ((long[])src)[srcPos++];
                }
                break;
            case "[F":
                for(int i = 0; i < length; i++) {
                    ((float[])dest)[destPos++] = ((float[])src)[srcPos++];
                }
                break;
            case "[D":
                for(int i = 0; i < length; i++) {
                    ((double[])dest)[destPos++] = ((double[])src)[srcPos++];
                }
                break;
            case "[Z":
                for(int i = 0; i < length; i++) {
                    ((boolean[])dest)[destPos++] = ((boolean[])src)[srcPos++];
                }
                break;
            case "[C":
                for(int i = 0; i < length; i++) {
                    ((char[])dest)[destPos++] = ((char[])src)[srcPos++];
                }
                break;
            default:
                for(int i = 0; i < length; i++) {
                    ((Object[])dest)[destPos++] = ((Object[])src)[srcPos++];
                }
        }
    }
}

class ArrayStoreException extends java.lang.ArrayStoreException {
    public ArrayStoreException() {}
    public ArrayStoreException(String msg) {
        super(msg);
    }
}
