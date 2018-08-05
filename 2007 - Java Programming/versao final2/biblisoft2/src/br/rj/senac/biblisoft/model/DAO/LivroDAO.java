package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.LivroTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;
import br.rj.senac.biblisoft.view.LivroView;


public class LivroDAO {
	Connection conn = Conexao.getConexao();

	public boolean incluir(Livro livro) {
		int resultado = 0;
		try {

			String query = "INSERT INTO LIVRO(EDITORA_ID,NOME,ISBN,FOTO) VALUES (?,?,?,?)";
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, livro.getIdEditora());
			ps.setString(2, livro.getNome());
			ps.setString(3, livro.getIsbn());
			ps.setString(4, livro.getFoto());

			ps.executeUpdate();

			conn.commit();
//			conn.close();

		} catch (SQLException e) {
			System.out
					.println("houve algum erro ao tentar inserir dados na tabela de livros");
			e.printStackTrace();

		}
		if (resultado == 0) {
			return false;
		} else {
			return true;
		}

	}

	public boolean delete(Livro livro) {
		try {

			String query = "DELETE FROM LIVRO WHERE LIVRO_ID = (?)";

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, livro.getId());
			ps.executeUpdate();

			conn.commit();
//			conn.close();

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar remover dados da tabela de livros");
		}
		return true;
	}

	public void update(Livro livro) {
		try {
			String query = "UPDATE LIVRO SET NOME = (?), ISBN = (?), EDITORA_ID = (?) WHERE LIVRO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, livro.getNome());
			ps.setString(2, livro.getIsbn());
			ps.setInt(3, livro.getIdEditora());
			ps.setInt(4, livro.getId());
			ps.executeUpdate();
			conn.commit();
//			conn.close();
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar atualizar o cadastro de um livro");
		}

	}

	public void select(Livro livro, LivroView tela) {
		ResultSet rs = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
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
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar os dados de um livro");
		}

	}

	public String getId(Livro livro) {
		ResultSet rs = null;
		String id = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, livro.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getString("LIVRO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			e.printStackTrace();
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		return id;

	}

	public String getNome(Livro livro) {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				nome = (rs.getString("NOME"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o nome de um livro");
		}
		return nome;

	}
	
	public String selectEditora(Livro livro) {
		ResultSet rs = null;
		Integer editoraID = -9999;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				editoraID = (rs.getInt("EDITORA_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, editoraID);
			rs = ps.executeQuery();
			while (rs.next()) {

				nome = (rs.getString("NOME"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		return nome;

	}
	
	public String selectIsbn(Livro livro) {
		ResultSet rs = null;
		String isbn = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				isbn = (rs.getString("ISBN"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		return isbn;

	}
	
	public String selectEditora(int idEditora){
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE EDITORA_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, idEditora);
			rs = ps.executeQuery();
			while (rs.next()) {

				nome = (rs.getString("NOME"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		return nome;
	}
	
	
	public int selectEditora(String nome){
		ResultSet rs = null;
		int id = -9999;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, nome);
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("EDITORA_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um livro");
		}
		return id;
	}

	public void listar(EntityModelView tela) {
		LivroTableModel.dados.clear();

		try {
			String query = "SELECT LIVRO_ID,EDITORA_ID,NOME,ISBN FROM LIVRO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");
				int idEditora = rs.getInt("EDITORA_ID");
				String nomeEditora = selectEditora(idEditora);
				String isbn = rs.getString("ISBN");
				

				LivroTableModel.dados.add(new String[] { "" + id + "","" + nome + "","" + isbn + "","" + nomeEditora, "Selecione para visualizar"});
//				
			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na tela");

		}

	}
	
	public void listarChoice(EntityModelView tela) {
		ExemplarView.getLivroChoice().removeAll();
		

		try {
			String query = "SELECT * FROM LIVRO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
//				Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");
				
				
				ExemplarView.getLivroChoice().add(nome);
				
//				
			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na lista de livros");

		}

	}
	
	public void listarList(EntityModelView tela) {
		EmprestimoView.livroModel.removeAllElements();
		

		try {
			String query = "SELECT * FROM LIVRO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
//				Integer id = rs.getInt("LIVRO_ID");
				String nome = rs.getString("NOME");
				
				
				EmprestimoView.livroModel.addElement(nome);
				
//				
			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na lista de livros");

		}

	}
	
	
	
	public Integer getId(String nome) {
		ResultSet rs = null;
		Integer id = -99999;
		// System.out.println(editora.getId());
		try {

			String query = "SELECT * FROM EDITORA WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			System.out.println("oeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
			System.out.println(nome);
			ps.setString(1, nome);
			rs = ps.executeQuery();
			
			while (rs.next()) {

				id = (rs.getInt("EDITORA_ID"));
				
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o nome de um editora");
		}
		return id;

}

	
	public String getNome(int id) {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE LIVRO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, id);
			rs = ps.executeQuery();
			while (rs.next()) {

				nome = (rs.getString("NOME"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o Nome de um livro");
		}
		return nome;

	}
	
	public int getIdLivro(String nome) {
		ResultSet rs = null;
		Integer id = null;
		// System.out.println(livro.getId());
		try {

			String query = "SELECT * FROM LIVRO WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, nome);
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("LIVRO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o Nome de um livro");
		}
		return id;

	}
	
}