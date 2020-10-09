#include <stdio.h>
#include <stdlib.h>
/*#include <sqlite3.h> */

static int callback(void *NotUsed, int argc,  char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("person.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE PERSON("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \ ");";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   
    /* Create SQL statement */
   sql = "INSERT INTO PERSON (ID,NAME,AGE) "  \
         "VALUES (1, 'Paul', 12); " \
         "INSERT INTO PERSON (ID,NAME,AGE) "  \
         "VALUES (2, 'Allens', 25 ); "     \
         "INSERT INTO PERSON (ID,NAME,AGE)" \
         "VALUES (3, 'Tessy', 23 );" \
         "INSERT INTO PERSON (ID,NAME,AGE)" \
         "VALUES (4, 'Mark', 25);";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
    /* Create merged SQL statement */
   sql = "SELECT count(*) from PERSON where AGE>=18; " \
         "SELECT * from PERSON";

   sqlite3_close(db);
   return 0;
}
