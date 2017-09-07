import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.DatabaseMetaData;
import java.sql.SQLException;
import java.util.Properties;

public class MysqlTransactionIsolationLevel {
    public static void main(String[] args) {
        Properties connectionProps = new Properties();
        connectionProps.put("user", "lgy");
        connectionProps.put("password", "198708060316");

        //Connection con = null;

        try(Connection con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/",
                    connectionProps)) {
            DatabaseMetaData dbMetaData = con.getMetaData();

            System.out.println("TRANSACTION_NONE " +
                    Connection.TRANSACTION_NONE + " " +
                    dbMetaData.supportsTransactionIsolationLevel(
                        Connection.TRANSACTION_NONE));
            System.out.println("TRANSACTION_READ_COMMITTED " +
                    Connection.TRANSACTION_READ_COMMITTED + " " +
                    dbMetaData.supportsTransactionIsolationLevel(
                        Connection.TRANSACTION_READ_COMMITTED));
            System.out.println("TRANSACTION_READ_UNCOMMITTED " +
                    Connection.TRANSACTION_READ_UNCOMMITTED + " " +
                    dbMetaData.supportsTransactionIsolationLevel(
                        Connection.TRANSACTION_READ_UNCOMMITTED));
            System.out.println("TRANSACTION_REPEATABLE_READ " +
                    Connection.TRANSACTION_REPEATABLE_READ + " " +
                    dbMetaData.supportsTransactionIsolationLevel(
                        Connection.TRANSACTION_REPEATABLE_READ));
            System.out.println("TRANSACTION_SERIALIZABLE " +
                    Connection.TRANSACTION_SERIALIZABLE + " " +
                    dbMetaData.supportsTransactionIsolationLevel(
                        Connection.TRANSACTION_SERIALIZABLE));
        } catch (SQLException se) {
            PrintException.printSQLException(se);
        }
    }
}
