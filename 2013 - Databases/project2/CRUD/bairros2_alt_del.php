<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>
<?php $link = dbconnect(); // faz conexao com o banco de dados
   $bairro_id = $_GET['cadastrados'];
   $query =  "SELECT * FROM bairro WHERE idbairro = ".$bairro_id;
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	$get_nome = mysqli_fetch_assoc($result);
	$bairro_nome = $get_nome['nome_bairro'];
	$bairro_cidade = $get_nome['cidade_idcidade'];


echo '<form id="form1" name="form1" method="get" action="bairros3_alterar.php">
    <label for="id">ID:</label>
    <input type="text" style="width:300px" name="id" id="id" disabled="disabled" value="'.$bairro_id.'" />
	<input type="hidden" name="bairro_id" id="bairro_id" value="'.$bairro_id.'" />
<br />
    <label for="nome">Bairro:</label>
    <input type="text" style="width:300px" name="nome" id="nome" value="'.$bairro_nome.'" />

';
  ?>
  
  
  <p>cidade:</p>
  
  
  <label for="cidade"></label>
    <select name="cidade" size="10" id="cidade">
	
	
   <?php 

	
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
		
	
	
		if($bairro_cidade != $cidade_id){
			echo "<option value='$cidade_id'>$cidade_nome, $fk_pais_nome</option>";
		}else{
			echo "<option value='$cidade_id' selected>$cidade_nome, $fk_pais_nome</option>";
		}
	  
	}
	  
	?>
    </select>  

	
	<p>
    <input type="submit" name="submit" id="submit" value="Modificar"/>
	</p>

</form>

<?php

echo '<form id="form2" name="form2" method="get" action="bairros3_deletar.php">
	<input type="hidden" name="bairro_id" id="bairro_id" value="'.$bairro_id.'" />
<br />
    <input type="hidden" style="width:300px" name="nome" id="nome" value="'.$bairro_nome.'" />

  <p>
    <input type="submit" name="submit" id="submit" value="Deletar"/>
  </p>';
  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
  ?>


</form>