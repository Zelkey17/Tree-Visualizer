//
// Created by ash on 24.05.23.
//

#include "RBT.h"
#include "AVL.h"

const int NODE_DIAMETR = 200, Y_DISTANCE = 500;

namespace trees {
    RBT::RBT() {
        TNULL = new Node;
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    bool RBT::searchTreeHelper(Node *node, int key) {
        if (node == TNULL) {
            return false;
        }
        if (key == node->data) {
            return true;
        }

        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void RBT::fixDelete(Node *x) {
        Node * s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == RED) {
                    // case 3.RED
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }


    void RBT::rbTransplant(Node *u, Node *v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    bool RBT::searchTree(int k) {
        return searchTreeHelper(this->root, k);
    }


    RBT::Node *RBT::minimum(RBT::Node *node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    RBT::Node *RBT::maximum(RBT::Node *node) {
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }

    void RBT::deleteNodeHelper(Node *node, int key) {
        // find the node containing key
        Node * z = TNULL;
        Node * x, *y;
        while (node != TNULL) {
            if (node->data == key) {
                z = node;
            }

            if (node->data <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (z == TNULL) {
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK) {
            fixDelete(x);
        }
    }

    void RBT::fixInsert(Node *k) {
        Node * u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;

                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }


    void RBT::leftRotate(Node *x) {
        Node * y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
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

    void RBT::rightRotate(Node *x) {
        Node * y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
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

    void RBT::insert(int key) {
        if (this->searchTree(key)) return;
        Node *node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        Node *y = nullptr;
        Node *x = this->root;

        while (x != TNULL) {
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

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        fixInsert(node);
    }

    RBT::Node *RBT::getRoot() {
        return this->root;
    }


    void RBT::treeFilling(Node *&x, int dl) {
        if (x == nullptr || x == TNULL) return;

        if (x->left) x->left->x -= dl;
        if (x->right) x->right->x -= dl;

        treeFilling(x->left, dl);
        treeFilling(x->right, dl);

    }

    int RBT::max_right(Node *x, int mx) {
        if (x == nullptr || x == TNULL) return mx;
        mx = std::max(x->x + NODE_DIAMETR, max_right(x->right, mx));
        mx = std::max(x->x + NODE_DIAMETR, max_right(x->left, mx));
        return mx;
    }

    int RBT::max_left(Node *x, int mx) {
        if (x == nullptr || x == TNULL) return mx;
        mx = std::min(x->x, max_left(x->right, mx));
        mx = std::min(x->x, max_left(x->left, mx));
        return mx;
    }

    void RBT::Stand(Node *&x) {
        if (x == nullptr || x == TNULL) return;

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

    void RBT::fix_position(Node *&x) {
        if (x == nullptr || x == TNULL) return;
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

    void RBT::Standing(Node *&x) {
        fix_position(x);
        Stand(x);
    }

    void RBT::paintTree(Node *x, QGraphicsScene *&scene) {
        if (!x || x == TNULL) return;
        auto *ellipse = new QGraphicsEllipseItem(x->x, x->y, NODE_DIAMETR, NODE_DIAMETR);
        QPen *pen = new QPen(Qt::black);
        if (x->color == RED) {
            pen->setColor(Qt::red);
            pen->setWidth(20);
        } else {
            pen->setColor(Qt::white);
            pen->setWidth(20);
        }
        ellipse->setPen(*pen);
        if (x->color == RED) {
            ellipse->setBrush(QBrush(QColor(255, 100, 100)));
        } else {
            ellipse->setBrush(QBrush(QColor(100, 100, 100)));
        }
        auto *text = new QGraphicsTextItem(QString::number(x->data));
        text->setPos(ellipse->boundingRect().center() - text->boundingRect().center());
        scene->addItem(ellipse);
        scene->addItem(text);
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


    void RBT::display(QGraphicsScene *scene, Node *_root) {
        scene->clear();
        Standing(_root);
        paintTree(_root, scene);

    }

    void RBT::Node::setPos(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void RBT::click_delete(Node *cur, int x, int y) {
        if (!cur && cur != TNULL) return;
        if (x > cur->x && x < cur->x + NODE_DIAMETR && y > cur->y && y < cur->y + NODE_DIAMETR) {
            this->deleteNode(cur->data);
        } else {
            click_delete(cur->left, x, y);
            click_delete(cur->right, x, y);
        }
    }

    void RBT::deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

} // trees