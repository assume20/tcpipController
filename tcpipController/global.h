#pragma once
#include <iostream>
#include <QMutex>
#include <QtWidgets>

typedef struct Date
{
	int year;
	int month;
	int day;
}Date_t;


const std::string EvtStr0 = "ϵͳ�ȸ�λ";
const std::string EvtStr1 = "ϵͳ�临λ";
const std::string EvtStr2 = "�������ⲿ��Դ����";
const std::string EvtStr3 = "�������ⲿ��Դ�ָ�����";
const std::string EvtStr4 = "������";//"�����䱻��";
const std::string EvtStr5 = "�𾯶���";//"�����䱻�ر�";
const std::string EvtStr8 = "������·";
const std::string EvtStr9 = "������·";
const std::string EvtStr10 = "���û���";//"����㿪��";
const std::string EvtStr11 = "���û���";//"�����ر�";
const std::string EvtStr12 = "����㿪��";
const std::string EvtStr13 = "�����ر�";
const std::string EvtStr16 = "���Ű�ť����";
const std::string EvtStr17 = "���Ű�ť�ָ�";
const std::string EvtStr18 = "������";
const std::string EvtStr19 = "�����ر�";
const std::string EvtStr20 = "��������";
const std::string EvtStr21 = "���쳣��";
const std::string EvtStr22 = "�������ر�";
const std::string EvtStr23 = "���쳣�ر�";
const std::string EvtStr24 = "�ſ���ʱ";
const std::string EvtStr25 = "��δ��";
const std::string EvtStr26 = "�ŵĹ���ģʽ״̬�ı�";
const std::string EvtStr32 = "��Ч��ˢ������";
const std::string EvtStr33 = "ʹ�÷�ע�Ῠ��ˢ����Ч";
const std::string EvtStr34 = "δ��Ȩ���ŵ㣬ˢ����Ч";
const std::string EvtStr35 = "δ��Ȩ��ʱ��Σ�ˢ����Ч";
const std::string EvtStr36 = "����Ŀ����룬ˢ����Ч";
const std::string EvtStr37 = "������ţ�ˢ����Ч";
const std::string EvtStr38 = "���������ˢ����Ч";
const std::string EvtStr39 = "ʹ��в�����뿪��";
const std::string EvtStr40 = "ʹ�ó������뿪��";
const std::string EvtStr41 = "ʹ�ô���ĳ���������ţ�������Ч";
const std::string EvtStr48 = "��Ч��ˢ������";
const std::string EvtStr49 = "ʹ�÷�ע�Ῠ��ˢ����Ч";
const std::string EvtStr50 = "δ��Ȩ���ŵ㣬ˢ����Ч";
const std::string EvtStr51 = "δ��Ȩ��ʱ��Σ�ˢ����Ч";
const std::string EvtStr52 = "����Ŀ����룬ˢ����Ч";
const std::string EvtStr53 = "������ţ�ˢ����Ч";
const std::string EvtStr54 = "���������ˢ����Ч";
const std::string EvtStr55 = "ʹ��в���������";
const std::string EvtStr56 = "ʹ�ó����������";
const std::string EvtStr57 = "ʹ�ô���ĳ���������ţ�������Ч";
const std::string EvtStr65 = "�û��������";
const std::string EvtStr256 = "��������ͨ";
const std::string EvtStr257 = "����������";
const std::string EvtStr300 = "ʹ�ù�ʧ����ˢ����Ч";

//extern Date_t getNewDate(Date_t initDate, int diffDays);
extern QMutex g_eventMutex;
extern QMutex g_timeMutex;
extern QMutex g_databaseInit;
extern QMutex g_createDataMutex;
extern QMutex g_preCardDoorAddrMutex;
extern QMutex g_sucFileMutex;

extern 	QMap<QString, int> g_preCardDooraddrMap;

//������ʱ��
extern int g_TRYLOCKTIME;

extern QFile g_sucFile;



//class ipdoor
//{
//public:
//	qdatetime datatime;
//
//	qstring cardnumstr;
//
//	int ndooraddr;
//};


//extern QMap<QString, QVector<IPdoor>> g_ipDoorMap;