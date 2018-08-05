package br.rj.senac.biblisoft.view;

import java.awt.Rectangle;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import br.rj.senac.biblisoft.model.DAO.BibliotecarioDAO;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;
import br.rj.senac.biblisoft.model.DAO.UsuarioDAO;


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
			emprestimosBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					@SuppressWarnings("unused")
					BibliotecarioDAO bibliotecarioDAO = new BibliotecarioDAO();
					EmprestimoView emprestimoView = new EmprestimoView();
					LivroDAO livroDAO = new LivroDAO();
					livroDAO.listarList(emprestimoView);
					UsuarioDAO usuarioDAO = new UsuarioDAO();
					usuarioDAO.listarList(emprestimoView);
//					bibliotecarioDAO.listarChoice(emprestimoView);
				
				}
			});
		}
		return emprestimosBut;
	}

} // @jve:decl-index=0:visual-constraint="10,10"
