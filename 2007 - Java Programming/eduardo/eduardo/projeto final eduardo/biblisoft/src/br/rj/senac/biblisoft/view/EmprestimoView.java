package br.rj.senac.biblisoft.view;

import java.awt.Choice;
import java.awt.ComponentOrientation;
import java.awt.Font;
import java.awt.Rectangle;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.control.BibliotecarioController;
import br.rj.senac.biblisoft.control.EmprestimoController;
import br.rj.senac.biblisoft.control.ExemplarController;
import br.rj.senac.biblisoft.control.LivroController;
import br.rj.senac.biblisoft.control.UsuarioController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Bibliotecario;
import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.Usuario;
import br.rj.senac.biblisoft.model.DAO.ExemplarDAO;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;
import br.rj.senac.biblisoft.model.table.EmprestimoTableModel;

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
	private JLabel dataLab = null;
	private JScrollPane jScrollPane2 = null;
	private JTable emprestimoTable = null;
	private EmprestimoTableModel emprestimoModel = null;
	private EmprestimoController emprestimoController = new EmprestimoController(); // @jve:decl-index=0:

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
		this.setSize(671, 702);
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
			dataLab.setBounds(new Rectangle(27, 8, 179, 23));
			java.util.Date data = new java.util.Date();

			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

			String s = sdf.format(data);

			dataLab.setText("Hoje é dia: " + s);
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
			usuarioLab.setBounds(new Rectangle(28, 35, 52, 27));
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
			jContentPane.add(dataLab, null);
			jContentPane.add(getJScrollPane2(), null);
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
			jScrollPane.setBounds(new Rectangle(29, 64, 222, 273));
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
			bibliotecarioChoice.setBounds(new Rectangle(373, 31, 122, 21));
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

							try {
								livro.setId(livroDAO.getIdLivro(y));
							} catch (DAOException e1) {

								e1.printStackTrace();
							}

							try {
								exemplarDAO.listarChoice(getThis(), livro);
							} catch (DAOException e1) {
								// TODO Auto-generated catch block
								e1.printStackTrace();
							}

						}
					}

				}
			});
		}
		return okBut;
	}

	private EmprestimoView getThis() {
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
			emprestarBut.setBounds(new Rectangle(508, 30, 132, 37));
			emprestarBut.setText("EMPRESTAR!");
			emprestarBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Emprestimo emprestimo = new Emprestimo();

					java.util.Date data = new java.util.Date();
					Calendar cal = Calendar.getInstance();
					cal.setTime(data);
					cal.add(Calendar.DAY_OF_MONTH, 14);

					emprestimo.setDataEntrega(cal.getTime());

					SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

					String s = sdf.format(cal.getTime());

					Bibliotecario bibliotecario = new Bibliotecario();
					BibliotecarioController bibliotecarioController = new BibliotecarioController();
					bibliotecario.setNome(getBibliotecarioChoice()
							.getSelectedItem());
					Integer bibliotecarioId = null;
					try {
						bibliotecarioId = bibliotecarioController
								.getId(bibliotecario);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					bibliotecario.setId(bibliotecarioId);
					emprestimo.setIdBibliotecario(bibliotecario.getId());

					Usuario usuario = new Usuario();
					UsuarioController usuarioController = new UsuarioController();

					int x;
					boolean oi;
					for (x = 0; x < usuarioModel.size(); x++) {
						oi = usuarioList.isSelectedIndex(x);
						if (oi == true) {

							String y = (String) usuarioModel.getElementAt(x);
							usuario.setNome(y);

						}
					}
					try {
						usuario.setId(usuarioController.getId(usuario));
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}
					emprestimo.setIdUsuario(usuario.getId());

					Livro livro = new Livro();
					Exemplar exemplar = new Exemplar();
					LivroController livroController = new LivroController();
					ExemplarController exemplarController = new ExemplarController();

					int it;
					boolean bool;
					for (it = 0; it < livroModel.getSize(); it++) {
						bool = getLivroList().isSelectedIndex(it);
						if (bool == true) {

							String y = (String) livroModel.getElementAt(it);
							livro.setNome(y);

							try {
								livro.setId(livroController.getId(livro));
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}
						}
					}
					exemplar.setIdLivro(livro.getId());
					exemplar.setLivroNome(livro.getNome());
					exemplar.setNumex(Integer.parseInt(getExemplarChoice()
							.getSelectedItem()));

					try {
						exemplar.setId(exemplarController.getId(exemplar));
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}
					emprestimo.setIdExemplar(exemplar.getId());

					try {
						
						emprestimoController.inserirEmprestimo(emprestimo);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					String[] linha = new String[] { "atualize para ver",
							"" + emprestimo.getIdExemplar(), usuario.getNome(),
							bibliotecario.getNome(), "" + s, "null" };

					emprestimoModel.addRow(linha);

				}
			});

		}
		return emprestarBut;
	}

	/**
	 * This method initializes jScrollPane2
	 * 
	 * @return javax.swing.JScrollPane
	 */
	private JScrollPane getJScrollPane2() {
		if (jScrollPane2 == null) {
			jScrollPane2 = new JScrollPane();
			jScrollPane2.setBounds(new Rectangle(14, 354, 639, 319));
			jScrollPane2.setViewportView(getEmprestimoTable());
		}
		return jScrollPane2;
	}

	/**
	 * This method initializes emprestimoModel
	 * 
	 * @return br.rj.senac.biblisoft.model.table.AutorTableModel
	 */
	private EmprestimoTableModel getEmprestimoModel() {
		if (emprestimoModel == null) {
			emprestimoModel = new EmprestimoTableModel(
					EmprestimoTableModel.dados, EmprestimoTableModel.colunas);
		}
		return emprestimoModel;
	}

	/**
	 * This method initializes emprestimoTable
	 * 
	 * @return javax.swing.JTable
	 */
	private JTable getEmprestimoTable() {
		if (emprestimoTable == null) {
			emprestimoTable = new JTable(getEmprestimoModel());
			emprestimoTable
					.setComponentOrientation(ComponentOrientation.UNKNOWN);
			emprestimoTable.setName("AutoresTable");
			emprestimoTable.setCellSelectionEnabled(true);
			emprestimoTable.setColumnSelectionAllowed(false);
			emprestimoTable.setRowSelectionAllowed(true);
			emprestimoTable
					.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			emprestimoTable.setShowGrid(true);
			emprestimoTable.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return emprestimoTable;
	}

} // @jve:decl-index=0:visual-constraint="10,10"
