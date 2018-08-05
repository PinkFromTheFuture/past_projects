package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.DAO.EmprestimoDAO;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.EmprestimoTableModel;
import br.rj.senac.biblisoft.view.EntityModelView;

public class EmprestimoController extends BibliosoftController {
	private EmprestimoDAO emprestimoDAO = new EmprestimoDAO();
	public static final Integer MAXIMO_EMPRESTIMO = 3;

	public EmprestimoController() {

	}

	public void inserirEmprestimo(Emprestimo emprestimo)
			throws BusinessException, DatabaseException {
		try {

			Conexao.beginTransaction();
			criticarEmprestimo(emprestimo);
			
//			criticarNumeroEmprestimos(emprestimo.getIdUsuario());

			emprestimoDAO.incluir(emprestimo);

			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	public void devolver(Emprestimo emprestimo) throws BusinessException,
			DatabaseException {
		try {

			Conexao.beginTransaction();
			emprestimoDAO.devolver(emprestimo);
			Conexao.commit();

		} catch (Exception e) {

			super.doRollback(e);
		}
	}

	private void criticarEmprestimo(Emprestimo emprestimo)
			throws BusinessException {

		if (emprestimo.getIdBibliotecario() == null
				|| emprestimo.getIdExemplar() == null
				|| emprestimo.getIdUsuario() == null) {

			throw new BusinessException(
					"Todos os campos devem ser preenchidos!");

		}
	}

	
	/**
	 * esse métodos criticarNumeroEmprestimos esta muito problematico...
	 * 
	 * no sabado ele funcionou, mas eu perdi, e agora quando refiz ele simplesmente da tilt!
	 * meu tmepo acabou, não vou ter chance de arrumalo.
	 * 
	 * @param tela
	 * @throws BusinessException
	 * @throws DatabaseException
	 */
	
	
//	private void criticarNumeroEmprestimos(int usuarioId)
//			throws BusinessException {
//Integer num =null;
//System.out.println("oioi 22222" + num);
//			
//			try {
//				num = emprestimoDAO.getEmprestimos(usuarioId);
//			} catch (DAOException e) {
//				
//				e.printStackTrace();
//			}
//			System.out.println("oioi " + num);
//			if (num >= MAXIMO_EMPRESTIMO) {
//
//				throw new BusinessException(
//						"Não é possível realizar o empréstimo"
//								+ "\nO número máximo permitido é de"
//								+ MAXIMO_EMPRESTIMO + " empréstimos.");
//			}
//
//
//	}

	public void listar(EntityModelView tela) throws BusinessException,
			DatabaseException {
		EmprestimoTableModel.dados.clear();

		try {
			emprestimoDAO.listar(tela);

		} catch (Exception e) {
			super.doRollback(e);

		}

	}

}
