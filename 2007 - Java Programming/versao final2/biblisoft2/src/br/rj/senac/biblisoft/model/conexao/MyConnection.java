package br.rj.senac.biblisoft.model.conexao;

import java.sql.Connection;
import java.sql.DriverManager;

public class MyConnection {

	private static Connection conn;
	
	public static Connection getConnection() {	
		try {
			
			if (conn == null || conn.isClosed()) {
				Class.forName("com.mysql.jdbc.Driver");
				
				conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/biblioteca?user=root&password=");
				
				conn.setAutoCommit(Boolean.FALSE);
			}
			
			return conn;
			
		} catch (Exception e) {
			
			System.out.println(e.getStackTrace().toString() );
			
			return null;
		}
	}
	
	public static void beginTransaction() {
		MyConnection.getConnection();
	}
	
	public static void commit() {
		try {
			
			if (MyConnection.getConnection() != null) {
				conn.commit();	
			}
			
		} catch (Exception e) {
			System.out.println(e.getStackTrace().toString() );
		}
	}
	
	public static void rollback() {
		try {
			
			if (MyConnection.getConnection() != null) {
				conn.rollback();	
			}
			
		} catch (Exception e) {
			System.out.println(e.getStackTrace().toString() );
		}
	}
}
