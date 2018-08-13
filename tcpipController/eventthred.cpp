#include "eventthred.h"
#include "global.h"
#include "sdkcontrol.h"
#include <sstream>
#include <QSqlQuery>
#include <QDateTime>
#include <QVariant>
#include <qDebug>
#include <QSqlError>
#include <QSettings>
#include <QTextCodec>
#include <QFile>
#include "glog/logging.h"

typedef int (__stdcall *pGethisevent)(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);
typedef  int (__stdcall *pGetnameAndVer)(int serverport, char *clientip, uint8 dcuid,
                                         tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);

typedef int (__stdcall *pSetdatetime)(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);

//QMutex EVentthred::s_sqlMutex;
EVentthred::EVentthred(QObject *parent, QString ip, int addr)
    : QThread(parent),
      m_clientip(ip),
      m_addr(addr),
      m_setTimeIsValid(false)
{

    connect(this, SIGNAL(editTextUiSig(QString)),
            parent, SLOT(textEditUiSlot(QString)));

    evtStrInit();
    memset(&Bagevt, 0, sizeof(Bagevt));
    memset(&gevtlist, 0, sizeof(gevtlist));


    m_myDll = new QLibrary("drrs.dll");
    if(!m_myDll->load())
    {
        emit editTextUiSig(QString::fromLocal8Bit("load dll fail!"));
    }

    databaseInit();

	m_timer = new QTimer(this);

	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateControlTime()));
	m_timer->start(1000 * 60 * 60 * 24);  //һ������һ��ʱ��
}

EVentthred::~EVentthred()
{
	//m_pDataBase->close();
	//delete m_pDataBase;
	//m_pDataBase->removeDatabase(m_clientip);
	delete m_myDll;
	mysql_close(m_pConn);
    terminate();
}

void EVentthred::databaseInit()
{
    

    QSettings fd("dbconfig.ini", QSettings::IniFormat);
    fd.setIniCodec(QTextCodec::codecForName("UTF-8"));

    QByteArray hostName = fd.value("config/servername", "0").toByteArray();
	QByteArray database = fd.value("config/database", "0").toByteArray();
	QByteArray userName = fd.value("config/username", "0").toByteArray();
	//qDebug() << userName;
	QByteArray password = fd.value("config/password", "0").toByteArray();

	g_databaseInit.lock();
	m_pConn = mysql_init(NULL);

	//��2��3��4��5��������˼�ֱ��ǣ���������ַ���û��������롢���ݿ�������6��Ϊmysql�˿ںţ�0ΪĬ��ֵ3306��

	if (!mysql_real_connect(m_pConn, hostName.constData(), userName.constData()
											,password.constData(), database.constData(), 0, NULL, 0))
	{
		emit editTextUiSig(QString::fromLocal8Bit("�޷��������ݿ�:%1").arg(mysql_error(m_pConn)));
	}
	else
	{
		emit editTextUiSig(QString::fromLocal8Bit("%1�������ݿ�ɹ�").arg((m_clientip)));
	}

	char value = 1;
	mysql_options(m_pConn, MYSQL_OPT_RECONNECT, (char *)&value);
	g_databaseInit.unlock();
	mysql_query(m_pConn, "set names gbk");//��ֹ���롣���ú����ݿ�ı���һ�¾Ͳ�������



#if 0
    /*sql server���÷�ʽ*/
    m_pDataBase->setDatabaseName(QString("DRIVER={SQL SERVER};"
                                       "SERVER=%1;"
                                       "DATABASE=%2;"
                                       "UID=%3;"
                                       "PWD=%4;")
                               .arg(hostName)
                               .arg(database)
                               .arg(userName)
                               .arg(password));
#endif

#if 0
	m_pDataBase = new QSqlDatabase();
	*m_pDataBase = QSqlDatabase::addDatabase("QMYSQL", m_clientip);
	//m_pDataBase = &m_dataBase;
    m_pDataBase->setHostName(hostName);
    m_pDataBase->setDatabaseName(database);
    m_pDataBase->setUserName(userName);
    m_pDataBase->setPassword(password);
	m_pDataBase->setConnectOptions("MYSQL_OPT_RECONNECT=1;");
    if (m_pDataBase->open())
    {
        emit editTextUiSig(QString::fromLocal8Bit("%1���ݿ����ӳɹ�!").arg(m_clientip));
    }
    else
    {
        emit editTextUiSig(QString::fromLocal8Bit("%1���ݿ�����ʧ��!").arg(m_clientip));
    }
#endif
}



