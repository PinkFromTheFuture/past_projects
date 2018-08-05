package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.conexao.Conexao;





public class EmprestimoDAO {
	Connection conn = Conexao.getConexao();

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	SELECT NUMEX,LIVRO_ID FROM EXEMPLAR LEFT OUTER JOIN EMPRESTIMO ON EXEMPLAR.EXEMPLAR_ID = EMPRESTIMO.EXEMPLAR_ID WHERE EMPRESTIMO.DATADEVOLUCAO IS NULL AND LIVRO_ID = 1;
//	SELECT EXEMPLAR.EXEMPLAR_ID,  EMPRESTIMO.DATADEVOLUCAO FROM EXEMPLAR INNER JOIN EMPRESTIMO ON EXEMPLAR.EXEMPLAR_ID = EMPRESTIMO.EXEMPLAR_ID  WHERE EMPRESTIMO.DATADEVOLUCAO IS NOT NULL ;
//	
//	SELECT NUMEX,LIVRO_ID FROM EXEMPLAR LEFT OUTER JOIN EMPRESTIMO ON EXEMPLAR.EXEMPLAR_ID = EMPRESTIMO.EXEMPLAR_ID WHERE EMPRESTIMO.DATADEVOLUCAO IS NULL;
//	PRA OUTRA COISA.. FAZER UM OUTER JOIN!
	
	
	
	
	
	
	
	public boolean incluir(Emprestimo emprestimo) {
		int resultado = 0;
		try {

			String query = "INSERT INTO EMPRESTIMO(EXEMPLAR_ID,USUARIO_ID,BIBLIOTECARIO_ID,DATAENTREGA) VALUES (?,?,?,?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, emprestimo.getIdExemplar());
			ps.setInt(2, emprestimo.getIdUsuario());
			ps.setInt(3, emprestimo.getIdBibliotecario());
			ps.setDate(4, emprestimo.getDataEntrega());
			ps.executeUpdate();

			conn.commit();
			conn.close();

		} catch (Exception ex) {
			ex.printStackTrace();
		}
		if (resultado == 0) {
			return false;
		} else {
			return true;
		}

	}
	
	
	public void devolver(Emprestimo emprestimo) {
		try {
			String query = "UPDATE EMPRESTIMO SET DATADEVOLUCAO = (?) WHERE EMPRESTIMO_ID = (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setDate(1, emprestimo.getDataDevolucao());
			ps.setInt(2, emprestimo.getId());
			ps.executeUpdate();
			conn.commit();
			
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar atualizar o cadastro de um autor");
		}

	}

	// public boolean delete(Emprestimo emprestimo){
	// try{
	//			 
	//
	// String query = "DELETE FROM AUTOR WHERE AUTOR_ID =(?)";
	//			
	// PreparedStatement ps = conn.prepareStatement(query);
	// String id = ""+ emprestimo.getId();
	// ps.setString(1, id);
	// ps.executeUpdate();
	//			
	// conn.commit();
	// conn.close();
	//			
	//				
	// }catch(Exception ex){
	// ex.printStackTrace();
	// }
	// return true;
	// }

}
