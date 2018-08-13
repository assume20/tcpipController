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

typedef int (__stdcall *pGethisevent)(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);



class EVentthred: public QThread
{
    Q_OBJECT
public:
    EVentthred(QObject *parent,QString ip, int addr);

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

signals:
    void editTextUiSig(QString text);

public slots:
	void updateControlTime();



private:

	//static QMutex s_sqlMutex;

    QLibrary *m_myDll;

	//QMap<QString, int> m_preCardDooraddrMap;

    QMap<QString, QMap<int, QDateTime>> m_preDateTime;

    //QString m_prevIdStr;

	//int m_prevDoorAddr;


    QDateTime m_prevTime;

    std::string EvtStr[512];

    const int m_addr;
    const QString m_clientip;

    HBagEvt Bagevt;
    HISEVTLIST gevtlist;

    bool m_setTimeIsValid;

	bool m_bPrevIsSuc;


	QTimer *m_timer;


	MYSQL *m_pConn;

	//¿¨ºÅ ÊýÁ¿
	QMap<QString, int> m_cardNumMap;

	pGethisevent Gethisevent;



};

#endif // EVENTTHRED_H
