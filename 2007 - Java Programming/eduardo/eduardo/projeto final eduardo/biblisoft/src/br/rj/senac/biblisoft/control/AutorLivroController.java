package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.AutorLivro;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.DAO.AutorLivroDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;

public class AutorLivroController extends BibliosoftController {
	private AutorLivroDAO autorLivroDAO = new AutorLivroDAO();

	public AutorLivroController() {

	}

	public void inserir(AutorLivro autorLivro) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarLivro(autorLivro);

			autorLivroDAO.incluir(autorLivro);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluir(AutorLivro autorLivro) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			autorLivroDAO.delete(autorLivro);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Livro livro) throws BusinessException, DatabaseException {
		try {

			autorLivroDAO.select(livro);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	// public void alterarLivro(AutorLivro autorLivro) throws BusinessException,
	// DatabaseException {
	// try {
	//
	// Conexao.beginTransaction();
	// autorLivroDAO.update(autorLivro);
	// Conexao.commit();
	//
	// } catch (Exception e) {
	//
	// super.doRollback(e);
	// }
	// }

	private void criticarLivro(AutorLivro autorLivro) throws BusinessException {

		if (autorLivro.getIdAutor() == null || autorLivro.getIdLivro() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	// public int getId(AutorLivro autorLivro) throws DAOException {
	//
	// Integer id = null;
	//
	// try {
	//
	// id = autorLivroDAO.getId(autorLivro);
	//
	// } catch (Exception e) {
	// throw new DAOException(e);
	// }
	// return id;
	//
	// }
	//
	// public int getEditoraId(AutorLivro autorLivro) throws DAOException {
	//
	// Integer id = null;
	//
	// try {
	//
	// id = autorLivroDAO.getEditoraId(autorLivro);
	//
	// } catch (Exception e) {
	// throw new DAOException(e);
	// }
	// return id;
	//
	// }
}
