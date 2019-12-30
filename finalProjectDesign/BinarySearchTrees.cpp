// Nancy Moreno Huizar

#include "BinarySearchTrees.h"
#include <vector>
#include <string>
#include "Vectors.h"
#include <fstream>

ActorActressBSTree:: ActorActressBSTree()
{
    root = nullptr;
}
PicturesBSTree:: PicturesBSTree()
{
    root = nullptr;
}


ActorActressBSTree::~ActorActressBSTree() {
    freeNode(root);
}


void ActorActressBSTree::freeNode(NodeActorActress* leaf)
{
    if ( leaf != NULL )
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        free(leaf);
    }
    
}


PicturesBSTree::~PicturesBSTree() {
    freeNode(root);
}


void PicturesBSTree::freeNode(NodePictures * leaf)
{
    if ( leaf != NULL )
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        free(leaf);
    }
    
}


// function will create level one of tree
void ActorActressBSTree::addNode(NodeActorActress node)
{

    if (root == nullptr)
    {
        NodeActorActress* nodePtr = new NodeActorActress; // Must create a new node and copy data from object to node that has a pointer to
        nodePtr -> setYear(node.getYear());               // it. Otherwise, the following error: assigning to NodeActorActress * from
                                                        // incompatible type NodeActorActress; take the address
        nodePtr -> setAward(node.getAward());
        nodePtr -> setWinner(node.getWinner());
        nodePtr -> setName(node.getName());
        nodePtr -> setFilm(node.getFilm());
        root = nodePtr;                                 // root pointer points to where nodePtr is pointing to.
    }
    else
    {
        addNode(node, root);
    }
    
}

 void ActorActressBSTree:: addNode(NodeActorActress node, NodeActorActress* leaf)
{
    if (node.getName() <= leaf->getName())  // at level one, leaf is the root pointer, name of first nodes is compared to name of
                                            // node object
    {
        if (leaf -> Left() != nullptr)       // checks if left pointer of first node is null, if not, leaf points at node in level 2
                                             // and compares its name to the name of node object then checks if left pointer is null
            addNode(node, leaf-> Left());    // through recursion, every node is checked, until the leafs of the tree are reached,
                                            // left pointer is nullptr
        else
        {
            NodeActorActress* nodePtr = new NodeActorActress;
            nodePtr -> setYear(node.getYear());
            nodePtr -> setAward(node.getAward());
            nodePtr -> setWinner(node.getWinner());
            nodePtr -> setName(node.getName());
            nodePtr -> setFilm(node.getFilm());
            nodePtr -> setParent(leaf);           // links child to parent
            leaf -> setLeft(nodePtr);              // links parent to child, adding new node to tree
        }
    }
    else
    {
        if (leaf -> Right() != nullptr)
            addNode(node, leaf-> Right());
        else
        {
            NodeActorActress* nodePtr = new NodeActorActress;
            nodePtr -> setYear(node.getYear());
            nodePtr -> setAward(node.getAward());
            nodePtr -> setWinner(node.getWinner());
            nodePtr -> setName(node.getName());
            nodePtr -> setFilm(node.getFilm());
            nodePtr -> setParent(leaf);
            leaf -> setRight(nodePtr);
        }
    }
}

void PicturesBSTree::addNode(NodePictures node)
{
    
    if (root == nullptr)
    {
        NodePictures* nodePtr = new NodePictures; // Must create a new node and copy data from object to node that has a pointer to
        nodePtr -> setName(node.getName());               // it. Otherwise, the following error: assigning to NodeActorActress * from
                                                // incompatible type NodeActorActress; take the address
        nodePtr -> setYear(node.getYear());
        nodePtr -> setNominations(node.getNominations());
        nodePtr -> setRating(node.getRating());
        nodePtr -> setDuration(node.getDuration());
        nodePtr -> setGenre1(node.getGenre1());
        nodePtr -> setGenre2(node.getGenre2());
        nodePtr -> setRelease(node.getRelease());
        nodePtr -> setMetacritic(node.getMetacritic());
        nodePtr -> setSynopsis(node.getSynopsis());
        root = nodePtr;                                 // root pointer points to where nodePtr is pointing to.
    }
    else
    {
        addNode(node, root);
    }
    
}

