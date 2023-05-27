#ifndef SPLAY_H
#define SPLAY_H

#include "qgraphicsscene.h"
#include <iostream>

namespace trees {
    const int SPLAY_NODE_DIAMETR = 200;
    const int SPLAY_Y_DISTANCE = 500;

    class Splay {
    public:
        struct Node {
            int data;
            Node *parent;
            Node *left;
            Node *right;
            int x, y;

            void setPos(int, int);
        };

    private:
        Node *root;


        Node *searchTreeHelper(Node *node, int key);

        void deleteNodeHelper(Node *node, int key);


        // rotate left at node x
        void leftRotate(Node *x);

        void rightRotate(Node *x);


        // splaying
        void splay(Node *x);

        // joins two trees s and t
        Node *join(Node *s, Node *t);

        // splits the tree into s and t
        void split(Node *&x, Node *&s, Node *&t);

    public:
        Splay();

        void click_delete(Node *cur, int x, int y);


        Node *searchTree(int k);

        // find the node with the minimum key
        static Node *minimum(Node *node);

        // find the node with the maximum key
        static Node *maximum(Node *node);

        // insert the key to the tree in its appropriate position
        void insert(int key);

        Node *getRoot();

        // delete the node from the tree
        void deleteNode(int data);

        static void display(QGraphicsScene *scene, Node *root);


    };
} //trees
#endif // SPLAY_H
