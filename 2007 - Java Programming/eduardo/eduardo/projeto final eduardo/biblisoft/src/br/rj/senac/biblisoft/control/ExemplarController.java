package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.DAO.ExemplarDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.ExemplarTableModel;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;

public class ExemplarController extends BibliosoftController {
	private ExemplarDAO exemplarDAO = new ExemplarDAO();

	public ExemplarController() {

	}

	public void inserirExemplar(Exemplar exemplar) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarExemplar(exemplar);

			exemplarDAO.incluir(exemplar);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirExemplar(Exemplar exemplar) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			exemplarDAO.delete(exemplar);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarExemplar(Exemplar exemplar) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			exemplarDAO.update(exemplar);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Exemplar exemplar, ExemplarView tela)
			throws BusinessException, DatabaseException {
		try {

			exemplarDAO.select(exemplar, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		ExemplarTableModel.dados.clear();

		try {
			exemplarDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	private void criticarExemplar(Exemplar exemplar) throws BusinessException {

		if (exemplar.getNumex() == null || exemplar.getLivroNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public int getId(Exemplar exemplar) throws BusinessException,
			DatabaseException {

		Integer id = null;

		try {
			id = exemplarDAO.getId(exemplar);
		} catch (DAOException e) {

			e.printStackTrace();
		}

		return id;

	}
}
