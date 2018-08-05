package br.rj.senac.biblisoft.view;

import java.awt.Rectangle;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import br.rj.senac.biblisoft.control.BibliotecarioController;
import br.rj.senac.biblisoft.control.EmprestimoController;
import br.rj.senac.biblisoft.control.LivroController;
import br.rj.senac.biblisoft.control.UsuarioController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;

public class LoginView extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton devolucaoBut = null;
	private JButton cadastrosBut = null;
	private JButton emprestimosBut = null;

	/**
	 * This is the default constructor
	 */
	public LoginView() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {

		this.setSize(347, 390);
		this.setContentPane(getJContentPane());
		this.setTitle("Biblioteca");
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
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
			jContentPane.add(getDevolucaoBut(), null);
			jContentPane.add(getCadastrosBut(), null);
			jContentPane.add(getEmprestimosBut(), null);
		}
		return jContentPane;
	}

	/**
	 * This method initializes devolucaoBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getDevolucaoBut() {
		if (devolucaoBut == null) {
			devolucaoBut = new JButton();
			devolucaoBut.setBounds(new Rectangle(48, 186, 181, 49));
			devolucaoBut.setText("DEVOLUÇÕES");
			devolucaoBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					EmprestimoController emprestimoController = new EmprestimoController();
					DevolucaoView devolucaoView = new DevolucaoView();
					
					

					try {
						emprestimoController.listar(devolucaoView);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

				}
			});
		}
		return devolucaoBut;
	}

	/**
	 * This method initializes cadastrosBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getCadastrosBut() {
		if (cadastrosBut == null) {
			cadastrosBut = new JButton();
			cadastrosBut.setBounds(new Rectangle(51, 35, 175, 57));
			cadastrosBut.setText("CADASTROS");
			cadastrosBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					CadastrosView cadastros = new CadastrosView();
				}
			});
		}
		return cadastrosBut;
	}

	/**
	 * This method initializes emprestimosBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getEmprestimosBut() {
		if (emprestimosBut == null) {
			emprestimosBut = new JButton();
			emprestimosBut.setBounds(new Rectangle(55, 111, 162, 47));
			emprestimosBut.setText("EMPRESTIMOS");
			emprestimosBut
					.addActionListener(new java.awt.event.ActionListener() {
						public void actionPerformed(java.awt.event.ActionEvent e) {
							@SuppressWarnings("unused")
							EmprestimoController emprestimoController = new EmprestimoController();
							BibliotecarioController bibliotecarioController = new BibliotecarioController();
							EmprestimoView emprestimoView = new EmprestimoView();
							LivroController livroController = new LivroController();
							UsuarioController usuarioController = new UsuarioController();

							try {
								bibliotecarioController
										.listarChoice(emprestimoView);
								livroController.listarList(emprestimoView);
								usuarioController.listarList(emprestimoView);
								
								emprestimoController.listar(emprestimoView);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

						}
					});
		}
		return emprestimosBut;
	}

} // @jve:decl-index=0:visual-constraint="10,10"
