package br.rj.senac.biblisoft.view;

import java.awt.ComponentOrientation;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Rectangle;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.control.AutorController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.table.AutorTableModel;

public class AutorView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton insertBut = null;
	private JButton deleteBut = null;
	private JTextField nomeField = null;
	private JTextField idField = null;
	private JButton updateBut = null;

	private JButton selectBut = null;
	private JScrollPane jScrollPane = null;
	private JTable jTable1 = null; // @jve:decl-index=0:visual-constraint="-211,288"
	private AutorTableModel autorModel = new AutorTableModel(
			AutorTableModel.dados, AutorTableModel.colunas);
	private JLabel nomeLab = null;
	private JLabel idLab = null;
	private AutorController autorController = new AutorController(); // @jve:decl-index=0:

	private JButton getInsertBut() {
		if (insertBut == null) {
			insertBut = new JButton();
			insertBut.setBounds(new Rectangle(258, 13, 116, 24));
			insertBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			insertBut.setText("CADASTRAR");
			insertBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {

					Autor autor = new Autor();

					autor.setNome(getNomeField().getText());

					try {
						autorController.inserirAutor(autor);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					try {
						autor.setId(autorController.getId(autor));

					} catch (DAOException e1) {

						e1.printStackTrace();
					}

					String[] linha = new String[] { "" + autor.getId(),
							autor.getNome() };

					autorModel.addRow(linha);

				}
			});

		}
		return insertBut;
	}

	private JButton getDeleteBut() {
		if (deleteBut == null) {
			deleteBut = new JButton();
			deleteBut.setBounds(new Rectangle(258, 159, 116, 24));
			deleteBut.setText("DELETAR");
			deleteBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			deleteBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Autor autor = new Autor();

					Integer id = null;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							autor.setId(id);
							try {
								autorController.excluirAutor(autor);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

							autorModel.removeRow(x);

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
			nomeField.setBounds(new Rectangle(60, 13, 175, 16));
			nomeField.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return nomeField;
	}

	public JTextField getIdField() {
		if (idField == null) {
			idField = new JTextField();
			idField.setBounds(new Rectangle(60, 34, 72, 16));
			idField.setEditable(false);
			idField.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return idField;
	}

	private JButton getUpdateBut() {
		if (updateBut == null) {
			updateBut = new JButton();
			updateBut.setBounds(new Rectangle(258, 52, 116, 24));
			updateBut.setText("ALTERAR");
			updateBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			updateBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Autor autor = new Autor();

					int id = Integer.parseInt(getIdField().getText());
					autor.setId(id);
					autor.setNome(getNomeField().getText());

					try {
						autorController.alterarAutor(autor);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					int z = Integer.parseInt(getIdField().getText());
					autor.setId(z);
					String[] linha = new String[] { "" + autor.getId(),
							autor.getNome() };

					autorModel.addRow(linha);

					int idd = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {
							String y = (String) jTable1.getValueAt(x, 0);
							idd = Integer.parseInt(y);
							autor.setId(idd);

							autorModel.removeRow(x);
						}
					}
				}

			});
		}
		return updateBut;
	}

	private AutorView getThis() {
		return this;
	}

	private JButton getSelectBut() {
		if (selectBut == null) {
			selectBut = new JButton();
			selectBut.setBounds(new Rectangle(258, 123, 116, 24));
			selectBut.setText("SELECIONAR");
			selectBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

			selectBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Autor autor = new Autor();

					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							autor.setId(id);
							try {
								autorController.select(autor, getThis());
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
			jScrollPane.setBounds(new Rectangle(25, 56, 216, 261));
			jScrollPane.setViewportView(getJTable1());

		}
		return jScrollPane;
	}

	private JTable getJTable1() {
		if (jTable1 == null) {

			jTable1 = new JTable(autorModel);
			jTable1.setName("AutoresTable");
			jTable1.setColumnSelectionAllowed(false);
			jTable1.setRowSelectionAllowed(true);
			jTable1.setShowGrid(true);
			jTable1.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			jTable1.setComponentOrientation(ComponentOrientation.UNKNOWN);
			jTable1.setSize(new Dimension(213, 8));
			jTable1.setCellSelectionEnabled(true);
			jTable1.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));

		}

		return jTable1;
	}

	public void select() {
		boolean oi;
		for (int x = 0; x < jTable1.getRowCount(); x++) {
			oi = jTable1.isRowSelected(x);
			if (oi == true) {

				// System.out.println(jTable1.getValueAt(x, 0));

			}

		}
	}

	public AutorView() {
		super();
		initialize();
	}

	private void initialize() {
		this.setSize(390, 366);

		this.setContentPane(getJContentPane());
		this.setTitle("AutorView");
		this.setVisible(true);
		this.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

	}

	private JPanel getJContentPane() {
		if (jContentPane == null) {

			idLab = new JLabel();
			idLab.setBounds(new Rectangle(31, 34, 21, 16));
			idLab.setText("ID:");
			idLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			nomeLab = new JLabel();
			nomeLab.setBounds(new Rectangle(8, 13, 44, 16));
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
		}
		return jContentPane;
	}

}