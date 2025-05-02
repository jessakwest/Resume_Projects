/*  Program by Jessa K. West
    Employee BST Program: Binary Tree implementation code
    
     Concepts: Designed & implemented a generic, smart-pointer based Binary Search Tree with custom objects, operator overloading, and recursive algorithms
*/ 

#include "BinaryTree.h"

template<class ItemType>
BinaryTree<ItemType>::BinaryTree() : root(nullptr) {}

template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const { return root == nullptr; }

template<class ItemType>
bool BinaryTree<ItemType>::add(const ItemType& item) {
    std::shared_ptr<BinaryNode<ItemType>> newNode = std::make_shared<BinaryNode<ItemType>>(item);

    if (root == nullptr)
        root = newNode;
    else {
        root = insert(root, newNode);
    }

    return true;
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryTree<ItemType>::insert(std::shared_ptr<BinaryNode<ItemType>> subtree, std::shared_ptr<BinaryNode<ItemType>> node) {
    if (subtree == nullptr)
        return node;
    
    if (node->getData() < subtree->getData()) {
        subtree->setLeft(insert(subtree->getLeft(), node));
    }
    else {
        subtree->setRight(insert(subtree->getRight(), node));
    }
    return subtree;
}

template<class ItemType>
std::vector<ItemType> BinaryTree<ItemType>::display() const {
    std::vector<ItemType> items;
    inorderTraverse(root, items);
    return items;
}

template<class ItemType>
void BinaryTree<ItemType>::inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> tree, std::vector<ItemType>& items) const {
    if (tree) {
        inorderTraverse(tree->getLeft(), items);
        items.push_back(tree->getData());
        inorderTraverse(tree->getRight(), items);
    }
}


template<class ItemType>
bool BinaryTree<ItemType>::containsID(int id) const {
    if (root == nullptr)
        return false;
    
    return findNode(root, id) != nullptr;
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subtree, int target) const {
    if (subtree == nullptr)
        return nullptr;

    if (target == subtree->getData().getID())
        return subtree;
    
    if (target < subtree->getData().getID())
        return findNode(subtree->getLeft(), target);
    else // target > subtree->getData()
        return findNode(subtree->getRight(), target);
}

template<class ItemType>
std::string BinaryTree<ItemType>::getNameFromID(int id) const {
    std::shared_ptr<BinaryNode<ItemType>> node = findNode(root, id);

    if (node!= nullptr)
        return node->getData().getName();
    else
        return nullptr;
}