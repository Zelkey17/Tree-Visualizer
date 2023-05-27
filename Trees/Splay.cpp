#include "Splay.h"
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include "Splay.h"

trees::Splay::Splay() {
    root = nullptr;
}

void trees::Splay::deleteNode(int data) {
    deleteNodeHelper(this->root, data);
}

trees::Splay::Node *trees::Splay::getRoot() {
    return this->root;
}

void trees::Splay::insert(int key) {
    // normal BST insert
    auto *node = new trees::Splay::Node;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->data = key;
    trees::Splay::Node *y = nullptr;
    trees::Splay::Node *x = this->root;

    while (x != nullptr) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    // splay the node
    splay(node);
}

trees::Splay::Node *trees::Splay::maximum(trees::Splay::Node *node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

trees::Splay::Node *trees::Splay::minimum(trees::Splay::Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

trees::Splay::Node *trees::Splay::searchTree(int k) {
    trees::Splay::Node *x = searchTreeHelper(this->root, k);
    if (x) {
        splay(x);
    }
    return x;
}

void trees::Splay::split(trees::Splay::Node *&x, trees::Splay::Node *&s, trees::Splay::Node *&t) {
    splay(x);
    if (x->right) {
        t = x->right;
        t->parent = nullptr;
    } else {
        t = nullptr;
    }
    s = x;
    s->right = nullptr;
    x = nullptr;
}

trees::Splay::Node *trees::Splay::join(trees::Splay::Node *s, trees::Splay::Node *t) {
    if (!s) {
        return t;
    }

    if (!t) {
        return s;
    }
    trees::Splay::Node *x = maximum(s);
    splay(x);
    x->right = t;
    t->parent = x;
    return x;
}

void trees::Splay::leftRotate(trees::Splay::Node *x) {
    trees::Splay::Node *y = x->right;
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

// rotate right at node x
void trees::Splay::rightRotate(trees::Splay::Node *x) {
    trees::Splay::Node *y = x->left;
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

// splaying
void trees::Splay::splay(trees::Splay::Node *x) {
    while (x->parent) {
        if (!x->parent->parent) {
            if (x == x->parent->left) {
                // zig rotation
                rightRotate(x->parent);
            } else {
                // zag rotation
                leftRotate(x->parent);
            }
        } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
            // zig-zig rotation
            rightRotate(x->parent->parent);
            rightRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
            // zag-zag rotation
            leftRotate(x->parent->parent);
            leftRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
            // zig-zag rotation
            leftRotate(x->parent);
            rightRotate(x->parent);
        } else {
            // zag-zig rotation
            rightRotate(x->parent);
            leftRotate(x->parent);
        }
    }
}

void trees::Splay::deleteNodeHelper(trees::Splay::Node *node, int key) {
    trees::Splay::Node *x = nullptr;
    trees::Splay::Node *t, *s;
    while (node != nullptr) {
        if (node->data == key) {
            x = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (x == nullptr) {
        return;
    }
    split(x, s, t); // split the tree
    if (s->left) { // remove x
        s->left->parent = nullptr;
    }
    root = join(s->left, t);
    delete (s);
    s = nullptr;
}

trees::Splay::Node *trees::Splay::searchTreeHelper(trees::Splay::Node *node, int key) {
    if (node == nullptr || key == node->data) {
        return node;
    }

    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}


void trees::Splay::Node::setPos(int _x, int _y) {
    x = _x;
    y = _y;
}


void treeFilling(trees::Splay::Node *&x, int dl) {
    if (x == nullptr) return;

    if (x->left) x->left->x -= dl;
    if (x->right) x->right->x -= dl;

    treeFilling(x->left, dl);
    treeFilling(x->right, dl);

}

int max_right(trees::Splay::Node *x, int mx) {
    if (x == nullptr) return mx;
    mx = std::max(x->x + trees::SPLAY_NODE_DIAMETR, max_right(x->right, mx));
    mx = std::max(x->x + trees::SPLAY_NODE_DIAMETR, max_right(x->left, mx));
    return mx;
}

int max_left(trees::Splay::Node *x, int mx) {
    if (x == nullptr) return mx;
    mx = std::min(x->x, max_left(x->right, mx));
    mx = std::min(x->x, max_left(x->left, mx));
    return mx;
}

void Stand(trees::Splay::Node *&x) {
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

void fix_position(trees::Splay::Node *&x) {
    if (x == nullptr) return;
    if (x->parent == nullptr) {
        x->x = 300;
        x->y = 100;
    } else {
        if (x->parent->left == x) {
            x->setPos(x->parent->x - trees::SPLAY_NODE_DIAMETR, x->parent->y + trees::SPLAY_Y_DISTANCE);
        } else {
            x->setPos(x->parent->x + trees::SPLAY_NODE_DIAMETR, x->parent->y + trees::SPLAY_Y_DISTANCE);

        }
    }
    fix_position(x->left);
    fix_position(x->right);
}

void Standing(trees::Splay::Node *&x) {
    fix_position(x);
    Stand(x);
}

void paintTree(trees::Splay::Node *x, QGraphicsScene *&scene) {
    if (!x) return;
    auto *ellipse = new QGraphicsEllipseItem(x->x, x->y, trees::SPLAY_NODE_DIAMETR,
                                                             trees::SPLAY_NODE_DIAMETR);
    ellipse->setBrush(QBrush(Qt::white));
    auto *text = new QGraphicsTextItem(QString::number(x->data));
    text->setPos(ellipse->boundingRect().center() - text->boundingRect().center());
    scene->addItem(ellipse);
    scene->addItem(text);
    if (x->parent) {
        auto *line = new QGraphicsLineItem(x->parent->x + trees::SPLAY_NODE_DIAMETR / 2.,
                                                        x->parent->y + trees::SPLAY_NODE_DIAMETR / 2.,
                                                        x->x + trees::SPLAY_NODE_DIAMETR / 2.,
                                                        x->y + trees::SPLAY_NODE_DIAMETR / 2.);
        line->setZValue(-1);
        auto uu = QPen(QColor(200, 100, 40));
        uu.setWidth(10);
        line->setPen(uu);

        scene->addItem(line);
    }
    paintTree(x->left, scene);
    paintTree(x->right, scene);

}


void trees::Splay::display(QGraphicsScene *scene, trees::Splay::Node *_root) {
    scene->clear();
    Standing(_root);
    paintTree(_root, scene);

}

void trees::Splay::click_delete(trees::Splay::Node *cur, int x, int y) {
    if (!cur) return;
    if (x > cur->x && x < cur->x + trees::SPLAY_NODE_DIAMETR && y > cur->y && y < cur->y + trees::SPLAY_NODE_DIAMETR) {
        this->deleteNode(cur->data);
    } else {
        click_delete(cur->left, x, y);
        click_delete(cur->right, x, y);
    }
}
