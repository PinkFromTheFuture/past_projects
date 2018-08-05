<?php 
ini_set('display_errors',1);
error_reporting(E_ALL);
	function dbconnect(){
		//header('Content-Type: text/html; charset=utf-8');
		ini_set('display_errors',1);
		error_reporting(E_ALL);
		//faz a conexão com o banco:
		$db_host = "localhost";
		$db_username = "taekwondouser";
		$db_pw = "taekwondopw";
		$db_name = "taekwondo";
		$link = ($GLOBALS["___mysqli_ston"] = mysqli_connect("$db_host", "$db_username", "$db_pw")) or die ("Não foi possível conectar ao MySQL !!");
		((bool)mysqli_query($GLOBALS["___mysqli_ston"], "USE $db_name")) or die ("Banco de dados inexistente.");
		mysqli_query($GLOBALS["___mysqli_ston"], "SET NAMES 'utf8'");
		mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_connection=utf8');
		mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_client=utf8');
		mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_results=utf8');
		//echo "Conexão com o banco de dados estabelecida";
		return $link;
	}
?>