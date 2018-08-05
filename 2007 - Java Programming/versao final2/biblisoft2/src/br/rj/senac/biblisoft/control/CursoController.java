package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Curso;
import br.rj.senac.biblisoft.model.DAO.CursoDAO;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.table.CursoTableModel;
import br.rj.senac.biblisoft.model.table.EditoraTableModel;
import br.rj.senac.biblisoft.view.CursoView;
import br.rj.senac.biblisoft.view.EntityModelView;

public class CursoController extends BibliosoftController {
	private CursoDAO cursoDAO = new CursoDAO();

	public CursoController() {

	}

	public void inserirCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();

			criticarCurso(curso);

			cursoDAO.incluir(curso);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();
			cursoDAO.delete(curso);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			MyConnection.beginTransaction();
			cursoDAO.update(curso);
			MyConnection.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void select(Curso curso, CursoView tela) throws BusinessException,
			DatabaseException {
		try {

			cursoDAO.select(curso, tela);

		} catch (Exception e) {

			super.doRollback(e);

		}
	}

	public int getId(Curso curso) throws DAOException {

		Integer id = null;

		try {

			id = cursoDAO.getId(curso);

		} catch (Exception e) {
			throw new DAOException(e);
		}
		return id;

	}

	public String getNome(Curso curso) throws BusinessException,
			DatabaseException {
		String nome = null;
		try {
			MyConnection.beginTransaction();
			nome = cursoDAO.getNome(curso);

		} catch (Exception e) {

			super.doRollback(e);
		}
		return nome;
	}

	private void criticarCurso(Curso curso) throws BusinessException {

		if (curso.getNome() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		CursoTableModel.dados.clear();

		try {
			cursoDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

}
