

CREATE DATABASE teste 
CREATE SCHEMA esquema
    AUTHORIZATION guest

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------




CREATE TABLE esquema.contas (
    nome_cliente VARCHAR(40),
    nro_conta INTEGER NOT NULL,
	CONSTRAINT pk_nro_conta PRIMARY KEY (nro_conta)
);

CREATE TABLE esquema.emprestimos (
    nome_agentica VARCHAR(40),
    nro_emprestimo INTEGER,
	total INTEGER
);

CREATE TABLE esquema.devedores (
    nome_cliente VARCHAR(40),
    nro_emprestimo INTEGER
);



-- --------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------


INSERT
  INTO esquema.contas
  (nome_cliente, nro_conta)
  VALUES ('Eduardo Furtado', 11111);
  
  
INSERT
  INTO esquema.contas
  (nome_cliente, nro_conta)
  VALUES ('Gipsy Mothafucka', 22222);
  

-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------

  
INSERT INTO esquema.contas (nome_cliente, nro_conta) VALUES ('Jonas'	, 11111);
INSERT INTO esquema.contas (nome_cliente, nro_conta) VALUES ('Silvio'	, 22222);
INSERT INTO esquema.contas (nome_cliente, nro_conta) VALUES ('Henrique'	, 33333);
INSERT INTO esquema.contas (nome_cliente, nro_conta) VALUES ('Jackson'	, 44444);


INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Timbo'	, 17, 1000);
INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Indaial'	, 23, 2000);
INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Blumenau', 15, 1500);
INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Pomerode', 93, 500);
INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Gaspar'	, 11, 900);
INSERT INTO esquema.emprestimos (nome_agencia, nro_emprestimo, total) VALUES ('Blumenau', 16, 1300);


INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Jonas'	, 17);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Silvio'	, 23);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Henrique'	, 15);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Carlos'	, 93);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Silvio'	, 11);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('William'	, 17);
INSERT INTO esquema.devedores (nome_cliente, nro_emprestimo) VALUES ('Adalberto', 16);
  
  
  
  
---------------------


SELECT dev.nome_cliente,  emp.nro_emprestimo, emp.total
FROM esquema.emprestimos emp, esquema.devedores dev
WHERE emp.nome_agencia = 'Blumenau' and emp.nro_emprestimo = dev.nro_emprestimo
  
  
  
SELECT nome_cliente
FROM esquema.devedores
	UNION
SELECT nome_cliente
FROM  esquema.contas