package br.rj.senac.biblisoft.view;

import java.awt.BorderLayout;

import javax.swing.DefaultListModel;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.Dimension;
import javax.swing.JLabel;
import java.awt.Rectangle;
import javax.swing.JScrollPane;
import javax.swing.JList;
import java.awt.Choice;
import java.util.Calendar;

import javax.swing.JTextField;
import javax.swing.JButton;

import sun.security.jca.GetInstance;
import sun.text.normalizer.Trie.DataManipulate;

import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.DAO.ExemplarDAO;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;





public class EmprestimoView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JLabel usuarioLab = null;
	private JScrollPane jScrollPane = null;
	private JList usuarioList = null;
	private JLabel bibliotecarioLab = null;
	public static Choice bibliotecarioChoice = null;
	private JLabel livroLab = null;
	private JScrollPane jScrollPane1 = null;
	private JList livroList = null;
	
	public static DefaultListModel livroModel = new DefaultListModel();
	public static DefaultListModel usuarioModel = new DefaultListModel();
	private JButton okBut = null;
	private static Choice exemplarChoice = null;
	private JLabel exemplarLab = null;
	private JButton emprestarBut = null;
	private JButton cancelarBut = null;
	private JLabel dataLab = null;

	/**
	 * This is the default constructor
	 */
	public EmprestimoView() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(921, 383);
		this.setContentPane(getJContentPane());
		this.setTitle("EmprestimosView");
		this.setVisible(true);
		
	}

	/**
	 * This method initializes jContentPane
	 * 
	 * @return javax.swing.JPanel
	 */
	private JPanel getJContentPane() {
		if (jContentPane == null) {
			dataLab = new JLabel();
			dataLab.setBounds(new Rectangle(581, 23, 179, 23));
			java.util.Date data = new java.util.Date();
			String a = data.toGMTString();
			
			
			dataLab.setText("Hoje é dia: " + a);
			exemplarLab = new JLabel();
			exemplarLab.setBounds(new Rectangle(284, 79, 209, 20));
			exemplarLab.setText("e selecione um exemplar disponivel");
			livroLab = new JLabel();
			livroLab.setBounds(new Rectangle(284, 52, 181, 23));
			livroLab.setText("Selecione um livro, clique OK");
			bibliotecarioLab = new JLabel();
			bibliotecarioLab.setBounds(new Rectangle(287, 27, 76, 24));
			bibliotecarioLab.setText("Bibliotecario:");
			usuarioLab = new JLabel();
			usuarioLab.setBounds(new Rectangle(28, 21, 52, 27));
			usuarioLab.setText("Usuario:");
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(usuarioLab, null);
			jContentPane.add(getJScrollPane(), null);
			jContentPane.add(bibliotecarioLab, null);
			jContentPane.add(getBibliotecarioChoice(), null);
			jContentPane.add(livroLab, null);
			jContentPane.add(getJScrollPane1(), null);
			jContentPane.add(getOkBut(), null);
			jContentPane.add(getExemplarChoice(), null);
			jContentPane.add(exemplarLab, null);
			jContentPane.add(getEmprestarBut(), null);
			jContentPane.add(getCancelarBut(), null);
			jContentPane.add(dataLab, null);
		}
		return jContentPane;
	}

	/**
	 * This method initializes jScrollPane	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getJScrollPane() {
		if (jScrollPane == null) {
			jScrollPane = new JScrollPane();
			jScrollPane.setBounds(new Rectangle(29, 62, 222, 191));
			jScrollPane.setViewportView(getUsuarioList());
		}
		return jScrollPane;
	}

	/**
	 * This method initializes usuarioList	
	 * 	
	 * @return javax.swing.JList	
	 */
	private JList getUsuarioList() {
		if (usuarioList == null) {
			usuarioList = new JList();
			usuarioList.setModel(usuarioModel);
		}
		return usuarioList;
	}

	/**
	 * This method initializes bibliotecarioChoice	
	 * 	
	 * @return java.awt.Choice	
	 */
	public static Choice getBibliotecarioChoice() {
		if (bibliotecarioChoice == null) {
			bibliotecarioChoice = new Choice();
			bibliotecarioChoice.setBounds(new Rectangle(373, 31, 146, 20));
		}
		return bibliotecarioChoice;
	}

	/**
	 * This method initializes jScrollPane1	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getJScrollPane1() {
		if (jScrollPane1 == null) {
			jScrollPane1 = new JScrollPane();
			jScrollPane1.setBounds(new Rectangle(285, 102, 209, 202));
			jScrollPane1.setViewportView(getLivroList());
		}
		return jScrollPane1;
	}

	/**
	 * This method initializes livroList	
	 * 	
	 * @return javax.swing.JList	
	 */
	private JList getLivroList() {
		if (livroList == null) {
			livroList = new JList();
			livroList.setModel(livroModel);
		}
		return livroList;
	}

	/**
	 * This method initializes okBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getOkBut() {
		if (okBut == null) {
			okBut = new JButton();
			okBut.setBounds(new Rectangle(285, 307, 61, 31));
			okBut.setText("OK");
			okBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					LivroDAO livroDAO = new LivroDAO();
					Livro livro = new Livro();
					ExemplarDAO exemplarDAO = new ExemplarDAO();
					
					int x;
					boolean oi;
					for (x = 0; x < livroModel.getSize(); x++) {
						oi = getLivroList().isSelectedIndex(x);
						if (oi == true) {

							String y = (String) livroModel.getElementAt(x);
							livro.setNome(y);
							
							livro.setId(livroDAO.getIdLivro(y));
							
							exemplarDAO.listarChoice(getThis(), livro);
							
							
							
						}
					}
					
				}
			});
		}
		return okBut;
	}
	private EmprestimoView getThis(){
		return this;
	}
	/**
	 * This method initializes exemplarChoice	
	 * 	
	 * @return java.awt.Choice	
	 */
	public static Choice getExemplarChoice() {
		if (exemplarChoice == null) {
			exemplarChoice = new Choice();
			exemplarChoice.setBounds(new Rectangle(349, 307, 144, 30));
		}
		return exemplarChoice;
	}

	/**
	 * This method initializes emprestarBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getEmprestarBut() {
		if (emprestarBut == null) {
			emprestarBut = new JButton();
			emprestarBut.setBounds(new Rectangle(618, 306, 132, 37));
			emprestarBut.setText("EMPRESTAR!");
			emprestarBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Emprestimo emprestimo = new Emprestimo();
					
				}
			});
		}
		return emprestarBut;
	}

	/**
	 * This method initializes cancelarBut	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getCancelarBut() {
		if (cancelarBut == null) {
			cancelarBut = new JButton();
			cancelarBut.setBounds(new Rectangle(757, 307, 131, 34));
			cancelarBut.setText("CANCELAR!");
		}
		return cancelarBut;
	}

}  //  @jve:decl-index=0:visual-constraint="10,10"
