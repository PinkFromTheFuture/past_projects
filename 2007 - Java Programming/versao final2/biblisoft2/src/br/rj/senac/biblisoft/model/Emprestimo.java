package br.rj.senac.biblisoft.model;

import java.sql.Date;

public class Emprestimo {
	private Integer id;
	private Integer idExemplar;
	private Integer idUsuario;
	private Integer idBibliotecario;
	private Date dataEntrega;
	private Date dataDevolucao;

	public Date getDataDevolucao() {
		return dataDevolucao;
	}

	public void setDataDevolucao(Date dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}

	public Date getDataEntrega() {
		return dataEntrega;
	}

	public void setDataEntrega(Date dataEntrega) {
		this.dataEntrega = dataEntrega;
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
