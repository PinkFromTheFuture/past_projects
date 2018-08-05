package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.LivroTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;
import br.rj.senac.biblisoft.view.LivroView;

public class LivroDAO {

	public void incluir(Livro livro) throws DAOException {

		try {

			String query = "INSERT INTO LIVRO(EDITORA_ID,NOME,ISBN,FOTO) VALUES (?,?,?,?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, livro.getIdEditora());
			ps.setString(2, livro.getNome());
			ps.setString(3, livro.getIsbn());
			ps.setString(4, livro.getFoto());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Livro livro) throws DAOException {
		try {

			String query = "DELETE FROM LIVRO WHERE LIVRO_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, livro.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void update(Livro livro) throws DAOException {
		try {
			String query = "UPDATE LIVRO SET NOME = (?), ISBN = (?), EDITORA_ID = (?) WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, livro.getNome());
			ps.setString(2, livro.getIsbn());
			ps.setInt(3, livro.getIdEditora());
			ps.setInt(4, livro.getId());
			ps.executeUpdate();
			conn.commit();
			// conn.close();
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void select(Livro livro, LivroView tela) throws DAOException {
		ResultSet rs = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = (rs.getString("NOME"));
				String isbn = (rs.getString("ISBN"));

				tela.getNomeField().setText(nome);
				tela.getIsbnField().setText(isbn);

			}
			tela.getIdField().setText("" + livro.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Livro livro) throws DAOException {
		ResultSet rs = null;
		Integer id = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, livro.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("LIVRO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public String getNome(Livro livro) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
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

	public String selectEditora(Livro livro) throws DAOException {
		ResultSet rs = null;
		Integer editoraID = -9999;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				editoraID = (rs.getInt("EDITORA_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, editoraID);
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

	public String selectIsbn(Livro livro) throws DAOException {
		ResultSet rs = null;
		String isbn = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				isbn = (rs.getString("ISBN"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return isbn;

	}

	public String getNomeEditora(int idEditora) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, idEditora);
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

	public int getEditoraId(Livro livro) throws DAOException {
		ResultSet rs = null;
		int id = -9999;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, livro.getNomeEditora());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("EDITORA_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;
	}

	public void listar(EntityModelView tela) throws DAOException {
		LivroTableModel.dados.clear();

		try {
			String query = "SELECT LIVRO_ID,EDITORA_ID,NOME,ISBN FROM LIVRO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");
				int idEditora = rs.getInt("EDITORA_ID");
				String nomeEditora = getNomeEditora(idEditora);
				String isbn = rs.getString("ISBN");

				LivroTableModel.dados.add(new String[] { "" + id + "",
						"" + nome + "", "" + isbn + "", "" + nomeEditora,
						"Selecione para visualizar" });
				//				
			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarChoice(EntityModelView tela) throws DAOException {
		ExemplarView.getLivroChoice().removeAll();

		try {
			String query = "SELECT * FROM LIVRO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				// Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");

				ExemplarView.getLivroChoice().add(nome);

				//				
			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarList(EntityModelView tela) throws DAOException {
		EmprestimoView.livroModel.removeAllElements();

		try {
			String query = "SELECT * FROM LIVRO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				// Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");

				EmprestimoView.livroModel.addElement(nome);

				//				
			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public Integer getId(String nome) throws DAOException {
		ResultSet rs = null;
		Integer id = -99999;
		// System.out.println(editora.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setString(1, nome);
			rs = ps.executeQuery();

			while (rs.next()) {

				id = (rs.getInt("EDITORA_ID"));

				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public String getNome(int id) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, id);
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

	public int getIdLivro(String nome) throws DAOException {
		ResultSet rs = null;
		Integer id = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, nome);
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("LIVRO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

}