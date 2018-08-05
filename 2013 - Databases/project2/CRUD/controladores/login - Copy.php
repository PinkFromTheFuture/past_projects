<?php
	define( '_JEXEC', 1 );
	define( 'DS', DIRECTORY_SEPARATOR );
	define('JPATH_BASE', dirname(__FILE__).DS."..".DS.".." ); //alterar o numero de ".." aqui caso mude de diretorio

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
	  echo "<h2>Bem vindo, ". $user->name."</h2>";
	} else {
		echo ("Por favor autentique-se.<br />");
		
?>
<!--<form id='login' action='login2.php' method='post' accept-charset='UTF-8'>-->
<table width="100%">
	<td>
		<form id="form1" name="form1" method="post" action="./controladores/login2.php">
		<fieldset>
										<div class="login-fields">
										  <label id="username-lbl" for="username" class="">email</label>
										  <input type="text" name="username" id="username" value="" class="validate-username" size="25">
										</div>
										<div class="login-fields">
										  <label id="password-lbl" for="password" class="">Senha</label>
										  <input type="password" name="password" id="password" value="" class="validate-password" size="25">
										</div>
										<div class="login-fields">
										  <label id="remember-lbl" for="remember">Lembrar-me</label>
										  <input id="remember" type="checkbox" name="remember" class="inputbox" value="yes" alt="Lembrar-me">
										</div>
										  <button type="submit" class="button art-button">Entrar</button>
										<li>
										<a target="_top" href="/index.php/component/users/?view=reset">Esqueceu sua senha?</a>
										</li>
		</fieldset>
		</form>
	</td>
	<td>
		<iframe src="/index.php/component/users/?view=registration"></iframe>
	</td>
</table>

		
<?php	






die;	
	}

		



?>









