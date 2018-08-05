--EDUARDO FURTADO S� CORR�A 	- 09/0111575
--Thomaz Maciel de Macedo					 	- 11/0142179
--o exerc�cio de TRIGGERS para entrega em 21 de outubro come�a no final, linha 107.
-----------------------------------------------------
CREATE DATABASE postgres
  WITH OWNER = postgres
       ENCODING = 'UTF8'
       TABLESPACE = pg_default
       LC_COLLATE = 'Portuguese_Brazil.1252'
       LC_CTYPE = 'Portuguese_Brazil.1252'
       CONNECTION LIMIT = -1;

CREATE SCHEMA aula
  AUTHORIZATION postgres;



------------------------------------------------------

CREATE TABLE aula.cliente

(
nome character varying(40),
  
ende character varying(40),
 
rg character varying(40) NOT NULL,
 
cidade character varying(40),
 
CONSTRAINT pk_rg PRIMARY KEY (rg)

)

WITH (

  OIDS=FALSE

);


ALTER TABLE aula.cliente
  OWNER TO postgres;









------------------------------------------------------



CREATE TABLE aula.tg_cliente
(
  nome character varying(40),
  ende character varying(40),
  rg character varying(40) NOT NULL,
  cidade character varying(40)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE aula.tg_cliente
  OWNER TO postgres;

------------------------------------------------------


INSERT 
INTO aula.cliente (nome, ende, rg, cidade) 
VALUES ('EDUARDO FURTADO', 'SQN 103', '114011234-1', 'BRAS�LIA');



INSERT 
INTO aula.cliente (nome, ende, rg, cidade) 
VALUES ('EDUARDO2 FURTADO', 'SQN 103b', '114011234-2', 'BRAS�LIA-df');

INSERT 
INTO aula.cliente (nome, ende, rg, cidade) 
VALUES ('james apksjdaspk', 'S12313', '000123-1', 'disneyland');



------------------------------------------------------
CREATE OR REPLACE FUNCTION salvardadosexcl()
RETURNS trigger AS
$BODY$ BEGIN
INSERT INTO aula.tg_cliente VALUES (old.nome, old.ende, old.rg, old.cidade);
RETURN NULL;
END;
$BODY$ LANGUAGE plpgsql;
------------------------------------------------------
CREATE TRIGGER exclui_cliente
AFTER DELETE
ON aula.cliente
FOR EACH ROW
EXECUTE PROCEDURE salvardadosexcl();
------------------------------------------------------
DELETE
FROM aula.cliente
WHERE cliente.rg = '114011234-2';
------------------------------------------------------
--exerc�cio:
--Usando a sintaxe de trigger, escreva as regras b�sicas para INSERT e UPADATE.
--NEW:
		-- no caso do INSERT, armazena o registro que est� sendo inserido;
		-- no caso UPDATE, armazena a nova vers�o do registro depois da atualiza��o.
--OLD:
		-- no caso UPDATE, armazena a antiga vers�o do registro depois da atualiza��o.

		
-- procedimento para armazenar dados novos de um registro
CREATE OR REPLACE FUNCTION salvardadosincluidos()
RETURNS trigger AS
$BODY$ BEGIN
INSERT INTO aula.tg_cliente VALUES (new.nome, new.ende, new.rg, new.cidade);
RETURN NULL;
END;
$BODY$ LANGUAGE plpgsql;

--insert (new)		
CREATE TRIGGER new_insert_cliente
AFTER  INSERT
ON aula.cliente
FOR EACH ROW --ROW / STATEMENT
EXECUTE PROCEDURE salvardadosincluidos();

-- update (new)
CREATE TRIGGER new_update_cliente
AFTER UPDATE 
ON aula.cliente
FOR EACH ROW
EXECUTE PROCEDURE salvardadosincluidos();

--update (old)
CREATE TRIGGER old_update_cliente
AFTER UPDATE 
ON aula.cliente
FOR EACH ROW
EXECUTE PROCEDURE salvardadosexcl();	
		
------------------------------------------------------
-- queries para testar os triggers:
INSERT 
INTO aula.cliente (nome, ende, rg, cidade) 
VALUES ('teste trigger insert', 'unb', '007', 'brasilia');

UPDATE aula.cliente
SET nome='teste trigger update'
WHERE rg = '007';


------------------------------------------------------