void EVentthred::evtStrInit()
{
    EvtStr[0] = EvtStr0;
    EvtStr[1] = EvtStr1;
    EvtStr[2] = EvtStr2;
    EvtStr[3] = EvtStr3;
    EvtStr[4] = EvtStr4;
    EvtStr[5] = EvtStr5;
    EvtStr[8] = EvtStr8;
    EvtStr[9] = EvtStr9;
    EvtStr[10] = EvtStr10;
    EvtStr[11] = EvtStr11;
    EvtStr[12] = EvtStr12;
    EvtStr[13] = EvtStr13;
    EvtStr[16] = EvtStr16;
    EvtStr[17] = EvtStr17;
    EvtStr[18] = EvtStr18;
    EvtStr[19] = EvtStr19;
    EvtStr[20] = EvtStr20;
    EvtStr[21] = EvtStr21;
    EvtStr[22] = EvtStr22;
    EvtStr[23] = EvtStr23;
    EvtStr[24] = EvtStr24;
    EvtStr[25] = EvtStr25;
    EvtStr[26] = EvtStr26;
    EvtStr[32] = EvtStr32;
    EvtStr[33] = EvtStr33;
    EvtStr[34] = EvtStr34;
    EvtStr[35] = EvtStr35;
    EvtStr[36] = EvtStr36;
    EvtStr[37] = EvtStr37;
    EvtStr[38] = EvtStr38;
    EvtStr[39] = EvtStr39;
    EvtStr[40] = EvtStr40;
    EvtStr[41] = EvtStr41;
    EvtStr[48] = EvtStr48;
    EvtStr[49] = EvtStr49;
    EvtStr[50] = EvtStr50;
    EvtStr[51] = EvtStr51;
    EvtStr[52] = EvtStr52;
    EvtStr[53] = EvtStr53;
    EvtStr[54] = EvtStr54;
    EvtStr[55] = EvtStr55;
    EvtStr[56] = EvtStr56;
    EvtStr[57] = EvtStr57;
    EvtStr[65] = EvtStr65;
    EvtStr[256] = EvtStr256;
    EvtStr[257] = EvtStr257;
    EvtStr[300] = EvtStr300;
}


void EVentthred::updateControlTime()
{
	//����ʱ���־
	m_setTimeIsValid = false;
	LOG(INFO) << "enter set time The timer succeed!";
#if 0

	if (g_sucFileMutex.tryLock(g_TRYLOCKTIME))
	{
		if (g_sucFile.isOpen())
		{
			//��ʱ�ر�һ��
			g_sucFile.close();
			g_sucFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		}

		//>200Mʱ����ļ�����
		if (g_sucFile.size() > 1024 * 1024 * 200)
		{
			g_sucFile.close();
			g_sucFile.open(QFile::WriteOnly | QFile::Truncate);
		}
		g_sucFile.close();
		g_sucFileMutex.unlock();

	}

	QFile errFile("sqlerrrecord.txt");
	errFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	if (errFile.size() > 1024 * 1024 * 200)
	{
		errFile.close();
		errFile.open(QFile::WriteOnly | QFile::Truncate);
	}
	errFile.close();

#endif
	
}


