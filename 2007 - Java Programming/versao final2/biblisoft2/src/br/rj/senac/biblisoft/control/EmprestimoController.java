package br.rj.senac.biblisoft.control;

import java.util.Collection;

import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.EntityModel;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.DAO.EmprestimoDAO;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;

public class EmprestimoController extends BibliosoftController {
private EmprestimoDAO emprestimoDAO = new EmprestimoDAO();
	
	public EmprestimoController() {
		
	}
	
	public void inserirEmprestimo(Emprestimo emprestimo) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			emprestimoDAO.incluir(emprestimo);
			MyConnection.commit();
			
		} catch (Exception e) {

			super.doRollback(e);
		}
	}
	
	public void devolver(Emprestimo emprestimo) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			emprestimoDAO.devolver(emprestimo);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	

	
	public Collection<? extends EntityModel> pesquisarEditora(Emprestimo emprestimo) throws BusinessException, DatabaseException {
		try {
			
			return emprestimoDAO.pesquisar(emprestimo);
			
		} catch (Exception e) {
			
			super.doRollback(e);
			
			return null;
		}
	}
}
