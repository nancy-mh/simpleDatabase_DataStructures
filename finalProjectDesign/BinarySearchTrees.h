//Nancy Moreno Huizar

#ifndef BSTREE_
#define BSTREE_
#include <iostream>
#include "Node.h"
#include <vector>
#include "Vectors.h"
using namespace std;

// Binary Search Tree class
class ActorActressBSTree {
    
private:
    NodeActorActress* root;
    void addNode(NodeActorActress node, NodeActorActress* leaf);  // builds levels after level one is in place
    void freeNode(NodeActorActress* leaf);
    
public:
    ActorActressBSTree();
    ~ActorActressBSTree();
    NodeActorActress* Root() { return root; };
    void addNode(NodeActorActress node);              // builds level one of tree
    NodeActorActress* findNode(string key, NodeActorActress* parent);
    void printPreorder(NodeActorActress* node);
vector<ActorActress> inorderTraversal(NodeActorActress* node, vector<ActorActress>&);   // Depth First Traversal method used to copy tree
   NodeActorActress* deleteNode(NodeActorActress*, string name);
    NodeActorActress* min(NodeActorActress* node);
    NodeActorActress* max(NodeActorActress* node);
    NodeActorActress* successor(string name, NodeActorActress* parent);
    NodeActorActress* predecessor(string name, NodeActorActress* parent);
    
    void writeToFile( string, NodeActorActress*);

};

class PicturesBSTree {
private:
    NodePictures* root;
    void addNode(NodePictures node, NodePictures* leaf);  // builds levels after level one is in place
    void freeNode(NodePictures* leaf);
    
public:
    PicturesBSTree();
    ~PicturesBSTree();
    NodePictures* Root() { return root; };
    void addNode(NodePictures node);              // builds level one of tree,
    NodePictures* findNode(string key, NodePictures* parent);
    vector<Pictures> inorderTraversal(NodePictures* node, vector<Pictures>&);    // Depth First Traversal method used to copy tree into
    NodePictures* deleteNode(NodePictures*, string name);
    NodePictures* min(NodePictures* node);
    NodePictures* max(NodePictures* node);
    NodePictures* successor(string name, NodePictures* parent);
    NodePictures* predecessor(string name, NodePictures* parent);
    void writeToFile( string, NodePictures*);
};


#endif  //BST
