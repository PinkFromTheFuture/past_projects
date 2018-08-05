#Questão 4

#A - Liste todos os dados da table atores

select * from atores; 

#B - Liste todos os filmes e suas respectivas categorias

select nome_filme, NOME_CATEGORIA 
from filmes t1 
inner join categorias t2 
on t1.ID_CATEGORIA =t2.ID_CATEGORIA;

#C - Liste os filmes e o nome dos atores em cada filme

select nome_filme, nome_ator
from filmes t1 inner join elenco t2
on t1.ID_FILME = t2.id_filme
inner join atores t3
on t2.ID_ATORES = t3.ID_ATORES;

#D - Listar todos os filmes e todos os atores cadastrados
select nome_filme, nome_ator
from filmes t1 left outer join elenco t2
on t1.ID_FILME = t2.id_filme
left outer join atores t3
on t2.ID_ATORES = t3.ID_ATORES;

#Inserindo novo ator para testar
insert into atores (nome_ator, nome_real, DATA_NASCIMENTO)  values ('Brad Pitt', 'William Bradley Pitt', '1963-12-18');
select *from atores;
insert into elenco values (9, 9);


#E - Liste os nomes dos atores que trabalham no mesmo filme que Brad Pitt

create view atuou_filme as 
select id_filme as result
from elenco t1 
left outer join atores t2 
on t1.id_atores = t2.id_atores
where t2.id_atores = 9;

select NOME_ATOR 
from atores a1 
left outer join elenco a2
on  a1.ID_ATORES = a2.ID_ATORES
inner join atuou_filme a3
on a2.ID_FILME = a3.result
order by nome_ator;


#F -Liste todos os atores que começam com a letra 'J'
	#Inserindo novo ator para poder testar
insert into atores (NOME_ATOR, nome_real, data_nascimento) values ('James Franco', 'James Edward Franco', '1978-04-19');

select * from atores where NOME_ATOR like 'J%' ; 
 
#G - Liste o nome dos clientes que já alugaram filmes (os nomes não devem ser repetidos)

select distinct NOME_CLIENTE
from cliente t1
inner join aluga t2
where t1.id_CLIENTE = t2.id_cliente;


#H - Liste o nome dos clientes e o número de locação realizada por cada um respectivamente

select nome_cliente, count(*) as locacao
from cliente t1 
inner join aluga t2
on t1.ID_CLIENTE= t2.ID_CLIENTE
group by NOME_CLIENTE;


#I - Liste o nome dos clientes e o número de locação apenas dos clientes que tiveram mais de uma locação.
select nome_cliente, count(*) as locacao
from cliente t1 
inner join aluga t2
on t1.ID_CLIENTE= t2.ID_CLIENTE
group by NOME_CLIENTE
having locacao >1 ;