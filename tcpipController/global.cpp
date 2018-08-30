#include "global.h"

QMutex g_eventMutex;
QMutex g_timeMutex;
QMutex g_databaseInit;
QMutex g_createDataMutex;
QMutex g_preCardDoorAddrMutex;
QMutex g_sucFileMutex;

int g_TRYLOCKTIME = 1000 * 6;

QFile g_sucFile("sqlsuccess.txt");


QVector<QPair<QString, int>> g_controlInfoVec;

//QMap<QString, int> g_preCardDooraddrMap;

//QMap<QString, QVector<IPdoor>> g_ipDoorMap;