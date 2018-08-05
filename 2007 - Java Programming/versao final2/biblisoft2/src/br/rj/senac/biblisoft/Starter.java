package br.rj.senac.biblisoft;

import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import br.rj.senac.biblisoft.view.LoginView;



public class Starter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		 try {
			  UIManager.setLookAndFeel(
			            UIManager.getSystemLookAndFeelClassName());
		    } 
		    catch (UnsupportedLookAndFeelException e) {
		      System.out.println("look and feel não suportado");
		    }
		    catch (ClassNotFoundException e) {
		       System.out.println("classe de look and feel não encontrada");
		    }
		    catch (InstantiationException e) {
		       System.out.println("erro ao iniciar o look and feel");
		    }
		    catch (IllegalAccessException e) {
		     System.out.println("access denied :)");
		    }
		@SuppressWarnings("unused")
		LoginView login = new LoginView();
		

	}

}
