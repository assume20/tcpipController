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


const std::string EvtStr0 = "系统热复位";
const std::string EvtStr1 = "系统冷复位";
const std::string EvtStr2 = "控制箱外部电源掉电";
const std::string EvtStr3 = "控制箱外部电源恢复正常";
const std::string EvtStr4 = "火警消除";//"控制箱被打开";
const std::string EvtStr5 = "火警动作";//"控制箱被关闭";
const std::string EvtStr8 = "输入点短路";
const std::string EvtStr9 = "输入点断路";
const std::string EvtStr10 = "启用互锁";//"输入点开启";
const std::string EvtStr11 = "禁用互锁";//"输入点关闭";
const std::string EvtStr12 = "输出点开启";
const std::string EvtStr13 = "输出点关闭";
const std::string EvtStr16 = "出门按钮触发";
const std::string EvtStr17 = "出门按钮恢复";
const std::string EvtStr18 = "门锁打开";
const std::string EvtStr19 = "门锁关闭";
const std::string EvtStr20 = "门正常打开";
const std::string EvtStr21 = "门异常打开";
const std::string EvtStr22 = "门正常关闭";
const std::string EvtStr23 = "门异常关闭";
const std::string EvtStr24 = "门开超时";
const std::string EvtStr25 = "门未打开";
const std::string EvtStr26 = "门的工作模式状态改变";
const std::string EvtStr32 = "有效卡刷卡开门";
const std::string EvtStr33 = "使用非注册卡，刷卡无效";
const std::string EvtStr34 = "未授权的门点，刷卡无效";
const std::string EvtStr35 = "未授权的时间段，刷卡无效";
const std::string EvtStr36 = "错误的卡密码，刷卡无效";
const std::string EvtStr37 = "跟随进门，刷卡无效";
const std::string EvtStr38 = "错误的区域，刷卡无效";
const std::string EvtStr39 = "使用胁迫密码开门";
const std::string EvtStr40 = "使用超级密码开门";
const std::string EvtStr41 = "使用错误的超级密码进门，操作无效";
const std::string EvtStr48 = "有效卡刷卡出门";
const std::string EvtStr49 = "使用非注册卡，刷卡无效";
const std::string EvtStr50 = "未授权的门点，刷卡无效";
const std::string EvtStr51 = "未授权的时间段，刷卡无效";
const std::string EvtStr52 = "错误的卡密码，刷卡无效";
const std::string EvtStr53 = "跟随出门，刷卡无效";
const std::string EvtStr54 = "错误的区域，刷卡无效";
const std::string EvtStr55 = "使用胁迫密码出门";
const std::string EvtStr56 = "使用超级密码出门";
const std::string EvtStr57 = "使用错误的超级密码出门，操作无效";
const std::string EvtStr65 = "用户区域更改";
const std::string EvtStr256 = "控制器接通";
const std::string EvtStr257 = "控制器离线";
const std::string EvtStr300 = "使用挂失卡，刷卡无效";

//extern Date_t getNewDate(Date_t initDate, int diffDays);
extern QMutex g_eventMutex;
extern QMutex g_timeMutex;
extern QMutex g_databaseInit;
extern QMutex g_createDataMutex;
extern QMutex g_preCardDoorAddrMutex;
extern QMutex g_sucFileMutex;

extern 	QMap<QString, int> g_preCardDooraddrMap;

//尝试锁时间
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