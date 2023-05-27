#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Trees/Splay.h"
#include "Trees/Treap.h"
#include <QIntValidator>
#include <QTimer>
#include<random>

QVector<QPushButton *> btns;

QGraphicsScene *avl_scene;
trees::AVL *avl_tree;

QGraphicsScene *rb_scene;
trees::RBT *rb_tree;

QGraphicsScene *s_scene;
trees::Splay *s_tree;

QGraphicsScene *t_scene;
trees::Treap *t_tree;

const int seed=11223344;
std::mt19937 rnd(seed);
std::uniform_int_distribution random_data;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    btns = {ui->AVLButton, ui->RBButton, ui->DDButton, ui->SplayButton};
    view = new GraphicsView;
    connect(view, &GraphicsView::mousePressed, this, &MainWindow::treeClick_checking);

    view->setGeometry(0, 0, 820, 720);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    view->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    view->setCacheMode(QGraphicsView::CacheNone); // Кэш фона
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->viewport()->setAttribute(Qt::WA_AcceptTouchEvents);

    avl_scene = new QGraphicsScene;
    avl_scene->setSceneRect(0, 0, 820, 720);

    rb_scene = new QGraphicsScene;
    rb_scene->setSceneRect(0, 0, 820, 720);

    s_scene = new QGraphicsScene;
    s_scene->setSceneRect(0, 0, 820, 720);

    t_scene = new QGraphicsScene;
    t_scene->setSceneRect(0, 0, 820, 720);

    avl_tree = new trees::AVL();
    rb_tree = new trees::RBT();
    s_tree = new trees::Splay();
    t_tree = new trees::Treap();

    trees::AVL::display(avl_scene, avl_tree->getRoot());

    view->setScene(avl_scene);

    auto *viewLayout = new QVBoxLayout(this);
    viewLayout->addWidget(view);
    ui->frame->setLayout(viewLayout);

    ui->InsertLine->setValidator(new QIntValidator(-2147483648, 2147483647, this));
    ui->InsertSomeLine->setValidator(new QIntValidator(0, 2147483647, this));
    ui->containsLine->setValidator(new QIntValidator(-2147483648, 2147483647, this));


}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_RBButton_clicked() {
    for (auto &i: btns) {
        i->setEnabled(true);
    }
    ui->RBButton->setEnabled(false);
    view->setScene(rb_scene);
}


void MainWindow::on_AVLButton_clicked() {
    for (auto &i: btns) {
        i->setEnabled(true);
    }
    ui->AVLButton->setEnabled(false);
    view->setScene(avl_scene);
    view->toDefault();


}


void MainWindow::on_DDButton_clicked() {
    for (auto &i: btns) {
        i->setEnabled(true);
    }
    ui->DDButton->setEnabled(false);
    view->setScene(t_scene);
    view->toDefault();


}


void MainWindow::on_SplayButton_clicked() {
    for (auto &i: btns) {
        i->setEnabled(true);
    }
    ui->SplayButton->setEnabled(false);
    view->setScene(s_scene);
    view->toDefault();


}


void MainWindow::on_Insert_clicked() {
    if (!ui->AVLButton->isEnabled()) {
        avl_tree->insert(ui->InsertLine->text().toInt());
        trees::AVL::display(avl_scene, avl_tree->getRoot());
        ui->InsertLine->setText("");
    } else if (!ui->RBButton->isEnabled()) {
        rb_tree->insert(ui->InsertLine->text().toInt());
        rb_tree->display(rb_scene, rb_tree->getRoot());
        ui->InsertLine->setText("");
    } else if (!ui->SplayButton->isEnabled()) {
        s_tree->insert(ui->InsertLine->text().toInt());
        trees::Splay::display(s_scene, s_tree->getRoot());
        ui->InsertLine->setText("");
    } else if (!ui->DDButton->isEnabled()) {
        int pr = (int)(random_data(rnd) % 2147483648);
        if (t_tree->searchTree(ui->InsertLine->text().toInt())) return;
        while (t_tree->searchPrior(t_tree->getRoot(), pr)) pr = (int)(random_data(rnd) % 2147483648);
        t_tree->insert(ui->InsertLine->text().toInt(), (float)pr);
        trees::Treap::display(t_scene, t_tree->getRoot());
        ui->InsertLine->setText("");
    }
}


