<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>
<?php $link = dbconnect(); // faz conexao com o banco de dados
   $pais_id = $_GET['cadastrados'];
   $query =  "SELECT * FROM pais WHERE idpais = ".$pais_id;
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $query); 
	if (!$result) {
		((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
		die('Invalid query: ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	$get_nome = mysqli_fetch_assoc($result);
	$pais_nome = $get_nome['nome_pais'];


echo '<form id="form1" name="form1" method="get" action="paises3_alterar.php">
    <label for="id">ID:</label>
    <input type="text" style="width:300px" name="id" id="id" disabled="disabled" value="'.$pais_id.'" />
	<input type="hidden" name="pais_id" id="pais_id" value="'.$pais_id.'" />
<br />
    <label for="nome">Pais:</label>
    <input type="text" style="width:300px" name="nome" id="nome" value="'.$pais_nome.'" />

  <p>
    <input type="submit" name="submit" id="submit" value="Modificar"/>
  </p>';
  ?>


</form>

<?php

echo '<form id="form2" name="form2" method="get" action="paises3_deletar.php">
	<input type="hidden" name="pais_id" id="pais_id" value="'.$pais_id.'" />
<br />
    <input type="hidden" style="width:300px" name="nome" id="nome" value="'.$pais_nome.'" />

  <p>
    <input type="submit" name="submit" id="submit" value="Deletar"/>
  </p>';
  ((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
  ?>


</form>