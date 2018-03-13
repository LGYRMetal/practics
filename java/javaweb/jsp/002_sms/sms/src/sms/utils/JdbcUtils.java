package sms.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JdbcUtils {
	private static Connection conn;

	// 加载DB驱动
	static {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	// 获取Connection对象
	public static Connection getConnection() throws SQLException {
		String url = "jdbc:mysql:///sms";
		String user = "root";
		String password = "111111";

		if (conn == null || conn.isClosed()) {
			conn = DriverManager.getConnection(url, user, password);
		}
		return conn;
	}
	
	// 关闭资源
	public static void close(Connection conn, Statement stmt, ResultSet rs)
			throws SQLException {
		if(conn != null && !conn.isClosed()) {
			conn.close();
		}

		if(stmt != null && !stmt.isClosed()) {
			stmt.close();
		}

		if(rs != null && !rs.isClosed()) {
			rs.close();
		}
	}
}
