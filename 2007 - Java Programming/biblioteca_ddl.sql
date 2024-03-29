DROP TABLE IF EXISTS `biblioteca`.`usuario`;
CREATE TABLE  `biblioteca`.`usuario` (
  `USUARIO_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  `MATRICULA` varchar(50) NOT NULL,
  PRIMARY KEY  (`USUARIO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`curso`;
CREATE TABLE  `biblioteca`.`curso` (
  `CURSO_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  PRIMARY KEY  (`CURSO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`usuario_curso`;
CREATE TABLE  `biblioteca`.`usuario_curso` (
  `USUARIO_ID` int(10) unsigned NOT NULL,
  `CURSO_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`USUARIO_ID`,`CURSO_ID`),
  KEY `FK_USUARIO_CURSO_CURSO` (`CURSO_ID`),
  CONSTRAINT `FK_USUARIO_CURSO_CURSO` FOREIGN KEY (`CURSO_ID`) REFERENCES `curso` (`CURSO_ID`),
  CONSTRAINT `FK_USUARIO_CURSO_USUARIO` FOREIGN KEY (`USUARIO_ID`) REFERENCES `usuario` (`USUARIO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`editora`;
CREATE TABLE  `biblioteca`.`editora` (
  `EDITORA_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  PRIMARY KEY  (`EDITORA_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`livro`;
CREATE TABLE  `biblioteca`.`livro` (
  `LIVRO_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  `ISBN` varchar(50) NOT NULL,
  `EDITORA_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`LIVRO_ID`),
  KEY `FK_LIVRO_EDITORA` (`EDITORA_ID`),
  CONSTRAINT `FK_LIVRO_EDITORA` FOREIGN KEY (`EDITORA_ID`) REFERENCES `editora` (`EDITORA_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`autor`;
CREATE TABLE  `biblioteca`.`autor` (
  `AUTOR_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  PRIMARY KEY  (`AUTOR_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`livro_autor`;
CREATE TABLE  `biblioteca`.`livro_autor` (
  `LIVRO_ID` int(10) unsigned NOT NULL,
  `AUTOR_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`LIVRO_ID`,`AUTOR_ID`),
  KEY `FK_LIVRO_AUTOR_AUTOR` (`AUTOR_ID`),
  CONSTRAINT `FK_LIVRO_AUTOR_AUTOR` FOREIGN KEY (`AUTOR_ID`) REFERENCES `autor` (`AUTOR_ID`),
  CONSTRAINT `FK_LIVRO_AUTOR_LIVRO` FOREIGN KEY (`LIVRO_ID`) REFERENCES `livro` (`LIVRO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`exemplar`;
CREATE TABLE  `biblioteca`.`exemplar` (
  `EXEMPLAR_ID` int(10) unsigned NOT NULL auto_increment,
  `CODIGO` varchar(20) NOT NULL,
  `DISPONIVEL` tinyint(1) NOT NULL,
  `LIVRO_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`EXEMPLAR_ID`),
  KEY `FK_EXEMPLAR_LIVRO` (`LIVRO_ID`),
  CONSTRAINT `FK_EXEMPLAR_LIVRO` FOREIGN KEY (`LIVRO_ID`) REFERENCES `livro` (`LIVRO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`bibliotecario`;
CREATE TABLE  `biblioteca`.`bibliotecario` (
  `BIBLIOTECARIO_ID` int(10) unsigned NOT NULL auto_increment,
  `NOME` varchar(70) NOT NULL,
  `USUARIO` varchar(20) NOT NULL,
  `SENHA` varchar(12) NOT NULL,
  PRIMARY KEY  (`BIBLIOTECARIO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `biblioteca`.`emprestimo`;
CREATE TABLE  `biblioteca`.`emprestimo` (
  `EMPRESTIMO_ID` int(10) unsigned NOT NULL auto_increment,
  `DATA_RESERVA` datetime NOT NULL,
  `DATA_ENTREGA` datetime default NULL,
  `USUARIO_ID` int(10) unsigned NOT NULL,
  `BIBLIOTECARIO_ID` int(10) unsigned NOT NULL,
  `EXEMPLAR_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`EMPRESTIMO_ID`),
  KEY `FK_EMPRESTIMO_USUARIO` (`USUARIO_ID`),
  KEY `FK_EMPRESTIMO_BIBLIOTECARIO` (`BIBLIOTECARIO_ID`),
  KEY `FK_EMPRESTIMO_EXEMPLAR` (`EXEMPLAR_ID`),
  CONSTRAINT `FK_EMPRESTIMO_BIBLIOTECARIO` FOREIGN KEY (`BIBLIOTECARIO_ID`) REFERENCES `bibliotecario` (`BIBLIOTECARIO_ID`),
  CONSTRAINT `FK_EMPRESTIMO_EXEMPLAR` FOREIGN KEY (`EXEMPLAR_ID`) REFERENCES `exemplar` (`EXEMPLAR_ID`),
  CONSTRAINT `FK_EMPRESTIMO_USUARIO` FOREIGN KEY (`USUARIO_ID`) REFERENCES `usuario` (`USUARIO_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
