 -- pais

INSERT INTO `pais` (`idpais`, `nome_pais`) VALUES
(1, 'Brasil'),
(2, 'Argentina'),
(3, 'Coreia do Sul'),
(4, 'Japao'),
(5, 'EUA'),
(6, 'Canada'),
(7, 'China'),
(8, 'Camaroes'),
(9, 'Angola'),
(10, 'Peru'),
(11, 'Espanha'),
(12, 'Russia'),
(13, 'Iran'),
(14, 'Turquia'),
(15, 'Italia'),
(16, 'Gabao'),
(17, 'Cuba'),
(18, 'Franca'),
(19, 'Servia'),
(20, 'Croacia'),
(21, 'Tailandia'),
(22, 'Mexico');

-- atleta

INSERT INTO `atleta` (`idatleta`, `nome_atleta`, `sobrenome_atleta`, `idade_atleta`, `peso_atleta`, `foto_atleta`, `pais_idpais`, `sexo`) VALUES
(1, 'Joel', 'Gonzalez', 23, 48, NULL, 11, 'm'),
(2, 'Lee', 'Dae-Hoon', 28, 52, NULL, 3, 'm'),
(3, 'Aleksey', 'Deniesenko', 24, 53, NULL, 12, 'm'),
(4, 'Oscar ', 'Munoz', 21, 57, NULL, 11, 'm'),
(5, 'Servet', 'Tazegul', 19, 71, NULL, 14, 'm'),
(6, 'Mohammad', 'Bagheri', 20, 73, NULL, 13, 'm'),
(7, 'Terrence', 'Jennings', 22, 79, NULL, 5, 'm'),
(8, 'Sebastian', 'Crismanich', 25, 82, NULL, 2, 'm'),
(9, 'Nicolas', 'Garcia', 26, 83, NULL, 11, 'm'),
(10, 'Lutalo', 'Muhammad', 27, 80, NULL, 13, 'm'),
(11, 'Mauro', 'Sarmiento', 25, 84, NULL, 15, 'm'),
(12, 'Carlo', 'Molfetta', 28, 89, NULL, 15, 'm'),
(13, 'Anthony', 'Obame', 29, 87, NULL, 16, 'm'),
(14, 'Robelis', 'Despaigne', 30, 90, NULL, 17, 'm'),
(15, 'Liu', 'Xiaobo', 22, 88, NULL, 7, 'm'),
(16, 'Thomaz', 'Macedo', 25, 58, NULL, 1, 'm'),
(17, 'Eduardo', 'Furtado', 22, 73, NULL, 19, 'm'),
(18, 'Jim ', 'Morrison', 60, 78, NULL, 5, 'm'),
(19, 'Ozzy', 'Osbourne', 58, 130, NULL, 5, 'm'),
(20, 'John', 'Lennon', 60, 82, NULL, 22, 'm'),
(21, 'Joao', 'Dideus', 57, 42, NULL, 13, 'm'),
(23, 'Zeah', 'Dascouve', 29, 69, NULL, 9, 'm');



-- cidade

