package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Curso;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.CursoTableModel;
import br.rj.senac.biblisoft.view.CursoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.UsuarioView;

public class CursoDAO {

	public void incluir(Curso curso) throws DAOException {

		try {

			String query = "INSERT INTO CURSO(NOME) VALUES (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, curso.getNome());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Curso curso) throws DAOException {
		try {

			String query = "DELETE FROM CURSO WHERE CURSO_ID =(?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, curso.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void update(Curso curso) throws DAOException {
		try {
			String query = "UPDATE CURSO SET NOME = (?) WHERE CURSO_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, curso.getNome());
			ps.setInt(2, curso.getId());
			ps.executeUpdate();
			conn.commit();
			conn.close();
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void select(Curso curso, CursoView tela) throws DAOException {
		ResultSet rs = null;
		// System.out.println(curso.getId());
		try {

			String query = "SELECT * FROM CURSO WHERE CURSO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, curso.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = (rs.getString("NOME"));

				tela.getNomeField().setText(nome);

			}
			tela.getIdField().setText("" + curso.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Curso curso) throws DAOException {
		ResultSet rs = null;
		Integer id = null;

		try {

			String query = "SELECT * FROM CURSO WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, curso.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("CURSO_ID"));

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public String getNome(Curso curso) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(curso.getId());
		try {

			String query = "SELECT * FROM CURSO WHERE CURSO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, curso.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				nome = (rs.getString("NOME"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return nome;

	}

	public void listar(EntityModelView tela) throws DAOException {
		CursoTableModel.dados.clear();

		try {
			String query = "SELECT CURSO_ID,NOME FROM CURSO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("CURSO_ID");
				String nome = rs.getString("NOME");

				CursoTableModel.dados.add(new String[] { "" + id + "",
						"" + nome + "" });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarChoice(EntityModelView tela) throws DAOException {
		UsuarioView.cursoChoice.removeAll();

		try {
			String query = "SELECT NOME FROM CURSO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {

				String nome = rs.getString("NOME");

				UsuarioView.cursoChoice.add(nome);

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}