void MainWindow::on_InsertSome_clicked() {
    if (!ui->AVLButton->isEnabled()) {

        int num = ui->InsertSomeLine->text().toInt();
        int i = 0;
        while (i < num) {
            int pret = (int)(random_data(rnd) % 2147483648);
            if (!avl_tree->contains(pret)) {
                avl_tree->insert(pret);
                i++;
            }
        }
        trees::AVL::display(avl_scene, avl_tree->getRoot());
        ui->InsertSomeLine->setText("");
    } else if (!ui->RBButton->isEnabled()) {
        int num = ui->InsertSomeLine->text().toInt();
        int i = 0;
        while (i < num) {
            int pret = (int)(random_data(rnd) % 2147483648);
            if (!rb_tree->searchTree(pret)) {
                rb_tree->insert(pret);
                i++;
            }
        }
        rb_tree->display(rb_scene, rb_tree->getRoot());
        ui->InsertSomeLine->setText("");
    } else if (!ui->SplayButton->isEnabled()) {
        int num = ui->InsertSomeLine->text().toInt();
        int i = 0;
        while (i < num) {
            int pret = (int)(random_data(rnd) % 2147483648);
            if (!s_tree->searchTree(pret)) {
                s_tree->insert(pret);
                i++;
            }
        }
        trees::Splay::display(s_scene, s_tree->getRoot());
        ui->InsertSomeLine->setText("");
    } else if (!ui->DDButton->isEnabled()) {
        int num = ui->InsertSomeLine->text().toInt();
        int i = 0;
        while (i < num) {
            int pret = (int)(random_data(rnd) % 2147483648);
            if (!t_tree->searchTree(pret)) {
                int pr = (int)(random_data(rnd) % 2147483648);
                while (t_tree->searchPrior(t_tree->getRoot(), pr)) pr = (int)(random_data(rnd) % 2147483648);
                t_tree->insert(pret, (float)pr);
                i++;
            }
        }
        trees::Treap::display(t_scene, t_tree->getRoot());
        ui->InsertSomeLine->setText("");
    }
}


void MainWindow::on_InsertSomeLine_textChanged(const QString &arg1) {
}

void MainWindow::treeClick_checking(int x, int y) {
    if (!ui->AVLButton->isEnabled()) {
        avl_tree->click_delete(avl_tree->getRoot(), x, y);
        trees::AVL::display(avl_scene, avl_tree->getRoot());
    } else if (!ui->RBButton->isEnabled()) {
        rb_tree->click_delete(rb_tree->getRoot(), x, y);
        rb_tree->display(rb_scene, rb_tree->getRoot());
    } else if (!ui->SplayButton->isEnabled()) {
        s_tree->click_delete(s_tree->getRoot(), x, y);
        trees::Splay::display(s_scene, s_tree->getRoot());
    } else if (!ui->DDButton->isEnabled()) {
        t_tree->click_delete(t_tree->getRoot(), x, y);
        trees::Treap::display(t_scene, t_tree->getRoot());
    }
}


void MainWindow::on_clickDel_clicked() {
}


void MainWindow::on_InsertLine_editingFinished() {

}

void MainWindow::MessageClear() {
    ui->containsResult->setText("");
    ui->containsLine->setText("");
    ui->containsBtn->setEnabled(true);
    ui->containsLine->setReadOnly(false);
}

void MainWindow::on_containsBtn_clicked() {
    if (!ui->AVLButton->isEnabled()) {
        if (avl_tree->contains(ui->containsLine->text().toInt())) {
            ui->containsResult->setText(
                    "There is a node with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:green;");
        } else {
            ui->containsResult->setText(
                    "There are no nodes with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:red;");
        }
        ui->containsBtn->setEnabled(false);
        ui->containsLine->setReadOnly(true);
        QTimer::singleShot(3000, this, &MainWindow::MessageClear);
    } else if (!ui->RBButton->isEnabled()) {
        if (rb_tree->searchTree(ui->containsLine->text().toInt())) {
            ui->containsResult->setText(
                    "There is a node with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:green;");
        } else {
            ui->containsResult->setText(
                    "There are no nodes with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:red;");
        }
        ui->containsBtn->setEnabled(false);
        ui->containsLine->setReadOnly(true);
        QTimer::singleShot(3000, this, &MainWindow::MessageClear);
    } else if (!ui->SplayButton->isEnabled()) {
        if (s_tree->searchTree(ui->containsLine->text().toInt())) {
            ui->containsResult->setText(
                    "There is a node with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:green;");
        } else {
            ui->containsResult->setText(
                    "There are no nodes with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:red;");
        }
        ui->containsBtn->setEnabled(false);
        ui->containsLine->setReadOnly(true);
        QTimer::singleShot(3000, this, &MainWindow::MessageClear);
    } else if (!ui->DDButton->isEnabled()) {
        if (t_tree->searchTree(ui->containsLine->text().toInt())) {
            ui->containsResult->setText(
                    "There is a node with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:green;");
        } else {
            ui->containsResult->setText(
                    "There are no nodes with value " + QString::number(ui->containsLine->text().toInt()));
            ui->containsResult->setStyleSheet("color:red;");
        }
        ui->containsBtn->setEnabled(false);
        ui->containsLine->setReadOnly(true);
        QTimer::singleShot(3000, this, &MainWindow::MessageClear);
    }
}


void MainWindow::on_pushButton_clicked() const {
    view->toDefault();
}