insert into cidade (nome_cidade, pais_idpais) values ('Brasilia', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Rio de Janeiro', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Sao Paulo', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Goiania', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Belo Horizonte', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Fortaleza', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Porto Alegre', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Cuiaba', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Natal', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Manaus', 1) ;
insert into cidade (nome_cidade, pais_idpais) values ('Belem', 1) ;


-- bairro
insert into bairro (nome_bairro, cidade_idcidade) values ('Asa Sul', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Asa Norte', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Guara', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Taguatinga', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Lago Sul', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Lago Norte', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Sobradinho', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Sudoeste', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Noroeste', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Parkway', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Gama', 1) ;
insert into bairro (nome_bairro, cidade_idcidade) values ('Ceilandia', 1) ;


-- Tipo Culinaria
insert into tipo_culinaria (tipo_culinaria) values ('American Fast Food') ;
insert into tipo_culinaria (tipo_culinaria) values ('Mexicano') ;
insert into tipo_culinaria (tipo_culinaria) values ('Chinesa') ;
insert into tipo_culinaria (tipo_culinaria) values ('Japonesa') ;
insert into tipo_culinaria (tipo_culinaria) values ('Nordestina') ;
insert into tipo_culinaria (tipo_culinaria) values ('Churrascaria') ;
insert into tipo_culinaria (tipo_culinaria) values ('Buteco') ;
insert into tipo_culinaria (tipo_culinaria) values ('Chopperia') ;
insert into tipo_culinaria (tipo_culinaria) values ('Self Service') ;


-- endereco

insert into endereco (endereco, bairro_idbairro) values ('CLS 109 ', 1) ;
insert into endereco (endereco, bairro_idbairro) values ('CLS 407', 1) ;
insert into endereco (endereco, bairro_idbairro) values ('CLS 302', 1) ;
insert into endereco (endereco, bairro_idbairro) values ('CLN 309', 2) ;
insert into endereco (endereco, bairro_idbairro) values ('CLN 115', 2) ;
insert into endereco (endereco, bairro_idbairro) values ('CLN 304', 2) ;
insert into endereco (endereco, bairro_idbairro) values ('QI 7', 3) ;
insert into endereco (endereco, bairro_idbairro) values ('QE 40', 3) ;
insert into endereco (endereco, bairro_idbairro) values ('QI 23', 3) ;
insert into endereco (endereco, bairro_idbairro) values ('Praca do Relogio', 4) ;
insert into endereco (endereco, bairro_idbairro) values ('Perto do metro', 4) ;
insert into endereco (endereco, bairro_idbairro) values ('Pistao Sul', 4) ;
insert into endereco (endereco, bairro_idbairro) values ('SMDB 17', 5) ;
insert into endereco (endereco, bairro_idbairro) values ('Perto do Gilberto Salomao', 5) ;
insert into endereco (endereco, bairro_idbairro) values ('Terceira Ponte', 5) ;
insert into endereco (endereco, bairro_idbairro) values ('CA 05', 6) ;
insert into endereco (endereco, bairro_idbairro) values ('Clube do Congresso', 6) ;
insert into endereco (endereco, bairro_idbairro) values ('Perto do Big Box', 6) ;
insert into endereco (endereco, bairro_idbairro) values ('Far Away', 7) ;
insert into endereco (endereco, bairro_idbairro) values ('Far Far Away', 7) ;
insert into endereco (endereco, bairro_idbairro) values ('Onde?', 7) ;
insert into endereco (endereco, bairro_idbairro) values ('CLSW 301', 8) ;
insert into endereco (endereco, bairro_idbairro) values ('CLSW 105', 8) ;
insert into endereco (endereco, bairro_idbairro) values ('CLSW 102', 8) ;
insert into endereco (endereco, bairro_idbairro) values ('Ja Existe?', 9) ;
insert into endereco (endereco, bairro_idbairro) values ('Pertinho de algum lugar', 9) ;
insert into endereco (endereco, bairro_idbairro) values ('Num predio novo', 9) ;
insert into endereco (endereco, bairro_idbairro) values ('SMPW 5', 10) ;
insert into endereco (endereco, bairro_idbairro) values ('SMPW 27', 10) ;
insert into endereco (endereco, bairro_idbairro) values ('SMPW 08', 10) ;
insert into endereco (endereco, bairro_idbairro) values ('Perto do estadio', 11) ;
insert into endereco (endereco, bairro_idbairro) values ('Perto da rodovia', 11) ;
insert into endereco (endereco, bairro_idbairro) values ('La longe', 11) ;
insert into endereco (endereco, bairro_idbairro) values ('Na esquina', 12) ;
insert into endereco (endereco, bairro_idbairro) values ('Na outra esquina', 12) ;
insert into endereco (endereco, bairro_idbairro) values ('QNR 08', 12) ;


-- Especialidade Medica
insert into especialidade_medica (nome_especialidade) values ('Pedriatria');
insert into especialidade_medica (nome_especialidade) values ('Ortopedia');
insert into especialidade_medica (nome_especialidade) values ('Implante Bionico');
insert into especialidade_medica (nome_especialidade) values ('Transplante de cerebro');
insert into especialidade_medica (nome_especialidade) values ('Fusao a frio');
insert into especialidade_medica (nome_especialidade) values ('Terapia do sono');
insert into especialidade_medica (nome_especialidade) values ('Cirurgia subaquatica');
insert into especialidade_medica (nome_especialidade) values ('Troca de oleo');
insert into especialidade_medica (nome_especialidade) values ('Remendo do estomago');
insert into especialidade_medica (nome_especialidade) values ('Tirar bicho de pe');


-- Categorias

insert into categoria (nome_categoria, faixa_de_peso) values ('Peso mosca masculino' , 'ate 58 kg' ) ; 	
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso leve masculino' , '58–68 kg') ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso medio masculino' ,'68–80 kg' ) ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso pesado masculino' , 'acima de 80 kg') ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso mosca feminino',  'ate 49 kg') ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso leve feminino',  '49–57 kg') ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso medio feminino' , '57–67 kg') ;
insert into categoria (nome_categoria, faixa_de_peso) values ('Peso pesado feminino', 'acima de 67 kg') ;


