
/*  Program by Jessa K. West
    Employee BST Program: Binary Node implementation code
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/

#include "BinaryNode.h"

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : left(nullptr), right(nullptr) {}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& newItem) : data(newItem), left(nullptr), right(nullptr) {}

template<class ItemType>
void BinaryNode<ItemType>::setData(const ItemType& item) { data = item; }

template<class ItemType>
ItemType BinaryNode<ItemType>::getData() const { return data; }

template<class ItemType>
void BinaryNode<ItemType>::setLeft(const std::shared_ptr<BinaryNode<ItemType>>& leftPtr) { left = leftPtr; }

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeft() const { return left; }

template<class ItemType>
void BinaryNode<ItemType>::setRight(const std::shared_ptr<BinaryNode<ItemType>>& rightPtr) { right = rightPtr; }

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRight() const { return right; }

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const { return left == nullptr && right == nullptr; }