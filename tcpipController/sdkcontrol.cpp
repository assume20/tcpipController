#include "sdkcontrol.h"
#include "ui_sdkcontrol.h"
#include "global.h"
#include "eventthred.h"
#include <QSettings>
#include <QDebug>
#include <QTextCodec>


SDkcontrol::SDkcontrol(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::SDkform())
{
    ui->setupUi(this);

	//createData();

    init();
}




void SDkcontrol::init()
{




	//RAW_LOG(INFO, "RAW_LOG");

    ui->tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->textEdit->document()->setMaximumBlockCount(40000);   //设置最大行数

    load();

    startGetEvent();

	


}



void SDkcontrol::startGetEvent()
{
    //建立线程 并启动
    foreach (QString ip, m_controlInfoMap.keys())
    {
        EVentthred *pEventThred = new EVentthred(this, ip, m_controlInfoMap[ip]);

        pEventThred->start();
        m_eventThreadVec.push_back(pEventThred);
    }
}

SDkcontrol::~SDkcontrol()
{
    foreach (EVentthred *pEventThread, m_eventThreadVec)
    {
        delete pEventThread;
    }
	delete ui;
}





void SDkcontrol::load()
{
    QSettings fd("ipaddrconfig.ini", QSettings::IniFormat);
    //fd.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QStringList grouplist = fd.childGroups();
    QStringList::iterator it = grouplist.begin();
    for(int row = 0; it != grouplist.end(); ++it, ++row)
    {
        ui->tab->insertRow(row);
        QString ip = fd.value(QString("%1/ip").arg(*it),QString("-----")).toString();
        QString addr = fd.value(QString("%1/addr").arg(*it),QString("-----")).toString();
        QTableWidgetItem *ipItem = new QTableWidgetItem(ip);
        QTableWidgetItem *addrItem = new QTableWidgetItem(addr);
        ipItem->setTextAlignment(Qt::AlignHCenter);
        addrItem->setTextAlignment(Qt::AlignHCenter);
        ui->tab->setItem(row, TABCOLUMN_IP, ipItem);
        ui->tab->setItem(row, TABCOLUMN_ADDR, addrItem);


        m_controlInfoMap.insert(ip, addr.toInt());

    }


}





void SDkcontrol::textEditUiSlot(QString text)
{
    ui->textEdit->append(text);
}



