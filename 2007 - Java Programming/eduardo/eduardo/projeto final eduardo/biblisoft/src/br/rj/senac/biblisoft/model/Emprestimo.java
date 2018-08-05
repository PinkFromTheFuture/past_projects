package br.rj.senac.biblisoft.model;



public class Emprestimo {
	private Integer id;
	private Integer idExemplar;
	private Integer idUsuario;
	private Integer idBibliotecario;
	private java.util.Date dataEntrega;
	private java.util.Date dataDevolucao;

	public java.util.Date getDataDevolucao() {
		return dataDevolucao;
	}

	public void setDataDevolucao(java.util.Date date) {
		this.dataDevolucao = date;
	}

	public java.util.Date getDataEntrega() {
		return dataEntrega;
	}

	public void setDataEntrega(java.util.Date date) {
		this.dataEntrega = date;
	}

	public Integer getIdBibliotecario() {
		return idBibliotecario;
	}

	public void setIdBibliotecario(Integer idBibliotecario) {
		this.idBibliotecario = idBibliotecario;
	}

	public Integer getIdExemplar() {
		return idExemplar;
	}

	public void setIdExemplar(Integer idExemplar) {
		this.idExemplar = idExemplar;
	}

	public Integer getIdUsuario() {
		return idUsuario;
	}

	public void setIdUsuario(Integer idUsuario) {
		this.idUsuario = idUsuario;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

}
