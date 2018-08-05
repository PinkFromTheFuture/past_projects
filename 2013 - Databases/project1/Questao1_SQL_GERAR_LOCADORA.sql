/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     04/10/2013 17:17:27                          */
/*==============================================================*/


drop table if exists aluga;

drop table if exists atores;

drop table if exists categorias;

drop table if exists cliente;

drop table if exists elenco;

drop table if exists filmes;

drop table if exists fita;

/*==============================================================*/
/* Table: ALUGA                                                 */
/*==============================================================*/
create table aluga
(
   ID_FITA              int not null ,
   ID_CLIENTE           int not null,
   primary key (ID_FITA, ID_CLIENTE)
);

/*==============================================================*/
/* Table: ATORES                                                */
/*==============================================================*/
create table atores
(
   ID_ATORES            int not null auto_increment,
   NOME_ATOR            varchar(40) not null,
   NOME_REAL            varchar(40) not null,
   DATA_NASCIMENTO      date,
   primary key (ID_ATORES)
);

/*==============================================================*/
/* Table: CATEGORIAS                                            */
/*==============================================================*/
create table categorias
(
   ID_CATEGORIA         int not null auto_increment,
   NOME_CATEGORIA       varchar(30) not null,
   primary key (ID_CATEGORIA)
);

/*==============================================================*/
/* Table: CLIENTE                                               */
/*==============================================================*/
create table cliente
(
   ID_CLIENTE           int not null auto_increment,
   NOME_CLIENTE         varchar(40),
   TELEFONE             varchar(40),
   ENDERECO             varchar(40),
   primary key (ID_CLIENTE)
);

/*==============================================================*/
/* Table: ELENCO                                                */
/*==============================================================*/
create table elenco
(
   ID_ATORES            int not null ,
   ID_FILME             int not null,
   primary key (ID_ATORES, ID_FILME)
);

/*==============================================================*/
/* Table: FILMES                                                */
/*==============================================================*/
create table filmes
(
   ID_FILME             int not null auto_increment,
   ID_CATEGORIA         int not null,
   NOME_FILME           varchar(40),
   primary key (ID_FILME)
);

/*==============================================================*/
/* Table: FITA                                                  */
/*==============================================================*/
create table fita
(
   ID_FITA              int not null auto_increment,
   ID_FILME             int not null,
   QUANTIDADE_FITA      int,
   primary key (ID_FITA)
);

alter table aluga add constraint FK_ALUGA foreign key (ID_FITA)
      references fita (ID_FITA) on delete restrict on update restrict;

alter table aluga add constraint FK_ALUGA2 foreign key (ID_CLIENTE)
      references cliente (ID_CLIENTE) on delete restrict on update restrict;

alter table elenco add constraint FK_ELENCO foreign key (ID_ATORES)
      references atores (ID_ATORES) on delete restrict on update restrict;

alter table elenco add constraint FK_ELENCO2 foreign key (ID_FILME)
      references filmes (ID_FILME) on delete restrict on update restrict;

alter table filmes add constraint FK_GENERO foreign key (ID_CATEGORIA)
      references categorias (ID_CATEGORIA) on delete restrict on update restrict;

alter table fita add constraint FK_CONTEM foreign key (ID_FILME)
      references filmes (ID_FILME) on delete restrict on update restrict;

