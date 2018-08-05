package br.rj.senac.biblisoft.model.conexao;

import java.sql.*;
/**classe do edu*/
 


public class Conexao {
	
	private static Connection conn = null;
	
	
	public static Connection getConexao(){
		
		try{
			Class.forName("com.mysql.jdbc.Driver");
			
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/biblioteca?user=root&password=");
			conn.setAutoCommit(false); 
			
		}catch(Exception ex){
			
			ex.printStackTrace();
		}
		
		
	return conn;
	}

	public static void closeConn(){
		try {
			conn.close();
		} catch (SQLException e) {
		
			e.printStackTrace();
		}
	}
}