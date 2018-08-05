package br.rj.senac.biblisoft.model;

public class Exemplar {

	private Integer id;
	private Integer idLivro;
	private Integer numex;
	private String livroNome;

	public String getLivroNome() {
		return livroNome;
	}

	public void setLivroNome(String livroNome) {
		this.livroNome = livroNome;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getIdLivro() {
		return idLivro;
	}

	public void setIdLivro(Integer idLivro) {
		this.idLivro = idLivro;
	}

	public Integer getNumex() {
		return numex;
	}

	public void setNumex(Integer numex) {
		this.numex = numex;
	}
}
