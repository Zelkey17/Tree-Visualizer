/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *InsertSomeLine;
    QPushButton *InsertSome;
    QHBoxLayout *horizontalLayout;
    QLineEdit *InsertLine;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Insert;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *containsLine;
    QPushButton *containsBtn;
    QLabel *containsResult;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *AVLButton;
    QPushButton *RBButton;
    QPushButton *DDButton;
    QPushButton *SplayButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1190, 753);
        MainWindow->setMinimumSize(QSize(1190, 753));
        MainWindow->setMaximumSize(QSize(1190, 753));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(36, 31, 49, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(54, 46, 73, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(45, 38, 61, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(18, 15, 24, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(24, 21, 33, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(310, 10, 830, 730));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setMouseTracking(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 430, 291, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat Medium"));
        font.setPointSize(10);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 276, 281));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        InsertSomeLine = new QLineEdit(layoutWidget);
        InsertSomeLine->setObjectName(QString::fromUtf8("InsertSomeLine"));
        InsertSomeLine->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat Medium"));
        font1.setPointSize(9);
        InsertSomeLine->setFont(font1);
        InsertSomeLine->setMaxLength(32767);
        InsertSomeLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(InsertSomeLine);

        InsertSome = new QPushButton(layoutWidget);
        InsertSome->setObjectName(QString::fromUtf8("InsertSome"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InsertSome->sizePolicy().hasHeightForWidth());
        InsertSome->setSizePolicy(sizePolicy);
        InsertSome->setMinimumSize(QSize(100, 40));
        InsertSome->setFont(font);
        InsertSome->setLayoutDirection(Qt::LeftToRight);
        InsertSome->setAutoExclusive(false);

        horizontalLayout_2->addWidget(InsertSome);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        InsertLine = new QLineEdit(layoutWidget);
        InsertLine->setObjectName(QString::fromUtf8("InsertLine"));
        InsertLine->setMinimumSize(QSize(0, 40));
        InsertLine->setFont(font1);
        InsertLine->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout->addWidget(InsertLine);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout->addLayout(verticalLayout_2);

        Insert = new QPushButton(layoutWidget);
        Insert->setObjectName(QString::fromUtf8("Insert"));
        Insert->setMinimumSize(QSize(100, 40));
        Insert->setFont(font);

        horizontalLayout->addWidget(Insert);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        containsLine = new QLineEdit(layoutWidget);
        containsLine->setObjectName(QString::fromUtf8("containsLine"));
        containsLine->setMinimumSize(QSize(0, 40));
        containsLine->setFont(font1);

        horizontalLayout_3->addWidget(containsLine);

        containsBtn = new QPushButton(layoutWidget);
        containsBtn->setObjectName(QString::fromUtf8("containsBtn"));
        containsBtn->setMinimumSize(QSize(100, 40));
        containsBtn->setFont(font);

        horizontalLayout_3->addWidget(containsBtn);


        verticalLayout_4->addLayout(horizontalLayout_3);

        containsResult = new QLabel(layoutWidget);
        containsResult->setObjectName(QString::fromUtf8("containsResult"));
        containsResult->setFont(font1);
        containsResult->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(containsResult);


        verticalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 161, 411));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        AVLButton = new QPushButton(layoutWidget1);
        AVLButton->setObjectName(QString::fromUtf8("AVLButton"));
        AVLButton->setEnabled(false);
        AVLButton->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Montserrat Medium"));
        font2.setPointSize(14);
        AVLButton->setFont(font2);

        gridLayout->addWidget(AVLButton, 0, 0, 1, 1);

        RBButton = new QPushButton(layoutWidget1);
        RBButton->setObjectName(QString::fromUtf8("RBButton"));
        RBButton->setMinimumSize(QSize(0, 40));
        RBButton->setFont(font2);

        gridLayout->addWidget(RBButton, 1, 0, 1, 1);

        DDButton = new QPushButton(layoutWidget1);
        DDButton->setObjectName(QString::fromUtf8("DDButton"));
        DDButton->setMinimumSize(QSize(0, 40));
        DDButton->setFont(font2);

        gridLayout->addWidget(DDButton, 2, 0, 1, 1);

        SplayButton = new QPushButton(layoutWidget1);
        SplayButton->setObjectName(QString::fromUtf8("SplayButton"));
        SplayButton->setMinimumSize(QSize(0, 40));
        SplayButton->setFont(font2);

        gridLayout->addWidget(SplayButton, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        InsertSomeLine->setInputMask(QString());
        InsertSomeLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        InsertSome->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\276", nullptr));
        InsertLine->setText(QString());
        InsertLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 ", nullptr));
        Insert->setText(QCoreApplication::translate("MainWindow", "       \320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214          ", nullptr));
        containsLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        containsBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\270\321\202 \320\273\320\270 \320\264\320\265\321\200\320\265\320\262\320\276 ", nullptr));
        containsResult->setText(QString());
        AVLButton->setText(QCoreApplication::translate("MainWindow", "\320\220\320\222\320\233", nullptr));
        RBButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\247\320\224", nullptr));
        DDButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\320\265\320\262\320\276", nullptr));
        SplayButton->setText(QCoreApplication::translate("MainWindow", "Splay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
