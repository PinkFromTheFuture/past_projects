package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Curso;
import br.rj.senac.biblisoft.model.DAO.CursoDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.CursoTableModel;
import br.rj.senac.biblisoft.view.CursoView;
import br.rj.senac.biblisoft.view.EntityModelView;
import br.rj.senac.biblisoft.view.UsuarioView;

public class CursoController extends BibliosoftController {
	private CursoDAO cursoDAO = new CursoDAO();

	public CursoController() {

	}

	public void inserirCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();

			criticarCurso(curso);

			cursoDAO.incluir(curso);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void excluirCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			cursoDAO.delete(curso);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void alterarCurso(Curso curso) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			cursoDAO.update(curso);
			Conexao.commit();

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
			Conexao.beginTransaction();
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

	public void listarChoice(EntityModelView tela) throws BusinessException,
			DatabaseException {
		UsuarioView.cursoChoice.removeAll();

		try {
			cursoDAO.listarChoice(tela);
		} catch (DAOException e) {

			e.printStackTrace();
		}

	}

}
