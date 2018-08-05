package br.rj.senac.biblisoft.exception;

@SuppressWarnings("serial")
public class DAOException extends Exception {

	public DAOException(String msg) {
		super(msg);
	}
	
	public DAOException(Exception e) {
		super(e);
	}
	
	public DAOException(String msg, Exception e) {
		super(msg, e);
	}
}
