#ifndef SDKCONTROL_H
#define SDKCONTROL_H
#include <QObject>
#include "drrs.h"
#include <QSqlDatabase>
#include <QDateTime>
#include <QMap>
#include <QVector>

typedef  int (__stdcall *pGetnameAndVer)(int serverport, char *clientip, uint8 dcuid,
                                         tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);


typedef int (__stdcall *pSetdatetime)(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);




class EVentthred;
class SDkcontrol: public QObject
{
	Q_OBJECT
public:
    explicit SDkcontrol();

    void init();


	//void createData();

    ~SDkcontrol();

    enum
    {
        TABCOLUMN_IP = 0,
        TABCOLUMN_ADDR
    };


private:


    void load();


    //建立并开启线程
    void startGetEvent();






private:

    QMap<QString, int> m_controlInfoMap;

    QVector<EVentthred *> m_eventThreadVec;

    QSqlDatabase m_dataBase;

	EVentthred *m_pEventThred;

};

#endif // SDKCONTROL_H
