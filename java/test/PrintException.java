import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.DatabaseMetaData;
import java.sql.SQLException;
import java.util.Properties;

public class PrintException {
    public static void printSQLException(SQLException se) {
        System.err.println("SQLState: " + se.getSQLState());
        System.err.println("Error Code: " + se.getErrorCode());
        System.err.println("Message: " + se.getMessage());

        Throwable t = se.getCause();
        while(t != null) {
            System.out.println("Cause: " + t);
            t = t.getCause();
        }
    }
}
