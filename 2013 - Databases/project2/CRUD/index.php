<?php
	$PATH_ROOT = $_SERVER['DOCUMENT_ROOT']; //pasta base do site em qualquer servidor
	//echo $PATH_ROOT;
	include($PATH_ROOT."/crud/controladores/dbhandler.php");
?>

<h2>CRUD basico para as tabelas PAIS, CIDADE e BAIRRO</h2>
<p>feito em PHP</p
<p>Eduardo Furtado Sá Corrêa - 09/0111575 - eduardoxfurtado@gmail.com</p>
<p>Thomaz Maciel de Macedo - 11/0142179 - tho.macedo@gmail.com</p>

<br /><br />


<table width="100%" border="0"><tr>
	<td width="280px">	
		<form id="form1" name="form1" method="post" action="paises1.php">
		  <input class="button orange" style="width:230px;"" type="submit" name="paises" id="paises" value="CRUD de paises" />
		</form>
		<form id="form4" name="form4" method="post" action="cidades1.php">
		  <input class="button orange" style="width:230px;" type="submit" name="cidades" id="cidades" value="CRUD de cidades" />
		</form>
		<form id="form2" name="form2" method="post" action="bairros1.php">
		  <input class="button orange" style="width:230px;" type="submit" name="bairros" id="bairros" value="CRUD de bairros" />
		</form>
	</td>
</tr></table>
