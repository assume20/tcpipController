#ifndef SDKCONTROL_H
#define SDKCONTROL_H
#include <QWidget>
#include "drrs.h"
#include<QSqlDatabase>
#include <QDateTime>
#include <QMap>

typedef  int (__stdcall *pGetnameAndVer)(int serverport, char *clientip, uint8 dcuid,
                                         tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);


typedef int (__stdcall *pSetdatetime)(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);


namespace Ui {
    class SDkform;
} // namespace Ui


class EVentthred;
class SDkcontrol : public QWidget
{
    Q_OBJECT
public:
    explicit SDkcontrol(QWidget *parent = 0);

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



public slots:

#if 0
	void databaseInit();
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_modify_clicked();
    void clickItemSlot(int row, int column);
#endif

    //
    void textEditUiSlot(QString text);


private:

    Ui::SDkform *ui;


    QMap<QString, int> m_controlInfoMap;

    QVector<EVentthred *> m_eventThreadVec;

    QSqlDatabase m_dataBase;



};

#endif // SDKCONTROL_H
