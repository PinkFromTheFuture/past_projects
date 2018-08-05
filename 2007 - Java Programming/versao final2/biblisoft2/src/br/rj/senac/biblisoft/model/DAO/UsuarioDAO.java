package br.rj.senac.biblisoft.model.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;



import br.rj.senac.biblisoft.model.Usuario;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.UsuarioTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.UsuarioView;


public class UsuarioDAO {
	Connection conn = Conexao.getConexao();

	public void incluir(Usuario usuario) {
	
		try {

			String query = "INSERT INTO USUARIO(CURSO_ID,NOME,MATRICULA) VALUES (?,?,?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, usuario.getCursoId());
			ps.setString(2, usuario.getNome());
			ps.setString(3, usuario.getMatricula());

			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (SQLException e) {
			System.out
					.println("houve algum erro ao tentar inserir dados na tabela de usuarios");
			

		}


	}

	public void delete(Usuario usuario) {
		try {

			String query = "DELETE FROM USUARIO WHERE USUARIO_ID =(?)";

			PreparedStatement ps = conn.prepareStatement(query);

			ps.setInt(1, usuario.getId());
			ps.executeUpdate();

			conn.commit();
			// conn.close();

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar remover dados da tabela de usuarios");
		}
		
	}

	public void update(Usuario usuario) {
		try {
			String query = "UPDATE USUARIO SET NOME = (?), MATRICULA = (?), CURSO_ID = (?) WHERE USUARIO_ID = (?)";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, usuario.getNome());
			ps.setString(2, usuario.getMatricula());
			ps.setInt(3, usuario.getCursoId());
			ps.setInt(4, usuario.getId());
			ps.executeUpdate();
			conn.commit();
			
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar atualizar o cadastro de um usuario");
		}

	}

	public void select(Usuario usuario, UsuarioView tela) {
		ResultSet rs = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE USUARIO_ID = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setInt(1, usuario.getId());
			rs = ps.executeQuery();
			while (rs.next()) {

				String nome = rs.getString("NOME");
				String matricula = rs.getString("MATRICULA");
				

				tela.getNomeField().setText(nome);
				tela.getIdField().setText(""+usuario.getId());
				tela.getMatriculaField().setText(matricula);

			}
			tela.getIdField().setText("" + usuario.getId());
		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar os dados de um usuario");
		}

	}
	
	
	
	

	public String selectId(Usuario usuario) {
		ResultSet rs = null;
		String id = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE NOME = ?";
			PreparedStatement ps = conn.prepareStatement(query);
			ps.setString(1, usuario.getNome());
			rs = ps.executeQuery();
			while (rs.next()) {

				id = (rs.getString("USUARIO_ID"));
				// System.out.println(id);

				// conn.close();

			}

		} catch (SQLException e) {
			System.out
					.println("houve algum problema ao tentar selecionar o ID de um usuario");
		}
		return id;

	}

	public String selectNome(int id) {
		ResultSet rs = null;
		String nome = null;
		// System.out.println(usuario.getId());
		try {

			String query = "SELECT * FROM USUARIO WHERE USUARIO_ID = ?";
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
					.println("houve algum problema ao tentar selecionar o ID de um usuario");
		}
		return nome;

	}

	public void listar(EntityModelView tela) {
		UsuarioTableModel.dados.clear();
		CursoDAO cursoDAO = new CursoDAO();
		try {
			String query = "SELECT * FROM USUARIO ORDER BY NOME";
			PreparedStatement sql = conn.prepareStatement(query);
			ResultSet rs = sql.executeQuery();
			conn.commit();

			while (rs.next()) {
				Integer id = rs.getInt("USUARIO_ID");
				String nome = rs.getString("NOME");
				String matricula = rs.getString("MATRICULA");
				int cursoId = rs.getInt("CURSO_ID");
				String cursoNome = cursoDAO.getNome(cursoId);
				

				UsuarioTableModel.dados.add(new String[] { "" + id + "","" + nome + "", matricula, cursoNome });

			}

		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na tela");

		}

	}
	
	
	public void listarList(EntityModelView tela) {
		EmprestimoView.usuarioModel.removeAllElements();
		 ArrayList<String> util = new ArrayList<String>();
		
		try {
			String query = "SELECT * FROM USUARIO ORDER BY NOME";
			String query2 = "select usuario_id from emprestimo where datadevolucao is null";
//			String query1 = "select distinct usuario_id from usuario where usuario_id IN(select usuario_id from emprestimo where datadevolucao is null)";
			PreparedStatement sql = conn.prepareStatement(query);
			PreparedStatement sql2 = conn.prepareStatement(query2);
			ResultSet rs = sql.executeQuery();
			ResultSet rs2 = sql2.executeQuery();
//			conn.commit();

			
while (rs2.next()) {
				
				Integer id = rs.getInt("USUARIO_ID");
//				for (int x = 0; x< 999999; x++){
//					util.contains(x);
//					util.
//				}
//				
//				util.add(""+id);
//				util.
				
			}
			
			while (rs.next()) {
				
				String nome = rs.getString("NOME");
				
				
				util.add(nome);
				



			}
			int a = util.size();

			if(a < 4) {
				for(int i = 0; i < util.size(); i++){
					EmprestimoView.usuarioModel.addElement(util.get(i));
				}
				
				
				
			}

			
			


		} catch (SQLException e) {
			System.out
					.println("Houve algum problema ao exibir os dados na tela");

		}

	}
	
	


}