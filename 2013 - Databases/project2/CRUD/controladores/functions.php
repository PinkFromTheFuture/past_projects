<?php
//Connect Database
function connectDB () {
	//header('Content-Type: text/html; charset=utf-8');

	//Declaration of Variables
	$database = 'bracorpus';
	$host = 'localhost';
	$user = 'bracorpus';
	$pass = 'JLetW12d6';
	
	//Connection Database
	$link = ($GLOBALS["___mysqli_ston"] = mysqli_connect($host,  $user,  $pass));
	if (!$link) {
		die('Not connected : ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	} 

	//Database Select
	$db_selected = ((bool)mysqli_query( $link, "USE $database"));
	if (!$db_selected) {
		die ('Can\'t use '.$database.': ' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	} 
	
	//Aqui está o segredo
	mysqli_query($GLOBALS["___mysqli_ston"], "SET NAMES 'utf8'");
	mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_connection=utf8');
	mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_client=utf8');
	mysqli_query($GLOBALS["___mysqli_ston"], 'SET character_set_results=utf8');

}

//Function for get results in one table of database selected
function getResultsOptions($table, $select) {
	//Declaration of Variables
	$idTable = 'id'.ucfirst($table);
	$table = 'sis_'.strtolower($table);
	
	//Connect Database
	connectDB();

	//Enable Query
	$sql = 'SELECT * FROM '.$table.' ORDER BY descricao;';
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//Generator of <options>
	echo '<option name="'.$table.'-descricao" value="0">---</option>';
	while ($row = mysqli_fetch_assoc($result)) {
		if ($row['descricao'] == $select) {
			echo '<option name="'.$table.'-descricao" value="'.$row[''.$idTable.''].'" selected="selected">'.ucfirst($row['descricao']).'</option>';
		} else {
			echo '<option name="'.$table.'-descricao" value="'.$row[''.$idTable.''].'">'.ucfirst($row['descricao']).'</option>';
		}
	}
	
	//close conection with database
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
}

function listTerms($table, $term, $type) {
	//Declaration of Variables
	$idTable = 'id'.ucfirst($table);
	$table = 'sis_'.strtolower($table);
	
	//verification of type
	switch ($type) {
		case "consultar":
			$dir = "consultas";
			break;
		case "modificar":
			$dir = "modificadores";
			break;
		case "excluir";
			$dir = "exclusao";
			break;
	}
	
	//Connect Database
	ConnectDB();
	
	//Enable Query
	$sql = 'SELECT * FROM '.$table.' WHERE descricao LIKE "%'.$term.'%" AND ativo = "1" ORDER BY descricao';
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//List Generator
	echo '<table border="0" align="center"><ul>';
	echo '<tr><td> --- </td></tr>';
	while ($row = mysqli_fetch_assoc($result)) {
		echo '<tr>';
		echo '<td><li><a href="../'.$dir.'/ficha.php?idTerm='.$row["$idTable"].'">'.ucfirst($row['descricao']).'</a></li></td>';
		echo '</tr>';
	}
	echo '</ul></table>';

	//close conection with database
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
}

function getTerm($idTerm) {
	//Connect Database
	ConnectDB();
	
	//Enable Query
	$sql = 'SELECT * FROM sis_geral WHERE ativo = "1" AND idTermo = '.$idTerm;
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//close conection with database
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
	
	return $result;
}

function deleteTerm($idTerm) {
	//Connect Database
	ConnectDB();
	
	//Logic delete of the term
	$sql = 'UPDATE sis_termo SET ativo="0" WHERE idTermo = '.$idTerm;
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	echo "<h1 align='center'>Termo excluído com sucesso</h1>";
	
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
}

function insertSubTerm($descricao, $type, $at) {
	//Connect Database
	ConnectDB();
	
	//select type
	switch ($type) {
		case "etimologia":
			$sql = "INSERT INTO `bracorpus`.`sis_etimologia` (descricao) VALUES ('$descricao')";
			break;
		case "areatematica":
			$sql = "INSERT INTO `bracorpus`.`sis_areatematica` (`descricao`) VALUES ('$descricao');";
			break;
		case "subareatematica";
			$sql = "INSERT INTO `bracorpus`.`sis_subareatematica` (`descricao`, `sis_areatematica_idAreaTematica`) VALUES ('$descricao', '$at');";
			break;
	}
	
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	echo "<h1 align='center'>Termo '$descricao' inserido com sucesso</h1>";
	
	echo "<a href='javascript:window.history.go(-1)' align='center'>Voltar</a>";
	
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);	
}

function insertTerm($term) {
	//Connect Database
	connectDB();
	
	$termo = 					$term['termo'];
	$etiqueta = 				$term['etiqueta'];
	$definicao =				$term['definicao'];
	$comentario =				$term['comentario'];
	$etimologia =				$term['etimologia'];
	$provatextual =				$term['provatextual'];
	$categoriagramatical =		$term['categoriagramatical'];
	$codfiabilidade =			$term['codfiabilidade'];
	$numero =					$term['numero'];
	$genero =					$term['genero'];
	$subareatematica =			$term['subareatematica'];
	$lingua =					$term['lingua'];
	$lingua1 =					$term['lingua1'];	
	$lingua2 =					$term['lingua2'];
	$lingua3 =					$term['lingua3'];
	$areatematica =				$term['areatematica'];
	$contextoexplicativo = 		$term['contextoExplicativo'];
	$unidadefraseologica =		$term['unidadeFraseologica'];
	$autor =  					$term['autor'];
	$fonte = 					$term['fonte'];
	
	//Enable Query
	//add fonte
	$sql = "INSERT INTO `bracorpus`.`sis_fonte` (`autor`, `fonte`) VALUES ('$autor', '$fonte');";
	$result1 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result1) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//select fonte
	$sql = "SELECT idFonte FROM `bracorpus`.`sis_fonte` WHERE autor = '$autor' AND fonte = '$fonte';";
	$result2 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);	
	$row = mysqli_fetch_assoc($result2);
	$idfonte = $row['idFonte'];
	if (!$result2) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//add provatextual
	$sql = "INSERT INTO `bracorpus`.`sis_provatextual` (`contextoExplicativo`, `unidadeFraseologica`, `sis_fonte_idFonte`) VALUES ('$contextoexplicativo', '$unidadefraseologica', '$idfonte');";
	$result3 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result3) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//select provatextual
	$sql = "SELECT idProvaTextual FROM `bracorpus`.`sis_provatextual` WHERE sis_fonte_idFonte = '$idfonte';";
	$result4 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	$row = mysqli_fetch_assoc($result4);
	$idProvaTextual = $row['idProvaTextual'];
	if (!$result4) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//add term
	$sql = "INSERT INTO `bracorpus`.`sis_termo` (`descricao`, `definicao`, `comentario`, `ativo`, `sis_etimologia_idEtimologia`, `sis_provatextual_idprovaTextual`, `sis_categoriagramatical_idCategoriaGramatical`, `sis_codfiabilidade_idcodFiabilidade`, `sis_numero_idNumero`, `sis_genero_idGenero`, `sis_subareatematica_idSubAreaTematica`, `sis_lingua_idLingua`) VALUES ('$termo', '$definicao', '$comentario', '1', '$etimologia', '$idProvaTextual', '$categoriagramatical', '$codfiabilidade', '$numero', '$genero', '$subareatematica', '$lingua');";
	$result5 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result5) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//select idTermo
	$sql = "SELECT idTermo FROM `bracorpus`.`sis_termo` WHERE descricao = '$termo' AND definicao = '$definicao' AND comentario = '$comentario';";
	$result6 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	$row = mysqli_fetch_assoc($result6);
	$idTermo = $row['idTermo'];
	if (!$result6) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//add traducoes
	$sql = "INSERT INTO `bracorpus`.`sis_traducoes` (`sis_termo_idTermo`, `lingua1`, `lingua2`, `lingua3`, `sis_linguagem_idLinguagem`) VALUES ('$idTermo', '$lingua1', '$lingua2', '$lingua3', '$lingua');";
	$result7 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result6) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	echo "<h1 align='center'>Termo inserido com sucesso</h1>";
	
	//close conection with database
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
}

