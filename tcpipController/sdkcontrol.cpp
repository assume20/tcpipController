#include "sdkcontrol.h"
#include "global.h"
#include "eventthred.h"
#include <QSettings>
#include <QDebug>
#include <QTextCodec>


SDkcontrol::SDkcontrol()
{

    init();
}




void SDkcontrol::init()
{

    load();

    startGetEvent();

}



void SDkcontrol::startGetEvent()
{
    //建立线程 并启动
    //foreach (QString ip, m_controlInfoMap.keys())
    {
        m_pEventThred = new EVentthred();

		m_pEventThred->start();
        //m_eventThreadVec.push_back(pEventThred);
    }
}

SDkcontrol::~SDkcontrol()
{
    //foreach (EVentthred *pEventThread, m_eventThreadVec)
    {
        delete m_pEventThred;
    }

}



void SDkcontrol::load()
{
    QSettings fd("ipaddrconfig.ini", QSettings::IniFormat);
    fd.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QStringList grouplist = fd.childGroups();
    QStringList::iterator it = grouplist.begin();
    for(int row = 0; it != grouplist.end(); ++it, ++row)
    {

        QString ip = fd.value(QString("%1/ip").arg(*it),QString("-----")).toString();
        QString addr = fd.value(QString("%1/addr").arg(*it),QString("-----")).toString();


		g_controlInfoVec.push_back(qMakePair(ip, addr.toInt()));

    }


}





