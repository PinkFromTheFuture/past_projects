package br.rj.senac.biblisoft.view;

import java.awt.Choice;
import java.awt.ComponentOrientation;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Rectangle;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.control.AutorLivroController;
import br.rj.senac.biblisoft.control.LivroController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.AutorLivro;
import br.rj.senac.biblisoft.model.Livro;
import br.rj.senac.biblisoft.model.table.AutorTableModel;
import br.rj.senac.biblisoft.model.table.LivroTableModel;

public class LivroView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton insertBut = null;
	private JButton deleteBut = null;
	private JTextField nomeField = null;
	private JTextField idField = null;
	private JButton updateBut = null;

	private JButton selectBut = null;
	private JScrollPane jScrollPane = null;
	private JTable jTable1 = null; // @jve:decl-index=0:visual-constraint="-205,264"
	private LivroTableModel livroModel = new LivroTableModel(
			LivroTableModel.dados, LivroTableModel.colunas);
	private JLabel nomeLab = null;
	private JLabel idLab = null;
	private JLabel isbnLab = null;
	private JTextField isbnField = null;
	private static Choice editora = null;
	private JLabel editoraLab = null;
	private JLabel autorLab = null;
	public static DefaultListModel listModel = new DefaultListModel();

	private JScrollPane jScrollPane2 = null;
	private static JList jList = null;
	private JLabel jLabel = null;
	AutorLivroController autorLivroController = new AutorLivroController(); // @jve:decl-index=0:
	private LivroController livroController = new LivroController(); // @jve:decl-index=0:
	private JScrollPane jScrollPane1 = null;
	private JTable autorTable = null;
	private AutorTableModel autorModel1 = null;

	private JButton getInsertBut() {
		if (insertBut == null) {
			insertBut = new JButton();
			insertBut.setBounds(new Rectangle(662, 36, 116, 24));
			insertBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			insertBut.setText("CADASTRAR");
			insertBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {

					Livro livro = new Livro();
					AutorLivro autorLivro = new AutorLivro();
					livro.setNomeEditora(getEditora().getSelectedItem());

					livro.setNome(getNomeField().getText());
					livro.setIsbn(getIsbnField().getText());

					Integer idEditora = null;

					try {
						idEditora = livroController.getEditoraId(livro);
					} catch (BusinessException e3) {

						e3.printStackTrace();
					} catch (DatabaseException e3) {

						e3.printStackTrace();
					}

					livro.setIdEditora(idEditora);

					try {
						livroController.inserirLivro(livro);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					try {
						livro.setId(livroController.getId(livro));
					} catch (BusinessException e3) {

						e3.printStackTrace();
					} catch (DatabaseException e3) {

						e3.printStackTrace();
					}

					String[] linha = new String[] { "" + livro.getId(),
							livro.getNome(), livro.getIsbn(),
							livro.getNomeEditora(), "Selecione para visualizar" };

					livroModel.addRow(linha);

					int i = -99999;
					int it;

					for (it = 0; it < autorTable.getRowCount(); it++) {
						boolean oi = false;
						oi = autorTable.isRowSelected(it);

						if (oi == true) {

							String y = (String) autorTable.getValueAt(it, 0);
							i = Integer.parseInt(y);

							Integer idLivro = null;

							try {
								idLivro = livroController.getId(livro);
							} catch (BusinessException e2) {

								e2.printStackTrace();
							} catch (DatabaseException e2) {

								e2.printStackTrace();
							}

							autorLivro.setIdLivro(idLivro);
							autorLivro.setIdAutor(i);
							try {
								autorLivroController.inserir(autorLivro);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

						}
					}

				}
			});

		}
		return insertBut;
	}

	private JButton getDeleteBut() {
		if (deleteBut == null) {
			deleteBut = new JButton();
			deleteBut.setBounds(new Rectangle(662, 267, 116, 24));
			deleteBut.setText("DELETAR");
			deleteBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			deleteBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					AutorLivro autorLivro = new AutorLivro();
					Livro livro = new Livro();

					Integer id = null;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							livro.setId(id);
							autorLivro.setIdLivro(id);
							try {
								autorLivroController.excluir(autorLivro);
								livroController.excluirLivro(livro);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

							livroModel.removeRow(x);

						}

					}
				}
			});
		}
		return deleteBut;
	}

	public JTextField getNomeField() {
		if (nomeField == null) {
			nomeField = new JTextField();
			nomeField.setBounds(new Rectangle(74, 17, 250, 22));
			nomeField.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return nomeField;
	}

	public JTextField getIdField() {
		if (idField == null) {
			idField = new JTextField();
			idField.setBounds(new Rectangle(74, 150, 72, 22));
			idField.setEditable(false);
			idField.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return idField;
	}

	private JButton getUpdateBut() {
		if (updateBut == null) {
			updateBut = new JButton();
			updateBut.setBounds(new Rectangle(662, 196, 116, 24));
			updateBut.setText("ALTERAR");
			updateBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			updateBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {

					Livro livro = new Livro();
					AutorLivro autorLivro = new AutorLivro();

					int setId = Integer.parseInt(getIdField().getText());
					String setIsbn = getIsbnField().getText();
					String setNome = getNomeField().getText();
					String setNomeEditora = getEditora().getSelectedItem();
					Integer setIdEditora = null;
					livro.setNomeEditora(setNomeEditora);

					try {
						setIdEditora = livroController.getEditoraId(livro);
					} catch (BusinessException e3) {

						e3.printStackTrace();
					} catch (DatabaseException e3) {

						e3.printStackTrace();
					}

					int ide = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {
							String y = (String) jTable1.getValueAt(x, 0);
							ide = Integer.parseInt(y);
							livro.setId(ide);

							livroModel.removeRow(x);
						}
					}

					livro.setId(setId);
					livro.setIsbn(setIsbn);
					livro.setNome(setNome);
					livro.setIdEditora(setIdEditora);
					livro.setNomeEditora(getEditora().getSelectedItem());

					String[] linha = new String[] { "" + livro.getId(),
							livro.getNome(), livro.getIsbn(),
							livro.getNomeEditora(), "selecione para visualizar" };

					try {
						livroController.alterarLivro(livro);
					} catch (BusinessException e2) {

						e2.printStackTrace();
					} catch (DatabaseException e2) {

						e2.printStackTrace();
					}
					livroModel.addRow(linha);

					autorLivro.setIdLivro(livro.getId());
					try {
						autorLivroController.excluir(autorLivro);
					} catch (BusinessException e2) {

						e2.printStackTrace();
					} catch (DatabaseException e2) {

						e2.printStackTrace();
					}

					int i = -99999;
					int it;

					for (it = 0; it < autorTable.getRowCount(); it++) {
						boolean bool = false;
						bool = autorTable.isRowSelected(it);

						if (bool == true) {

							String y = (String) autorTable.getValueAt(it, 0);
							i = Integer.parseInt(y);

							autorLivro.setIdLivro(livro.getId());
							autorLivro.setIdAutor(i);
							try {
								autorLivroController.inserir(autorLivro);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

						}
					}

					int id = Integer.parseInt(getIdField().getText());
					livro.setId(id);
					livro.setNome(getNomeField().getText());

					try {
						livroController.alterarLivro(livro);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					int z = Integer.parseInt(getIdField().getText());
					livro.setId(z);
					//
					// autorModel.addRow(linha);

				}

			});
		}
		return updateBut;
	}

	private LivroView getThis() {
		return this;
	}

	private JButton getSelectBut() {
		if (selectBut == null) {
			selectBut = new JButton();
			selectBut.setBounds(new Rectangle(662, 232, 116, 24));
			selectBut.setText("SELECIONAR");
			selectBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

			selectBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {

					Livro livro = new Livro();

					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							livro.setId(id);
							try {
								livroController.select(livro, getThis());
								autorLivroController.select(livro);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}
						}
					}
				}
			});
		}
		return selectBut;
	}

	private JScrollPane getJScrollPane() {
		if (jScrollPane == null) {
			jScrollPane = new JScrollPane();
			jScrollPane.setBounds(new Rectangle(25, 192, 628, 391));
			jScrollPane.setViewportView(getJTable1());

		}
		return jScrollPane;
	}

	private JTable getJTable1() {
		if (jTable1 == null) {

			jTable1 = new JTable(livroModel);
			jTable1.setName("AutoresTable");
			jTable1.setColumnSelectionAllowed(false);
			jTable1.setRowSelectionAllowed(true);
			jTable1.setShowGrid(true);
			jTable1.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			jTable1.setComponentOrientation(ComponentOrientation.UNKNOWN);
			jTable1.setSize(new Dimension(625, 62));
			jTable1.setCellSelectionEnabled(true);
			jTable1.setRowHeight(22);
			jTable1.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));

		}

		return jTable1;
	}

	public LivroView() {
		super();
		initialize();
	}

	private void initialize() {
		this.setSize(804, 618);

		this.setContentPane(getJContentPane());
		this.setTitle("LivroView");
		this.setVisible(true);
		this.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

	}

	private JPanel getJContentPane() {
		if (jContentPane == null) {

			jLabel = new JLabel();
			jLabel.setBounds(new Rectangle(663, 307, 104, 24));
			jLabel.setText("AUTORES");
			autorLab = new JLabel();
			autorLab.setBounds(new Rectangle(396, 9, 66, 22));
			autorLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			autorLab.setText("AUTORES:");
			editoraLab = new JLabel();
			editoraLab.setBounds(new Rectangle(22, 113, 69, 22));
			editoraLab.setText("EDITORA:");
			editoraLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			isbnLab = new JLabel();
			isbnLab.setBounds(new Rectangle(22, 67, 32, 22));
			isbnLab.setText("ISBN:");
			idLab = new JLabel();
			idLab.setBounds(new Rectangle(22, 150, 21, 22));
			idLab.setText("ID:");
			idLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			nomeLab = new JLabel();
			nomeLab.setBounds(new Rectangle(22, 17, 44, 22));
			nomeLab.setText("NOME:");
			nomeLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(getInsertBut(), null);
			jContentPane.add(getDeleteBut(), null);
			jContentPane.add(getNomeField(), null);
			jContentPane.add(getIdField(), null);
			jContentPane.add(getUpdateBut(), null);
			jContentPane.add(getSelectBut(), null);
			jContentPane.add(getJScrollPane(), null);
			jContentPane.add(nomeLab, null);
			jContentPane.add(idLab, null);
			jContentPane.add(isbnLab, null);
			jContentPane.add(getIsbnField(), null);
			jContentPane.add(getEditora(), null);
			jContentPane.add(editoraLab, null);
			jContentPane.add(autorLab, null);
			jContentPane.add(getJScrollPane2(), null);
			jContentPane.add(jLabel, null);
			jContentPane.add(getJScrollPane1(), null);
		}
		return jContentPane;
	}

	public JTextField getIsbnField() {
		if (isbnField == null) {
			isbnField = new JTextField();
			isbnField.setBounds(new Rectangle(74, 67, 171, 22));
		}
		return isbnField;
	}

	public static Choice getEditora() {
		if (editora == null) {
			editora = new Choice();

			editora.setBounds(new Rectangle(101, 113, 143, 22));

		}
		return editora;
	}

	private JScrollPane getJScrollPane2() {
		if (jScrollPane2 == null) {
			jScrollPane2 = new JScrollPane();
			jScrollPane2.setBounds(new Rectangle(668, 334, 111, 246));
			jScrollPane2.setViewportView(getJList());
		}
		return jScrollPane2;
	}

	public static JList getJList() {
		if (jList == null) {
			jList = new JList();

			jList.setModel(listModel);

		}
		return jList;
	}

	private JScrollPane getJScrollPane1() {
		if (jScrollPane1 == null) {
			jScrollPane1 = new JScrollPane();
			jScrollPane1.setBounds(new Rectangle(400, 37, 251, 145));
			jScrollPane1.setViewportView(getAutorTable());
		}
		return jScrollPane1;
	}

	private AutorTableModel getAutorModel1() {
		if (autorModel1 == null) {
			autorModel1 = new AutorTableModel(AutorTableModel.dados,
					AutorTableModel.colunas);
		}
		return autorModel1;
	}

	private JTable getAutorTable() {
		if (autorTable == null) {
			autorTable = new JTable(getAutorModel1());
			autorTable.setComponentOrientation(ComponentOrientation.UNKNOWN);
			autorTable.setName("AutoresTable");
			autorTable.setCellSelectionEnabled(true);
			autorTable.setColumnSelectionAllowed(false);
			autorTable.setRowSelectionAllowed(true);
			autorTable
					.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
			autorTable.setShowGrid(true);
			autorTable.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return autorTable;
	}

}
