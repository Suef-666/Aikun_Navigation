#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include "solve.h"
#include "node.h"
#include "edge.h"
#include <QPainter>
#define MAXN 10000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1280,640);

    init();

    connect(ui->combo_start,SIGNAL(currentIndexChanged(int)),this,SLOT(comboBoxIndexChanged(int)));
    connect(ui->combo_end,SIGNAL(currentIndexChanged(int)),this,SLOT(comboBoxIndexChanged(int)));

    ui->combo_start->installEventFilter(this);
    ui->combo_end->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){

    //创建津南边缘，并入队
    Edge* edge_1 = new Edge(1,2,110);      Edge* edge_2 = new Edge(2,1,110);
    Edge* edge_3 = new Edge(1,11,100);     Edge* edge_4 = new Edge(11,1,100);
    Edge* edge_5 = new Edge(1,17,100);     Edge* edge_6 = new Edge(17,1,100);
    Edge* edge_7 = new Edge(2,12,100);     Edge* edge_8 = new Edge(12,2,100);
    Edge* edge_9 = new Edge(2,16,120);     Edge* edge_10 = new Edge(16,2,120);
    Edge* edge_11 = new Edge(2,20,150);    Edge* edge_12 = new Edge(20,2,150);
    Edge* edge_13 = new Edge(3,13,110);    Edge* edge_14 = new Edge(13,3,110);
    Edge* edge_15 = new Edge(3,16,10);     Edge* edge_16 = new Edge(16,3,10);
    Edge* edge_17 = new Edge(14,45,60);    Edge* edge_18 = new Edge(45,14,60);
    Edge* edge_19 = new Edge(3,15,80);     Edge* edge_20 = new Edge(3,15,80);
    Edge* edge_21 = new Edge(4,22,90);     Edge* edge_22 = new Edge(22,4,90);
    Edge* edge_23 = new Edge(4,23,40);     Edge* edge_24 = new Edge(23,4,40);
    Edge* edge_25 = new Edge(4,5,150);     Edge* edge_26 = new Edge(5,4,150);
    Edge* edge_27 = new Edge(4,27,220);    Edge* edge_28 = new Edge(27,4,220);
    Edge* edge_29 = new Edge(5,6,220);     Edge* edge_30 = new Edge(6,5,220);
    Edge* edge_31 = new Edge(6,26,40);     Edge* edge_32 = new Edge(26,6,40);
    Edge* edge_33 = new Edge(6,29,220);    Edge* edge_34 = new Edge(29,6,220);
    Edge* edge_35 = new Edge(7,28,100);    Edge* edge_36 = new Edge(28,7,100);
    Edge* edge_37 = new Edge(7,31,100);    Edge* edge_38 = new Edge(31,7,100);
    Edge* edge_39 = new Edge(7,30,100);    Edge* edge_40 = new Edge(30,7,100);
    Edge* edge_41 = new Edge(8,42,100);    Edge* edge_42 = new Edge(42,8,100);
    Edge* edge_43 = new Edge(8,38,150);    Edge* edge_44 = new Edge(38,8,150);
    Edge* edge_45 = new Edge(8,35,100);    Edge* edge_46 = new Edge(35,8,100);
    Edge* edge_47 = new Edge(8,30,100);    Edge* edge_48 = new Edge(30,8,100);
    Edge* edge_49 = new Edge(9,40,110);    Edge* edge_50 = new Edge(40,9,110);
    Edge* edge_51 = new Edge(9,41,100);    Edge* edge_52 = new Edge(41,9,100);
    Edge* edge_53 = new Edge(9,44,110);    Edge* edge_54 = new Edge(44,9,110);
    Edge* edge_55 = new Edge(10,37,100);   Edge* edge_56 = new Edge(37,10,100);
    Edge* edge_57 = new Edge(10,34,30);    Edge* edge_58 = new Edge(34,10,30);
    Edge* edge_59 = new Edge(11,12,110);   Edge* edge_60 = new Edge(12,11,110);
    Edge* edge_61 = new Edge(12,13,130);   Edge* edge_62 = new Edge(13,12,130);
    Edge* edge_63 = new Edge(13,14,40);    Edge* edge_64 = new Edge(14,13,40);
    Edge* edge_65 = new Edge(14,15,110);   Edge* edge_66 = new Edge(15,14,110);
    Edge* edge_67 = new Edge(15,22,150);   Edge* edge_68 = new Edge(22,15,150);
    Edge* edge_69 = new Edge(16,21,150);   Edge* edge_70 = new Edge(21,16,150);
    Edge* edge_71 = new Edge(17,18,90);    Edge* edge_72 = new Edge(18,17,90);
    Edge* edge_73 = new Edge(18,19,110);   Edge* edge_74 = new Edge(19,18,110);
    Edge* edge_75 = new Edge(19,20,40);    Edge* edge_76 = new Edge(20,19,40);
    Edge* edge_77 = new Edge(20,21,120);   Edge* edge_78 = new Edge(21,20,120);
    Edge* edge_79 = new Edge(21,22,40);    Edge* edge_80 = new Edge(22,21,40);
    Edge* edge_81 = new Edge(23,24,220);   Edge* edge_82 = new Edge(23,24,220);
    Edge* edge_83 = new Edge(23,26,370);   Edge* edge_84 = new Edge(26,23,370);
    Edge* edge_85 = new Edge(24,25,370);   Edge* edge_86 = new Edge(25,24,370);
    Edge* edge_87 = new Edge(25,26,180);   Edge* edge_88 = new Edge(26,25,180);
    Edge* edge_89 = new Edge(27,28,150);   Edge* edge_90 = new Edge(28,27,150);
    Edge* edge_91 = new Edge(28,29,150);   Edge* edge_92 = new Edge(29,28,150);
    Edge* edge_93 = new Edge(27,30,180);   Edge* edge_94 = new Edge(30,27,180);
    Edge* edge_95 = new Edge(27,43,40);    Edge* edge_96 = new Edge(43,27,40);
    Edge* edge_97 = new Edge(29,31,110);   Edge* edge_98 = new Edge(31,29,110);
    Edge* edge_99 = new Edge(32,33,100);   Edge* edge_100 = new Edge(33,32,100);
    Edge* edge_101 = new Edge(32,34,110);  Edge* edge_102 = new Edge(34,32,110);
    Edge* edge_103 = new Edge(33,35,110);  Edge* edge_104 = new Edge(35,33,110);
    Edge* edge_105 = new Edge(34,35,100);  Edge* edge_106 = new Edge(35,34,100);
    Edge* edge_107 = new Edge(36,37,60);   Edge* edge_108 = new Edge(37,36,60);
    Edge* edge_109 = new Edge(36,39,90);   Edge* edge_110 = new Edge(39,36,90);
    Edge* edge_111 = new Edge(37,38,50);   Edge* edge_112 = new Edge(38,37,50);
    Edge* edge_113 = new Edge(38,41,100);  Edge* edge_114 = new Edge(51,38,100);
    Edge* edge_115 = new Edge(39,40,100);  Edge* edge_116 = new Edge(40,39,100);
    Edge* edge_117 = new Edge(39,41,110);  Edge* edge_118 = new Edge(41,39,110);
    Edge* edge_119 = new Edge(40,45,160);  Edge* edge_120 = new Edge(45,40,160);
    Edge* edge_121 = new Edge(41,42,150);  Edge* edge_122 = new Edge(42,41,150);
    Edge* edge_123 = new Edge(42,43,100);  Edge* edge_124 = new Edge(43,42,100);
    Edge* edge_125 = new Edge(43,44,20);   Edge* edge_126 = new Edge(44,43,20);

    //津南边缘入队
    JinnanEdgeList<<edge_1<<edge_2<<edge_3<<edge_4<<edge_5<<edge_6<<edge_7<<edge_8<<edge_9<<edge_10
                  <<edge_11<<edge_12<<edge_13<<edge_14<<edge_15<<edge_16<<edge_17<<edge_18<<edge_19<<edge_20
                  <<edge_21<<edge_22<<edge_23<<edge_24<<edge_25<<edge_26<<edge_27<<edge_28<<edge_29<<edge_30
                  <<edge_31<<edge_32<<edge_33<<edge_34<<edge_35<<edge_36<<edge_37<<edge_38<<edge_39<<edge_40
                  <<edge_41<<edge_42<<edge_43<<edge_44<<edge_45<<edge_46<<edge_47<<edge_48<<edge_49<<edge_50
                  <<edge_51<<edge_52<<edge_53<<edge_54<<edge_55<<edge_56<<edge_57<<edge_58<<edge_59<<edge_60
                  <<edge_61<<edge_62<<edge_63<<edge_64<<edge_65<<edge_66<<edge_67<<edge_68<<edge_69<<edge_70
                  <<edge_71<<edge_72<<edge_73<<edge_74<<edge_75<<edge_76<<edge_77<<edge_78<<edge_79<<edge_80
                  <<edge_81<<edge_82<<edge_83<<edge_84<<edge_85<<edge_86<<edge_87<<edge_88<<edge_89<<edge_90
                  <<edge_91<<edge_92<<edge_93<<edge_94<<edge_95<<edge_96<<edge_97<<edge_98<<edge_99<<edge_100
                  <<edge_101<<edge_102<<edge_103<<edge_104<<edge_105<<edge_106<<edge_107<<edge_108<<edge_109<<edge_110
                  <<edge_111<<edge_112<<edge_113<<edge_114<<edge_115<<edge_116<<edge_117<<edge_118<<edge_119<<edge_120
                  <<edge_121<<edge_122<<edge_123<<edge_124<<edge_125<<edge_126;

    //创建校区边缘，并入队
    Edge* edge_1001 = new Edge(9,13,4);    Edge* edge_1002 = new Edge(13,9,4);
    Edge* edge_1003 = new Edge(6,7,36);Edge* edge_1004 = new Edge(7,6,36);
    Edge* edge_1005 = new Edge(5,6,6);Edge* edge_1006 = new Edge(6,5,6);
    Edge* edge_1007 = new Edge(4,5,17);Edge* edge_1008 = new Edge(5,4,17);
    Edge* edge_1009 = new Edge(10,13,8);Edge* edge_1010 = new Edge(13,10,8);
    Edge* edge_1011 = new Edge(7,13,12);Edge* edge_1012 = new Edge(13,7,12);
    Edge* edge_1013 = new Edge(8,13,12);Edge* edge_1014 = new Edge(13,8,12);
    Edge* edge_1015 = new Edge(7,9,2);Edge* edge_1016 = new Edge(9,7,2);
    Edge* edge_1017 = new Edge(7,8,3);Edge* edge_1018 = new Edge(8,7,3);
    Edge* edge_1019 = new Edge(8,10,5);Edge* edge_1020 = new Edge(10,8,5);
    Edge* edge_1021 = new Edge(3,13,45);Edge* edge_1022 = new Edge(13,3,45);
    Edge* edge_1023 = new Edge(2,13,70);Edge* edge_1024 = new Edge(13,2,70);

    //校区边缘入队
    XiaoquEdgeList<<edge_1001<<edge_1002<<edge_1003<<edge_1004<<edge_1005<<edge_1006<<edge_1007<<edge_1008<<edge_1009<<edge_1010
                  <<edge_1011<<edge_1012<<edge_1013<<edge_1014<<edge_1015<<edge_1016<<edge_1017<<edge_1018<<edge_1019<<edge_1020
                  <<edge_1021<<edge_1022<<edge_1023<<edge_1024;

    //创建津南结点
    node_1 = new Node(320 + 4 , 374 + 7 , 1 ,"理科宿舍楼");
    node_2 = new Node(319 + 4 , 331 + 10 , 2 ,"第二食堂");
    node_3 = new Node(318 + 4 , 293 - 1 , 3 ,"人工智能学院楼");
    node_4 = new Node(450 + 4 , 271 + 7 , 4 ,"公共教学楼");
    node_5 = new Node(545 + 4 , 260 + 8 , 5 ,"津南图书馆");
    node_6 = new Node(678 + 5 , 236 + 7 , 6 ,"大通学生活动中心");
    node_7 = new Node(504 + 4 , 115 + 6 , 7 ,"津南体育馆");
    node_8 = new Node(365 + 4 , 116 + 6 , 8 ,"文科宿舍楼");
    node_9 = new Node(284 + 3 , 193 + 7 , 9 ,"文科学院楼");
    node_10 = new Node(253 + 4 , 74 + 4 , 10 ,"第一食堂");
    node_11 = new Node(258 + 4 , 375 + 5 , 11 );
    node_12 = new Node(253 + 4 , 334 + 5 , 12 );
    node_13 = new Node(249 + 4, 286 + 5 , 13 );
    node_14 = new Node(247 +3 , 263 + 7 , 14 );
    node_15 = new Node(316 , 263 + dy , 15 );
    node_16 = new Node(317 + 4 , 295 + 9 , 16 );
    node_17 = new Node(380 , 371 + dy , 17 );
    node_18 = new Node(433 , 368 + dy , 18 );
    node_19 = new Node(430 , 328 + dy , 19 );
    node_20 = new Node(403 + 3 , 329 + 8 , 20 );
    node_21 = new Node(398 + 4 , 291 + 9 , 21 );
    node_22 = new Node(395 + 4, 265 + 5 , 22 );
    node_23 = new Node(460 , 295 + dy , 23 );
    node_24 = new Node(492 , 361 + dy , 24 );
    node_25 = new Node(704 , 331 + dy , 25 );
    node_26 = new Node(688 , 261 + dy , 26 );
    node_27 = new Node(422 + 4 , 178 + 8 , 27 );
    node_28 = new Node(522 + 6 , 166 + 7 , 28 );
    node_29 = new Node(641 + 8 , 150 + 5 , 29 );
    node_30 = new Node(431 + 2 , 116 + 6 , 30 );
    node_31 = new Node(586 + 8 , 96 + 4 , 31 );
    node_32 = new Node(282 , 23 + dy , 32 );
    node_33 = new Node(357 , 19 + dy , 33 );
    node_34 = new Node(284 + 2 , 72 + 4 , 34 );
    node_35 = new Node(362 + 4 , 70 + 3 , 35 );
    node_36 = new Node(198 + 4 , 123 + 4 , 36 );
    node_37 = new Node(255 + 3 , 121 + 4 , 37 );
    node_38 = new Node(279 + 2 , 119 + 6 , 38 );
    node_39 = new Node(210 + 1 , 161 + 4 , 39 );
    node_40 = new Node(212 + 3 , 195 + 4 , 40 );
    node_41 = new Node(281 + 1 , 161 + 7 , 41 );
    node_42 = new Node(366 + 4 , 156 + 4 , 42 );
    node_43 = new Node(366 + 7 , 189 + 6 , 43 );
    node_44 = new Node(348 + 2 , 192 + 6 , 44 );
    node_45 = new Node(210 + 1 , 250 + 14 , 45 );

    //设定真值
    node_1->setReal(1);
    node_2->setReal(1);
    node_3->setReal(1);
    node_4->setReal(1);
    node_5->setReal(1);
    node_6->setReal(1);
    node_7->setReal(1);
    node_8->setReal(1);
    node_9->setReal(1);
    node_10->setReal(1);

    //结点入队
    JinnanNodeList<<node_1;
    JinnanNodeList<<node_2;
    JinnanNodeList<<node_3;
    JinnanNodeList<<node_4;
    JinnanNodeList<<node_5;
    JinnanNodeList<<node_6;
    JinnanNodeList<<node_7;
    JinnanNodeList<<node_8;
    JinnanNodeList<<node_9;
    JinnanNodeList<<node_10;
    JinnanNodeList<<node_11;
    JinnanNodeList<<node_12;
    JinnanNodeList<<node_13;
    JinnanNodeList<<node_14;
    JinnanNodeList<<node_15;
    JinnanNodeList<<node_16;
    JinnanNodeList<<node_17;
    JinnanNodeList<<node_18;
    JinnanNodeList<<node_19;
    JinnanNodeList<<node_20;
    JinnanNodeList<<node_21;
    JinnanNodeList<<node_22;
    JinnanNodeList<<node_23;
    JinnanNodeList<<node_24;
    JinnanNodeList<<node_25;
    JinnanNodeList<<node_26;
    JinnanNodeList<<node_27;
    JinnanNodeList<<node_28;
    JinnanNodeList<<node_29;
    JinnanNodeList<<node_30;
    JinnanNodeList<<node_31;
    JinnanNodeList<<node_32;
    JinnanNodeList<<node_33;
    JinnanNodeList<<node_34;
    JinnanNodeList<<node_35;
    JinnanNodeList<<node_36;
    JinnanNodeList<<node_37;
    JinnanNodeList<<node_38;
    JinnanNodeList<<node_39;
    JinnanNodeList<<node_40;
    JinnanNodeList<<node_41;
    JinnanNodeList<<node_42;
    JinnanNodeList<<node_43;
    JinnanNodeList<<node_44;
    JinnanNodeList<<node_45;

    if(isStart == 0){
        ui->textBrowser->setText("欢迎来到南开导航系统！");
        ui->textBrowser->append("请选择您希望的 导航模式！");

        //初始隐藏按钮
        ui->pushButton_1->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();
        ui->pushButton_6->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();

        //初始化图标
        icon1.addFile(tr(":/button.png"));
        icon2.addFile(tr(":/button2.png"));

        //设置按钮图标
        ui->pushButton_1->setIcon(icon1);
        ui->pushButton_2->setIcon(icon1);
        ui->pushButton_3->setIcon(icon1);
        ui->pushButton_4->setIcon(icon1);
        ui->pushButton_5->setIcon(icon1);
        ui->pushButton_6->setIcon(icon1);
        ui->pushButton_7->setIcon(icon1);
        ui->pushButton_8->setIcon(icon1);
        ui->pushButton_9->setIcon(icon1);
        ui->pushButton_10->setIcon(icon1);

        //去除按钮边界
        ui->pushButton_1->setFlat(true);
        ui->pushButton_2->setFlat(true);
        ui->pushButton_3->setFlat(true);
        ui->pushButton_4->setFlat(true);
        ui->pushButton_5->setFlat(true);
        ui->pushButton_6->setFlat(true);
        ui->pushButton_7->setFlat(true);
        ui->pushButton_8->setFlat(true);
        ui->pushButton_9->setFlat(true);
        ui->pushButton_10->setFlat(true);

        //去除按钮背景
        ui->pushButton_1->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_2->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_3->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_4->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_5->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_6->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_7->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_8->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_9->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        ui->pushButton_10->setStyleSheet("QPushButton{color:white; background-color:transparent;}");

        //设置按钮位置
        ui->pushButton_1->setGeometry(312,324,25,30);
        ui->pushButton_2->setGeometry(311,281,25,30);
        ui->pushButton_3->setGeometry(310,235,25,30);
        ui->pushButton_4->setGeometry(442,221,25,30);
        ui->pushButton_5->setGeometry(537,210,25,30);
        ui->pushButton_6->setGeometry(672,186,25,30);
        ui->pushButton_7->setGeometry(496,65,25,30);
        ui->pushButton_8->setGeometry(357,66,25,30);
        ui->pushButton_9->setGeometry(276,143,25,30);
        ui->pushButton_10->setGeometry(245,21,25,30);

        //清空comboBox的内容，再初始化数据，用于comboBox的设置
        JinnanList.clear();
        JinnanList<<tr("理科宿舍楼")
                  <<tr("第二食堂")
                  <<tr("人工智能学院楼")
                  <<tr("公共教学楼")
                  <<tr("津南图书馆")
                  <<tr("大通学生活动中心")
                  <<tr("津南体育馆")
                  <<tr("文科宿舍楼")
                  <<tr("文科学院楼")
                  <<tr("第一食堂");

        XiaoquList.clear();
        XiaoquList<<tr("津南校区")
                  <<tr("八里台校区");

        ui->combo_start->clear();
        ui->combo_end->clear();

        ui->combo_start->addItem("起始点");
        ui->combo_end->addItem("目的地");

        isStart = 1;
    }

    //创建跨校区结点
    node_101 = new Node(1,"津南校区");
    node_102 = new Node(2,"津南校区西门站");
    node_103 = new Node(3,"津南校区梨园站");
    node_104 = new Node(4,"南开大学津南校区站");
    node_105 = new Node(5,"渌水道站6M号线");
    node_106 = new Node(6,"渌水道站6号线");
    node_107 = new Node(7,"红旗南路站6号线");
    node_108 = new Node(8,"红旗南路站3号线");
    node_109 = new Node(9,"一中心医院站");
    node_110 = new Node(10,"天塔站");
    node_111 = new Node(11,"八里台校区西门点对点站");
    node_112 = new Node(12,"八里台校区西门快线站");
    node_113 = new Node(13,"八里台校区");

    //设定真值
    node_101->setReal(1);
    node_113->setReal(1);

    //节点入队
    XiaoquNodeList<<node_101;
    XiaoquNodeList<<node_102;
    XiaoquNodeList<<node_103;
    XiaoquNodeList<<node_104;
    XiaoquNodeList<<node_105;
    XiaoquNodeList<<node_106;
    XiaoquNodeList<<node_107;
    XiaoquNodeList<<node_108;
    XiaoquNodeList<<node_109;
    XiaoquNodeList<<node_110;
    XiaoquNodeList<<node_111;
    XiaoquNodeList<<node_112;
    XiaoquNodeList<<node_113;

    //初始化图层
    G = new SolveGraph(JinnanEdgeList,45);
    T = new SolveGraph(XiaoquEdgeList,13);

    //初始化图片显示
    currentImagePath = ":/title.jpg";  // 初始化为 title.jpg 图片路径
    showLine = false;  // 初始化为不显示直线

    map = 3;

    //在初始页面下不需要以下功能
    ui->combo_start->hide();
    ui->combo_end->hide();
    ui->m_time->hide();
    ui->label_3->hide();
    ui->GuideBtn->setDisabled(true);

}

