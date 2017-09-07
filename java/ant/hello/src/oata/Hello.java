package oata;

import org.apache.log4j.Logger;
//import org.apache.log4j.BasicConfigurator;

public class Hello {
    static Logger logger = Logger.getLogger(Hello.class);

    public static void main(String[] args) {
        //System.out.println("Hello world!");
        //BasicConfigurator.configure();
        logger.info("Hello World!");
    }
}
