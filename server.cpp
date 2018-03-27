//
// Created by lyk on 3/24/18.
//

#define WIN32_LEAN_AND_MEAN  /* required by xmlrpc-c/server_abyss.hpp */

#include <cassert>
#include <stdexcept>
#include <iostream>
#ifdef _WIN32
#  include <windows.h>
#else
#  include <unistd.h>
#endif

using namespace std;

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#include "Services.h"



int main(int const, const char ** const) {

    try {
        xmlrpc_c::registry myRegistry;

        // sampleAdd
        xmlrpc_c::methodPtr const sampleAddMethodP(new sampleAddMethod);
        myRegistry.addMethod("sample.add", sampleAddMethodP);
        // getAllUser
        xmlrpc_c::methodPtr const getAllUserMethodP(new getAllUserMethod);
        myRegistry.addMethod("get.all.user", getAllUserMethodP);
        // getOneUser
        xmlrpc_c::methodPtr const getOneUserMethodP(new getOneUserMethod);
        myRegistry.addMethod("get.one.user", getOneUserMethodP);
        // addUser
        xmlrpc_c::methodPtr const addUserMethodP(new addUserMethod);
        myRegistry.addMethod("add.user", addUserMethodP);
        // updateUser
        xmlrpc_c::methodPtr const updateUserMethodP(new updateUserMethod);
        myRegistry.addMethod("update.user", updateUserMethodP);
        // deleteUser
        xmlrpc_c::methodPtr const deleteUserMethodP(new deleteUserMethod);
        myRegistry.addMethod("delete.user", deleteUserMethodP);


        xmlrpc_c::serverAbyss myAbyssServer(
                xmlrpc_c::serverAbyss::constrOpt()
                        .registryP(&myRegistry)
                        .portNumber(8080));

        myAbyssServer.run();
        // xmlrpc_c::serverAbyss.run() never returns
        assert(false);
    } catch (exception const& e) {
        cerr << "Something failed.  " << e.what() << endl;
    }
    return 0;
}