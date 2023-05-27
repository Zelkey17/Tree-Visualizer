//
// Created by ash on 24.05.23.
//

#include "Treap.h"

namespace trees {

    Treap::Node *Treap::searchTreeHelper(Node *node, int key) {
        if (node == nullptr || key == node->data) {
            return node;
        }

        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void Treap::moveUp(Node *x) {
        if (x->parent == nullptr) {
            return;
        }
        if (x->parent != nullptr && x->priority >= x->parent->priority) {
            return;
        }

        if (x == x->parent->left) {
            rightRotate(x->parent);
        } else {
            leftRotate(x->parent);
        }

        moveUp(x);
    }

    void Treap::deleteNodeHelper(Node *node, int k) {
        Node *x = nullptr;
        while (node != nullptr) {
            if (node->data == k) {
                x = node;
                break;
            }

            if (node->data <= k) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (x == nullptr) {
            return;
        }

        moveDown(x);
        if (x->parent == nullptr) {
            root = nullptr;
            delete x;
            return;
        }
        if (x == x->parent->left) {
            x->parent->left = nullptr;
        } else {
            x->parent->right = nullptr;
        }
        delete x;
    }

    void Treap::moveDown(Node *x) {
        if (x->left == nullptr && x->right == nullptr) {
            return;
        }

        if (x->left != nullptr && x->right != nullptr) {
            if (x->left->priority < x->right->priority) {
                rightRotate(x);
            } else {
                leftRotate(x);
            }
        } else if (x->left != nullptr) {
            rightRotate(x);
        } else {
            leftRotate(x);
        }

        moveDown(x);
    }

    Treap::Treap() {
        root = nullptr;
    }

    Treap::Node *Treap::searchTree(int k) {
        return searchTreeHelper(this->root, k);
    }

    Treap::Node *Treap::minimum(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Treap::Node *Treap::maximum(Node *node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    void Treap::insert(int key, float priority) {
        Node *node = new Node;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        node->data = key;
        node->priority = (int) priority;
        Node *y = nullptr;
        Node *x = this->root;

        while (x != nullptr) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent != nullptr) {
            moveUp(node);
        }
    }

    void Treap::split(int x, Treap *t1, Treap *t2) {
        this->insert(x, -99);

        t1->root = this->root->left;
        t2->root = this->root->right;

        this->root->left = nullptr;
        this->root->right = nullptr;
        delete this->root;
        this->root = nullptr;
    }

    void Treap::merge(Treap t1, Treap t2) {
        Node *largest = t1.maximum(t1.root);
        Node *smallest = t2.minimum(t2.root);

        Node *newRoot = new Node();
        newRoot->data = (largest->data + smallest->data) / 2;
        newRoot->left = t1.root;
        newRoot->right = t2.root;
        newRoot->parent = nullptr;
        newRoot->priority = 99;

        moveDown(newRoot);

        Node *currPtr = newRoot;
        while (currPtr->parent != nullptr) {
            currPtr = currPtr->parent;
        }

        this->root = currPtr;

        if (newRoot == newRoot->parent->left) {
            newRoot->parent->left = nullptr;
        } else {
            newRoot->parent->right = nullptr;
        }

        delete (newRoot);

    }

    Treap::Node *Treap::getRoot() {
        return this->root;
    }

    void Treap::deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }


    void Treap::Node::setPos(int _x, int _y) {
        x = _x;
        y = _y;
    }


    void treeFilling(Treap::Node *&x, int dl) {
        if (x == nullptr) return;

        if (x->left) x->left->x -= dl;
        if (x->right) x->right->x -= dl;

        treeFilling(x->left, dl);
        treeFilling(x->right, dl);

    }

    int max_right(Treap::Node *x, int mx) {
        if (x == nullptr) return mx;
        mx = std::max(x->x + NODE_DIAMETR, max_right(x->right, mx));
        mx = std::max(x->x + NODE_DIAMETR, max_right(x->left, mx));
        return mx;
    }

    int max_left(Treap::Node *x, int mx) {
        if (x == nullptr) return mx;
        mx = std::min(x->x, max_left(x->right, mx));
        mx = std::min(x->x, max_left(x->left, mx));
        return mx;
    }

    void Stand(Treap::Node *&x) {
        if (x == nullptr) return;

        Stand(x->left);
        Stand(x->right);
        int mr = max_right(x->left, -1e6), ml = max_left(x->right, 1e6);

        int delta = (mr == -1e6 || ml == 1e6 ? 0 : ml - mr);
        if (delta < 0) {
            if (x->left)
                x->left->x -= (abs(delta) / 2 + 25);
            if (x->right)
                x->right->x += (abs(delta) / 2 + 25);

            treeFilling(x->left, (abs(delta) / 2 + 25));
            treeFilling(x->right, -(abs(delta) / 2 + 25));
        }

    }

    void fix_position(Treap::Node *&x) {
        if (x == nullptr) return;
        if (x->parent == nullptr) {
            x->x = 300;
            x->y = 100;
        } else {
            if (x->parent->left == x) {
                x->setPos(x->parent->x - NODE_DIAMETR, x->parent->y + Y_DISTANCE);
            } else {
                x->setPos(x->parent->x + NODE_DIAMETR, x->parent->y + Y_DISTANCE);

            }
        }
        fix_position(x->left);
        fix_position(x->right);
    }

    void Standing(Treap::Node *&x) {
        fix_position(x);
        Stand(x);
    }

    void paintTree(Treap::Node *x, QGraphicsScene *&scene) {
        if (!x) return;
        auto *ellipse = new QGraphicsEllipseItem(x->x, x->y, NODE_DIAMETR, NODE_DIAMETR);
        ellipse->setBrush(QBrush(Qt::white));
        auto *text = new QGraphicsTextItem(QString::number(x->data));

        text->setPos(ellipse->boundingRect().center() - text->boundingRect().center() + QPointF(0, -8));

        auto *textPrior = new QGraphicsTextItem(QString::number(x->priority));
        textPrior->setPos(ellipse->boundingRect().center() - textPrior->boundingRect().center() + QPointF(0, 8));
        QFont f = text->font();
        f.setBold(true);
        text->setFont(f);


        scene->addItem(ellipse);
        scene->addItem(text);

        scene->addItem(textPrior);
        if (x->parent) {
            auto *line = new QGraphicsLineItem(x->parent->x + NODE_DIAMETR / 2.,
                                               x->parent->y + NODE_DIAMETR / 2., x->x + NODE_DIAMETR / 2.,
                                               x->y + NODE_DIAMETR / 2.);
            line->setZValue(-1);
            auto uu = QPen(QColor(200, 100, 40));
            uu.setWidth(10);
            line->setPen(uu);

            scene->addItem(line);
        }
        paintTree(x->left, scene);
        paintTree(x->right, scene);

    }


    void Treap::display(QGraphicsScene *scene, Node *_root) {
        scene->clear();
        Standing(_root);
        paintTree(_root, scene);

    }

    void Treap::click_delete(Node *cur, int x, int y) {
        if (!cur) return;
        if (x > cur->x && x < cur->x + NODE_DIAMETR && y > cur->y && y < cur->y + NODE_DIAMETR) {
            this->deleteNode(cur->data);
        } else {
            click_delete(cur->left, x, y);
            click_delete(cur->right, x, y);
        }
    }

    bool Treap::searchPrior(Node *x, int p) {
        if (!x) return false;
        if (x->priority == p) return true;
        bool i = searchPrior(x->left, p);
        if (i) return true;
        return searchPrior(x->right, p);
    }

    void Treap::leftRotate(Treap::Node *x) {
        Treap::Node *y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void Treap::rightRotate(Treap::Node *x) {
        Treap::Node *y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
} // trees