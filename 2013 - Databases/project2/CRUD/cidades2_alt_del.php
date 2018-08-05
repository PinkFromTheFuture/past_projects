<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>
<?php $link = dbconnect(); // faz conexao com o banco de dados
   $cidade_id = $_GET['cadastrados'];
   $query =  "SELECT * FROM cidade WHERE idcidade = ".$cidade_id;
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	$get_nome = mysqli_fetch_assoc($result);
	$cidade_nome = $get_nome['nome_cidade'];
	$cidade_pais = $get_nome['pais_idpais'];
	


echo '<form id="form1" name="form1" method="get" action="cidades3_alterar.php">
    <label for="id">ID:</label>
    <input type="text" style="width:300px" name="id" id="id" disabled="disabled" value="'.$cidade_id.'" />
	<input type="hidden" name="cidade_id" id="cidade_id" value="'.$cidade_id.'" />
<br />
    <label for="nome">Cidade:</label>
    <input type="text" style="width:300px" name="nome" id="nome" value="'.$cidade_nome.'" />'; ?>
	<p>Pais:</p>
	
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
   
		if($cidade_pais != $pais_id){
			echo '<option value="'. $pais_id . '">'.$pais_nome.'</option>';
		}else{
			echo '<option value="'. $pais_id . '"selected>'.$pais_nome.'</option>';
		}
	}
	  
	?>
    </select>
	
	
	
	
  <p>
    <input type="submit" name="submit" id="submit" value="Modificar"/>
  </p>


</form>

<?php

echo '<form id="form2" name="form2" method="get" action="cidades3_deletar.php">
	<input type="hidden" name="cidade_id" id="cidade_id" value="'.$cidade_id.'" />
<br />
    <input type="hidden" style="width:300px" name="nome" id="nome" value="'.$cidade_nome.'" />

  <p>
    <input type="submit" name="submit" id="submit" value="Deletar"/>
  </p>';
  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
  ?>


</form>