package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.LivroTableModel;
import br.rj.senac.biblisoft.view.EmprestimoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.ExemplarView;
import br.rj.senac.biblisoft.view.LivroView;

public class LivroController extends BibliosoftController {
	private LivroDAO livroDAO = new LivroDAO();

	public LivroController() {

	}

	public void inserirLivro(Livro livro) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarLivro(livro);

			livroDAO.incluir(livro);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirLivro(Livro livro) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			livroDAO.delete(livro);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Livro livro, LivroView tela) throws BusinessException,
			DatabaseException {
		try {

			livroDAO.select(livro, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public void alterarLivro(Livro livro) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			livroDAO.update(livro);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	private void criticarLivro(Livro livro) throws BusinessException,
			DatabaseException {

		if (livro.getIsbn() == null || livro.getNome() == null
				|| livro.getIdEditora() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public int getId(Livro livro) throws BusinessException, DatabaseException {

		Integer id = null;

		try {

			id = livroDAO.getId(livro);

		} catch (Exception e) {

			super.doRollback(e);
		}
		return id;

	}

	public int getEditoraId(Livro livro) throws BusinessException,
			DatabaseException {

		Integer id = null;

		try {

			id = livroDAO.getEditoraId(livro);

		} catch (Exception e) {

			super.doRollback(e);
		}
		return id;

	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		LivroTableModel.dados.clear();

		try {
			livroDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	public void listarList(EntityModelView tela) throws BusinessException,
			DatabaseException {
		EmprestimoView.livroModel.removeAllElements();

		try {
			livroDAO.listarList(tela);
		} catch (DAOException e) {

			e.printStackTrace();
		}

	}

	public void listarChoice(EntityModelView tela) throws BusinessException,
			DatabaseException {
		ExemplarView.getLivroChoice().removeAll();

		try {
			livroDAO.listarChoice(tela);
		} catch (DAOException e) {

			e.printStackTrace();
		}

	}
}
