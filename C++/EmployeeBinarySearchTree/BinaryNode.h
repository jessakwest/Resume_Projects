/*  Program by Jessa K. West
    Employee BST Program: Binary Node header
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/
#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode {
    private:
        ItemType data;
        std::shared_ptr<BinaryNode<ItemType>> left;
        std::shared_ptr<BinaryNode<ItemType>> right;
        
    public:
        BinaryNode();
        BinaryNode(const ItemType& newItem);

        void setData(const ItemType& item);
        ItemType getData() const;

        void setLeft(const std::shared_ptr<BinaryNode<ItemType>>& leftPtr);
        std::shared_ptr<BinaryNode<ItemType>> getLeft() const;

        void setRight(const std::shared_ptr<BinaryNode<ItemType>>& rightPtr);
        std::shared_ptr<BinaryNode<ItemType>> getRight() const;

        bool isLeaf() const;
};
#include "BinaryNode.cpp"
#endif
