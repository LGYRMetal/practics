import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.DatabaseMetaData;
import java.sql.SQLException;
import java.util.Properties;

public class MysqlHoldability {
    public static void main(String[] args) throws SQLException {
        Properties connectionProps = new Properties();
        connectionProps.put("user", "lgy");
        connectionProps.put("password", "198708060316");

        Connection conn = null;

        try {
            conn = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/", 
                    connectionProps);
            DatabaseMetaData dbMetaData = conn.getMetaData();

            System.out.println("ResultSet.HOLD_CURSORS_OVER_COMMIT = " +
                    ResultSet.HOLD_CURSORS_OVER_COMMIT);

            System.out.println("ResultSet.CLOSE_CURSORS_AT_COMMIT = " +
                    ResultSet.CLOSE_CURSORS_AT_COMMIT);

            System.out.println("Default cursor holdability: " +
                    dbMetaData.getResultSetHoldability());

            System.out.println("Supports HOLD_CURSORS_OVER_COMMIT? " +
                    dbMetaData.supportsResultSetHoldability(
                        ResultSet.HOLD_CURSORS_OVER_COMMIT));

            System.out.println("Supports CLOSE_CURSORS_AT_COMMIT? " +
                    dbMetaData.supportsResultSetHoldability(
                        ResultSet.CLOSE_CURSORS_AT_COMMIT));
        } catch(SQLException e) {
            System.err.println("SQLState: " + e.getSQLState());
            System.err.println("Error Code: " + e.getErrorCode());
            System.err.println("Message: " + e.getMessage());

            Throwable t = e.getCause();
            while(t != null) {
                System.out.println("Cause: " + t);
                t = t.getCause();
            }
        } finally {
            if (conn != null) { conn.close(); }
        }
    }
}
