package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Bibliotecario;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.AutorTableModel;
import br.rj.senac.biblisoft.model.table.BibliotecarioTableModel;
import br.rj.senac.biblisoft.view.BibliotecarioView;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;


public class BibliotecarioDAO {
	Connection conn = Conexao.getConexao();

	public void incluir(Bibliotecario bibliotecario) throws DAOException{
		
		try {

			String query = "INSERT INTO BIBLIOTECARIO(NOME) VALUES (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, bibliotecario.getNome());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}


	}

	public  void delete(Bibliotecario bibliotecario) throws DAOException{
		try {

			String query = "DELETE FROM BIBLIOTECARIO WHERE BIBLIOTECARIO_ID =(?)";

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, bibliotecario.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}
		
	}

	public void update(Bibliotecario bibliotecario) throws DAOException{
		try {
			String query = "UPDATE BIBLIOTECARIO SET NOME = (?) WHERE BIBLIOTECARIO_ID = (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, bibliotecario.getNome());
			ps.setInt(2, bibliotecario.getId());
			ps.executeUpdate();
			conn.commit();
			conn.close();
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void select(Bibliotecario bibliotecario, BibliotecarioView tela) throws DAOException{
		ResultSet rs = null;
		// System.out.println(bibliotecario.getId());
		try {

			String query = "SELECT * FROM BIBLIOTECARIO WHERE BIBLIOTECARIO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, bibliotecario.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = (rs.getString("NOME"));

				tela.getNomeField().setText(nome);

			}
			tela.getIdField().setText("" + bibliotecario.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Bibliotecario bibliotecario) throws DAOException{
		ResultSet rs = null;
		int id = -99999;
		// System.out.println(bibliotecario.getId());
		try {

			String query = "SELECT * FROM BIBLIOTECARIO WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, bibliotecario.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("BIBLIOTECARIO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}
		return id;

	}

	public String getNome(Bibliotecario bibliotecario) throws DAOException{
		ResultSet rs = null;
		String nome = null;
		// System.out.println(bibliotecario.getId());
		try {

			String query = "SELECT * FROM BIBLIOTECARIO WHERE BIBLIOTECARIO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, bibliotecario.getId());
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

	public void listar(EntityModelView tela) throws DAOException{
		BibliotecarioTableModel.dados.clear();

		try {
			String query = "SELECT BIBLIOTECARIO_ID,NOME FROM BIBLIOTECARIO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("BIBLIOTECARIO_ID");
				String nome = rs.getString("NOME");

				BibliotecarioTableModel.dados.add(new String[] { "" + id , "" + nome  });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}
	
	public void listarChoice(EntityModelView tela) throws DAOException{
		EmprestimoView.bibliotecarioChoice.removeAll();

		try {
			String query = "SELECT * FROM BIBLIOTECARIO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
//				Integer id = rs.getInt("BIBLIOTECARIO_ID");
				String nome = rs.getString("NOME");
				EmprestimoView.bibliotecarioChoice.add(nome);
				

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}
