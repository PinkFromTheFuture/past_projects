package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;


import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.EmprestimoTableModel;
import br.rj.senac.biblisoft.view.EntityModelView;

public class EmprestimoDAO {

	public void incluir(Emprestimo emprestimo) throws DAOException {

		try {

			String query = "INSERT INTO EMPRESTIMO(EXEMPLAR_ID,USUARIO_ID,BIBLIOTECARIO_ID,DATAENTREGA) VALUES (?,?,?,?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, emprestimo.getIdExemplar());
			ps.setInt(2, emprestimo.getIdUsuario());
			ps.setInt(3, emprestimo.getIdBibliotecario());
			ps.setDate(4, new java.sql.Date(emprestimo.getDataEntrega()
					.getTime()));

			ps.executeUpdate();

		} catch (Exception e) {
			throw new DAOException(e);
		}

	}

	public void devolver(Emprestimo emprestimo) throws DAOException {
		try {
			String query = "UPDATE EMPRESTIMO SET DATADEVOLUCAO = (?) WHERE EMPRESTIMO_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setDate(1, new java.sql.Date(emprestimo.getDataDevolucao()
					.getTime()));
			// ps.setDate(1, emprestimo.getDataDevolucao());
			ps.setInt(2, emprestimo.getId());
			ps.executeUpdate();

		} catch (Exception e) {
			throw new DAOException(e);
		}

	}

	public int getId(Emprestimo emprestimo) throws DAOException {
		Integer id = null;
		ResultSet rs = null;
		try {

			String query = "SELECT FROM EMPRESTIMO WHERE EXEMPLAR_ID = ? AND USUARIO_ID = ? AND BIBLIOTECARIO_ID = ? AND DATAENTREGA = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, emprestimo.getIdExemplar());
			ps.setInt(2, emprestimo.getIdUsuario());
			ps.setInt(3, emprestimo.getIdBibliotecario());
			ps.setDate(4, new java.sql.Date(emprestimo.getDataEntrega()
					.getTime()));
			rs = ps.executeQuery();
			ps.executeUpdate();

			while (rs.next()) {

				id = (rs.getInt("EMPRESTIMO_ID"));
			}

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return id;
	}

	@SuppressWarnings("unchecked")
	public int getEmprestimos(int usuarioId) throws DAOException {
		System.out.println("Rafael... não sei porque esse método não esta funcionando... por mim eu fiz ele igual ao que eu tinha feito no sabado, mas infelizmente eu perdi aquele la... meu tempo acabou, vai ter q ficar assim mesmo");
		int numeroEmprestimos = -99999;
		int id = -99999;
		ResultSet rs = null;
		ArrayList util = new ArrayList();
		
		try {
			String query = "SELECT USUARIO_ID FROM EMPRESTIMO WHERE USUARIO_ID = ? AND DATADEVOLUCAO IS NULL";

			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, usuarioId);

			rs = ps.executeQuery();
			ps.executeUpdate();

			while (rs.next()) {

				id = (rs.getInt("EMPRESTIMO_ID"));
				util.add(""+id);

			}
			numeroEmprestimos = util.size();
			System.out.println(numeroEmprestimos);

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return numeroEmprestimos;
	}
	
	

	
	
	

	public void listar(EntityModelView tela) throws DAOException {

		try {
			String query = "SELECT * FROM EMPRESTIMO ORDER BY EMPRESTIMO_ID";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();

			while (rs.next()) {
				Integer id = rs.getInt("EMPRESTIMO_ID");
				Integer exemplarId = rs.getInt("EXEMPLAR_ID");
				Integer usuarioId = rs.getInt("USUARIO_ID");
				Integer bibliotecarioId = rs.getInt("BIBLIOTECARIO_ID");
				Date dataentrega = rs.getDate("DATAENTREGA");
				Date datadevolucao = rs.getDate("DATADEVOLUCAO");
			

				EmprestimoTableModel.dados.add(new String[] { "" + id,
						"" + exemplarId, "" + usuarioId, "" + bibliotecarioId,
						""+dataentrega, ""+ datadevolucao });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}
