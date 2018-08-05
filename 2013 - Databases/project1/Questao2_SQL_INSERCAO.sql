#Categorias
insert into  categorias (nome_categoria) values ('Drama');
insert into  categorias (nome_categoria) values ('Ficção');
insert into  categorias (nome_categoria) values ('Aventura');
insert into  categorias (nome_categoria) values ('Terror');
insert into  categorias (nome_categoria) values ('Ação');
insert into  categorias (nome_categoria) values ('Documentário');

#CLiente
insert into cliente (nome_cliente, telefone, endereco) values ('Thomaz Macedo', '061-3266-0666','Abbey Road Mi5');
insert into cliente (nome_cliente, telefone, endereco) values ('Flavio Martins', '061-3207-6969','Downtownm, Dog City');
insert into cliente (nome_cliente, telefone, endereco) values ('Leandro Silva', '061-3224-2424','Rainbow Road, Nowhere');
insert into cliente (nome_cliente, telefone, endereco) values ('Bob Dylan', '069-1963-2013','Nashville, Tennesse');
insert into cliente (nome_cliente, telefone, endereco) values ('Jim Morrison', '069-1940-1970','Cocaine Road, Los Angeles');
insert into cliente (nome_cliente, telefone, endereco) values ('Bob Marley', '071 -7171-0171','Happiness, Jamaica');

#Atores
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Marlon Brando', 'Marlon Brando Jr','1942-04-03');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Johnny Depp', 'John Christopher Depp II','1963-06-09');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Elvis Presley', 'Elvis Aaron Presley','1935-01-08');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Tom Cruise', 'Thomas Cruise Mapother IV','1962-07-03');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Edward Norton', 'Edward Harrison Norton','1969-08-19');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Scarlett Johansson','Scarlett Ingrid Johansson', '1984-11-22');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Bob Burnquist','Roberto Dean Silva Burnquist', '1976-10-10');
insert into atores ( nome_ator, nome_real, data_nascimento) values ('Vin Diesel','Mark Sinclair Vincent', '1967-07-18');
#Filmes
insert into filmes (id_categoria, nome_filme) values ( 1,'The Godfather'); #Brando
insert into filmes (id_categoria, nome_filme) values ( 1, 'Last Tango in Paris'); #Brando
insert into filmes (id_categoria, nome_filme) values ( 5, 'Oblivion'); #Cruise
insert into filmes (id_categoria, nome_filme) values ( 1, 'Last Samurai'); #Cruise
insert into filmes (id_categoria, nome_filme) values ( 5, 'Fast and Furious'); # Vin Diesel 
insert into filmes (id_categoria, nome_filme) values ( 6, 'Vida Sobre Rodas'); #Bob 
insert into filmes (id_categoria, nome_filme) values ( 5, 'Avengers'); #Scarlet
insert into filmes (id_categoria, nome_filme) values ( 4, 'Blair Witch'); #None
insert into filmes (id_categoria, nome_filme) values ( 5, 'Fight Club'); #Norton

#Fita
insert into fita (id_filme, quantidade_fita) values ( 1, 8);
insert into fita (id_filme, quantidade_fita) values ( 3, 10);
insert into fita (id_filme, quantidade_fita) values ( 7, 3);
insert into fita (id_filme, quantidade_fita) values ( 2, 5);
insert into fita (id_filme, quantidade_fita) values ( 5, 2);
insert into fita (id_filme, quantidade_fita) values ( 8, 12);

# Elenco
insert into elenco values (1,1);
insert into elenco values (1,2);
insert into elenco values (4,3);
insert into elenco values (4,4);
insert into elenco values (5,6);
insert into elenco values (5,9);
insert into elenco values (6,7);

#Aluga
insert into aluga values (1,1);
insert into aluga values (5,1);
insert into aluga values (3,1);
insert into aluga values (5,2);
insert into aluga values (1,2);
insert into aluga values (5,2);
insert into aluga values (3,3);
insert into aluga values (1,3);
insert into aluga values (5,3);
insert into aluga values (3,3);
insert into aluga values (2,4);
insert into aluga values (1,4);
insert into aluga values (4,4);
insert into aluga values (5,5);


