#include "DBManager.h"

DBManager::DBManager()
{
	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PWD);
	stmt = con->createStatement();
	stmt->execute("USE gamedb");
}


DBManager::~DBManager()
{
	delete stmt;
	delete con;
}
void DBManager::TestTable() {


}

//Funció per comprovar si el nom amb el que vol registrar-se un usuari ja existeix
bool DBManager::AltaCuenta(string name, string pwd) {
	ResultSet* rs = stmt->executeQuery(("select count(*) from UserAccounts where UserName = '" + name + "'").c_str());
	rs->next();
	int num = rs->getInt(1);
	delete rs;
	if (num == 0) //Em puc donar d'alta, ja que 0 significa que no existeix cap ususari amb el nom introduït
	{
		//Introduïm nom i contrassenya a la base de dades
		stmt->execute(("insert into UserAccounts (UserName, UserPwd, UserWins) values ('" + name + "', '" + pwd + "', '0')").c_str());
		cout << "User added" << endl;
		return true;
	}
	//El nom ja existeix
	cout << "User already exists" << endl;
	return false;
}

//Retorna true si l'ususari està registrat
bool DBManager::Login(string name, string pwd) {
	ResultSet* rs = stmt->executeQuery(("select count(*) from UserAccounts where UserName = '" + name + "' AND UserPwd = '" + pwd + "'").c_str());
	rs->next();
	int num = rs->getInt(1);
	if (num == 1) {
		cout << "Login OK!" << endl;
		return true;
	}
	cout << "Login failed!" << endl;
	return false;
}

bool DBManager::AddMatch(int idUser) {
	return false;
}

void DBManager::CloseSession() {

}
void DBManager::IncreaseGames(string name) {
	cout << "Seaching name" << endl;
	ResultSet* rs = stmt->executeQuery(("select count(*) from UserAccounts where UserName = '" + name + "'").c_str());
	rs->next();
	int num = rs->getInt(1);
	delete rs;
	if (num == 1)
	{
		cout << "Name found" << endl;
		stmt->execute(("update UserAccounts set UserGames = UserGames + '1' where UserName = '" + name + "'").c_str());
		cout << "Games updated" << endl;
	}
}

void DBManager::IncreaseWins(string name) {
	cout << "Seaching name" << endl;
	ResultSet* rs = stmt->executeQuery(("select count(*) from UserAccounts where UserName = '" + name + "'").c_str());
	rs->next();
	int num = rs->getInt(1);
	delete rs;
	if (num == 1)
	{
		cout << "Name found" << endl;
		stmt->execute(("update UserAccounts set UserWins = UserWins + '1' where UserName = '" + name + "'").c_str());
		cout << "Wins updated" << endl;
	}
}
