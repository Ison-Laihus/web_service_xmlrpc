//
// Created by lyk on 3/25/18.
//

#ifndef HOMEWORK_MYSQLMANAGER_H
#define HOMEWORK_MYSQLMANAGER_H

#include <mysql/mysql.h>
#include <iostream>
#include <vector>


class MysqlManager{
public:
    /*
     * Init MySQL
     * @param hosts:         Host IP address
     * @param userName:        Login UserName
     * @param password:        Login Password
     * @param dbName:        Database Name
     * @param port:                Host listen port number
     */
    MysqlManager(std::string hosts, std::string userName, std::string password, std::string dbName, unsigned int port);
    ~MysqlManager();
    void initConnection();
    /*
     * Making query from database
     * @param mysql:        MySQL Object
     * @param sql:                Running SQL command
     */
    bool runSQLCommand(std::string sql);
    /*
     * 执行插入语句
     * @param sql: 执行的SQL语句
     * @return: 受影响的行数
     */
    unsigned int insert(std::string sql);
    /**
     * Destroy MySQL object
     * @param mysql                MySQL object
     */
    void destroyConnection();
    bool getConnectionStatus();
    std::vector< std::vector<std::string> > getResult();
    /**
     * print result
     * @param result
     */
    void printResult(std::vector< std::vector<std::string> > result);
    unsigned int update(std::string sql);
    unsigned int deleteRecord(std::string sql);
protected:
    void setUserName(std::string userName);
    void setHosts(std::string hosts);
    void setPassword(std::string password);
    void setDBName(std::string dbName);
    void setPort(unsigned int port);
private:
    bool IsConnected;
    std::vector< std::vector<std::string> > resultList;
    MYSQL mySQLClient;
    unsigned int DEFAULTPORT;
    char * HOSTS;
    char * USERNAME;
    char * PASSWORD;
    char * DBNAME;
};

#endif //HOMEWORK_MYSQLMANAGER_H
