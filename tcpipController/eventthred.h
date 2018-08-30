#ifndef EVENTTHRED_H
#define EVENTTHRED_H
#include <QThread>
#include <QSqlDatabase>
#include <QLibrary>
#include <QDateTime>
#include <QMutex>
#include <QMap>
#include "drrs.h"
#include "QTimer"
#include <mysql.h>
#include <sstream>


typedef int (__stdcall *pGethisevent)(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);



class EVentthred: public QThread
{
    Q_OBJECT
public:
    EVentthred();

    ~EVentthred();


    void evtStrInit();

protected:

    void run();

private:
//    void databaseInit();

    bool sdkSetTime(QString ip, int addr);

	void databaseInit();

	void collectCardData();

	void tryExceptCall();


public slots:
	void updateControlTime();



private:

    QLibrary *m_myDll;


    std::string EvtStr[512];

    int m_addr;
    QString m_clientip;

    HBagEvt Bagevt;
    HISEVTLIST gevtlist;


	QMap<QString, HBagEvt> m_BagevtMap;

	QMap<QString, HISEVTLIST> m_gevtlistMap;

	//是否设置时间
    QMap<QString, bool>  m_setTimeIsValidMap;

	QTimer *m_timer;


	MYSQL *m_pConn;

	//卡号 数量
	QMap<QString, int> m_cardNumMap;

	pGethisevent Gethisevent;

	QString currentDateTime;

	QMap<QString, int> m_preCardDooraddrMap;

	//插入错误时 日志流
	std::stringstream m_errorStream;
	//打卡数据流
	std::stringstream m_clockInDataStream;

	//线程运行循环标志
	bool m_bIsRunning;

};

#endif // EVENTTHRED_H
