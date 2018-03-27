//
// Created by lyk on 3/26/18.
//

#include <iostream>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#include "UserOperation.h"

#ifdef _WIN32
#define SLEEP(seconds) SleepEx(seconds * 1000);
#else
#define SLEEP(seconds) sleep(seconds);
#endif

using namespace std;

class sampleAddMethod : public xmlrpc_c::method {
public:
    sampleAddMethod() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:ii";
        // method's result and two arguments are integers
        this->_help = "This method adds two integers together";
    }
    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value *   const  retvalP) {

        int const addend(paramList.getInt(0));
        int const adder(paramList.getInt(1));

        paramList.verifyEnd(2);

        *retvalP = xmlrpc_c::value_int(addend + adder);

        // Sometimes, make it look hard (so client can see what it's like
        // to do an RPC that takes a while).
        if (adder == 1)
            SLEEP(2);
    }
};

class getAllUserMethod : public xmlrpc_c::method {
public:
    getAllUserMethod() {
        this->_signature = "i:ii";
        this->_help = "";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value * const retvalP) {
        UserOperation *uo = new UserOperation();
        vector<vector<string> > result = uo->getAllUser();
        vector<xmlrpc_c::value> arr;
        for ( auto &res : result ) {
            vector<xmlrpc_c::value> ar;
            for ( auto &r : res ) {
                ar.emplace_back(xmlrpc_c::value_string(r));
            }
            xmlrpc_c::value_array x_ar(ar);
            arr.emplace_back(x_ar);
        }
        xmlrpc_c::value_array x_arr(arr);
        *retvalP = xmlrpc_c::value_array(x_arr);
        delete uo;
    }
};

class getOneUserMethod : public xmlrpc_c::method {
public:
    getOneUserMethod() {
        this->_signature = "i:ii";
        this->_help = "";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value * const retvalP) {
        int const id(paramList.getInt(0));
        UserOperation *uo = new UserOperation();
        vector<string>  result = uo->getOneUser(id);
        vector<xmlrpc_c::value> arr;
        for ( auto &res : result ) {
            arr.emplace_back(xmlrpc_c::value_string(res));
        }
        xmlrpc_c::value_array x_arr(arr);
        *retvalP = xmlrpc_c::value_array(x_arr);
        delete uo;
    }
};

class addUserMethod : public xmlrpc_c::method {
public:
    addUserMethod() {
        this->_signature = "i:ii";
        this->_help = "";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value * const retvalP) {
        string const name(paramList.getString(0));
        int const age(paramList.getInt(1));
        string const sex(paramList.getString(2));
        UserOperation *uo = new UserOperation();
        bool res = uo->addUser(name, age, sex);
        *retvalP = xmlrpc_c::value_boolean(res);
        delete uo;
    }
};

class updateUserMethod : public xmlrpc_c::method {
public:
    updateUserMethod() {
        this->_signature = "i:ii";
        this->_help = "";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value * const retvalP) {
        string const field(paramList.getString(0));
        string const value(paramList.getString(1));
        int const id(paramList.getInt(2));
        UserOperation *uo = new UserOperation();
        bool res = uo->updateUser(field, value, id);
        *retvalP = xmlrpc_c::value_boolean(res);
        delete uo;
    }
};

class deleteUserMethod : public xmlrpc_c::method {
public:
    deleteUserMethod() {
        this->_signature = "i:ii";
        this->_help = "";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value * const retvalP) {
        int const id(paramList.getInt(0));
        UserOperation *uo = new UserOperation();
        bool res = uo->deleteUser(id);
        *retvalP = xmlrpc_c::value_boolean(res);
        delete uo;
    }
};