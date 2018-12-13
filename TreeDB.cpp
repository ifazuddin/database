#include "TreeDB.h"
#include "TreeNode.h"

// the default constructor, creates an empty database.

TreeDB::TreeDB() {
    root = NULL;
    probesCount = 0;
}

// the destructor, deletes all the entries in the database.

TreeDB::~TreeDB() {
    
}

// inserts the entry pointed to by newEntry into the database.
// If an entry with the same key as newEntry's exists
// in the database, it returns false. Otherwise, it returns true.

bool TreeDB::insert(DBentry* newEntry) {
    if (root == NULL) { //if first entry
        TreeNode* temp = new TreeNode(newEntry);
        root = temp; //points root to new TreeNode
        return true;
    }
    if (find(newEntry->getName()) != NULL) { //if database has entry with same name, then cannot insert new node
        return false;
    } else {
        insertNode(newEntry);
        return true;
    }
}

void TreeDB::insertNode(DBentry* newEntry) {
    TreeNode* temp;
    temp = root;
    bool nodeInserted; //breaks loop when node isinserted

    nodeInserted = false;

    while (nodeInserted == false) {
        if (newEntry->getName() > (temp->getEntry())->getName()) {
            if ((temp->getRight()) != NULL) {
                temp = temp->getRight();
            } else {
                TreeNode* newTreeNode = new TreeNode(newEntry);
                temp->setRight(newTreeNode);
                nodeInserted = true;
            }
        }
        if (newEntry->getName() < (temp->getEntry())->getName()) {
            if ((temp->getLeft()) != NULL) {
                temp = temp->getLeft();
            } else {
                TreeNode* newTreeNode = new TreeNode(newEntry);
                temp->setLeft(newTreeNode);
                nodeInserted = true;
            }
        }
    }
}


// searches the database for an entry with a key equal to name.
// If the entry is found, a pointer to it is returned.
// If the entry is not found, the NULL pointer is returned.
// Also sets probesCount

DBentry* TreeDB::find(string name) {
    TreeNode* temp;
    temp = root;

    while (temp != NULL) {
        if (name == (temp->getEntry())->getName()) {
            return (temp->getEntry());
            break;
        }
        if (name > (temp->getEntry())->getName()) {
            if ((temp->getRight()) == NULL) {
                temp = temp->getRight();
                return NULL;
                break;
            }
            if ((temp->getRight()) != NULL) {
                temp = temp->getRight();
            }
        }
        if (name < (temp->getEntry())->getName()) {
            if ((temp->getLeft()) == NULL) {
                temp = temp->getRight();
                return NULL;
                break;
            }
            if ((temp->getLeft()) != NULL) {
                temp = temp->getLeft();
            }
        }
    }
}


// deletes the entry with the specified name (key) from the database.
// If the entry was indeed in the database, it returns true.
// Returns false otherwise.
// See Section 6 for the *required* removal method so you match
// exercise’s output.

bool TreeDB::remove(string name) {
    TreeNode* temp = getNode(name); //locates node if exists
    TreeNode* _left;
    TreeNode* _right; 
    TreeNode* cur;
    
    if (temp == NULL){ //if object does not exist
        return false;
    }
    else {
        if (temp->getRight() == NULL && temp->getLeft() == NULL){ //if node has no children
            delete temp;
            return true;
        }
        else if (temp->getRight() == NULL && temp->getLeft() != NULL){ //if node has 1 child on left
            _left = temp->getLeft();
            cur = temp;
            temp = _left; //check
            delete cur;
            return true;
        }
        else if (temp->getRight() != NULL && temp->getLeft() == NULL){ //if node has 1 child on right
            _right = temp->getRight();
            cur = temp;
            temp = _right; //check
            delete cur;
            return true;
        }
             
    }
    
    

}

// deletes all the entries in the database.

void TreeDB::clear() {

}
// prints the number of probes stored in probesCount

void TreeDB::printProbes() const {

}
// computes and prints out the total number of active entries
// in the database (i.e. entries with active==true).

void TreeDB::countActive() const {

}

// Prints the entire tree, in ascending order of key/name
// The entries are printed one per line, using the
// operator<< for DBentry.
// friend TreeDB::ostream& operator<<(ostream& out, const TreeDB& rhs) {}



// You *may* choose to implement the function below to help print the
// tree. You do not have to implement this function if you do not wish to.
//ostream& operator<<( ostream& out, TreeNode* rhs ) ;

TreeNode* TreeDB::getNode(string name){
    TreeNode* temp;
    temp = root;

    while (temp != NULL) {
        if (name == (temp->getEntry())->getName()) {
            return temp;
            break;
        }
        if (name > (temp->getEntry())->getName()) {
            if ((temp->getRight()) == NULL) {
                temp = temp->getRight();
                return NULL;
                break;
            }
            if ((temp->getRight()) != NULL) {
                temp = temp->getRight();
            }
        }
        if (name < (temp->getEntry())->getName()) {
            if ((temp->getLeft()) == NULL) {
                temp = temp->getRight();
                return NULL;
                break;
            }
            if ((temp->getLeft()) != NULL) {
                temp = temp->getLeft();
            }
        }
    }
}


