package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Editora;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.EditoraTableModel;
import br.rj.senac.biblisoft.view.EditoraView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.LivroView;

public class EditoraDAO {

	public void incluir(Editora editora) throws DAOException {

		try {

			String query = "INSERT INTO EDITORA(NOME) VALUES (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, editora.getNome());

			ps.executeUpdate();

			conn.commit();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Editora editora) throws DAOException {
		try {

			String query = "DELETE FROM EDITORA WHERE EDITORA_ID =(?)";
			Connection conn = Conexao.getConnection();

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, editora.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void update(Editora editora) throws DAOException {
		try {
			String query = "UPDATE EDITORA SET NOME = (?) WHERE EDITORA_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, editora.getNome());
			ps.setInt(2, editora.getId());
			ps.executeUpdate();
			conn.commit();
			conn.close();
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void select(Editora editora, EditoraView tela) throws DAOException {
		ResultSet rs = null;
		// System.out.println(editora.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, editora.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = (rs.getString("NOME"));

				tela.getNomeField().setText(nome);

			}
			tela.getIdField().setText("" + editora.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Editora editora) throws DAOException {

		ResultSet rs = null;
		Integer id = null;

		try {

			String query = "SELECT * FROM EDITORA WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, editora.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("EDITORA_ID"));

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public String getNome(Editora editora) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(editora.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, editora.getId());
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

	public String selectNome(Editora editora) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(editora.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, editora.getId());
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
		EditoraTableModel.dados.clear();

		try {
			String query = "SELECT EDITORA_ID,NOME FROM EDITORA ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("EDITORA_ID");
				String nome = rs.getString("NOME");

				EditoraTableModel.dados.add(new String[] { "" + id + "",
						"" + nome + "" });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarChoice(EntityModelView tela) throws DAOException {

		try {
			String query = "SELECT EDITORA_ID,NOME FROM EDITORA ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();
			LivroView.getEditora().add("");
			while (rs.next()) {
				// Integer id = rs.getInt("EDITORA_ID");
				String nome = rs.getString("NOME");
				LivroView.getEditora().add(nome);
				// AutorTableModel.dados.add(new String[] { "" + id + "",
				// "" + nome + "" });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}
