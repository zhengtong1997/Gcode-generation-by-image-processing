/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openLenaJpg;
    QAction *openCustomeFile;
    QAction *restoreFile;
    QAction *exitSystem;
    QAction *copyright;
    QAction *about;
    QAction *Clear;
    QAction *GcodePre;
    QAction *GcodePram;
    QAction *GcodeImg;
    QWidget *centralWidget;
    QLabel *label1;
    QLabel *label2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTextEdit *textEdit;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLabel *label_7;
    QComboBox *PortBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *BaudBox;
    QLabel *label_10;
    QComboBox *BitNumBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QComboBox *ParityBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QComboBox *StopBox;
    QSpacerItem *verticalSpacer;
    QPushButton *openButton;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *GcodeInitial;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(822, 745);
        openLenaJpg = new QAction(MainWindow);
        openLenaJpg->setObjectName(QStringLiteral("openLenaJpg"));
        openCustomeFile = new QAction(MainWindow);
        openCustomeFile->setObjectName(QStringLiteral("openCustomeFile"));
        restoreFile = new QAction(MainWindow);
        restoreFile->setObjectName(QStringLiteral("restoreFile"));
        exitSystem = new QAction(MainWindow);
        exitSystem->setObjectName(QStringLiteral("exitSystem"));
        copyright = new QAction(MainWindow);
        copyright->setObjectName(QStringLiteral("copyright"));
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        Clear = new QAction(MainWindow);
        Clear->setObjectName(QStringLiteral("Clear"));
        GcodePre = new QAction(MainWindow);
        GcodePre->setObjectName(QStringLiteral("GcodePre"));
        GcodePram = new QAction(MainWindow);
        GcodePram->setObjectName(QStringLiteral("GcodePram"));
        GcodeImg = new QAction(MainWindow);
        GcodeImg->setObjectName(QStringLiteral("GcodeImg"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(10, 30, 281, 241));
        label1->setFrameShape(QFrame::Box);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(380, 30, 291, 241));
        label2->setFrameShape(QFrame::Box);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 280, 121, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 280, 71, 21));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, -10, 221, 41));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 330, 520, 323));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        textEdit_2 = new QTextEdit(layoutWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        PortBox = new QComboBox(layoutWidget);
        PortBox->setObjectName(QStringLiteral("PortBox"));

        verticalLayout_3->addWidget(PortBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        BaudBox = new QComboBox(layoutWidget);
        BaudBox->setObjectName(QStringLiteral("BaudBox"));

        horizontalLayout_4->addWidget(BaudBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_3->addWidget(label_10);

        BitNumBox = new QComboBox(layoutWidget);
        BitNumBox->setObjectName(QStringLiteral("BitNumBox"));

        verticalLayout_3->addWidget(BitNumBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_3->addLayout(horizontalLayout_5);

        ParityBox = new QComboBox(layoutWidget);
        ParityBox->setObjectName(QStringLiteral("ParityBox"));

        verticalLayout_3->addWidget(ParityBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout_3);

        StopBox = new QComboBox(layoutWidget);
        StopBox->setObjectName(QStringLiteral("StopBox"));

        verticalLayout_2->addWidget(StopBox);

        verticalSpacer = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        openButton = new QPushButton(layoutWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_2->addWidget(openButton);


        horizontalLayout_7->addLayout(verticalLayout_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 630, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        GcodeInitial = new QMenu(menuBar);
        GcodeInitial->setObjectName(QStringLiteral("GcodeInitial"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(GcodeInitial->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(openLenaJpg);
        menu->addAction(openCustomeFile);
        menu->addAction(restoreFile);
        menu->addAction(Clear);
        menu->addAction(exitSystem);
        menu_2->addAction(copyright);
        menu_2->addAction(about);
        menu_3->addAction(GcodeImg);
        GcodeInitial->addAction(GcodePre);
        GcodeInitial->addAction(GcodePram);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GcodeCreator", 0));
        openLenaJpg->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\265\213\350\257\225\346\226\207\344\273\266\357\274\210lena.jpg)", 0));
        openCustomeFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\207\252\345\256\232\344\271\211\346\226\207\344\273\266", 0));
        restoreFile->setText(QApplication::translate("MainWindow", "\350\277\230\345\216\237", 0));
        exitSystem->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        copyright->setText(QApplication::translate("MainWindow", "\347\211\210\346\235\203", 0));
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        Clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
        GcodePre->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\345\211\215\351\242\204\345\244\204\347\220\206", 0));
        GcodePram->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        GcodeImg->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\345\210\207\347\211\207", 0));
        label1->setText(QString());
        label2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\345\233\276\345\203\217", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\345\233\276\345\203\217", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\215\216\344\270\255\347\247\221\346\212\200\345\244\247\345\255\246Focus\345\233\242\351\230\237\345\210\266\344\275\234", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", 0));
        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        label_8->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        label_9->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        BaudBox->clear();
        BaudBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        label_10->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", 0));
        BitNumBox->clear();
        BitNumBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_11->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", 0));
        ParityBox->clear();
        ParityBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0)
        );
        label_12->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", 0));
        StopBox->clear();
        StopBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\210\207\347\211\207", 0));
        GcodeInitial->setTitle(QApplication::translate("MainWindow", "G\344\273\243\347\240\201\345\210\235\345\247\213\345\214\226", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
