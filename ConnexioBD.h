#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
using namespace std;

class ConnexioBD
{
    private:
        sql::mysql::MySQL_Driver* driver = NULL;
        sql::Connection* con = NULL;
        sql::Statement* stmt = NULL;

    public:
        ConnexioBD() {
            if (con == NULL){
                map<string, string> config;
                ifstream file("configuracio.txt");

                if (!file.is_open()) {
                    cout << "Error: No se ha podido abrir el .txt" << endl;
                    return;
                }

                string line;
                while (getline(file, line)) {
                    if (line.empty()) continue;
                    istringstream iss(line);
                    string key, value;
                    if (getline(iss, key, '=') && getline(iss, value)) {
                        config[key] = value;
                    }
                }
                file.close();

                string host = config["host"];
                string user = config["user"];
                string password = config["password"];
                string database = config["database"];


                driver = sql::mysql::get_mysql_driver_instance();
                con = driver->connect(host, user, password);
                con->setSchema(database);
                stmt = con->createStatement();
            }
        }

        ~ConnexioBD() {
            if (con) {
                con->close();
            }
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

