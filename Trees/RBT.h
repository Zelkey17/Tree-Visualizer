//
// Created by ash on 24.04.23.
//

#ifndef TREE_VISUALIZER_RBT_H
#define TREE_VISUALIZER_RBT_H

#include "qgraphicsitem.h"
#include "qgraphicsscene.h"

namespace trees {

    class RBT {
    public:
        enum Color {
            RED, BLACK
        };

        struct Node {
            int data;
            Color color;
            Node *left;
            Node *right;
            Node *parent;

            int x, y;

            void setPos(int x, int y);

        };

    private:

        Node *root;
        Node *TNULL;


        bool searchTreeHelper(Node *node, int key);

        void fixDelete(Node *x);

        void rbTransplant(Node *u, Node *v);

        void deleteNodeHelper(Node *node, int key);

        void fixInsert(Node *k);

        void paintTree(Node *x, QGraphicsScene *&scene);

        void treeFilling(Node *&x, int dl);

        int max_left(Node *x, int mx);

        int max_right(Node *x, int mx);

        void Stand(Node *&x);

        void fix_position(Node *&x);

        void Standing(Node *&x);


    public:
        RBT();

        bool searchTree(int k);

        void click_delete(Node *cur, int x, int y);

        void display(QGraphicsScene *scene, Node *_root);

        Node *minimum(Node *node);

        Node *maximum(Node *node);

        void leftRotate(Node *x);

        void rightRotate(Node *x);

        void insert(int key);

        Node *getRoot();

        void deleteNode(int data);

    };

} // trees

#endif //TREE_VISUALIZER_RBT_H
