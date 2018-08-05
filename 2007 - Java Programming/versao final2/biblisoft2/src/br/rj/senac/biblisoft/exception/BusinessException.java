package br.rj.senac.biblisoft.exception;

public class BusinessException extends Exception {
	
	public BusinessException(String msg) {
		super(msg);
	}
	
	public BusinessException(Exception e) {
		super(e);
	}
	
	public BusinessException(String msg, Exception e) {
		super(msg, e);
	}
}
