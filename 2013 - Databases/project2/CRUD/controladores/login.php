<?php
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
	  //echo "<h2>Bem vindo, ". $idUser.".</h2>";
	} else {
	
	//header("location: /index.php/component/users/?view=registration");  //isso está redirecionando só o iframe. não serve
		echo ("Por favor autentique-se.<br />");
		
		
		
		
		//<meta HTTP-EQUIV="REFRESH" CONTENT="0; URL=javascript:window.open('/index.php/component/users/?view=registration','_top');"> //isso não está funcionando em todos os browsers
		
?>
		<body onload="parent.location.href='/index.php/component/users/?view=registration'"></body>

		
		<form name="form1" method="post" action="/index.php/component/users/?view=registration" target="_top">
		
		<input type="submit" class="large button blue" name="submit" id="submit" value="Clique aqui se não for redirecionado automaticamente">
		
		</form>

<?php	





exit;
die;	
	}

		



?>









