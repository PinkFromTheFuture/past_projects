package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.control.AutorController;
import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.AutorLivro;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.view.LivroView;

public class AutorLivroDAO {

	public void incluir(AutorLivro autorLivro) {

		try {

			String query = "INSERT INTO AUTOR_LIVRO(AUTOR_ID,LIVRO_ID) VALUES (?,?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, autorLivro.getIdAutor());
			ps.setInt(2, autorLivro.getIdLivro());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

	public void delete(AutorLivro autorLivro) {
		try {

			String query = "DELETE FROM AUTOR_LIVRO WHERE LIVRO_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, autorLivro.getIdLivro());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

	public void select(Livro livro) {
		LivroView.listModel.clear();
		ResultSet rs = null;
		AutorController autorController = new AutorController();
		Autor autor = new Autor();
		try {

			String query = "SELECT * FROM AUTOR_LIVRO WHERE LIVRO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, livro.getId());

			rs = ps.executeQuery();

			conn.commit();
			while (rs.next()) {
				Integer id = rs.getInt("AUTOR_ID");
				autor.setId(id);
				String nome = autorController.getNome(autor);
				LivroView.listModel.addElement(nome);

			}

			// conn.close();

		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

}
