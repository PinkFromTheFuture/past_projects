package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.ExemplarTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;

public class ExemplarDAO {

	public void incluir(Exemplar exemplar) throws DAOException {

		try {

			String query = "INSERT INTO EXEMPLAR(LIVRO_ID,NUMEX) VALUES (?,?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

			// } catch (Exception ex) {
			// ex.printStackTrace();
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Exemplar exemplar) throws DAOException {
		try {

			String query = "DELETE FROM EXEMPLAR WHERE EXEMPLAR_ID = (?)";
			Connection conn = Conexao.getConnection();

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, exemplar.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}
	}

	public void select(Exemplar exemplar, ExemplarView tela)
			throws DAOException {
		ResultSet rs = null;
		// System.out.println(exemplar.getId());
		try {

			String query = "SELECT * FROM EXEMPLAR WHERE EXEMPLAR_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String numex = (rs.getString("NUMEX"));

				tela.getNumeroField().setText(numex);

			}
			tela.getIdField().setText("" + exemplar.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listar(EntityModelView tela) throws DAOException {
		ExemplarTableModel.dados.clear();
		LivroDAO livroDAO = new LivroDAO();

		try {
			String query = "SELECT EXEMPLAR_ID,LIVRO_ID,NUMEX FROM EXEMPLAR ORDER BY EXEMPLAR_ID";

			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("EXEMPLAR_ID");
				int livroId = rs.getInt("LIVRO_ID");
				int numex = rs.getInt("NUMEX");
				String livroNome = null;
				try {
					livroNome = livroDAO.getNome(livroId);
				} catch (DAOException e) {

					e.printStackTrace();
				}

				ExemplarTableModel.dados.add(new String[] { "" + id + "",
						"" + livroNome + "", "" + numex });
				//				
			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Exemplar exemplar) throws DAOException {
		ResultSet rs = null;
		Integer id = null;
		// System.out.println(exemplar.getId());
		try {

			String query = "SELECT * FROM EXEMPLAR WHERE LIVRO_ID = ? AND NUMEX = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("EXEMPLAR_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public void update(Exemplar exemplar) throws DAOException {
		try {
			String query = "UPDATE EXEMPLAR SET LIVRO_ID = (?), NUMEX = (?) WHERE EXEMPLAR_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, exemplar.getIdLivro());
			ps.setInt(2, exemplar.getNumex());
			ps.setInt(3, exemplar.getId());
			ps.executeUpdate();
			conn.commit();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarChoice(EntityModelView tela, Livro livro)
			throws DAOException {
		ResultSet rs = null;
		EmprestimoView.getExemplarChoice().removeAll();


		try {
			

			String query = "select distinct exemplar_id,numex from exemplar where livro_id = ? AND exemplar_id NOT IN (select exemplar_id from emprestimo where datadevolucao is null)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, livro.getId());
			rs = ps.executeQuery();

			while (rs.next()) {
				
				int numex = rs.getInt("NUMEX");
			

				EmprestimoView.getExemplarChoice().add("" + numex);

						
			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}