package br.rj.senac.biblisoft.control;

import java.util.Collection;

import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.EntityModel;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.DAO.ExemplarDAO;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;

public class ExemplarController extends BibliosoftController {
private ExemplarDAO exemplarDAO = new ExemplarDAO();
	
	public ExemplarController() {
		
	}
	
	public void inserirExemplar(Exemplar exemplar) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			
			criticarExemplar(exemplar);
			
			exemplarDAO.incluir(exemplar);
			MyConnection.commit();
			
		} catch (Exception e) {

			super.doRollback(e);
		}
	}
	
	public void excluirExemplar(Exemplar exemplar) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			exemplarDAO.delete(exemplar);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	
	public void alterarExemplar(Exemplar exemplar) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			exemplarDAO.update(exemplar);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	
	public Collection<? extends EntityModel> pesquisarExemplar(Exemplar exemplar) throws BusinessException, DatabaseException {
		try {
			
			return exemplarDAO.pesquisar(exemplar);
			
		} catch (Exception e) {
			
			super.doRollback(e);
			
			return null;
		}
	}
	
	private void criticarExemplar(Exemplar exemplar) throws BusinessException{
		
		if(exemplar.getNumex()== null || exemplar.getLivroNome() == null){
			
			throw new BusinessException("Todos os campos devem ser preenchidos!");
			
		}
	}
}
