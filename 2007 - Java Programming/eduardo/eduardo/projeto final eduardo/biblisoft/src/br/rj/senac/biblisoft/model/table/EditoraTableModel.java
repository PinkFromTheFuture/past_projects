package br.rj.senac.biblisoft.model.table;

import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.table.AbstractTableModel;

public class EditoraTableModel extends AbstractTableModel {

	private static final long serialVersionUID = 1L;

	private ArrayList<String[]> linhas = null;

	public static ArrayList<String[]> dados = new ArrayList<String[]>();
	public static String[] colunas = { "ID", "NOME" };

	public EditoraTableModel(ArrayList<String[]> dados, String[] colunas) {
		setLinhas(dados);
		setColunas(colunas);
	}

	public String[] getColunas() {
		return colunas;
	}

	public ArrayList<String[]> getLinhas() {

		return linhas;
	}

	public void setColunas(String[] strings) {
		colunas = strings;
	}

	public void setLinhas(ArrayList<String[]> list) {
		linhas = list;
	}

	public int getColumnCount() {
		return getColunas().length;
	}

	public int getRowCount() {
		return getLinhas().size();
	}

	public Object getValueAt(int rowIndex, int columnIndex) {

		String[] linha = (String[]) getLinhas().get(rowIndex);

		return linha[columnIndex];
	}

	public void addRow(String[] dadosLinha) {

		getLinhas().add(dadosLinha);

		int linha = getLinhas().size() - 1;
		fireTableRowsInserted(linha, linha);

		return;
	}

	public void updateRow(String[] dadosLinha) {
		getLinhas().add(dadosLinha);

		fireTableDataChanged();
		return;
	}

	public boolean removeRow(int row) {

		Iterator<?> i = getLinhas().iterator();
		int linha = 0;

		while (i.hasNext()) {

			linha++;

			getLinhas().remove(row);

			fireTableRowsDeleted(row, row);
			return true;

		}

		return false;
	}

	public String getColumnName(int col) {
		return getColunas()[col];
	}
}