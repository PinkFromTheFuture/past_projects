package br.rj.senac.biblisoft.control;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.conexao.Conexao;



public class BibliosoftController {

	public void doRollback(Exception e) throws DatabaseException, BusinessException {
		
		System.out.println(e.getStackTrace().toString() );
		
		Conexao.rollback();
		
		if (e instanceof DAOException) {

			throw new DatabaseException("Ocorreu um erro ao efetuar uma operação com o banco de dados", e);
			
		} else if (e instanceof RuntimeException) {
			
			throw new BusinessException("Ocorreu um erro RUNTIME de programação! " +
					"Por favor contacte a equipe de suporte para que " +
					"possamos corrigir este erro. ", e);
			
		} else if (e instanceof BusinessException){
			throw new BusinessException(e);
		}
	}
}
