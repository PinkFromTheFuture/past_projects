﻿<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>

<form id="form1" name="form1" method="get" action="cidades2_cadastrar.php">
  <p>
    <label for="nome">Nome:</label>
    <input type="text" name="nome" id="nome" />
  </p>
  
  <label for="pais"></label>
    <select name="pais" size="10" id="pais">
	
	
   <?php $link = dbconnect(); // faz conexao com o banco de dados

	$query =  "SELECT * FROM pais ORDER BY nome_pais";
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	while($get_categoria = mysqli_fetch_assoc($result)){
		$pais_nome = $get_categoria['nome_pais']; 
		$pais_id = $get_categoria['idpais']; 
   
   	
      echo '<option value="'. $pais_id . '">'.$pais_nome.'</option>';
	}
	  
	  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
	?>
    </select>
  
  
  <p>
    <input type="submit" name="submit" id="submit" value="Cadastrar" />
  </p>

  <p>cidades já cadastradas:</p>
  </form>
  
  
  <form id="form2" name="form2" method="get" action="cidades2_alt_del.php">
  <p>
  <label for="cadastrados"></label>
    <select name="cadastrados" size="10" id="cadastrados">
	
	
   <?php $link = dbconnect(); // faz conexao com o banco de dados

	
	$query =  "SELECT * FROM cidade ORDER BY pais_idpais ASC, nome_cidade ASC";

	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	while($get_categoria = mysqli_fetch_assoc($result)){
		$cidade_nome = $get_categoria['nome_cidade']; 
		$cidade_id = $get_categoria['idcidade']; 
		$pais_id = $get_categoria['pais_idpais']; 
		
		
		$query =  "SELECT * FROM pais WHERE idpais = $pais_id";
		$result2 = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
		if (!$result2) {
			die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
		}
		$get_pais_nome = mysqli_fetch_assoc($result2);
		
		$fk_pais_nome = $get_pais_nome['nome_pais'];
   
      echo '<option value="'. $cidade_id . '">'.$cidade_nome.', '.$fk_pais_nome.'</option>';
	  
	}
	  
	  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
	?>
    </select>
  </p>
  <p>
    <input type="submit" name="submit" id="submit" value="Alterar/Deletar" />
  </p>

</form>