package br.rj.senac.biblisoft.model.conexao;

import java.sql.Connection;
import java.sql.DriverManager;

public class Conexao {

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
		Conexao.getConnection();
	}
	
	public static void commit() {
		try {
			
			if (Conexao.getConnection() != null) {
				conn.commit();	
			}
			
		} catch (Exception e) {
			System.out.println(e.getStackTrace().toString() );
		}
	}
	
	public static void rollback() {
		try {
			
			if (Conexao.getConnection() != null) {
				conn.rollback();	
			}
			
		} catch (Exception e) {
			System.out.println(e.getStackTrace().toString() );
		}
	}
}
