package br.rj.senac.biblisoft.control;

import java.util.Collection;

import br.rj.senac.biblisoft.model.Usuario;
import br.rj.senac.biblisoft.model.EntityModel;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.DAO.UsuarioDAO;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;

public class UsuarioController extends BibliosoftController {
private UsuarioDAO usuarioDAO = new UsuarioDAO();
	
	public UsuarioController() {
		
	}
	
	public void inserirUsuario(Usuario usuario) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			
			criticarUsuario(usuario);
			
			usuarioDAO.incluir(usuario);
			MyConnection.commit();
			
		} catch (Exception e) {

			super.doRollback(e);
		}
	}
	
	public void excluirUsuario(Usuario usuario) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			usuarioDAO.delete(usuario);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	
	public void alterarUsuario(Usuario usuario) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			usuarioDAO.update(usuario);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	
	public Collection<? extends EntityModel> pesquisarUsuario(Usuario usuario) throws BusinessException, DatabaseException {
		try {
			
			return usuarioDAO.pesquisar(usuario);
			
		} catch (Exception e) {
			
			super.doRollback(e);
			
			return null;
		}
	}
	
	private void criticarUsuario (Usuario usuario) throws BusinessException{
		
		if(usuario.getMatricula()==null || usuario.getNome()== null){
			
			throw new BusinessException("Todos os campos devem ser preenchidos!");
			
		}
	}
}