void PicturesBSTree:: addNode(NodePictures node, NodePictures* leaf)
{
    if (node.getName() <= leaf->getName())  // at level one, leaf is the root pointer, name of first nodes is compared to name of
        // node object
    {
        if (leaf -> Left() != nullptr)       // checks if left pointer of first node is null, if not, leaf points at node in level 2
                                          // and compares its name to the name of node object then checks if left pointer is null
            addNode(node, leaf-> Left());    // through recursion, every node is checked, until the leafs of the tree are reached,
        // left pointer is nullptr
        else
        {
            NodePictures* nodePtr = new NodePictures; // Must create a new node and copy data from object to node that has a pointer to
            nodePtr -> setName(node.getName());               // it. Otherwise, the following error: assigning to NodeActorActress * from
                                                  // incompatible type NodeActorActress; take the address
            nodePtr -> setYear(node.getYear());
            nodePtr -> setNominations(node.getNominations());
            nodePtr -> setRating(node.getRating());
            nodePtr -> setDuration(node.getDuration());
            nodePtr -> setGenre1(node.getGenre1());
            nodePtr -> setGenre2(node.getGenre2());
            nodePtr -> setRelease(node.getRelease());
            nodePtr -> setMetacritic(node.getMetacritic());
            nodePtr -> setSynopsis(node.getSynopsis());
            nodePtr -> setParent(leaf);           // links child to parent
            leaf -> setLeft(nodePtr);              // links parent to child, adding new node to tree
        }
    }
    else
    {
        if (leaf -> Right() != nullptr)
            addNode(node, leaf-> Right());
        else
        {
            NodePictures* nodePtr = new NodePictures; // Must create a new node and copy data from object to node that has a pointer to
            nodePtr -> setName(node.getName());               // it. Otherwise, the following error: assigning to NodeActorActress * from
                                                    // incompatible type NodeActorActress; take the address
            nodePtr -> setYear(node.getYear());
            nodePtr -> setNominations(node.getNominations());
            nodePtr -> setRating(node.getRating());
            nodePtr -> setDuration(node.getDuration());
            nodePtr -> setGenre1(node.getGenre1());
            nodePtr -> setGenre2(node.getGenre2());
            nodePtr -> setRelease(node.getRelease());
            nodePtr -> setMetacritic(node.getMetacritic());
            nodePtr -> setSynopsis(node.getSynopsis());
            nodePtr -> setParent(leaf);
            leaf -> setRight(nodePtr);
        }
    }
}


// must pass a vector to function and not create a vector within function, otherwise only info from one node will be added to vector
vector<ActorActress> ActorActressBSTree:: inorderTraversal(NodeActorActress* nodePtr, vector<ActorActress>& ActorActressVec )
{

    ActorActress ActorActressVecObj1;

    if(nodePtr != nullptr) //check root not nodePtr, noticed double check when studying for final 
    {

        
    if (nodePtr->Left() != nullptr)
    {


        inorderTraversal(nodePtr->Left(),ActorActressVec);

        
    }
        
        ActorActressVecObj1.setName(nodePtr-> getName());
        ActorActressVecObj1.setFilm(nodePtr -> getFilm());
        ActorActressVecObj1.setYear(nodePtr -> getYear());
        ActorActressVecObj1.setAward(nodePtr -> getAward());
        ActorActressVecObj1.setWinner(nodePtr-> getWinner());
        ActorActressVec.push_back(ActorActressVecObj1);
        
    if (nodePtr ->Right() != nullptr)
    {
        inorderTraversal(nodePtr ->Right(), ActorActressVec);
    }

    }

 
    return ActorActressVec;
}

vector<Pictures> PicturesBSTree:: inorderTraversal(NodePictures* nodePtr, vector<Pictures>& picturesVec )
{
    
    Pictures object;
    
    if(nodePtr != nullptr)
    {
        
        
        if (nodePtr->Left() != nullptr)
        {
            
            
            inorderTraversal(nodePtr->Left(),picturesVec);
            
            
        }
        
        object.setName(nodePtr-> getName());
        object.setYear(nodePtr-> getYear());
        object.setNominations(nodePtr-> getNominations());
        object.setRating(nodePtr-> getRating());
        object.setDuration(nodePtr-> getDuration());
        object.setGenre1(nodePtr-> getGenre1());
        object.setGenre2(nodePtr-> getGenre2());
        object.setRelease(nodePtr-> getRelease());
        object.setMetacritic(nodePtr-> getMetacritic());
        object.setSynopsis(nodePtr-> getSynopsis());
        picturesVec.push_back(object);
        
        if (nodePtr ->Right() != nullptr)
        {
            inorderTraversal(nodePtr ->Right(), picturesVec);
        }
        
    }
    

    return picturesVec;
}


NodeActorActress* ActorActressBSTree:: findNode(string key, NodeActorActress* nodePtr)
{
    if (nodePtr == nullptr)
    {
        return root;
    }
    else if (key == nodePtr->getName())
        {
            return nodePtr;

        }
        
    else  if(key < nodePtr -> getName())
        {
            if (nodePtr-> Left() != nullptr)
            {
                return findNode(key, nodePtr->Left());
            }
            else
                return nodePtr-> Left();
        }
  
        
    else if ( key > nodePtr->getName())
        {
            if(nodePtr->Right() != nullptr)
            {
                return findNode(key, nodePtr->Right());
            }
            else
                return nodePtr-> Right();
        }
    
    return nodePtr;
}

