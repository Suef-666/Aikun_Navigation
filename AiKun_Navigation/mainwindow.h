#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QStringList>
#include <QList>
#include "solve.h"
#include <QDate>
#include <QTime>
#include "node.h"
#include "edge.h"

#include "solvegraph.h"
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int map = 0;
    bool way;//校区间的交通方式
    int wayway;
    QString currentImagePath;  // 当前显示的图片路径
    bool showLine;  // 是否显示直线
    QIcon icon1;
    QIcon icon2;

    Solve *JinnanSolve =new Solve();
    Solve *XiaoquSolve= new Solve();
    SolveGraph *G;
    SolveGraph *T;
    int *p;

    int start = 0;
    int end = 0;
    bool combo = 0;
    bool isStart = 0;
    QDate DateNow;
    QTime TimeNow;

    bool pBtn_1 = 0;
    bool pBtn_2 = 0;
    bool pBtn_3 = 0;
    bool pBtn_4 = 0;
    bool pBtn_5 = 0;
    bool pBtn_6 = 0;
    bool pBtn_7 = 0;
    bool pBtn_8 = 0;
    bool pBtn_9 = 0;
    bool pBtn_10 = 0;

    const int dy = 9;               //用于位置微调
    const int delx = 2;
    const int dely = 10;

    QList<Edge*> JinnanEdgeList;
    QList<Edge*> XiaoquEdgeList;
    QList<Node*> JinnanNodeList;
    QList<Node*> XiaoquNodeList;
    QStringList JinnanList;
    QStringList XiaoquList;

    Node* node_1;
    Node* node_2;
    Node* node_3;
    Node* node_4;
    Node* node_5;
    Node* node_6;
    Node* node_7;
    Node* node_8;
    Node* node_9;
    Node* node_10;
    Node* node_11;
    Node* node_12;
    Node* node_13;
    Node* node_14;
    Node* node_15;
    Node* node_16;
    Node* node_17;
    Node* node_18;
    Node* node_19;
    Node* node_20;
    Node* node_21;
    Node* node_22;
    Node* node_23;
    Node* node_24;
    Node* node_25;
    Node* node_26;
    Node* node_27;
    Node* node_28;
    Node* node_29;
    Node* node_30;
    Node* node_31;
    Node* node_32;
    Node* node_33;
    Node* node_34;
    Node* node_35;
    Node* node_36;
    Node* node_37;
    Node* node_38;
    Node* node_39;
    Node* node_40;
    Node* node_41;
    Node* node_42;
    Node* node_43;
    Node* node_44;
    Node* node_45;

    Node* node_101;
    Node* node_102;
    Node* node_103;
    Node* node_104;
    Node* node_105;
    Node* node_106;
    Node* node_107;
    Node* node_108;
    Node* node_109;
    Node* node_110;
    Node* node_111;
    Node* node_112;
    Node* node_113;

    Edge* edge_1;
    Edge* edge_2;
    Edge* edge_3;
    Edge* edge_4;
    Edge* edge_5;
    Edge* edge_6;
    Edge* edge_7;
    Edge* edge_8;
    Edge* edge_9;
    Edge* edge_10;
    Edge* edge_11;
    Edge* edge_12;
    Edge* edge_13;
    Edge* edge_14;
    Edge* edge_15;
    Edge* edge_16;
    Edge* edge_17;
    Edge* edge_18;
    Edge* edge_19;
    Edge* edge_20;
    Edge* edge_21;
    Edge* edge_22;
    Edge* edge_23;
    Edge* edge_24;
    Edge* edge_25;
    Edge* edge_26;
    Edge* edge_27;
    Edge* edge_28;
    Edge* edge_29;
    Edge* edge_30;
    Edge* edge_31;
    Edge* edge_32;
    Edge* edge_33;
    Edge* edge_34;
    Edge* edge_35;
    Edge* edge_36;
    Edge* edge_37;
    Edge* edge_38;
    Edge* edge_39;
    Edge* edge_40;
    Edge* edge_41;
    Edge* edge_42;
    Edge* edge_43;
    Edge* edge_44;
    Edge* edge_45;
    Edge* edge_46;
    Edge* edge_47;
    Edge* edge_48;
    Edge* edge_49;
    Edge* edge_50;
    Edge* edge_51;
    Edge* edge_52;
    Edge* edge_53;
    Edge* edge_54;
    Edge* edge_55;
    Edge* edge_56;
    Edge* edge_57;
    Edge* edge_58;
    Edge* edge_59;
    Edge* edge_60;
    Edge* edge_61;
    Edge* edge_62;
    Edge* edge_63;
    Edge* edge_64;
    Edge* edge_65;
    Edge* edge_66;
    Edge* edge_67;
    Edge* edge_68;
    Edge* edge_69;
    Edge* edge_70;
    Edge* edge_71;
    Edge* edge_72;
    Edge* edge_73;
    Edge* edge_74;
    Edge* edge_75;
    Edge* edge_76;
    Edge* edge_77;
    Edge* edge_78;
    Edge* edge_79;
    Edge* edge_80;
    Edge* edge_81;
    Edge* edge_82;
    Edge* edge_83;
    Edge* edge_84;
    Edge* edge_85;
    Edge* edge_86;
    Edge* edge_87;
    Edge* edge_88;
    Edge* edge_89;
    Edge* edge_90;
    Edge* edge_91;
    Edge* edge_92;
    Edge* edge_93;
    Edge* edge_94;
    Edge* edge_95;
    Edge* edge_96;
    Edge* edge_97;
    Edge* edge_98;
    Edge* edge_99;
    Edge* edge_100;
    Edge* edge_101;
    Edge* edge_102;
    Edge* edge_103;
    Edge* edge_104;
    Edge* edge_105;
    Edge* edge_106;
    Edge* edge_107;
    Edge* edge_108;
    Edge* edge_109;
    Edge* edge_110;
    Edge* edge_111;
    Edge* edge_112;
    Edge* edge_113;
    Edge* edge_114;
    Edge* edge_115;
    Edge* edge_116;
    Edge* edge_117;
    Edge* edge_118;
    Edge* edge_119;
    Edge* edge_120;
    Edge* edge_121;
    Edge* edge_122;
    Edge* edge_123;
    Edge* edge_124;
    Edge* edge_125;
    Edge* edge_126;

    Edge* edge_1001;
    Edge* edge_1002;
    Edge* edge_1003;
    Edge* edge_1004;
    Edge* edge_1005;
    Edge* edge_1006;
    Edge* edge_1007;
    Edge* edge_1008;
    Edge* edge_1009;
    Edge* edge_1010;
    Edge* edge_1011;
    Edge* edge_1012;
    Edge* edge_1013;
    Edge* edge_1014;
    Edge* edge_1015;
    Edge* edge_1016;
    Edge* edge_1017;
    Edge* edge_1018;
    Edge* edge_1019;
    Edge* edge_1020;
    Edge* edge_1021;
    Edge* edge_1022;
    Edge* edge_1023;
    Edge* edge_1024;

    void init();
    void setbuttoncolor(int vex);

protected:

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *ev);
    bool eventFilter(QObject *watched, QEvent *ev);

private slots:

    void setComboStart();
    void setComboEnd();

    void comboBoxIndexChanged(int);

    void on_GuideBtn_clicked();
    void on_QuitBtn_clicked();

    void on_actionbangzhu_triggered();
    void on_actiontuichu_triggered();
    void on_actionbaocun_triggered();
    void on_actionguanyu_triggered();
    void on_actionjinnan_triggered();
    void on_actionxiaoqu_triggered();
    void on_actionfanhui_triggered();



    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void Print();
    void on_textBrowser_textChanged();
};
#endif // MAINWINDOW_H