void MainWindow::Print(){

    //先清空文本框，防止内容对冲，鲁棒性
    ui->textBrowser->clear();

    //在textBrower输出
    if(map == 0){//津南模式输出
        ui->textBrowser->clear();
        ui->textBrowser->append("当前模式为 津南");
        ui->textBrowser->append("出发时间为 " + QString::number(DateNow.year()) + " 年 " + QString::number(DateNow.month()) + " 月 " + QString::number(DateNow.day()) + " 日 " + QString::number(TimeNow.hour()) + " 时 " + QString::number(TimeNow.minute()) + " 分 ");
        ui->textBrowser->insertPlainText("今天是 ");
        switch (DateNow.dayOfWeek()) {
            case 1:
                ui->textBrowser->insertPlainText("可怕的星期一😴");
                break;
            case 2:
                ui->textBrowser->insertPlainText("忙碌的星期二😔");
                break;
            case 3:
                ui->textBrowser->insertPlainText("惊心的星期三😧");
                break;
            case 4:
                ui->textBrowser->insertPlainText("疯狂的星期四👅");
                break;
            case 5:
                ui->textBrowser->insertPlainText("希望的星期五😁");
                break;
            case 6:
                ui->textBrowser->insertPlainText("慵懒的星期六😪");
                break;
            case 7:
                ui->textBrowser->insertPlainText("紧张的星期日😒");
                break;
        }
        ui->textBrowser->insertPlainText("\n");

        ui->textBrowser->append("导航路线如下：");

        int cnt = JinnanSolve->getCount();
        p = JinnanSolve->getRoute();
        int dis = JinnanSolve->distance(G);
        while(dis < 0 || dis > 10000){
            dis = JinnanSolve->distance(G);
        }

        for(int i = 0 ; i < cnt ; i++){
            if(i == 0){
                ui->textBrowser->append("从起始点 " + JinnanNodeList.at(p[i]-1)->getName() + " 出发，");
                ui->textBrowser->insertPlainText("分别经过 " + JinnanNodeList.at(p[i]-1)->getName());
            }

            if(JinnanNodeList.at(p[i]-1)->getName() != 0 && i != 0){
                ui->textBrowser->insertPlainText("、 " + JinnanNodeList.at(p[i]-1)->getName());
            }

            if(i == cnt - 1){
                ui->textBrowser->insertPlainText("\n");
                ui->textBrowser->append("最终到达目的地 " + JinnanNodeList.at(p[i]-1)->getName());
                ui->textBrowser->append("预计总路程为： " + QString::number(dis , 10) + " 米。");
            }
        }
    }

    else if(map == 1){//跨校区模式输出

        ui->textBrowser->append("当前模式为 跨校区");


        ui->textBrowser->append("出发时间为 " + QString::number(DateNow.year()) + " 年 " + QString::number(DateNow.month()) + " 月 " + QString::number(DateNow.day()) + " 日 " + QString::number(TimeNow.hour()) + " 时 " + QString::number(TimeNow.minute()) + " 分 ");
        ui->textBrowser->insertPlainText("今天是 ");
        switch (DateNow.dayOfWeek()) {
            case 1:
                ui->textBrowser->insertPlainText("可怕的星期一😴");
                break;
            case 2:
                ui->textBrowser->insertPlainText("忙碌的星期二😔");
                break;
            case 3:
                ui->textBrowser->insertPlainText("惊心的星期三😧");
                break;
            case 4:
                ui->textBrowser->insertPlainText("疯狂的星期四👅");
                break;
            case 5:
                ui->textBrowser->insertPlainText("希望的星期五😁");
                break;
            case 6:
                ui->textBrowser->insertPlainText("慵懒的星期六😪");
                break;
            case 7:
                ui->textBrowser->insertPlainText("紧张的星期日😒");
                break;

        }
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->append("导航路线如下：");

        way=XiaoquSolve->getWay();
        int cnt = XiaoquSolve->getCount();
        int waitTime = XiaoquSolve->getWaitTime();
        int *p = XiaoquSolve->getRoute();
        int tim = XiaoquSolve->time(T);
        while(tim < 0 || tim > 1000){
            tim = XiaoquSolve->time(T);
        }

        if(way == 0){//采用地铁出行
            wayway=0;
            for(int i = 0 ; i < cnt ; i++){
                if(i == 0){
                    ui->textBrowser->append("从起始点 " + XiaoquNodeList.at(p[i]-1)->getName() + " 出发，");
                    ui->textBrowser->append("在 " + XiaoquNodeList.at(p[i+1])->getName() + " 乘坐地铁，预计等待 " + QString::number(waitTime) + " 分钟。");
                    ui->textBrowser->insertPlainText("分别经过 " + XiaoquNodeList.at(p[i]-1)->getName());
                }

                if(XiaoquNodeList.at(p[i]-1)->getName() != 0 && i != 0){
                    ui->textBrowser->insertPlainText("、 " + XiaoquNodeList.at(p[i]-1)->getName());
                }

                if(i == cnt - 1){
                    ui->textBrowser->insertPlainText("\n");
                    ui->textBrowser->append("最终到达目的地 " + XiaoquNodeList.at(p[i]-1)->getName());
                    ui->textBrowser->append("预计乘车总时长为： " + QString::number(tim , 10) + " 分钟。");
                }
            }
        }

        if(way == 1){//采用公交出行
            for(int i = 0 ; i < cnt ; i++){
                if(i == 0){
                    ui->textBrowser->append("从起始点 " + XiaoquNodeList.at(p[i]-1)->getName() + " 出发，");

                    if(XiaoquNodeList.at(p[i+1]-1)->getIndex() == 2 || XiaoquNodeList.at(p[i+1]-1)->getIndex() == 12)
                    {
                        ui->textBrowser->append("在 " + XiaoquNodeList.at(p[i]-1)->getName() + " 乘坐612路公交车快线，预计等待 " + QString::number(waitTime) + " 分钟。");
                        wayway=612;
                    }
                    if(XiaoquNodeList.at(p[i+1]-1)->getIndex() == 3 || XiaoquNodeList.at(p[i+1]-1)->getIndex() == 11)
                    {
                        ui->textBrowser->append("在 " + XiaoquNodeList.at(p[i]-1)->getName() + " 乘坐点对点公交车，预计等待 " + QString::number(waitTime) + " 分钟。");
                        wayway=101;
                    }
                    ui->textBrowser->insertPlainText("分别经过 " + XiaoquNodeList.at(p[i]-1)->getName());
                }

                if(XiaoquNodeList.at(p[i]-1)->getName() != 0 && i != 0){
                    ui->textBrowser->insertPlainText("、 " + XiaoquNodeList.at(p[i]-1)->getName());
                }

                if(i == cnt - 1){
                    ui->textBrowser->insertPlainText("\n");
                    ui->textBrowser->append("最终到达目的地 " + XiaoquNodeList.at(p[i]-1)->getName());
                    ui->textBrowser->append("预计乘车总时长为： " + QString::number(tim , 10) + " 分钟。");
                }
            }
        }
    }

}

