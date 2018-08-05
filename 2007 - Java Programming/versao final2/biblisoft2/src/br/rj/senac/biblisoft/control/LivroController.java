package br.rj.senac.biblisoft.control;

import java.util.Collection;

import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.EntityModel;
import br.rj.senac.biblisoft.model.conexao.MyConnection;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;
import br.rj.senac.biblisoft.view.AutorView;
import br.rj.senac.biblisoft.view.LivroView;

import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;

public class LivroController extends BibliosoftController {
private LivroDAO livroDAO = new LivroDAO();
	
	public LivroController() {
		
	}
	
	public void inserirLivro(Livro livro) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			
			criticarLivro(livro);
			
			livroDAO.incluir(livro);
			MyConnection.commit();
			
		} catch (Exception e) {

			super.doRollback(e);
		}
	}
	
	public void excluirLivro(Livro livro) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			livroDAO.delete(livro);
			MyConnection.commit();
			
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
	
	public void alterarLivro(Livro livro) throws BusinessException, DatabaseException {
		try {
			
			MyConnection.beginTransaction();
			livroDAO.update(livro);
			MyConnection.commit();
			
		} catch (Exception e) {
			
			super.doRollback(e);
		}
	}
	

	
	private void criticarLivro(Livro livro) throws BusinessException{
		
		if (livro.getIsbn()==null || livro.getNome()==null || livro.getIdEditora()==null){
			
			throw new BusinessException("Todos os campos devem ser preenchidos!");
			
		}
	}
}
