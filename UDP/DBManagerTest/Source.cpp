#include <mysql_connection.h>
#include <cppconn\driver.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <cppconn\exception.h>
#include "DBManagerT.h"

int main()
{
	DBManager* dbM = new DBManager();

	//dbM->TestTable();

	//dbM->AltaCuenta("Joan", "linux123");
	//dbM->Login("Miquel", "linux1234");
	//dbM->IncreaseWins("Arnau");
	//dbM->BeginSession("Arnau");
	//dbM->Login("Ripoll", "123");
	getchar();
}