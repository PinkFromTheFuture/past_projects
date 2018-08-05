package br.rj.senac.biblisoft.view;

import java.awt.ComponentOrientation;
import java.awt.Font;
import java.awt.Rectangle;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;

import br.rj.senac.biblisoft.control.EmprestimoController;
import br.rj.senac.biblisoft.exception.BusinessException;
import br.rj.senac.biblisoft.exception.DatabaseException;
import br.rj.senac.biblisoft.model.Emprestimo;
import br.rj.senac.biblisoft.model.table.EmprestimoTableModel;

public class DevolucaoView extends EntityModelView {

	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	public static DefaultListModel livroModel = new DefaultListModel();
	public static DefaultListModel usuarioModel = new DefaultListModel();
	private JLabel dataLab = null;
	private JScrollPane jScrollPane2 = null;
	private JTable emprestimoTable = null;
	private EmprestimoTableModel emprestimoModel = null;
	private EmprestimoController emprestimoController = new EmprestimoController(); // @jve:decl-index=0:
	private JButton devolverBut = null;

	/**
	 * This is the default constructor
	 */
	public DevolucaoView() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(668, 421);
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
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(dataLab, null);
			jContentPane.add(getJScrollPane2(), null);
			jContentPane.add(getDevolverBut(), null);
		}
		return jContentPane;
	}

	private JScrollPane getJScrollPane2() {
		if (jScrollPane2 == null) {
			jScrollPane2 = new JScrollPane();
			jScrollPane2.setBounds(new Rectangle(14, 42, 639, 338));
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

	/**
	 * This method initializes devolverBut
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getDevolverBut() {
		if (devolverBut == null) {
			devolverBut = new JButton();
			devolverBut.setBounds(new Rectangle(470, 8, 149, 27));
			devolverBut.setText("DEVOLVER!");
			devolverBut.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					Emprestimo emprestimo = new Emprestimo();
					java.util.Date data = new java.util.Date();
					Calendar cal = Calendar.getInstance();
					cal.setTime(data);
					emprestimo.setDataDevolucao(cal.getTime());

					int id = -99999;
					int x;
					boolean oi;
					for (x = 0; x < emprestimoTable.getRowCount(); x++) {
						oi = emprestimoTable.isRowSelected(x);
						if (oi == true) {

							String y = (String) emprestimoTable
									.getValueAt(x, 0);
							id = Integer.parseInt(y);
							emprestimo.setId(id);
							try {
								emprestimoController.devolver(emprestimo);
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
		return devolverBut;
	}

}