bool EVentthred::sdkSetTime(QString ip, int addr)
{
    pSetdatetime Setdatetime=(pSetdatetime)m_myDll->resolve("t_setdatetime");    //Ԯ�� add() ����
    if (Setdatetime == NULL)
    {
        emit editTextUiSig("load t_setdatetime address fail!");
        return false;
    }
    QDateTime startDateTime(QDate(2000, 1, 1));
    QDateTime currentDateTime = QDateTime::currentDateTime();
    int wdate = startDateTime.daysTo(currentDateTime);
    int hour = currentDateTime.time().hour();
    int minute = currentDateTime.time().minute();
    int second = currentDateTime.time().second();
    int wtime = (int)(1800 * hour + 30 * minute + second / 2);

    QByteArray clientip = ip.toLatin1(); // must

    int err = Setdatetime(49164, clientip.data(), addr, wdate, wtime, 300);
    if (err == 0)
    {
        emit editTextUiSig(QString::fromLocal8Bit("%1���ÿ�����ʱ��ɹ���").arg(ip));
        emit editTextUiSig(QString::fromLocal8Bit("��ǰʱ�䣺%1").arg(currentDateTime.toString("yyyy-MM-dd hh:mm:ss")));
        return true;
    }
    else
    {
        emit editTextUiSig(QString::fromLocal8Bit("%1���ÿ�����ʱ��ʧ�ܣ������룺%2").arg(ip).arg(err));
        return false;
    }

}



