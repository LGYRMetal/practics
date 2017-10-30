class HelloWorld {
    public static native void hello(String name);

    static {
        System.loadLibrary("hello");
    }

    public static void main(String[] args) {
        hello("lgy");
    }
}
