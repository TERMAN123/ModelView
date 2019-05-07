/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_serch;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Load;
    QGroupBox *groupBox_Sort;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_ByName;
    QRadioButton *radioButton_BySurname;
    QRadioButton *radioButton_ByPhone;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_Ascending;
    QRadioButton *radioButton_Descending;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Name;
    QLabel *label_3;
    QLineEdit *lineEdit_Surname;
    QLabel *label_4;
    QLineEdit *lineEdit_Phone;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Reset;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(445, 407);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        label->setMidLineWidth(4);

        horizontalLayout->addWidget(label);

        lineEdit_serch = new QLineEdit(centralWidget);
        lineEdit_serch->setObjectName(QString::fromUtf8("lineEdit_serch"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_serch->sizePolicy().hasHeightForWidth());
        lineEdit_serch->setSizePolicy(sizePolicy);
        lineEdit_serch->setMaximumSize(QSize(200, 16777215));
        lineEdit_serch->setBaseSize(QSize(20, 30));
        lineEdit_serch->setLayoutDirection(Qt::LeftToRight);
        lineEdit_serch->setMaxLength(200);
        lineEdit_serch->setFrame(false);

        horizontalLayout->addWidget(lineEdit_serch);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 6, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonAdd = new QPushButton(centralWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(centralWidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        verticalLayout->addWidget(pushButtonDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_Save = new QPushButton(centralWidget);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        verticalLayout->addWidget(pushButton_Save);

        pushButton_Load = new QPushButton(centralWidget);
        pushButton_Load->setObjectName(QString::fromUtf8("pushButton_Load"));

        verticalLayout->addWidget(pushButton_Load);


        gridLayout->addLayout(verticalLayout, 6, 1, 1, 1);

        groupBox_Sort = new QGroupBox(centralWidget);
        groupBox_Sort->setObjectName(QString::fromUtf8("groupBox_Sort"));
        groupBox_Sort->setCheckable(true);
        groupBox_Sort->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBox_Sort);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_3 = new QGroupBox(groupBox_Sort);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_ByName = new QRadioButton(groupBox_3);
        radioButton_ByName->setObjectName(QString::fromUtf8("radioButton_ByName"));
        radioButton_ByName->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_ByName);

        radioButton_BySurname = new QRadioButton(groupBox_3);
        radioButton_BySurname->setObjectName(QString::fromUtf8("radioButton_BySurname"));

        horizontalLayout_2->addWidget(radioButton_BySurname);

        radioButton_ByPhone = new QRadioButton(groupBox_3);
        radioButton_ByPhone->setObjectName(QString::fromUtf8("radioButton_ByPhone"));

        horizontalLayout_2->addWidget(radioButton_ByPhone);


        gridLayout_2->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_Sort);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_Ascending = new QRadioButton(groupBox_2);
        radioButton_Ascending->setObjectName(QString::fromUtf8("radioButton_Ascending"));
        radioButton_Ascending->setFont(font);
        radioButton_Ascending->setCheckable(true);
        radioButton_Ascending->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_Ascending);

        radioButton_Descending = new QRadioButton(groupBox_2);
        radioButton_Descending->setObjectName(QString::fromUtf8("radioButton_Descending"));
        radioButton_Descending->setFont(font);
        radioButton_Descending->setCheckable(true);
        radioButton_Descending->setChecked(false);

        horizontalLayout_3->addWidget(radioButton_Descending);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Sort, 7, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout = new QFormLayout(groupBox_4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_Name = new QLineEdit(groupBox_4);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Name);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_Surname = new QLineEdit(groupBox_4);
        lineEdit_Surname->setObjectName(QString::fromUtf8("lineEdit_Surname"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Surname);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_Phone = new QLineEdit(groupBox_4);
        lineEdit_Phone->setObjectName(QString::fromUtf8("lineEdit_Phone"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Phone);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_Apply = new QPushButton(groupBox_4);
        pushButton_Apply->setObjectName(QString::fromUtf8("pushButton_Apply"));

        horizontalLayout_4->addWidget(pushButton_Apply);

        pushButton_Reset = new QPushButton(groupBox_4);
        pushButton_Reset->setObjectName(QString::fromUtf8("pushButton_Reset"));

        horizontalLayout_4->addWidget(pushButton_Reset);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);


        gridLayout->addWidget(groupBox_4, 8, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 445, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Phone book", nullptr));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Search:", nullptr));
        pushButtonAdd->setText(QApplication::translate("MainWindowClass", "Add", nullptr));
        pushButtonDelete->setText(QApplication::translate("MainWindowClass", "Delete", nullptr));
        pushButton_Save->setText(QApplication::translate("MainWindowClass", "Save", nullptr));
        pushButton_Load->setText(QApplication::translate("MainWindowClass", "Load", nullptr));
        groupBox_Sort->setTitle(QApplication::translate("MainWindowClass", "Sort", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "Mode", nullptr));
        radioButton_ByName->setText(QApplication::translate("MainWindowClass", "By name", nullptr));
        radioButton_BySurname->setText(QApplication::translate("MainWindowClass", "By surname", nullptr));
        radioButton_ByPhone->setText(QApplication::translate("MainWindowClass", "By phone", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Order", nullptr));
        radioButton_Ascending->setText(QApplication::translate("MainWindowClass", "Ascending", nullptr));
        radioButton_Descending->setText(QApplication::translate("MainWindowClass", "Descending", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindowClass", "Filter", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "Name:", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "Surname:", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "Phone number:", nullptr));
        pushButton_Apply->setText(QApplication::translate("MainWindowClass", "Apply", nullptr));
        pushButton_Reset->setText(QApplication::translate("MainWindowClass", "Reset", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