//��run�е�����������Ҳ�����߳���
void EVentthred::collectCardData()
{
	int err;
#if 1
	if (!m_setTimeIsValid)
	{
		//��ʼ������ʱ��  ֱ���ɹ�
		//m_setTimeIsValid = sdkSetTime(m_clientip, m_addr);
	}
	//��������12����������ʱ�� �������ǰ�ε��ַ����

	if (QTime::currentTime().hour() == 12 && QTime::currentTime().minute() < 1)
	{
		if (g_preCardDoorAddrMutex.tryLock(g_TRYLOCKTIME))
		{
			g_preCardDooraddrMap.clear();
			LOG(INFO) << "clear precarddooraddrmap!";
			g_preCardDoorAddrMutex.unlock();
		}
	}

	QByteArray byteIp = m_clientip.toLatin1();

	if (g_eventMutex.tryLock(g_TRYLOCKTIME))
	{
		//err = Gethisevent(49164, byteIp.data(), m_addr, Bagevt, &gevtlist, 600);
		g_eventMutex.unlock();
	}
	QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

	err = 1;
	if (err == 1)
	{
		//����֮ǰ�ļ�¼
		Bagevt.EvtNum = gevtlist.EvtNum;
		Bagevt.BagID = gevtlist.BagID;


		if (mysql_ping(m_pConn))
		{



			//continue;
		}

		//�м�¼
		emit editTextUiSig(QString::fromLocal8Bit("%1ȡ��¼�ɹ���ȡ����¼����%2").arg(m_clientip)
			.arg((int)gevtlist.EvtNum));
		emit editTextUiSig(QString::fromLocal8Bit("��ǰʱ�䣺") + currentDateTime);

		/************************************************************************/
		gevtlist.EvtNum = 2;

		for (int i = 0; i < gevtlist.EvtNum; i++)
		{
			int hour = (int)(gevtlist.Evt[i].Time / 1800);
			int wtime = (int)(gevtlist.Evt[i].Time % 1800);
			int minute = (int)(wtime / 30);
			int second = (int)((wtime % 30) << 1);
			QDateTime datetime(QDate(2000, 1, 1), QTime(hour, minute, second));
			datetime = datetime.addDays(gevtlist.Evt[i].Date);

			std::stringstream stream;

			QString cardNumStr = QString("%1-%2").arg(gevtlist.Evt[i].CardZone).arg(gevtlist.Evt[i].CardId);
			int nDoorAddr = (int)gevtlist.Evt[i].DotId;

			QByteArray  str = datetime.toString(Qt::SystemLocaleLongDate).toLocal8Bit();
			std::string timeStr(str.data());
			stream << "ʱ�䣺" << timeStr
				<< "�����ַ��" << nDoorAddr
				<< "�����ţ�" << cardNumStr.toStdString()
				<< "���¼���" << EvtStr[gevtlist.Evt[i].Code]
				<< "\n";
			std::string hiseventInfo;
			getline(stream, hiseventInfo);
			emit editTextUiSig(QString::fromLocal8Bit(hiseventInfo.c_str()));

			bool isUnSamePreCardDoor = false;

			if (g_preCardDoorAddrMutex.tryLock(g_TRYLOCKTIME))
			{
				if (gevtlist.Evt[i].Code == 0x21 && g_preCardDooraddrMap[cardNumStr] != nDoorAddr)
				{
					isUnSamePreCardDoor = true;

				}
				g_preCardDoorAddrMutex.unlock();
			}


			/*ͬһ��ͬһ�������򿨻ᱻ����*/
			//if (gevtlist.Evt[i].Code == 0x21 && isUnSamePreCardDoor)
			{
				if (g_preCardDoorAddrMutex.tryLock(g_TRYLOCKTIME))
				{
					g_preCardDooraddrMap[cardNumStr] = nDoorAddr;
					g_preCardDoorAddrMutex.unlock();
				}
				//m_preDateTime[cardNumStr][nDoorAddr] = datetime;


				/*��������12�� �� �ڶ������� 12�����ڵ���*/
				QDate curDate(datetime.date());
				if (hour < 12)
				{
					curDate = curDate.addDays(-1);
				}

				QString queryString = QString("INSERT INTO eventinfos (task_date, eventtime, ip, dooraddr, card, flag)"
					"VALUES ('%1', '%2', '%3', %4, '%5', %6)")
					.arg(curDate.toString("yyyy-MM-dd"))
					.arg(datetime.toString("yyyy-MM-dd HH:mm:ss"))
					.arg(m_clientip)
					.arg(nDoorAddr)
					.arg(cardNumStr)
					.arg(0);
				QByteArray queryByteArray = queryString.toLocal8Bit();
				int ok = 0;
				ok = mysql_query(m_pConn, queryByteArray.data());

				if (ok)
				{
					/*
					*���ݿ����ʧ��ʱ
					*/
					std::stringstream warningStream;
					std::string warringStr1, warringStr2;


					warningStream << m_clientip.toStdString() << " " << QString::fromLocal8Bit(hiseventInfo.c_str()).toStdString();
					getline(warningStream, warringStr1);

					//qDebug() << QString::fromLocal8Bit(mysql_error(m_pConn));
					warringStr2 = QString::fromLocal8Bit(mysql_error(m_pConn)).toStdString();
					getline(warningStream, warringStr2);

					//qDebug() << QString(warringStr2.data());

					warringStr1 += '\n';
					warringStr1 += warringStr2;
					LOG(ERROR) << warringStr1;
				}
				else
				{
					std::stringstream okStream;

					okStream << m_clientip.toStdString() << " "
						<< QString::fromLocal8Bit(hiseventInfo.c_str()).toStdString()
						<< '\n';
					std::string okStr;
					getline(okStream, okStr);
					LOG(INFO) << okStr;
				}
			}
		}
	}//end if(err == 1)
	else if (err == 0)
	{
		//�޼�¼

		Bagevt.EvtNum = 0;
		Bagevt.BagID = 0;
	}
	QThread::msleep(400);
#endif
	
}

void EVentthred::tryExceptCall()
{

	//__try
	{
		collectCardData();
	}
	//__except (EXCEPTION_EXECUTE_HANDLER)
	{
		//qApp->exit(777);
		//msleep(5000);
	}
}


void EVentthred::run()
{
    Gethisevent = (pGethisevent)m_myDll->resolve("t_gethisevent");
    if (Gethisevent == NULL)
    {
        emit editTextUiSig("load t_gethisevent address fail!");
        return;
    }

	while (1)
	{
		//�����쳣ʱ����Ӧ��
		tryExceptCall();

    }// end for(;;)
}

