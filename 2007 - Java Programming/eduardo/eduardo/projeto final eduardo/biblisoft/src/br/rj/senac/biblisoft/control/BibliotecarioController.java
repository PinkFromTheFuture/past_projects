package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Bibliotecario;
import br.rj.senac.biblisoft.model.DAO.BibliotecarioDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.BibliotecarioTableModel;
import br.rj.senac.biblisoft.view.BibliotecarioView;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;

public class BibliotecarioController extends BibliosoftController {

	private BibliotecarioDAO bibliotecarioDAO = new BibliotecarioDAO();

	public BibliotecarioController() {

	}

	public void inserirBibliotecario(Bibliotecario bibliotecario)
			throws BusinessException, DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarBibliotecario(bibliotecario);

			bibliotecarioDAO.incluir(bibliotecario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirBibliotecario(Bibliotecario bibliotecario)
			throws BusinessException, DatabaseException {
		try {

			Conexao.beginTransaction();
			bibliotecarioDAO.delete(bibliotecario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarBibliotecario(Bibliotecario bibliotecario)
			throws BusinessException, DatabaseException {
		try {

			Conexao.beginTransaction();
			bibliotecarioDAO.update(bibliotecario);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Bibliotecario bibliotecario, BibliotecarioView tela)
			throws BusinessException, DatabaseException {
		try {

			bibliotecarioDAO.select(bibliotecario, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		BibliotecarioTableModel.dados.clear();

		try {
			bibliotecarioDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	public int getId(Bibliotecario bibliotecario) throws BusinessException,
			DatabaseException {

		Integer id = null;

		try {
			id = bibliotecarioDAO.getId(bibliotecario);
		} catch (DAOException e) {

			e.printStackTrace();
		}

		return id;

	}

	private void criticarBibliotecario(Bibliotecario bibliotecario)
			throws BusinessException {

		if (bibliotecario.getNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public void listarChoice(EntityModelView tela) throws BusinessException,
			DatabaseException {
		EmprestimoView.bibliotecarioChoice.removeAll();

		try {
			bibliotecarioDAO.listarChoice(tela);
		} catch (DAOException e) {

			e.printStackTrace();
		}

	}
}