void MainWindow::paintEvent(QPaintEvent *event) {

    QMainWindow::paintEvent(event);

    QPainter painter(this);

        // 绘制图片，先显示图片
        if (!currentImagePath.isEmpty())
        {
            QWidget *widget = ui->JinnanWidget;
            QRect targetRect = QRect(0, 0, widget->width(), widget->height());
            QPixmap pix(currentImagePath);
            painter.drawPixmap(targetRect, pix, pix.rect());
        }

        if (showLine)
        {
            int cnt = JinnanSolve->getCount();
            p = JinnanSolve->getRoute();

            //初始化画笔
            QPen pen(Qt::red);  // 创建红色画笔
            pen.setWidth(3);  // 设置线条宽度为2像素
            pen.setStyle(Qt::DashLine);//设置为虚线
            pen.setCapStyle(Qt::RoundCap);
            pen.setJoinStyle(Qt::RoundJoin);
            painter.setPen(pen);

            //依次绘图，画出路线
            for(int i = 0; i < cnt-1;i++){
                painter.drawLine(JinnanNodeList.at(p[i]-1)->poi(),JinnanNodeList.at(p[i+1]-1)->poi());
            }
        }
}

void MainWindow::keyPressEvent(QKeyEvent *ev){

    switch (ev->key()) {
        case Qt::Key_Escape:                                        //Esc 退出程序
            this->close();
            break;
        case Qt::Key_Enter:                                         //Enter 运行程序
            on_GuideBtn_clicked();
            break;

    }

    if(ev->modifiers() == Qt::ControlModifier){
        switch (ev->key()) {
            case Qt::Key_H:                                         //ctrl + H 帮助
                on_actionbangzhu_triggered();
                break;
            case Qt::Key_R:                                         //ctrl + R 返回
                on_actionfanhui_triggered();
                break;
            case Qt::Key_S:                                         //ctrl + S 保存
                on_actionbaocun_triggered();
                break;
            case Qt::Key_M:                                         //ctrl + M 切换地图模式
                if(map == 0)on_actionxiaoqu_triggered();
                else if(map == 1)on_actionjinnan_triggered();
                break;
            case Qt::Key_Tab:                                       //ctrl + Tab 切换combo选择
                if(combo == 0)setComboEnd();
                else if(combo == 1)setComboStart();
                break;
            case Qt::Key_1:                                         //ctrl + 1 地点1
                if(map != 0)break;
                on_pushButton_1_clicked();
                break;
            case Qt::Key_2:                                         //ctrl + 2 地点2
                if(map != 0)break;
                on_pushButton_2_clicked();
                break;
            case Qt::Key_3:                                         //ctrl + 3 地点3
                if(map != 0)break;
                on_pushButton_3_clicked();
                break;
            case Qt::Key_4:                                         //ctrl + 4 地点4
                if(map != 0)break;
                on_pushButton_4_clicked();
                break;
            case Qt::Key_5:                                         //ctrl + 5 地点5
                if(map != 0)break;
                on_pushButton_5_clicked();
                break;
            case Qt::Key_6:                                         //ctrl + 6 地点6
                if(map != 0)break;
                on_pushButton_6_clicked();
                break;
            case Qt::Key_7:                                         //ctrl + 7 地点7
                if(map != 0)break;
                on_pushButton_7_clicked();
                break;
            case Qt::Key_8:                                         //ctrl + 8 地点8
                if(map != 0)break;
                on_pushButton_8_clicked();
                break;
            case Qt::Key_9:                                         //ctrl + 9 地点9
                if(map != 0)break;
                on_pushButton_9_clicked();
                break;
            case Qt::Key_0:                                         //ctrl + 0 地点10
                if(map != 0)break;
                on_pushButton_10_clicked();
                break;
        }
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *ev){

    //用于获取comboBox的焦点
    if(watched == ui->combo_start){

        if(ev->type() == QEvent::FocusIn){
            setComboStart();
        }
    }
    if(watched == ui->combo_end){

        if(ev->type() == QEvent::FocusIn){
            setComboEnd();
        }
    }
    return QWidget::eventFilter(watched,ev);

}

void MainWindow::on_GuideBtn_clicked(){

    ui->textBrowser->clear();//鲁棒性
    if(ui->combo_start->currentIndex() == 0){
        ui->textBrowser->setText("您搁哪呢？");
        return ;
    }
    if(ui->combo_end->currentIndex() == 0){
        ui->textBrowser->append("您到哪去啊？");
        return ;
    }

    if(ui->combo_start->currentIndex() == ui->combo_end->currentIndex()){
        ui->textBrowser->setText("去不了！");
    }

    ui->textBrowser->clear();



    //Solve一下
    if(map == 0){
        start = ui->combo_start->currentIndex();
        end = ui->combo_end->currentIndex();

        DateNow = ui->m_time->date();
        TimeNow = ui->m_time->time();

        JinnanSolve->set(start , end , map );
        JinnanSolve->Route(G);
    }
    else if(map == 1){

        start = ui->combo_start->currentIndex();
        if(start == 2)start = 13;
        end = ui->combo_end->currentIndex();
        if(end == 2)end = 13;

        DateNow = ui->m_time->date();
        TimeNow = ui->m_time->time();

        XiaoquSolve->set(start,end,map,DateNow,TimeNow);//先构造在运行
        XiaoquSolve->Route(T);//运行
    }

    //文本框输出路线
    Print();

    //初始化绘画模式
    if(map==0)
    {
        showLine = true;  // 设置showLine为true，表示显示直线
        currentImagePath = ":/jinnan.jpg";  // 设置当前图片路径为空，表示不显示图片
    }
    if(map==1)
    {
        showLine = false;  // 设置showLine为true，表示显示直线
        if(wayway==0)
        {
            currentImagePath = ":/ditie.jpg";  //

        }
        else if(wayway==612||wayway==101)
        {
            currentImagePath = ":/gongjiao.jpg";  //
        }
    }

    //绘图
    update();

}

void MainWindow::on_QuitBtn_clicked(){
    qApp->quit();
}

void MainWindow::on_actionbangzhu_triggered(){
    QMessageBox::about(NULL, "快捷键说明",  "Esc             退出\n"
                                          "Enter          开始运行\n"
                                          "Ctrl + n      选择地点n\n"
                                          "Ctrl + Tab  切换选择起始点/目的地\n"
                                          "Ctrl + M     切换选择地图模式\n"
                                          "Ctrl + H      帮助\n"
                                          "Ctrl + R      返回初始界面\n"
                                          "Ctrl + S       保存");
}

void MainWindow::on_actiontuichu_triggered(){
    qApp->quit();
}

void MainWindow::on_actionbaocun_triggered(){
    QMessageBox::about(NULL,"保存","已保存！");           //实际上未实现，意义上不需要这个功能
}

void MainWindow::on_actionguanyu_triggered(){
    QMessageBox::about(NULL,"关于","啊对对队：\n汤纪洋  \n孙骁健  \n刚子棉  \n闫纪杰  ");
}

void MainWindow::on_actionjinnan_triggered(){

    //鲁棒性
    if(map == 0){
        ui->textBrowser->clear();
        ui->textBrowser->append("已选择津南校区！");
        return ;
    }
    ui->textBrowser->clear();
    ui->textBrowser->append("切换当前模式为 津南模式！");
    ui->textBrowser->append("请选择您希望的 起始点 和 目的地 ！");
    ui->textBrowser->append("请选择您希望出发的 时间 ！");
    map = 0;

    //显示功能栏
    ui->combo_start->show();
    ui->combo_end->show();
    ui->m_time->show();
    ui->label_3->show();
    ui->GuideBtn->setDisabled(false);

    //显示地图
    currentImagePath = ":/jinnan.jpg";  // 设置当前图片路径为 jinnan.jpg
    update();

    setWindowTitle("NKU-map-jinnan");

    //显示按钮
    ui->pushButton_1->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();

    //重置comboBox的内容
    ui->combo_start->clear();
    ui->combo_end->clear();

    ui->combo_start->addItem("起始点");
    ui->combo_end->addItem("目的地");
    ui->combo_start->addItems(JinnanList);
    ui->combo_end->addItems(JinnanList);
}

void MainWindow::on_actionxiaoqu_triggered(){

    //鲁棒性
    if(map == 1){
        ui->textBrowser->clear();
        ui->textBrowser->append("已选择跨校区！");
        return ;
    }
    ui->textBrowser->clear();
    ui->textBrowser->append("切换当前模式为 跨校区模式！");
    ui->textBrowser->append("请选择您希望的 起始点 和 目的地 ！");
    ui->textBrowser->append("请选择您希望出发的 时间 ！");
    map = 1;

    //显示功能栏
    ui->combo_start->show();
    ui->combo_end->show();
    ui->m_time->show();
    ui->label_3->show();
    ui->GuideBtn->setDisabled(false);

    //显示地图
    showLine = false;
    currentImagePath = ":/xiaoqu.png";  // 设置当前图片路径为 xiaoqu.jpg
    update();  // 触发重绘

    setWindowTitle("NKU-map-xiaoqu");

    //隐藏按钮
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();

    //重置comboBox的内容
    ui->combo_start->clear();
    ui->combo_end->clear();

    ui->combo_start->addItem("起始点");
    ui->combo_end->addItem("目的地");
    ui->combo_start->addItems(XiaoquList);
    ui->combo_end->addItems(XiaoquList);
}

void MainWindow::on_actionfanhui_triggered(){

    //鲁棒性
    if(map == 3){
        ui->textBrowser->clear();
        ui->textBrowser->append("已返回初始页面！");
        return ;
    }
    ui->textBrowser->clear();
    ui->textBrowser->setText("返回 初始页面！");
    map = 3;

    //回归初始状态
    ui->combo_start->hide();
    ui->combo_end->hide();
    ui->m_time->hide();
    ui->label_3->hide();
    ui->GuideBtn->setDisabled(true);

    //显示初始界面
    currentImagePath = ":/title.jpg";  // 初始化为 title.jpg 图片路径
    showLine = false;  // 初始化为不显示直线
    update();  // 触发重绘

    //回归初始状态
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();

    //去除comboBox内容
    ui->combo_start->clear();
    ui->combo_end->clear();

    ui->combo_start->addItem("起始点");
    ui->combo_end->addItem("目的地");
}

void MainWindow::on_pushButton_1_clicked(){

    if(pBtn_1 == 0){//当目前按钮没有被按下
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("理科宿舍楼\n");

        if(combo == 0){//如果是comboStar
            ui->combo_start->setCurrentIndex(1);//首先是设置combo的当前值，这个函数会改变1的颜色
        }
        else {
            ui->combo_end->setCurrentIndex(1);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("理科宿舍楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(pBtn_2 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("第二食堂\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(2);
        }
        else {
            ui->combo_end->setCurrentIndex(2);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("第二食堂\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(pBtn_3 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("人工智能学院楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(3);
        }
        else {
            ui->combo_end->setCurrentIndex(3);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("人工智能学院楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(pBtn_4 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("公共教学楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(4);
        }
        else {
            ui->combo_end->setCurrentIndex(4);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("公共教学楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(pBtn_5 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("津南图书馆\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(5);
        }
        else {
            ui->combo_end->setCurrentIndex(5);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("津南图书馆\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(pBtn_6 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("大通学生活动中心\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(6);
        }
        else {
            ui->combo_end->setCurrentIndex(6);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("大通学生活动中心\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(pBtn_7 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("津南体育馆\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(7);
        }
        else {
            ui->combo_end->setCurrentIndex(7);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("津南体育馆\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(pBtn_8 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("文科宿舍楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(8);
        }
        else {
            ui->combo_end->setCurrentIndex(8);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("文科宿舍楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if(pBtn_9 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("文科学院楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(9);
        }
        else {
            ui->combo_end->setCurrentIndex(9);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("文科学院楼\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if(pBtn_10 == 0){
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("第一食堂\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(10);
        }
        else {
            ui->combo_end->setCurrentIndex(10);
        }
    }
    else {
        ui->textBrowser->insertPlainText("\n");
        ui->textBrowser->insertPlainText("已取消选择您的 ");
        if(combo == 0)
            ui->textBrowser->insertPlainText("起始点 为： ");
        else if(combo == 1)
            ui->textBrowser->insertPlainText("目的地 为： ");
        ui->textBrowser->insertPlainText("第一食堂\n");

        if(combo == 0){
            ui->combo_start->setCurrentIndex(0);
        }
        else {
            ui->combo_end->setCurrentIndex(0);
        }
    }
}

void MainWindow::setComboStart(){
    if(combo == 0)return ;
    ui->textBrowser->append("现在选择 起始点！");
    combo = 0;
}

void MainWindow::setComboEnd(){
    if(combo == 1)return ;
    ui->textBrowser->append("现在选择 目的地！");
    combo = 1;
}

void MainWindow::setbuttoncolor(int vex)
{
    //当即将改变按钮状态时，去除已经画出的路线
    showLine = 0;
    update();

    switch(vex)
    {
        case 0:
            ui->pushButton_1->setIcon(icon1);
            ui->pushButton_2->setIcon(icon1);
            ui->pushButton_3->setIcon(icon1);
            ui->pushButton_4->setIcon(icon1);
            ui->pushButton_5->setIcon(icon1);
            ui->pushButton_6->setIcon(icon1);
            ui->pushButton_7->setIcon(icon1);
            ui->pushButton_8->setIcon(icon1);
            ui->pushButton_9->setIcon(icon1);
            ui->pushButton_10->setIcon(icon1);
            pBtn_1 = 0;
            pBtn_2 = 0;
            pBtn_3 = 0;
            pBtn_4 = 0;
            pBtn_5 = 0;
            pBtn_6 = 0;
            pBtn_7 = 0;
            pBtn_8 = 0;
            pBtn_9 = 0;
            pBtn_10 = 0;
            break;
        case 1:
            ui->pushButton_1->setIcon(icon2);
            pBtn_1 = 1;
            break;
        case 2:
            ui->pushButton_2->setIcon(icon2);
            pBtn_2 = 1;
            break;
        case 3:
            ui->pushButton_3->setIcon(icon2);
            pBtn_3 = 1;
            break;
        case 4:
            ui->pushButton_4->setIcon(icon2);
            pBtn_4 = 1;
            break;
        case 5:
            ui->pushButton_5->setIcon(icon2);
            pBtn_5 = 1;
            break;
        case 6:
            ui->pushButton_6->setIcon(icon2);
            pBtn_6 = 1;
            break;
        case 7:
            ui->pushButton_7->setIcon(icon2);
            pBtn_7 = 1;
            break;
        case 8:
            ui->pushButton_8->setIcon(icon2);
            pBtn_8 = 1;
            break;
        case 9:
            ui->pushButton_9->setIcon(icon2);
            pBtn_9 = 1;
            break;
        case 10:
            ui->pushButton_10->setIcon(icon2);
            pBtn_10 = 1;
            break;

        }
}

void MainWindow::comboBoxIndexChanged(int index){

    //槽函数，先重置状态，再设置新状态
    if(isStart == 1){

        switch(index){
            case 1:
                setbuttoncolor(0);
                setbuttoncolor(1);
                break;
            case 2:
                setbuttoncolor(0);
                setbuttoncolor(2);
                break;
            case 3:
                setbuttoncolor(0);
                setbuttoncolor(3);
                break;
            case 4:
                setbuttoncolor(0);
                setbuttoncolor(4);
                break;
            case 5:
                setbuttoncolor(0);
                setbuttoncolor(5);
                break;
            case 6:
                setbuttoncolor(0);
                setbuttoncolor(6);
                break;
            case 7:
                setbuttoncolor(0);
                setbuttoncolor(7);
                break;
            case 8:
                setbuttoncolor(0);
                setbuttoncolor(8);
                break;
            case 9:
                setbuttoncolor(0);
                setbuttoncolor(9);
                break;
            case 10:
                setbuttoncolor(0);
                setbuttoncolor(10);
                break;
            case 0:
                setbuttoncolor(0);
                break;

        }

        //将之前已经按下的按钮重新显示
        if(combo == 0 && ui->combo_end->currentIndex() != 0){
            setbuttoncolor(ui->combo_end->currentIndex());
        }
        if(combo == 1 && ui->combo_start->currentIndex() != 0){
            setbuttoncolor(ui->combo_start->currentIndex());
        }
    }
}

void MainWindow::on_textBrowser_textChanged()
{
    //让textBrowser的显示内容始终自动移动到最底下
    ui->textBrowser->moveCursor(QTextCursor::End);
}