NodePictures* PicturesBSTree :: findNode(string key, NodePictures* nodePtr)
{
    if (nodePtr == nullptr)
    {
        return root;
    }
    else if (key == nodePtr->getName())
    {
        return nodePtr;
        
    }
    
    else  if(key < nodePtr -> getName())
    {
        if (nodePtr-> Left() != nullptr)
        {
            return findNode(key, nodePtr->Left());
        }
    }
 
    
    else if ( key > nodePtr->getName())
    {
        if(nodePtr->Right() != nullptr)
        {
            return findNode(key, nodePtr->Right());
        }
    }
    
    return nodePtr;
}

NodeActorActress* ActorActressBSTree::min(NodeActorActress* node)
{
    NodeActorActress* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

NodePictures* PicturesBSTree::min(NodePictures* node)
{
    NodePictures* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
NodeActorActress* ActorActressBSTree::max(NodeActorActress* node)
{
    NodeActorActress * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

NodePictures* PicturesBSTree::max(NodePictures* node)
{
    NodePictures * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
NodeActorActress* ActorActressBSTree::successor(string key, NodeActorActress *node)
{
    NodeActorActress* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Right());
    
    return thisKey;
}

NodePictures* PicturesBSTree::successor(string key, NodePictures *node)
{
    NodePictures* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Right());
    
    return thisKey;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
NodeActorActress* ActorActressBSTree::predecessor(string key, NodeActorActress *node)
{
    NodeActorActress* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Left());
    return nullptr;
}

NodePictures* PicturesBSTree::predecessor(string key, NodePictures *node)
{
    NodePictures* thisKey = findNode(key, node);
    if ( thisKey )
        return max(thisKey->Left());
    return nullptr;
}


/* Given a binary search tree and a key, this function deletes the key
 and returns the new root */
NodeActorActress* ActorActressBSTree::deleteNode(NodeActorActress* root,string key)
{
    
    
    // tree is empty
    if (root == nullptr)
        return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->getName())
    {
        root->setLeft(deleteNode(root->Left(), key));
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->getName())
        root->setRight(deleteNode(root->Right(), key));
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with one or no child
        if (root->Left() == NULL)
        {
            NodeActorActress *temp = root->Right();
            free(root);
            return temp;
        }
        else if (root->Right() == NULL)
        {
            NodeActorActress *temp = root->Left();
            free(root);
            return temp;
        }
        

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            NodeActorActress* temp = min(root->Right());
            
            // Copy the inorder successor's content to this node
            root->setName((temp->getName()));
            
            // Delete the inorder successor
            root->setRight(deleteNode(root->Right(), temp->getName()));

    }
    return root;
    
}

// works the same as the function above
NodePictures* PicturesBSTree::deleteNode(NodePictures* root,string key)
{
    
    // tree is empty
    if (root == nullptr)
        return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->getName())
    {
        root->setLeft(deleteNode(root->Left(), key));
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->getName())
        root->setRight(deleteNode(root->Right(), key));
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->Left() == NULL)
        {
            NodePictures *temp = root->Right();
            free(root);
            return temp;
        }
        else if (root->Right() == NULL)
        {
            NodePictures *temp = root->Left();
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        NodePictures* temp = min(root->Right());
        
        // Copy the inorder successor's content to this node
        root->setName((temp->getName()));
        
        // Delete the inorder successor
        root->setRight(deleteNode(root->Right(), temp->getName()));
    }
    return root;
    
}


//node found with a matching name is written to file
void ActorActressBSTree:: writeToFile(string fileName, NodeActorActress* nodePtr)
{
    ofstream outFile;
    outFile.open(fileName);
   if (outFile)
   {
        outFile << nodePtr->getYear() << "\t"
       <<nodePtr->getAward() <<"\t"
       << nodePtr->getWinner()<< "\t"
       << nodePtr->getName()<<"\t"
       <<nodePtr->getFilm()<<"\t"<<endl;
   }
    else
        cout << "Could not open file.\n";
    
    outFile.close();
}

void PicturesBSTree:: writeToFile(string fileName, NodePictures* nodePtr)
{
    ofstream outFile;
    outFile.open(fileName);
    if (outFile)
    {
         outFile << nodePtr->getName()<< "\t"
                <<nodePtr-> getYear() <<"\t"
                <<nodePtr->getNominations()<< "\t"
                <<nodePtr->getRating()<<"\t"
                <<nodePtr->getDuration()<<"\t"
                <<nodePtr->getGenre1()<<"\t"
                <<nodePtr->getGenre2()<<"\t"
                <<nodePtr->getRelease()<<"\t"
                <<nodePtr->getSynopsis()<<"\t"<<endl;
    }
    else
        cout << "Could not open file.\n";
    
    outFile.close();
}
