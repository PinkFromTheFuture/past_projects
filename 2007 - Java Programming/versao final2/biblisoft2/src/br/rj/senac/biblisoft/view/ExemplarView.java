package br.rj.senac.biblisoft.view;

import java.awt.Choice;
import java.awt.ComponentOrientation;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Rectangle;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.model.Autor;
import br.rj.senac.biblisoft.model.Exemplar;
import br.rj.senac.biblisoft.model.DAO.AutorDAO;
import br.rj.senac.biblisoft.model.DAO.ExemplarDAO;
import br.rj.senac.biblisoft.model.DAO.LivroDAO;
import br.rj.senac.biblisoft.model.table.ExemplarTableModel;






public class ExemplarView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton insertBut = null;
	private JButton deleteBut = null;
	private JTextField idField = null;
	private JButton updateBut = null;

	private JButton selectBut = null;
	private JScrollPane jScrollPane = null;
	private JTable jTable1 = null; // @jve:decl-index=0:visual-constraint="-195,272"
	private ExemplarTableModel exemplarModel = new ExemplarTableModel(
			ExemplarTableModel.dados, ExemplarTableModel.colunas);
	private JLabel idLab = null;
	private JLabel livroLab = null;
	private JLabel numeroLab = null;
	private JTextField numeroField = null;
	public static DefaultListModel listModel = new DefaultListModel();
	private static Choice livroChoice = null;

	private JButton getInsertBut() {
		if (insertBut == null) {
			insertBut = new JButton();
			insertBut.setBounds(new Rectangle(377, 13, 116, 24));
			insertBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			insertBut.setText("CADASTRAR");
			insertBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Exemplar exemplar = new Exemplar();
					ExemplarDAO exemplarDAO = new ExemplarDAO();
					LivroDAO livroDAO = new LivroDAO();

					exemplar.setNumex(Integer.parseInt(getNumeroField()
							.getText()));
					exemplar.setIdLivro(livroDAO.getIdLivro(getLivroChoice()
							.getSelectedItem()));
					exemplar.setLivroNome(getLivroChoice().getSelectedItem());

					exemplarDAO.incluir(exemplar);
					String[] linha = new String[] {
							exemplarDAO.selectId(exemplar),
							exemplar.getLivroNome(), "" + exemplar.getNumex() };

					exemplarModel.addRow(linha);

				}
			});

		}
		return insertBut;
	}

	private JButton getDeleteBut() {
		if (deleteBut == null) {
			deleteBut = new JButton();
			deleteBut.setBounds(new Rectangle(377, 205, 116, 24));
			deleteBut.setText("DELETAR");
			deleteBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			deleteBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Exemplar exemplar = new Exemplar();
					ExemplarDAO dao = new ExemplarDAO();
					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							exemplar.setId(id);
							dao.delete(exemplar);

							exemplarModel.removeRow(x);
						}

					}
				}
			});
		}
		return deleteBut;
	}

	public JTextField getIdField() {
		if (idField == null) {
			idField = new JTextField();
			idField.setBounds(new Rectangle(61, 35, 72, 16));
			idField.setEditable(false);
			idField.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		}
		return idField;
	}

	private JButton getUpdateBut() {
		if (updateBut == null) {
			updateBut = new JButton();
			updateBut.setBounds(new Rectangle(377, 130, 116, 24));
			updateBut.setText("ALTERAR");
			updateBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

			updateBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Exemplar exemplar = new Exemplar();
					ExemplarDAO dao = new ExemplarDAO();
					int id = Integer.parseInt(getIdField().getText());
					exemplar.setId(id);
					exemplar.setIdLivro(Integer.parseInt(getNumeroField().getText()));
					exemplar.setLivroNome(getLivroChoice().getSelectedItem());
					exemplar.setNumex(Integer.parseInt(getNumeroField().getText()));
//					System.out.println(getNumeroField().getText());
//					System.out.println(exemplar.getNumex());
					dao.update(exemplar);
//					exemplar.setNome(getNomeField().getText());

					

					int z = Integer.parseInt(getIdField().getText());
					exemplar.setId(z);
					String[] linha = new String[] { "" + exemplar.getId(),
							exemplar.getLivroNome(), ""+exemplar.getNumex() };

					exemplarModel.addRow(linha);

					int idd = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {
							String y = (String) jTable1.getValueAt(x, 0);
							idd = Integer.parseInt(y);
							exemplar.setId(idd);
							
							exemplarModel.removeRow(x);
						}
					}
				}

			});
		}
		return updateBut;
	}

	private JButton getSelectBut() {
		if (selectBut == null) {
			selectBut = new JButton();
			selectBut.setBounds(new Rectangle(377, 169, 116, 24));
			selectBut.setText("SELECIONAR");
			selectBut.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

			selectBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Exemplar exemplar = new Exemplar();
					ExemplarDAO exemplarDAO = new ExemplarDAO();
					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							exemplar.setId(id);
							exemplarDAO.select(exemplar, getThis());
						}
					}
				}
			});
		}
		return selectBut;
	}

	private ExemplarView getThis(){
		return this;
	}
	private JScrollPane getJScrollPane() {
		if (jScrollPane == null) {
			jScrollPane = new JScrollPane();
			jScrollPane.setBounds(new Rectangle(37, 131, 306, 261));
			jScrollPane.setViewportView(getJTable1());

		}
		return jScrollPane;
	}

	private JTable getJTable1() {
		if (jTable1 == null) {

			jTable1 = new JTable(exemplarModel);
			jTable1.setName("ExemplaresTable");
			jTable1.setColumnSelectionAllowed(false);
			jTable1.setRowSelectionAllowed(true);
			jTable1.setShowGrid(true);
			jTable1.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			jTable1.setComponentOrientation(ComponentOrientation.UNKNOWN);
			jTable1.setSize(new Dimension(208, 8));
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

	public ExemplarView() {
		super();
		initialize();
	}

	private void initialize() {
		this.setSize(791, 431);

		this.setContentPane(getJContentPane());
		this.setTitle("ExemplarView");
		this.setVisible(true);
		this.setFont(new Font("Comic Sans MS", Font.BOLD, 12));

	}

	private JPanel getJContentPane() {
		if (jContentPane == null) {

			numeroLab = new JLabel();
			numeroLab.setBounds(new Rectangle(29, 66, 19, 17));
			numeroLab.setText("#:");
			livroLab = new JLabel();
			livroLab.setBounds(new Rectangle(16, 90, 42, 21));
			livroLab.setText("LIVRO:");
			idLab = new JLabel();
			idLab.setBounds(new Rectangle(30, 37, 21, 16));
			idLab.setText("ID:");
			idLab.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(getInsertBut(), null);
			jContentPane.add(getDeleteBut(), null);
			jContentPane.add(getIdField(), null);
			jContentPane.add(getUpdateBut(), null);
			jContentPane.add(getSelectBut(), null);
			jContentPane.add(getJScrollPane(), null);
			jContentPane.add(idLab, null);
			jContentPane.add(livroLab, null);
			jContentPane.add(numeroLab, null);
			jContentPane.add(getNumeroField(), null);
			jContentPane.add(getLivroChoice(), null);
		}
		return jContentPane;
	}


	public JTextField getNumeroField() {
		if (numeroField == null) {
			numeroField = new JTextField();
			numeroField.setBounds(new Rectangle(63, 66, 68, 16));
		}
		return numeroField;
	}

	/**
	 * This method initializes livroChoice
	 * 
	 * @return java.awt.Choice
	 */
	public static Choice getLivroChoice() {
		if (livroChoice == null) {
			livroChoice = new Choice();
			livroChoice.setBounds(new Rectangle(71, 94, 159, 19));
		}
		return livroChoice;
	}

} // @jve:decl-index=0:visual-constraint="13,10"
