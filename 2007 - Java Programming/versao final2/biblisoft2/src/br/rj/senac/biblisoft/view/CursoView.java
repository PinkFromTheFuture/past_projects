package br.rj.senac.biblisoft.view;

import java.awt.ComponentOrientation;
import java.awt.Rectangle;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.control.CursoController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DAOException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Curso;
import br.rj.senac.biblisoft.model.conexao.Conexao;
import br.rj.senac.biblisoft.model.table.CursoTableModel;

public class CursoView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JButton insertBut = null;
	private JButton deleteBut = null;
	private JTextField nomeField = null;
	private JTextField idField = null;
	private JButton updateBut = null;

	private JButton selectBut = null;
	private JScrollPane jScrollPane = null;
	private JTable jTable1 = null;
	private CursoTableModel cursoModel = new CursoTableModel(
			CursoTableModel.dados, CursoTableModel.colunas);
	private JLabel nomeLab = null;
	private JLabel idLab = null;
	private CursoController cursoController = new CursoController(); // @jve:decl-index=0:

	private JButton getInsertBut() {
		if (insertBut == null) {
			insertBut = new JButton();
			insertBut.setBounds(new Rectangle(17, 104, 118, 45));
			insertBut.setText("Inserir");
			insertBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Curso curso = new Curso();

					curso.setNome(getNomeField().getText());

					try {
						cursoController.inserirCurso(curso);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					Integer id = null;
					try {
						id = cursoController.getId(curso);

					} catch (DAOException e1) {

						e1.printStackTrace();
					}

					String[] linha = new String[] { "" + id, curso.getNome() };

					cursoModel.addRow(linha);
					Conexao.closeConn();
				}
			});

		}
		return insertBut;
	}

	private JButton getDeleteBut() {
		if (deleteBut == null) {
			deleteBut = new JButton();
			deleteBut.setBounds(new Rectangle(455, 92, 126, 51));
			deleteBut.setText("Deletar");
			deleteBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Curso curso = new Curso();

					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							curso.setId(id);
							try {
								cursoController.excluirCurso(curso);
							} catch (BusinessException e1) {

								e1.printStackTrace();
							} catch (DatabaseException e1) {

								e1.printStackTrace();
							}

							cursoModel.removeRow(x);

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
			nomeField.setBounds(new Rectangle(60, 7, 175, 31));
		}
		return nomeField;
	}

	public JTextField getIdField() {
		if (idField == null) {
			idField = new JTextField();
			idField.setBounds(new Rectangle(62, 46, 95, 42));

			idField.setEditable(false);
		}
		return idField;
	}

	private JButton getUpdateBut() {
		if (updateBut == null) {
			updateBut = new JButton();
			updateBut.setBounds(new Rectangle(13, 155, 114, 54));
			updateBut.setText("ALTERAR");
			updateBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Curso curso = new Curso();

					int id = Integer.parseInt(getIdField().getText());
					curso.setId(id);
					curso.setNome(getNomeField().getText());

					try {
						cursoController.alterarCurso(curso);
					} catch (BusinessException e1) {

						e1.printStackTrace();
					} catch (DatabaseException e1) {

						e1.printStackTrace();
					}

					int z = Integer.parseInt(getIdField().getText());
					curso.setId(z);
					String[] linha = new String[] { "" + curso.getId(),
							curso.getNome() };

					cursoModel.addRow(linha);

					int idd = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {
							String y = (String) jTable1.getValueAt(x, 0);
							idd = Integer.parseInt(y);
							curso.setId(idd);

							cursoModel.removeRow(x);
						}
					}
				}

			});
		}
		return updateBut;
	}

	private CursoView getThis() {
		return this;
	}

	private JButton getSelectBut() {
		if (selectBut == null) {
			selectBut = new JButton();
			selectBut.setBounds(new Rectangle(449, 36, 129, 36));
			selectBut.setText("Select");

			selectBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Curso curso = new Curso();

					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < jTable1.getRowCount(); x++) {
						oi = jTable1.isRowSelected(x);
						if (oi == true) {

							String y = (String) jTable1.getValueAt(x, 0);
							id = Integer.parseInt(y);
							curso.setId(id);
							try {
								cursoController.select(curso, getThis());
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
			jScrollPane.setBounds(new Rectangle(258, 21, 181, 239));
			jScrollPane.setViewportView(getJTable1());

		}
		return jScrollPane;
	}

	private JTable getJTable1() {
		if (jTable1 == null) {

			jTable1 = new JTable(cursoModel);
			jTable1.setName("AutoresTable");
			jTable1.setColumnSelectionAllowed(false);
			jTable1.setRowSelectionAllowed(true);
			jTable1.setShowGrid(true);
			jTable1.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			jTable1.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
			jTable1.setCellSelectionEnabled(true);
		}

		return jTable1;
	}

	public void select() {
		boolean oi;
		for (int x = 0; x < jTable1.getRowCount(); x++) {
			oi = jTable1.isRowSelected(x);
			if (oi == true) {

				System.out.println(jTable1.getValueAt(x, 0));

			}

		}
	}

	public CursoView() {
		super();
		initialize();
	}

	private void initialize() {
		this.setSize(624, 366);

		this.setContentPane(getJContentPane());
		this.setTitle("CursoView");
		this.setVisible(true);

	}

	private JPanel getJContentPane() {
		if (jContentPane == null) {

			idLab = new JLabel();
			idLab.setBounds(new Rectangle(17, 51, 33, 31));
			idLab.setText("ID:");
			nomeLab = new JLabel();
			nomeLab.setBounds(new Rectangle(8, 13, 52, 22));
			nomeLab.setText("NOME:");
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