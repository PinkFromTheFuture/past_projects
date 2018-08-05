<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>

<form id="form1" name="form1" method="get" action="bairros2_cadastrar.php">
  <p>
    <label for="nome">Nome:</label>
    <input type="text" name="nome" id="nome" />
  </p>
  
  <p>cidade:</p>
  
  
  <label for="cidade"></label>
    <select name="cidade" size="10" id="cidade">
	
	
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
  
  
  
  
  
  <p>
    <input type="submit" name="submit" id="submit" value="Cadastrar" />
  </p>

 
  </form>
  
   <p>bairros já cadastradas:</p>
  <form id="form2" name="form2" method="get" action="bairros2_alt_del.php">
  <p>
  <label for="cadastrados"></label>
    <select name="cadastrados" size="10" id="cadastrados">
	
	
   <?php $link = dbconnect(); // faz conexao com o banco de dados
	
	$query =  "	SELECT b.idbairro, b.nome_bairro, c.nome_cidade, p.nome_pais
				FROM bairro b, cidade c, pais p
				WHERE c.pais_idpais = p.idpais
				AND b.cidade_idcidade = c.idcidade
				ORDER BY pais_idpais ASC, nome_cidade ASC, nome_bairro ASC";
	
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	while($get_categoria = mysqli_fetch_assoc($result)){
		$bairro_nome = $get_categoria['nome_bairro']; 
		$bairro_id = $get_categoria['idbairro']; 
		$cidade_nome = $get_categoria['nome_cidade'];
		$pais_nome = $get_categoria['nome_pais'];
   
   	
      echo "<option value='$bairro_id'>$bairro_nome, $cidade_nome, $pais_nome</option>";
	}
	  
	  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
	?>
    </select>
  </p>
  <p>
    <input type="submit" name="submit" id="submit" value="Alterar/Deletar" />
  </p>

</form>