#include <iostream>
#include <string>
#include <sstream>

#include "TreeDB.h"
#include "DBentry.h"
#include "TreeNode.h"

//no global variables
using namespace std;

int main() {
    string line, command, name, status;
    unsigned int IPaddress;
    bool active;
    cout << "> ";
    getline(cin, line);

    TreeDB* tree; //contains root that point to top of tree

    while (!cin.eof()) {
        stringstream ss(line);
        ss >> command;

        if (command == "insert") {
            ss >> name >> IPaddress >> status;

            //if user indicated the DBentry active, set active to true
            if (status == "active") {
                active = true;
            } else {
                active = false;
            }

            DBentry* temp = new DBentry(name, IPaddress, active);
            if (tree->insert(temp)) { //returns true if unique key and inserts node
                cout << "Success" << endl;
            } else {
                cout << "Error: entry already exists" << endl;
                delete temp;
            }
        }
        if (command == "find") {
            ss >> name;
            if ((tree->find(name)) != NULL) {
                if ((tree->find(name))->getActive() == true) {
                    status = "active";
                } else {
                    status = "inactive";
                }
                cout << (tree->find(name))->getName() << " : " << (tree->find(name))->getIPaddress() << " : " << status << endl;
            } else {
                cout << "Error: entry does not exist" << endl;
            }
        }

        if (command == "remove") {
            ss >> name;
            if (tree->remove(name) == true)
                cout << "Success" << endl;
            else
                cout << "Error: entry does not exist" << endl;
        }


        if (command == "printall") {

        }

        if (command == "printprobes") {

        }

        if (command == "removeall") {

        }

        if (command == "countactive") {

        }

        if (command == "updatestatus") {
            ss >> name >> status;
            if ((tree->find(name)) != NULL) {
                if (status == "active") {
                    active = true;
                } else {
                    active = false;
                }
                (tree->find(name))->setActive(active);
                cout << "Success" << endl;
            } else {
                cout << "Error: entry does not exist" << endl;
            }
        }
        cout << "> ";
        getline(cin, line);
    }
    return 0;
}

