//
// Created by lyk on 3/26/18.
//

#ifndef HOMEWORK_USEROPERATION_H
#define HOMEWORK_USEROPERATION_H

#include <iostream>
#include <vector>
#include "MysqlManager.h"

class UserOperation{
public:
    UserOperation();
    ~UserOperation();
    /**
     * add one record to table user
     * @param name
     * @param age
     * @param sex
     * @return if success
     */
    bool addUser(const std::string name, const int age, const std::string sex);
    /**
     * get all users' information
     * @return information list
     */
    std::vector<std::vector<std::string> > getAllUser();
    /**
     * update user info according id
     * @param field
     * @param value
     * @param id
     * @return is success
     */
    bool updateUser(const std::string field, const std::string value, const int id);
    /**
     * get user info according given id
     * @param id
     * @return user info
     */
    std::vector<std::string> getOneUser(const int id);
    /**
     * delete one user record in user table
     * @param id
     * @return if success
     */
    bool deleteUser(const int id);

private:
    static std::string host;
    static std::string user;
    static std::string pwd;
    static std::string db;
    static int port;
    MysqlManager *mm;

};

#endif //HOMEWORK_USEROPERATION_H
