#pragma once
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

class ConnexioBD
{
    private:
        sql::mysql::MySQL_Driver* driver = NULL;
        sql::Connection* con = NULL;
        sql::Statement* stmt = NULL;

    public:
        ConnexioBD() {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
            con->setSchema("nom_base_dades");
            stmt = con->createStatement();
        }

        ~ConnexioBD() {
            sql::mysql::MySQL_Driver* driver = NULL;
            sql::Connection* con = NULL;
            sql::Statement* stmt = NULL;
        }

        sql::ResultSet* execQuery(string sql) {
            return stmt->executeQuery(sql);
        }

        void exec(string sql){
            stmt->execute(sql);
        }


        sql::Connection* getCon() {
            return con;
        }

        sql::Statement* getStmt() {
            return stmt;
        }
};

