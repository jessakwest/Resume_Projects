/*  Program by Jessa K. West
    Employee BST Program: Binary Tree header
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include <memory>
#include <vector>

template<class ItemType>
class BinaryTree {
    private:
        std::shared_ptr<BinaryNode<ItemType>> root;
        
        std::shared_ptr<BinaryNode<ItemType>> insert(std::shared_ptr<BinaryNode<ItemType>> subtree,  std::shared_ptr<BinaryNode<ItemType>> node);
        void inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> tree, std::vector<ItemType>& items) const;
        std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> subtree, int target) const;

        // std::shared_ptr<BinaryNode<ItemType>> removeNode(std::shared_ptr<BinaryNode> subtreePtr, int id, bool& success);
        // std::shared_ptr<BinaryNode<ItemType>> getMinNode(std::shared_ptr<BinaryNode> subtreePtr) const;

    public:
        BinaryTree();
        
        bool isEmpty() const;
        bool add(const ItemType& item);
        std::vector<ItemType> display() const;
        bool containsID(int id) const;
        std::string getNameFromID(int id) const;
        // bool remove(int id);

};
#include "BinaryTree.cpp"
#endif