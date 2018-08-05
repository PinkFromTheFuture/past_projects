package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.AutorTableModel;
import br.rj.senac.biblisoft.view.AutorView;
import br.rj.senac.biblisoft.view.EntityModelView;

public class AutorDAO {
	Connection conn = Conexao.getConexao();

	public void inserir(Autor autor) throws DAOException {

		try {

			String query = "INSERT INTO AUTOR(NOME) VALUES (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, autor.getNome());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Autor autor) throws DAOException {
		try {

			String query = "DELETE FROM AUTOR WHERE AUTOR_ID =(?)";

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, autor.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);
		}

	}

	public void update(Autor autor) throws DAOException {
		try {
			String query = "UPDATE AUTOR SET NOME = (?) WHERE AUTOR_ID = (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, autor.getNome());
			ps.setInt(2, autor.getId());
			ps.executeUpdate();
			conn.commit();

		} catch (Exception e) {
			throw new DAOException(e);
		}

	}

	public void select(Autor autor, AutorView tela) throws DAOException {
		ResultSet rs = null;
		// System.out.println(autor.getId());
		try {

			String query = "SELECT * FROM AUTOR WHERE AUTOR_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, autor.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = (rs.getString("NOME"));

				tela.getNomeField().setText(nome);

			}
			tela.getIdField().setText("" + autor.getId());
		} catch (Exception e) {
			throw new DAOException(e);
		}

	}

	public int getId(Autor autor) throws DAOException {
		ResultSet rs = null;
		int id = -9999;
		// System.out.println(autor.getId());
		try {

			String query = "SELECT * FROM AUTOR WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, autor.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("AUTOR_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return id;

	}

	public String getNome(Autor autor) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(autor.getId());
		try {

			String query = "SELECT * FROM AUTOR WHERE AUTOR_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, autor.getId());
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

		try {
			String query = "SELECT AUTOR_ID,NOME FROM AUTOR ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("AUTOR_ID");
				String nome = rs.getString("NOME");

				AutorTableModel.dados.add(new String[] { "" + id + "",
						"" + nome + "" });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}
