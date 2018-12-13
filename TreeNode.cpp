#include "TreeNode.h"

// A useful constructor
TreeNode::TreeNode(DBentry* _entryPtr) {
     entryPtr = _entryPtr;
     right = NULL;
     left = NULL;
 }
 
 // the destructor
 TreeNode::~TreeNode() {
     
 }
 
 // sets the left child of the TreeNode.
 void TreeNode::setLeft(TreeNode* newLeft) {
     left = newLeft;
 }

 // sets the right child of the TreeNode
 void TreeNode::setRight(TreeNode* newRight) {
     right = newRight;
 }
 
 // gets the left child of the TreeNode.
 TreeNode*TreeNode::getLeft() const {
     return left;
 }
 
 // gets the right child of the TreeNode
 TreeNode*TreeNode::getRight() const {
     return right;
 }
 
 // returns a pointer to the to the DBentry the TreeNode contains.
 DBentry* TreeNode::getEntry() const {
     return entryPtr;
} 


