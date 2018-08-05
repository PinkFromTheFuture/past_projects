package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Usuario;
import br.rj.senac.biblisoft.model.DAO.UsuarioDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.UsuarioTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.UsuarioView;

public class UsuarioController extends BibliosoftController {
	private UsuarioDAO usuarioDAO = new UsuarioDAO();

	public UsuarioController() {

	}

	public void inserirUsuario(Usuario usuario) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarUsuario(usuario);

			usuarioDAO.incluir(usuario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirUsuario(Usuario usuario) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			usuarioDAO.delete(usuario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarUsuario(Usuario usuario) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			usuarioDAO.update(usuario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Usuario usuario, UsuarioView tela)
			throws BusinessException, DatabaseException {
		try {

			usuarioDAO.select(usuario, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		UsuarioTableModel.dados.clear();

		try {
			usuarioDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	private void criticarUsuario(Usuario usuario) throws BusinessException {

		if (usuario.getMatricula() == null || usuario.getNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public int getId(Usuario usuario) throws BusinessException,
			DatabaseException {

		Integer id = null;

		try {
			id = usuarioDAO.getId(usuario);
		} catch (DAOException e) {

			e.printStackTrace();
		}

		return id;

	}

	public void listarList(EntityModelView tela) throws BusinessException,
			DatabaseException {
		EmprestimoView.usuarioModel.removeAllElements();

		try {
			usuarioDAO.listarList(tela);
		} catch (DAOException e) {

			e.printStackTrace();
		}

	}
}
