# Questão 3
/*
Apague alguns registros. 
Tente apagar registros que tenham chaves primárias 
referenciadas por chaves estrangeiras. 
Esse procedimento deu algum erro? Qual?
*/
delete from atores where ID_ATORES = 9;delete from atores where ID_ATORES = 9

/* Erro encontrado

811:16:28	delete from atores where ID_ATORES = 9	
Error Code: 1451. Cannot delete or update a parent row: 
		a foreign key constraint fails 
	(`aulas`.`elenco`, CONSTRAINT `FK_ELENCO` FOREIGN KEY (`ID_ATORES`) 
	REFERENCES `atores` (`ID_ATORES`))	0.031 sec
*/


