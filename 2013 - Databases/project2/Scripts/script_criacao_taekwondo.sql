SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP SCHEMA IF EXISTS `taekwondo` ;
CREATE SCHEMA IF NOT EXISTS `taekwondo` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `taekwondo` ;

-- -----------------------------------------------------
-- Table `taekwondo`.`pais`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`pais` (
  `idpais` INT NOT NULL AUTO_INCREMENT,
  `nome_pais` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idpais`),
  UNIQUE INDEX `idpais_UNIQUE` (`idpais` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`cidade`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`cidade` (
  `idcidade` INT NOT NULL AUTO_INCREMENT,
  `nome_cidade` VARCHAR(45) NOT NULL,
  `pais_idpais` INT NOT NULL,
  PRIMARY KEY (`idcidade`),
  UNIQUE INDEX `idcidade_UNIQUE` (`idcidade` ASC),
  INDEX `fk_cidade_pais_idx` (`pais_idpais` ASC),
  CONSTRAINT `fk_cidade_pais`
    FOREIGN KEY (`pais_idpais`)
    REFERENCES `taekwondo`.`pais` (`idpais`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`bairro`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`bairro` (
  `idbairro` INT NOT NULL AUTO_INCREMENT,
  `nome_bairro` VARCHAR(45) NOT NULL,
  `cidade_idcidade` INT NOT NULL,
  PRIMARY KEY (`idbairro`),
  UNIQUE INDEX `idbairro_UNIQUE` (`idbairro` ASC),
  INDEX `fk_bairro_cidade1_idx` (`cidade_idcidade` ASC),
  CONSTRAINT `fk_bairro_cidade1`
    FOREIGN KEY (`cidade_idcidade`)
    REFERENCES `taekwondo`.`cidade` (`idcidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`endereco`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`endereco` (
  `idendereco` INT NOT NULL AUTO_INCREMENT,
  `endereco` VARCHAR(105) NOT NULL,
  `bairro_idbairro` INT NOT NULL,
  PRIMARY KEY (`idendereco`),
  UNIQUE INDEX `idendereco_UNIQUE` (`idendereco` ASC),
  INDEX `fk_endereco_bairro1_idx` (`bairro_idbairro` ASC),
  CONSTRAINT `fk_endereco_bairro1`
    FOREIGN KEY (`bairro_idbairro`)
    REFERENCES `taekwondo`.`bairro` (`idbairro`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`locais_de_competicao`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`locais_de_competicao` (
  `idlocais_de_competicao` INT NOT NULL AUTO_INCREMENT,
  `nome_local` VARCHAR(60) NOT NULL,
  `endereco_idendereco` INT NOT NULL,
  PRIMARY KEY (`idlocais_de_competicao`),
  UNIQUE INDEX `idlocais_de_competicao_UNIQUE` (`idlocais_de_competicao` ASC),
  INDEX `fk_locais_de_competicao_endereco1_idx` (`endereco_idendereco` ASC),
  CONSTRAINT `fk_locais_de_competicao_endereco1`
    FOREIGN KEY (`endereco_idendereco`)
    REFERENCES `taekwondo`.`endereco` (`idendereco`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`tipo_culinaria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`tipo_culinaria` (
  `idtipo_culinaria` INT NOT NULL AUTO_INCREMENT,
  `tipo_culinaria` VARCHAR(60) NOT NULL,
  PRIMARY KEY (`idtipo_culinaria`),
  UNIQUE INDEX `idtipo_culinaria_UNIQUE` (`idtipo_culinaria` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`restaurante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`restaurante` (
  `idrestaurante` INT NOT NULL AUTO_INCREMENT,
  `nome_restaurante` VARCHAR(45) NOT NULL,
  `tipo_culinaria_idtipo_culinaria` INT NOT NULL,
  `endereco_idendereco` INT NOT NULL,
  PRIMARY KEY (`idrestaurante`),
  UNIQUE INDEX `idrestaurante_UNIQUE` (`idrestaurante` ASC),
  INDEX `fk_restaurante_tipo_culinaria1_idx` (`tipo_culinaria_idtipo_culinaria` ASC),
  INDEX `fk_restaurante_endereco1_idx` (`endereco_idendereco` ASC),
  CONSTRAINT `fk_restaurante_tipo_culinaria1`
    FOREIGN KEY (`tipo_culinaria_idtipo_culinaria`)
    REFERENCES `taekwondo`.`tipo_culinaria` (`idtipo_culinaria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_restaurante_endereco1`
    FOREIGN KEY (`endereco_idendereco`)
    REFERENCES `taekwondo`.`endereco` (`idendereco`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`especialidade_medica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`especialidade_medica` (
  `idespecialidade_medica` INT NOT NULL AUTO_INCREMENT,
  `nome_especialidade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idespecialidade_medica`),
  UNIQUE INDEX `idespecialidade_medica_UNIQUE` (`idespecialidade_medica` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`hospital`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`hospital` (
  `idhospital` INT NOT NULL AUTO_INCREMENT,
  `nome_hospital` VARCHAR(45) NOT NULL,
  `endereco_idendereco` INT NOT NULL,
  PRIMARY KEY (`idhospital`),
  UNIQUE INDEX `idhospital_UNIQUE` (`idhospital` ASC),
  INDEX `fk_hospital_endereco1_idx` (`endereco_idendereco` ASC),
  CONSTRAINT `fk_hospital_endereco1`
    FOREIGN KEY (`endereco_idendereco`)
    REFERENCES `taekwondo`.`endereco` (`idendereco`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`hospital_has_especialidade_medica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`hospital_has_especialidade_medica` (
  `hospital_idhospital` INT NOT NULL,
  `especialidade_medica_idespecialidade_medica` INT NOT NULL,
  PRIMARY KEY (`hospital_idhospital`, `especialidade_medica_idespecialidade_medica`),
  INDEX `fk_hospital_has_especialidade_medica_especialidade_medica1_idx` (`especialidade_medica_idespecialidade_medica` ASC),
  INDEX `fk_hospital_has_especialidade_medica_hospital1_idx` (`hospital_idhospital` ASC),
  CONSTRAINT `fk_hospital_has_especialidade_medica_hospital1`
    FOREIGN KEY (`hospital_idhospital`)
    REFERENCES `taekwondo`.`hospital` (`idhospital`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_hospital_has_especialidade_medica_especialidade_medica1`
    FOREIGN KEY (`especialidade_medica_idespecialidade_medica`)
    REFERENCES `taekwondo`.`especialidade_medica` (`idespecialidade_medica`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`empresa_transporte`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`empresa_transporte` (
  `idempresa_transporte` INT NOT NULL AUTO_INCREMENT,
  `nome_empresa` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idempresa_transporte`),
  UNIQUE INDEX `idempresa_transporte_UNIQUE` (`idempresa_transporte` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`linhas_de_transporte`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`linhas_de_transporte` (
  `idlinha` INT NOT NULL AUTO_INCREMENT,
  `numero_linha` VARCHAR(5) NOT NULL,
  `empresa_transporte_idempresa_transporte` INT NOT NULL,
  `horario_saida` TIME NOT NULL,
  `id_bairro_chegada` INT NOT NULL,
  `id_bairro_saida` INT NOT NULL,
  PRIMARY KEY (`idlinha`),
  UNIQUE INDEX `idlinha_UNIQUE` (`idlinha` ASC),
  INDEX `fk_linhas_de_transporte_empresa_transporte1_idx` (`empresa_transporte_idempresa_transporte` ASC),
  INDEX `fk_linhas_de_transporte_bairro1_idx` (`id_bairro_chegada` ASC),
  INDEX `fk_linhas_de_transporte_bairro2_idx` (`id_bairro_saida` ASC),
  CONSTRAINT `fk_linhas_de_transporte_empresa_transporte1`
    FOREIGN KEY (`empresa_transporte_idempresa_transporte`)
    REFERENCES `taekwondo`.`empresa_transporte` (`idempresa_transporte`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_linhas_de_transporte_bairro1`
    FOREIGN KEY (`id_bairro_chegada`)
    REFERENCES `taekwondo`.`bairro` (`idbairro`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_linhas_de_transporte_bairro2`
    FOREIGN KEY (`id_bairro_saida`)
    REFERENCES `taekwondo`.`bairro` (`idbairro`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`categoria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`categoria` (
  `idcategoria` INT NOT NULL AUTO_INCREMENT,
  `nome_categoria` VARCHAR(45) NOT NULL,
  `faixa_de_peso` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idcategoria`),
  UNIQUE INDEX `idcategoria_UNIQUE` (`idcategoria` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`atleta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`atleta` (
  `idatleta` INT NOT NULL AUTO_INCREMENT,
  `nome_atleta` VARCHAR(45) NOT NULL,
  `sobrenome_atleta` VARCHAR(45) NOT NULL,
  `idade_atleta` INT NOT NULL,
  `peso_atleta` FLOAT NOT NULL,
  `foto_atleta` LONGBLOB NULL,
  `pais_idpais` INT NOT NULL,
  `sexo` CHAR(1) NOT NULL,
  `imgtype` VARCHAR(200) NULL ,
  PRIMARY KEY (`idatleta`),
  UNIQUE INDEX `idatleta_UNIQUE` (`idatleta` ASC),
  INDEX `fk_atleta_pais1_idx` (`pais_idpais` ASC),
  CONSTRAINT `fk_atleta_pais1`
    FOREIGN KEY (`pais_idpais`)
    REFERENCES `taekwondo`.`pais` (`idpais`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = innoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`etapa_da_competicao`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`etapa_da_competicao` (
  `idetapa_da_competicao` INT NOT NULL AUTO_INCREMENT,
  `nome_etapa` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idetapa_da_competicao`),
  UNIQUE INDEX `idtipo_competicao_UNIQUE` (`idetapa_da_competicao` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `taekwondo`.`lutas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `taekwondo`.`lutas` (
  `idlutas` INT NOT NULL AUTO_INCREMENT,
  `id_atleta_vencedor` INT NOT NULL,
  `pontuacao_atleta1` INT NOT NULL,
  `pontuacao_atleta2` INT NOT NULL,
  `etapa_da_competicao_idetapa_da_competicao` INT NOT NULL,
  `atleta_idatleta2` INT NOT NULL,
  `atleta_idatleta1` INT NOT NULL,
  `duracao` TIME NOT NULL,
  `categoria_idcategoria` INT NOT NULL,
  `locais_de_competicao_idlocais_de_competicao` INT NOT NULL,
  PRIMARY KEY (`idlutas`),
  UNIQUE INDEX `idlutas_UNIQUE` (`idlutas` ASC),
  INDEX `fk_lutas_etapa_da_competicao1_idx` (`etapa_da_competicao_idetapa_da_competicao` ASC),
  INDEX `fk_lutas_atleta1_idx` (`atleta_idatleta2` ASC),
  INDEX `fk_lutas_atleta2_idx` (`atleta_idatleta1` ASC),
  INDEX `fk_lutas_categoria1_idx` (`categoria_idcategoria` ASC),
  INDEX `fk_lutas_locais_de_competicao1_idx` (`locais_de_competicao_idlocais_de_competicao` ASC),
  CONSTRAINT `fk_lutas_etapa_da_competicao1`
    FOREIGN KEY (`etapa_da_competicao_idetapa_da_competicao`)
    REFERENCES `taekwondo`.`etapa_da_competicao` (`idetapa_da_competicao`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
	CONSTRAINT `fk_atleta_vencedor`
    FOREIGN KEY (`id_atleta_vencedor`)
    REFERENCES `taekwondo`.`atleta` (`idatleta`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_lutas_atleta1`
    FOREIGN KEY (`atleta_idatleta1`)
    REFERENCES `taekwondo`.`atleta` (`idatleta`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_lutas_atleta2`
    FOREIGN KEY (`atleta_idatleta2`)
    REFERENCES `taekwondo`.`atleta` (`idatleta`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_lutas_categoria1`
    FOREIGN KEY (`categoria_idcategoria`)
    REFERENCES `taekwondo`.`categoria` (`idcategoria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_lutas_locais_de_competicao1`
    FOREIGN KEY (`locais_de_competicao_idlocais_de_competicao`)
    REFERENCES `taekwondo`.`locais_de_competicao` (`idlocais_de_competicao`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

CREATE USER 'taekwondouser'@'localhost' IDENTIFIED BY  'taekwondopw';
GRANT ALL PRIVILEGES ON  `taekwondo` . * TO  'taekwondouser'@'localhost';

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
