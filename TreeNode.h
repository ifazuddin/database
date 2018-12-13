#ifndef TREENODE_H
#define TREENODE_H
#include "DBentry.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

class TreeNode {
 private:
 DBentry* entryPtr ;
 TreeNode* left ;
 TreeNode* right ;
 public:
 // A useful constructor
 TreeNode( DBentry* _entryPtr ) ;
 // the destructor
 ~TreeNode() ;
 // sets the left child of the TreeNode.
 void setLeft( TreeNode* newLeft ) ;

 // sets the right child of the TreeNode
 void setRight( TreeNode* newRight ) ;
 // gets the left child of the TreeNode.
 TreeNode* getLeft() const ;
 // gets the right child of the TreeNode
 TreeNode* getRight() const ;
 // returns a pointer to the to the DBentry the TreeNode contains.
 DBentry* getEntry() const ;
} ;

#endif /* TREENODE_H */

