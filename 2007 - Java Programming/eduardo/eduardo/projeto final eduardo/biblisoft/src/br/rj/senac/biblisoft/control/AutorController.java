package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.DAO.AutorDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;

import br.rj.senac.biblisoft.model.table.AutorTableModel;
import br.rj.senac.biblisoft.view.AutorView;
import br.rj.senac.biblisoft.view.EntityModelView;

public class AutorController extends BibliosoftController {

	AutorDAO autorDAO = new AutorDAO();

	public AutorController() {

	}

	public void inserirAutor(Autor autor) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarAutor(autor);

			autorDAO.inserir(autor);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirAutor(Autor autor) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			autorDAO.delete(autor);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarAutor(Autor autor) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			autorDAO.update(autor);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public String getNome(Autor autor) throws BusinessException,
			DatabaseException {
		String nome = null;
		try {
			Conexao.beginTransaction();
			nome = autorDAO.getNome(autor);

		} catch (Exception e) {

			super.doRollback(e);
		}
		return nome;
	}

	public void select(Autor autor, AutorView tela) throws BusinessException,
			DatabaseException {
		try {

			autorDAO.select(autor, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		AutorTableModel.dados.clear();

		try {
			autorDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	private void criticarAutor(Autor autor) throws BusinessException {

		if (autor.getNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public int getId(Autor autor) throws DAOException {

		Integer id = null;

		try {

			id = autorDAO.getId(autor);

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return id;

	}
}
