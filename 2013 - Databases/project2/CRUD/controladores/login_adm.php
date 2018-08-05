<?php
/*	define( '_JEXEC', 1 );
	define( 'DS', DIRECTORY_SEPARATOR );
	define('JPATH_BASE', dirname(__FILE__).DS."..".DS.".." ); //alterar o numero de ".." aqui caso mude de diretorio
*/
	require_once ( JPATH_BASE.DS.'includes'.DS.'defines.php' );
	require_once ( JPATH_BASE.DS.'includes'.DS.'framework.php' );

	@$mainframe =& JFactory::getApplication('site');
	$mainframe->initialise();

	@$user =& JFactory::getUser();
	if (!$user->guest) {
	 // echo 'Autenticação::<br />';
	  //echo 'usuário: ' . $user->username . '<br />';
	  //echo 'nome: ' . $user->name . '<br />';
	  //echo 'User ID  : ' . $user->id . '<br />';
	  $idUser = $user->id;
	} else {
		echo ("Por favor autentique-se.<br />");
		die;	
	}
	
	//$groups = $user->get('groups'); 
	$tipo= $user->groups;


	if(@$tipo[8] != 8){
		echo "<h2>Desculpe, área reservada apenas para o administrador do sistema.</h2>";
		die;
	}else{
		//echo "<h2>Bem vindo, ". $user->name."</h2>";
	}
	

?>