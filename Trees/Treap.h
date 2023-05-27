//
// Created by ash on 24.04.23.
//

#ifndef TREE_VISUALIZER_TREAP_H
#define TREE_VISUALIZER_TREAP_H

#include "qgraphicsscene.h"
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"

namespace trees {

    const int NODE_DIAMETR = 200;
    const int Y_DISTANCE = 500;

    class Treap {
    public:
        struct Node {
            int data;
            int priority;
            Node *parent;
            Node *left;
            Node *right;
            int x, y;

            void setPos(int x, int y);
        };

    private:
        Node *root;


        Node *searchTreeHelper(Node *node, int key);

        void leftRotate(Node *x);

        void rightRotate(Node *x);

        void moveUp(Node *x);

        void deleteNodeHelper(Node *node, int k);

        void moveDown(Node *x);

    public:
        Treap();

        static void display(QGraphicsScene *scene, Node *root);

        void click_delete(Node *cur, int x, int y);

        Node *searchTree(int k);

        bool searchPrior(Node *, int x);

        static Node *minimum(Node *node);

        static Node *maximum(Node *node);

        void insert(int key, float priority);

        void split(int x, Treap *t1, Treap *t2);

        void merge(Treap t1, Treap t2);

        Node *getRoot();

        void deleteNode(int data);
    };


} // trees

#endif //TREE_VISUALIZER_TREAP_H
