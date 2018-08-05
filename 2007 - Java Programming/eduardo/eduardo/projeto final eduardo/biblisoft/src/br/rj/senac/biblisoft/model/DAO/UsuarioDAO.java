package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.model.Curso;
import br.rj.senac.biblisoft.model.Usuario;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.UsuarioTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.UsuarioView;

public class UsuarioDAO {

	public void incluir(Usuario usuario) throws DAOException {

		try {

			String query = "INSERT INTO USUARIO(CURSO_ID,NOME,MATRICULA) VALUES (?,?,?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, usuario.getCursoId());
			ps.setString(2, usuario.getNome());
			ps.setString(3, usuario.getMatricula());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void delete(Usuario usuario) throws DAOException {
		try {

			String query = "DELETE FROM USUARIO WHERE USUARIO_ID =(?)";
			Connection conn = Conexao.getConnection();

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, usuario.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void update(Usuario usuario) throws DAOException {
		try {
			String query = "UPDATE USUARIO SET NOME = (?), MATRICULA = (?), CURSO_ID = (?) WHERE USUARIO_ID = (?)";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, usuario.getNome());
			ps.setString(2, usuario.getMatricula());
			ps.setInt(3, usuario.getCursoId());
			ps.setInt(4, usuario.getId());
			ps.executeUpdate();
			conn.commit();

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void select(Usuario usuario, UsuarioView tela) throws DAOException {
		ResultSet rs = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE USUARIO_ID = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, usuario.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = rs.getString("NOME");
				String matricula = rs.getString("MATRICULA");

				tela.getNomeField().setText(nome);
				tela.getIdField().setText("" + usuario.getId());
				tela.getMatriculaField().setText(matricula);

			}
			tela.getIdField().setText("" + usuario.getId());
		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public int getId(Usuario usuario) throws DAOException {
		ResultSet rs = null;
		Integer id = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE NOME = ?";
			Connection conn = Conexao.getConnection();
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, usuario.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getInt("USUARIO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

		return id;

	}

	public String selectNome(int id) throws DAOException {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE USUARIO_ID = ?";
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

	public void listar(EntityModelView tela) throws DAOException {
		UsuarioTableModel.dados.clear();
		CursoDAO cursoDAO = new CursoDAO();
		Curso curso = new Curso();
		try {
			String query = "SELECT * FROM USUARIO ORDER BY NOME";
			Connection conn = Conexao.getConnection();
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("USUARIO_ID");
				String nome = rs.getString("NOME");
				String matricula = rs.getString("MATRICULA");
				int cursoId = rs.getInt("CURSO_ID");
				curso.setId(cursoId);
				String cursoNome = cursoDAO.getNome(curso);

				UsuarioTableModel.dados.add(new String[] { "" + id + "",
						"" + nome + "", matricula, cursoNome });

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

	public void listarList(EntityModelView tela) throws DAOException {

		try {
			String query = "SELECT * FROM USUARIO ORDER BY NOME";
			Connection conn = Conexao.getConnection();

			PreparedStatement sql = conn.prepareStatement(query);

			ResultSet rs = sql.executeQuery();

			while (rs.next()) {

				String nome = rs.getString("NOME");
				EmprestimoView.usuarioModel.addElement(nome);

			}

		} catch (Exception e) {
			throw new DAOException(e);

		}

	}

}