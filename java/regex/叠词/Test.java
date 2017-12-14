/*
 * 需求:
 * 将下列字符串转换成：我要学编程.
 *
 * String str = "我我...我我...我要..要要...要要...学学学....学学...编编编..编程..程.程程...程...程";
 */
package com.lgyrmetal;

public class Test {
    private static String str = "我我...我我...我要..要要...要要...学学学....学学...编编编..编程..程.程程...程...程";

    public static void main(String[] args) {
        System.out.println(str = str.replaceAll("\\.+", ""));
        System.out.println(str = str.replaceAll("(.)\\1+", "$1"));
        /*
        System.out.println(str = str.replaceAll("我+", "我"));
        System.out.println(str = str.replaceAll("要+", "要"));
        System.out.println(str = str.replaceAll("学+", "学"));
        System.out.println(str = str.replaceAll("编+", "编"));
        System.out.println(str = str.replaceAll("程+", "程"));
        */
    }
}
