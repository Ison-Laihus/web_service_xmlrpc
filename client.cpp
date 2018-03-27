//
// Created by lyk on 3/24/18.
//

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>

using namespace std;

int main(int argc, char **argv) {

    string const serverUrl("http://localhost:8080/RPC2");
    string const methodName("sample.add");
    string const methodName2("get.all.user");
    string const methodName3("get.one.user");
    string const methodName4("add.user");
    string const methodName5("update.user");
    string const methodName6("delete.user");

    xmlrpc_c::clientSimple myClient;

    string choice;
    do {
        cout << "The first test is calculating two integer, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        // sample.add
        xmlrpc_c::value result;
        myClient.call(serverUrl, methodName, "ii", &result, 5, 7);
        int const sum((xmlrpc_c::value_int(result)));
        cout << "\033[32mResult of RPC (sum of 5 and 7): " << sum << "\033[0m" << endl << endl;
    }

    do {
        cout << "The second test is getting all users from table user, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        // get.all.user
        xmlrpc_c::value result2;
        myClient.call(serverUrl, methodName2, "", &result2);
        cout << "\033[32mResult of RPC (getAllUser): " << endl;
        for ( auto &ve : ((xmlrpc_c::value_array)result2).vectorValueValue() ) {
            for ( auto &v : ((xmlrpc_c::value_array)ve).vectorValueValue() ) {
                string const value((xmlrpc_c::value_string(v)));
                cout << value << "\t";
            }
            cout << endl;
        }
        cout << "\033[0m" << endl;
    }

    do {
        cout << "The third test is getting one user from table user, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        // get.one.user
        xmlrpc_c::value result3;
        myClient.call(serverUrl, methodName3, "i", &result3, 1);
        cout << "\033[32mResult of RPC (getOneUser): " << endl;
        for ( auto &ve : ((xmlrpc_c::value_array)result3).vectorValueValue() ) {
            string const value((xmlrpc_c::value_string(ve)));
            cout << value << "\t";
        }
        cout << "\033[0m" << endl << endl;
    }

    do {
        cout << "The fourth test is adding user information to table user, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        // add.user
        xmlrpc_c::value result4;
        myClient.call(serverUrl, methodName4, "sis", &result4, "zhangsan", 14, "male");
        cout << "\033[32mResult of RPC (addUser): ";
        if ( (xmlrpc_c::value_boolean)result4 ) {
            cout << "\033[0m\033[34madd successfully\033[0m\033[32m" << endl;
        } else {
            cout << "\033[0m\033[31madd unsuccessfully\033[0m\033[32m" << endl;
        }
        cout << "\033[0m" << endl;
    }

    do {
        cout << "The fifth test is updating user information in table user, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        //updateUser
        xmlrpc_c::value result5;
        myClient.call(serverUrl, methodName5, "ssi", &result5, "name", "mingming", 11);
        cout << "\033[32mResult of RPC (updateUser): ";
        if ( (xmlrpc_c::value_boolean)result5 ) {
            cout << "\033[0m\033[34mupdate successfully\033[0m\033[32m" << endl;
        } else {
            cout << "\033[0m\033[31mupdate unsuccessfully\033[0m\033[32m" << endl;
        }
        cout << "\033[0m" << endl;
    }


    do {
        cout << "The sixth test is deleting user information in table user, do you want to test it (Y/N): ";
        cin >> choice;
    } while(choice!="Y" && choice!="y" && choice!="N" && choice!="n");

    if (choice=="Y" || choice=="y") {
        //deleteUser
        xmlrpc_c::value result6;
        myClient.call(serverUrl, methodName6, "i", &result6, 11);
        cout << "\033[32mResult of RPC (deleteUser): ";
        if ( (xmlrpc_c::value_boolean)result6 ) {
            cout << "\033[0m\033[34mdelete successfully\033[0m\033[32m" << endl;
        } else {
            cout << "\033[0m\033[31mdelete unsuccessfully\033[0m\033[32m" << endl;
        }
        cout << "\033[0m" << endl;
    }

    cout << "\033[36mTesting finished\033[0m" << endl;


    return 0;
}