function editTerm($term) {
	//Connect Database
	connectDB();

	$idtermo = 					$term['idTermo'];
	$termo = 					$term['termo'];
	$etiqueta = 				$term['etiqueta'];
	$definicao =				$term['definicao'];
	$comentario =				$term['comentario'];
	$etimologia =				$term['etimologia'];
	$provatextual =				$term['provatextual'];
	$categoriagramatical =		$term['categoriagramatical'];
	$codfiabilidade =			$term['codfiabilidade'];
	$numero =					$term['numero'];
	$genero =					$term['genero'];
	$subareatematica =			$term['subareatematica'];
	$linguaantiga = 			$term['linguaAntiga'];
	$lingua =					$term['lingua'];
	$lingua1 =					$term['lingua1'];	
	$lingua2 =					$term['lingua2'];
	$lingua3 =					$term['lingua3'];
	$areatematica =				$term['areatematica'];
	$contextoexplicativo = 		$term['contextoExplicativo'];
	$unidadefraseologica =		$term['unidadeFraseologica'];
	$autor =  					$term['autor'];
	$fonte = 					$term['fonte'];
	
	//GET idProvaTextual
	$sql = "SELECT sis_provatextual_idprovaTextual FROM `bracorpus`.`sis_termo` WHERE idTermo = '$idtermo';";
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	$row = mysqli_fetch_assoc($result);
	$idprovatextual = $row['sis_provatextual_idprovaTextual'];
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//GET idFonte
	$sql = "SELECT sis_fonte_idFonte FROM `bracorpus`.`sis_provatextual` WHERE idProvaTextual = '$idprovatextual';";
	$result = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	$row = mysqli_fetch_assoc($result);
	$idfonte = $row['sis_fonte_idFonte'];
	if (!$result) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//update sis_fonte
	$sql = "UPDATE `bracorpus`.`sis_fonte` SET `autor` = '$autor', `fonte` = '$fonte' WHERE `sis_fonte`.`idFonte` = '$idfonte';";
	$result1 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result1) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//update sis_provatextual
	$sql = "UPDATE `bracorpus`.`sis_provatextual` SET `contextoExplicativo` = '$contextoexplicativo', `unidadeFraseologica` = '$unidadefraseologica' WHERE `sis_provatextual`.`idProvaTextual` = '$idprovatextual' AND `sis_provatextual`.`sis_fonte_idFonte`= '$idfonte';";
	$result2 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result2) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//updadate sis_termo
	$sql = "UPDATE `bracorpus`.`sis_termo` SET `descricao` = '$termo', `etiqueta` = '$etiqueta', `definicao` = '$definicao', `comentario` = '$comentario', `sis_etimologia_idEtimologia` = '$etimologia', `sis_categoriagramatical_idCategoriaGramatical` = '$categoriagramatical', `sis_codfiabilidade_idcodFiabilidade` = '$codfiabilidade', `sis_numero_idNumero` = '$numero', `sis_genero_idGenero` = '$genero', `sis_subareatematica_idSubAreaTematica` = '$subareatematica', `sis_lingua_idLingua` = '$lingua' WHERE `sis_termo`.`idTermo` = '$idtermo';";
	$result3 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result3) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	//update sis_traducoes
	$sql = "UPDATE `bracorpus`.`sis_traducoes` SET `lingua1` = '$lingua1', `lingua2` = '$lingua2', `lingua3` = '$lingua3', `sis_linguagem_idLinguagem` = '$lingua' WHERE `sis_traducoes`.`sis_termo_idTermo` = '$idtermo' AND `sis_traducoes`.`sis_linguagem_idLinguagem` = '$linguaantiga';";
	$result4 = mysqli_query($GLOBALS["___mysqli_ston"], $sql);
	if (!$result4) {
		die ("Could not run query ($sql) in database: " . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)));
	}
	
	echo "<h1 align='center'>Termo modificado com sucesso</h1>";
	
	//close conection with database
	((is_null($___mysqli_res = mysqli_close($link))) ? false : $___mysqli_res);
}
?>