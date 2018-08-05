package br.rj.senac.biblisoft.view;

import java.awt.Rectangle;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import br.rj.senac.biblisoft.control.AutorController;
import br.rj.senac.biblisoft.control.BibliotecarioController;
import br.rj.senac.biblisoft.control.CursoController;
import br.rj.senac.biblisoft.control.EditoraController;
import br.rj.senac.biblisoft.control.ExemplarController;
import br.rj.senac.biblisoft.control.LivroController;
import br.rj.senac.biblisoft.control.UsuarioController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;



public class CadastrosView extends JFrame {

	private static final long serialVersionUID = 1L;

	private JPanel jContentPane = null;

	private JButton autorBut = null;

	private JButton cursoBut = null;

	private JButton editoraBut = null;

	private JButton bibliotecarioBut = null;

	private JButton livroBut = null;

	private JButton exemplarBut = null;

	private JButton usuariosBut = null;

	/**
	 * This is the default constructor
	 */
	public CadastrosView() {
		super();
		initialize();

	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(831, 293);
		this.setContentPane(getJContentPane());
		this.setTitle("CADASTROS");
		this.setVisible(true);
	}

	/**
	 * This method initializes jContentPane
	 * 
	 * @return javax.swing.JPanel
	 */
	private JPanel getJContentPane() {
		if (jContentPane == null) {
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(getAutorBut(), null);
			jContentPane.add(getCursoBut(), null);
			jContentPane.add(getEditoraBut(), null);
			jContentPane.add(getBibliotecarioBut(), null);
			jContentPane.add(getLivroBut(), null);
			jContentPane.add(getExemplarBut(), null);
			jContentPane.add(getUsuariosBut(), null);
		}
		return jContentPane;
	}

	/**
	 * This method initializes autorBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getAutorBut() {
		if (autorBut == null) {
			autorBut = new JButton();
			autorBut.setBounds(new Rectangle(39, 30, 140, 43));

			autorBut.setText("AUTORES");
			autorBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					AutorView autorView = new AutorView();
					AutorController autorController = new AutorController();
					try {
						autorController.listar(autorView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
						
						e1.printStackTrace();
					}

				}
			});
		}
		return autorBut;
	}

	/**
	 * This method initializes cursoBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getCursoBut() {
		if (cursoBut == null) {
			cursoBut = new JButton();
			cursoBut.setBounds(new Rectangle(34, 94, 150, 44));
			cursoBut.setText("CURSOS");

			cursoBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {

					@SuppressWarnings("unused")
					CursoView cursoView = new CursoView();
					CursoController cursoController = new CursoController();
					try {
						cursoController.listar(cursoView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
						
						e1.printStackTrace();
					}
				}
			});
		}
		return cursoBut;
	}

	/**
	 * This method initializes editoraBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getEditoraBut() {
		if (editoraBut == null) {
			editoraBut = new JButton();
			editoraBut.setBounds(new Rectangle(53, 163, 130, 38));
			editoraBut.setText("EDITORAS");
			editoraBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					EditoraView editoraView = new EditoraView();
					EditoraController editoraController = new EditoraController();
					try {
						editoraController.listar(editoraView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			});
		}
		return editoraBut;
	}

	/**
	 * This method initializes bibliotecarioBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getBibliotecarioBut() {
		if (bibliotecarioBut == null) {
			bibliotecarioBut = new JButton();
			bibliotecarioBut.setBounds(new Rectangle(258, 34, 159, 47));
			bibliotecarioBut.setText("BIBLIOTECARIOS");
			bibliotecarioBut
					.addActionListener(new java.awt.event.ActionListener() {
						public void actionPerformed(java.awt.event.ActionEvent e) {
							@SuppressWarnings("unused")
							BibliotecarioView bibliotecarioView = new BibliotecarioView();
							BibliotecarioController bibliotecarioController = new BibliotecarioController();
							try {
								bibliotecarioController.listar(bibliotecarioView);
							} catch (BusinessException e1) {
								
								e1.printStackTrace();
							} catch (DatabaseException e1) {
							
								e1.printStackTrace();
							}
						}
					});
		}
		return bibliotecarioBut;
	}

	/**
	 * This method initializes livroBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getLivroBut() {
		if (livroBut == null) {
			livroBut = new JButton();
			livroBut.setBounds(new Rectangle(260, 99, 150, 50));
			livroBut.setText("LIVROS");
			livroBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					LivroView livroView = new LivroView();
					LivroController livroController = new LivroController();
				
					EditoraController editoraController = new EditoraController();
					
					AutorController autorController = new AutorController();
					try {
						autorController.listar(livroView);
						editoraController.listarChoice(livroView);
						livroController.listar(livroView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
						
						e1.printStackTrace();
					}
					LivroView.listModel.clear();
				}
			});
		}
		return livroBut;
	}

	/**
	 * This method initializes exemplarBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getExemplarBut() {
		if (exemplarBut == null) {
			exemplarBut = new JButton();
			exemplarBut.setBounds(new Rectangle(259, 163, 156, 40));
			exemplarBut.setText("EXEMPLARES");
			exemplarBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					ExemplarView exemplarView = new ExemplarView();
					ExemplarController exemplarController = new ExemplarController();
				
					LivroController livroController = new LivroController();
					try {
						exemplarController.listar(exemplarView);
						livroController.listarChoice(exemplarView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
						
						e1.printStackTrace();
					}

					
				}
			});
		}
		return exemplarBut;
	}

	/**
	 * This method initializes usuariosBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getUsuariosBut() {
		if (usuariosBut == null) {
			usuariosBut = new JButton();
			usuariosBut.setBounds(new Rectangle(487, 41, 166, 46));
			usuariosBut.setText("USUARIOS");
			usuariosBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					UsuarioView usuarioView = new UsuarioView();
					UsuarioController usuarioController = new UsuarioController();
					
					CursoController cursoController = new CursoController();
					try {
						cursoController.listarChoice(usuarioView);
						usuarioController.listar(usuarioView);
					} catch (BusinessException e1) {
						
						e1.printStackTrace();
					} catch (DatabaseException e1) {
					
						e1.printStackTrace();
					}
				}
			});
		}
		return usuariosBut;
	}

} // @jve:decl-index=0:visual-constraint="10,10"
