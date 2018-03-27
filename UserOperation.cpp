//
// Created by lyk on 3/26/18.
//
#include <iostream>
#include "UserOperation.h"
#include "MysqlManager.h"

using namespace std;

string UserOperation::host = "localhost";
string UserOperation::user = "root";
string UserOperation::pwd = "lyk";
string UserOperation::db = "test_xmlrpc";
int UserOperation::port = 3306;

UserOperation::UserOperation() {
    mm = new MysqlManager(host, user, pwd, db, port);
    mm->initConnection();
}

UserOperation::~UserOperation() {
    mm->destroyConnection();
    delete mm;
}

bool UserOperation::addUser(const string name, const int age, const string sex) {
    if ( name.empty() || !age || sex.empty() ) {
        cout << "none of name, age, sex can be empty" << endl;
    }
    if ( sex != "female" && sex != "male" ) {
        cout << "the value of sex is not available" << endl;
    }
    string sql = "INSERT INTO `user` VALUES(0, '" + name + "', " + to_string(age) + ", '" + sex + "')";

    unsigned int res = mm->insert(sql);
    if ( res ) {
        return true;
    } else {
        return false;
    }

}

vector<vector<string>> UserOperation::getAllUser() {
    const string sql = "select * from user";
    mm->runSQLCommand(sql);
    vector<vector<string>> result = mm->getResult();
    return result;
}

bool UserOperation::updateUser(const string field, const string value, const int id) {
    string sql = "UPDATE `user` SET " + field + " = ";
    if ( field == "age" ) {
        sql += "" + value + "";
    } else {
        sql += "'" + value + "'";
    }
    sql += " WHERE id = " + to_string(id);
    unsigned int res = mm->update(sql);
    if ( res ) {
        return true;
    } else {
        return false;
    }
}

vector<string> UserOperation::getOneUser(const int id) {
    string sql = "SELECT * FROM `user` WHERE id = " + to_string(id);
    mm->runSQLCommand(sql);
    vector<vector<string>> result = mm->getResult();
    vector<string> res = result[0];
    return res;
}

bool UserOperation::deleteUser(const int id) {
    string sql = "DELETE FROM `user` WHERE id = " + to_string(id);
    unsigned int res = mm->deleteRecord(sql);
    if ( res ) {
        return true;
    } else {
        return false;
    }
}