-- empresa_transporte
insert into empresa_transporte (nome_empresa) values('Busao Velho') ;
insert into empresa_transporte (nome_empresa) values('Caixote Express') ;
insert into empresa_transporte (nome_empresa) values('Carcaca Transportes') ;
insert into empresa_transporte (nome_empresa) values('Melhor Ir A Pe') ;
insert into empresa_transporte (nome_empresa) values('Rapidao da Emocao') ;
insert into empresa_transporte (nome_empresa) values('Clube dos Motoristas Insanos') ;
insert into empresa_transporte (nome_empresa) values('Suvaco Transportes') ;


-- etapa_da_competicao

insert into etapa_da_competicao (nome_etapa) values ('Eliminatorias') ;
insert into etapa_da_competicao (nome_etapa) values ('Oitavas de final') ;
insert into etapa_da_competicao (nome_etapa) values ('Quartas de Final') ;
insert into etapa_da_competicao (nome_etapa) values ('Semifinal') ;
insert into etapa_da_competicao (nome_etapa) values ('Final') ;
insert into etapa_da_competicao (nome_etapa) values ('Disputa terceiro Lugar') ;

-- hospital

insert into hospital (nome_hospital, endereco_idendereco) values ('Entra bom, sai ruim', 1) ;
insert into hospital (nome_hospital, endereco_idendereco) values ('Quase morte', 4) ;
insert into hospital (nome_hospital, endereco_idendereco) values ('Infeccao geral', 7) ;
insert into hospital (nome_hospital, endereco_idendereco) values ('Luz no fim do tunel', 10) ;
insert into hospital (nome_hospital, endereco_idendereco) values ('Va com Deus', 13) ;
insert into hospital (nome_hospital, endereco_idendereco) values ('Conserta um, estraga outro', 16);
insert into hospital (nome_hospital, endereco_idendereco) values ('Clinica das dores', 19) ;


-- locais de competicao

insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Pallet Arena', 2) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Vermilion Arena', 5) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Cinnabar Arena', 8) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Celadon Arena', 11) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Cerulean Arena', 14) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Safari Arena', 17) ;
insert into locais_de_competicao (nome_local, endereco_idendereco) values ('Unknown Dungeon Arena', 20) ;


-- restaurante
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Fat Gordices', 1, 3) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('El Cabron!', 2 , 6) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Xin Ling Express', 3 , 9) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Jaspion Sushi', 4, 12) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Oxi, Buchudo!', 5, 15) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Dead Bull', 6, 18) ;
insert into restaurante (nome_restaurante, tipo_culinaria_idtipo_culinaria, endereco_idendereco) values ('Pereba nos Beiço', 7, 21) ;


