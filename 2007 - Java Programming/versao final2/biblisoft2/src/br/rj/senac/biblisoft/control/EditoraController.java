package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Editora;
import br.rj.senac.biblisoft.model.DAO.EditoraDAO;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.table.EditoraTableModel;
import br.rj.senac.biblisoft.view.EditoraView;
import br.rj.senac.biblisoft.view.EntityModelView;

public class EditoraController extends BibliosoftController {

	private EditoraDAO editoraDAO = new EditoraDAO();

	public EditoraController() {

	}

	public void inserirEditora(Editora editora) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();

			criticarEditora(editora);

			editoraDAO.incluir(editora);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirEditora(Editora editora) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();
			editoraDAO.delete(editora);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarEditora(Editora editora) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();
			editoraDAO.update(editora);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		EditoraTableModel.dados.clear();

		try {
			editoraDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

	public String getNome(Editora editora) throws BusinessException,
			DatabaseException {

		String nome = null;

		try {

			nome = editoraDAO.getNome(editora);

		} catch (Exception e) {

			super.doRollback(e);
		}
		return nome;

	}

	public void select(Editora editora, EditoraView tela)
			throws BusinessException, DatabaseException {
		try {

			editoraDAO.select(editora, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	private void criticarEditora(Editora editora) throws BusinessException {

		if (editora.getNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public int getId(Editora editora) throws DAOException {

		Integer id = null;

		try {

			id = editoraDAO.getId(editora);

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return id;

	}

}
