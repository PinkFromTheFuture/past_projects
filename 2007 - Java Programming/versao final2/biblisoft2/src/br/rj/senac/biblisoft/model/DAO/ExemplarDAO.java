package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.ExemplarTableModel;
import br.rj.senac.biblisoft.model.table.LivroTableModel;
import br.rj.senac.biblisoft.view.AutorView;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;

import com.mysql.jdbc.exceptions.MySQLIntegrityConstraintViolationException;




public class ExemplarDAO {
	Connection conn = Conexao.getConexao();

	public void incluir(Exemplar exemplar) {

		try {

			String query = "INSERT INTO EXEMPLAR(LIVRO_ID,NUMEX) VALUES (?,?)";
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

			// } catch (Exception ex) {
			// ex.printStackTrace();
		} catch (MySQLIntegrityConstraintViolationException e) {
			System.out.println("Cadastro já efetuado.");
		} catch (SQLException e) {

			e.printStackTrace();
		}

	}

	public void delete(Exemplar exemplar) {
		try {

			String query = "DELETE FROM EXEMPLAR WHERE EXEMPLAR_ID = (?)";

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, exemplar.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

	public void select(Exemplar exemplar, ExemplarView tela) {
		ResultSet rs = null;
		// System.out.println(exemplar.getId());
		try {

			String query = "SELECT * FROM EXEMPLAR WHERE EXEMPLAR_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String numex = (rs.getString("NUMEX"));

				tela.getNumeroField().setText(numex);

			}
			tela.getIdField().setText("" + exemplar.getId());
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar os dados de um exemplar");
		}

	}

	public void listar(EntityModelView tela) {
		ExemplarTableModel.dados.clear();
		LivroDAO livroDAO = new LivroDAO();

		try {
			String query = "SELECT EXEMPLAR_ID,LIVRO_ID,NUMEX FROM EXEMPLAR ORDER BY EXEMPLAR_ID";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("EXEMPLAR_ID");
				int livroId = rs.getInt("LIVRO_ID");
				int numex = rs.getInt("NUMEX");
				String livroNome = livroDAO.getNome(livroId);

				ExemplarTableModel.dados.add(new String[] { "" + id + "",
						"" + livroNome + "", "" + numex });
				//				
			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na telaaaaaaa");
			e.printStackTrace();

		}

	}

	public String selectId(Exemplar exemplar) {
		ResultSet rs = null;
		String id = null;
		// System.out.println(exemplar.getId());
		try {

			String query = "SELECT * FROM EXEMPLAR WHERE LIVRO_ID = ? AND NUMEX = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getString("EXEMPLAR_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um exemplar");
		}
		return id;

	}

	public void update(Exemplar exemplar) {
		try {
			String query = "UPDATE EXEMPLAR SET LIVRO_ID = (?), NUMEX = (?) WHERE EXEMPLAR_ID = (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());
			ps.setInt(3, exemplar.getId());
			ps.executeUpdate();
			conn.commit();

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar atualizar o cadastro de um exemplar");
			e.printStackTrace();
		}

	}

	public void listarChoice(EntityModelView tela, Livro livro) {
		ResultSet rs = null;
		EmprestimoView.getExemplarChoice().removeAll();
		LivroDAO livroDAO = new LivroDAO();

		try {
			// String query = "SELECT EXEMPLAR_ID,NUMEX FROM EXEMPLAR WHERE
			
//			select exemplar_id,numex from exemplar where exemplar_id NOT IN (select * from emprestimo where emprestimo.datadevolucao is not null);
//			select exemplar_id,numex from exemplar where exemplar_id NOT IN (select exemplar_id, datadevolucao from emprestimo where datadevolucao is not null);
//			String query = "SELECT NUMEX,LIVRO_ID FROM EXEMPLAR LEFT OUTER JOIN EMPRESTIMO ON EXEMPLAR.EXEMPLAR_ID = EMPRESTIMO.EXEMPLAR_ID WHERE EMPRESTIMO.DATADEVOLUCAO IS NOT NULL AND LIVRO_ID = (?)";
			
			String query = "select distinct exemplar_id,numex from exemplar where livro_id = ? AND exemplar_id NOT IN (select exemplar_id from emprestimo where datadevolucao is null)";
			
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();

			while (rs.next()) {
				// Integer id = rs.getInt("EXEMPLAR_ID");
				// int livroId = rs.getInt("LIVRO_ID");
				int numex = rs.getInt("NUMEX");
				// String livroNome = livroDAO.getNome(livroId);

				EmprestimoView.getExemplarChoice().add("" + numex);

				//				
			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na telaaaaaaa");
			e.printStackTrace();

		}

	}

}