-- linha_de_transporte

insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('111', 1, '12:00', 1, 2) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('222', 2, '13:00', 2, 3) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('333', 3, '14:00', 3, 4) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('444', 4, '15:00', 4, 5) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('555', 5, '16:00', 5, 6) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('666', 6, '17:00', 6, 2) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('777', 1, '10:00', 3, 6) ;
insert into linhas_de_transporte (numero_linha, empresa_transporte_idempresa_transporte, horario_saida, id_bairro_chegada, id_bairro_saida) values ('888', 3, '08:00', 4, 1) ;


-- hospital_has_especialidade_medica

insert into hospital_has_especialidade_medica values (1, 1) ;
insert into hospital_has_especialidade_medica values (2, 2) ;
insert into hospital_has_especialidade_medica values (3, 3) ;
insert into hospital_has_especialidade_medica values (4, 4) ;
insert into hospital_has_especialidade_medica values (5, 5) ;
insert into hospital_has_especialidade_medica values (5, 1) ;
insert into hospital_has_especialidade_medica values (6, 2) ;
insert into hospital_has_especialidade_medica values (1, 4) ;
insert into hospital_has_especialidade_medica values (3, 6) ;
insert into hospital_has_especialidade_medica values (2, 5) ;
insert into hospital_has_especialidade_medica values (2, 6) ;

-- lutas

INSERT INTO `taekwondo`.`lutas` (`idlutas`, `id_atleta_vencedor`, `pontuacao_atleta1`, `pontuacao_atleta2`, `etapa_da_competicao_idetapa_da_competicao`, `atleta_idatleta2`, `atleta_idatleta1`, `duracao`, `categoria_idcategoria`, `locais_de_competicao_idlocais_de_competicao`)
 VALUES (NULL, '1', '7', '5', '5', '2', '1', '00:03:00', '1', '1');
 
 INSERT INTO `taekwondo`.`lutas` (`idlutas`, `id_atleta_vencedor`, `pontuacao_atleta1`, `pontuacao_atleta2`, `etapa_da_competicao_idetapa_da_competicao`, `atleta_idatleta2`, `atleta_idatleta1`, `duracao`, `categoria_idcategoria`, `locais_de_competicao_idlocais_de_competicao`) 
 VALUES (NULL, '3', '4', '2', '6', '4', '3', '00:02:51', '1', '2');
 
 INSERT INTO `taekwondo`.`lutas` (`idlutas`, `id_atleta_vencedor`, `pontuacao_atleta1`, `pontuacao_atleta2`, `etapa_da_competicao_idetapa_da_competicao`, `atleta_idatleta2`, `atleta_idatleta1`, `duracao`, `categoria_idcategoria`, `locais_de_competicao_idlocais_de_competicao`) 
VALUES (NULL, '2', '3', '1', '4', '3', '2', '00:04:20', '1', '4');

INSERT INTO `taekwondo`.`lutas` (`idlutas`, `id_atleta_vencedor`, `pontuacao_atleta1`, `pontuacao_atleta2`, `etapa_da_competicao_idetapa_da_competicao`, `atleta_idatleta2`, `atleta_idatleta1`, `duracao`, `categoria_idcategoria`, `locais_de_competicao_idlocais_de_competicao`) 
VALUES (NULL, '19', '5', '4', '1', '20', '19', '00:30:00', '4', '6');

INSERT INTO `taekwondo`.`lutas` (`idlutas`, `id_atleta_vencedor`, `pontuacao_atleta1`, `pontuacao_atleta2`, `etapa_da_competicao_idetapa_da_competicao`, `atleta_idatleta2`, `atleta_idatleta1`, `duracao`, `categoria_idcategoria`, `locais_de_competicao_idlocais_de_competicao`) 
VALUES (NULL, '16', '7', '2', '2', '21', '16', '00:01:15', '1', '3');

 