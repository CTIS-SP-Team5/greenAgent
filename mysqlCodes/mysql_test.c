#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "mysql.h"
//#include <mysql/mysql.h>


MYSQL *mysql;
MYSQL_RES *results;
MYSQL_ROW record;

static char *server_options[] = {"mysql_test", "--defaults-file=my.cnf"};
int num_elements = sizeof(server_options) / sizeof(char *);

static char *server_groups[] = {"libmysqd_server", "libmysqd_client"};

int main(void)
{
   mysql_server_init(num_elements, server_options, server_groups);
   mysql = mysql_init(NULL);

   mysql_options(mysql, MYSQL_READ_DEFAULT_GROUP, "libmysqld_client");
   mysql_options(mysql, MYSQL_OPT_USE_EMBEDDED_CONNECTION, NULL);

   mysql_real_connect(mysql, "hostnameHere","userNameHere","userPasswordHere", "bookstore", 0,"PortNumberHere",0);
   mysql_options(mysql, MYSQL_SET_CLIENT_IP, "10.1.1.2");

   mysql_query(mysql, "insertSQLstatementHere");

   results = mysql_store_result(mysql);

   while((record = mysql_fetch_row(results))) {
      printf("%s - %s \n", record[0], record[1]);
   }

   mysql_free_result(results);
   mysql_close(mysql);
   mysql_server_end();

   return 0;
}
