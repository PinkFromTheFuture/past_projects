<?php
	define( '_JEXEC', 1 );
	define( 'DS', DIRECTORY_SEPARATOR );
	define('JPATH_BASE', dirname(__FILE__).DS."..".DS.".." ); //alterar o numero de ".." aqui caso mude de diretorio

require_once('../../configuration.php');
require_once ( JPATH_BASE .DS.'includes'.DS.'defines.php' );
require_once ( JPATH_BASE .DS.'includes'.DS.'framework.php' );
require_once ( JPATH_BASE .DS.'libraries'.DS.'joomla'.DS.'factory.php' );

$user = $_POST['username'];
$pw = $_POST['password'];

/* Create the Application */
@$mainframe =& JFactory::getApplication('site');
jimport('joomla.plugin.helper');

$credentials = array();
$credentials['username'] = JRequest::getVar('username', '', 'method', 'username');
$credentials['password'] = JRequest::getVar('passwd', '', 'method', 'passwd');
$credentials['username'] = $user;
$credentials['password'] = $pw;

//preform the login action
$error = $mainframe->login($credentials);
$user = JFactory::getUser();
//now you are log in

//$mainframe->logout();
//now you are log out
		//die;	
	

		echo "<h2>Bem vindo, ". $user->name."</h2>";


?>



