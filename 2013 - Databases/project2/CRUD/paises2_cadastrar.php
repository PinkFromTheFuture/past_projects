<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");

$nome = $_GET['nome'];



$link = dbconnect(); // faz conexao com o banco de dados

	$query =  "INSERT INTO `taekwondo`.`pais` (`idpais`, `nome_pais`) VALUES (NULL, '$nome')";
	
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query);
	
	if (!$result) {
		((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
		die('Invalid query:'.$query .'<br />'. ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	else{
		
		echo '<h2>Pais cadastrada com sucesso.</h2>';

	}

	echo '<br /><br /><a class="large button blue" href="javascript:history.go(-2)">Clique aqui para voltar</a>';
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
?>
