#include "eventthred.h"
#include "global.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QVariant>
#include <qDebug>
#include <QSqlError>
#include <QSettings>
#include <QTextCodec>
#include <QFile>
#include "glog/logging.h"
#include "MiniDump.h"

typedef int(__stdcall *pGethisevent)(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);
typedef  int(__stdcall *pGetnameAndVer)(int serverport, char *clientip, uint8 dcuid,
	tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);

typedef int(__stdcall *pSetdatetime)(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);

EVentthred::EVentthred()
{

	m_bIsRunning = true;

	evtStrInit();

	for (int i = 0; i < g_controlInfoVec.size(); ++i)
	{
		QString client = g_controlInfoVec.at(i).first;
		memset(&m_BagevtMap[client], 0, sizeof(m_BagevtMap[client]));
		memset(&m_gevtlistMap[client], 0, sizeof(m_gevtlistMap[client]));
	}

	memset(&Bagevt, 0, sizeof(Bagevt));
	memset(&gevtlist, 0, sizeof(gevtlist));


	m_myDll = new QLibrary("drrs.dll");
	if (!m_myDll->load())
	{
		LOG(ERROR) << "load dll fail!";
	}

	databaseInit();

	m_timer = new QTimer(this);

	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateControlTime()));
	m_timer->start(1000 * 60 * 60 * 24);  //һ������һ��ʱ��
}

EVentthred::~EVentthred()
{

	delete m_myDll;
	mysql_close(m_pConn);

	m_bIsRunning = false;
	//this->quit();
	//this->wait(300);
}

void EVentthred::databaseInit()
{


	QSettings fd("dbconfig.ini", QSettings::IniFormat);
	fd.setIniCodec(QTextCodec::codecForName("UTF-8"));

	QByteArray hostName = fd.value("config/servername", "0").toByteArray();
	QByteArray database = fd.value("config/database", "0").toByteArray();
	QByteArray userName = fd.value("config/username", "0").toByteArray();

	QByteArray password = fd.value("config/password", "0").toByteArray();

	g_databaseInit.lock();
	m_pConn = mysql_init(NULL);

	//��2��3��4��5��������˼�ֱ��ǣ���������ַ���û��������롢���ݿ�������6��Ϊmysql�˿ںţ�0ΪĬ��ֵ3306��


	//if (!mysql_real_connect(m_pConn, "10.43.72.223", "root"
	//	, "Liu***1016", "patrol", 0, NULL, 0))
	if (!mysql_real_connect(m_pConn, hostName.constData(), userName.constData()
		, password.constData(), database.constData(), 0, NULL, 0))
	{
		std::cout << m_clientip.toStdString() << "�޷��������ݿ�!\n";
	}
	else
	{
		std::cout << m_clientip.toStdString() << "�������ݿ�ɹ�!\n";
	}

	char value = 1;
	mysql_options(m_pConn, MYSQL_OPT_RECONNECT, (char *)&value);
	g_databaseInit.unlock();
	mysql_query(m_pConn, "set names utf8");//��ֹ���롣���ú����ݿ�ı���һ�¾Ͳ�������

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
	m_setTimeIsValidMap.clear();
	LOG(INFO) << "clear m_setTimeIsValidMap successfully!";
}


bool EVentthred::sdkSetTime(QString ip, int addr)
{
	pSetdatetime Setdatetime = (pSetdatetime)m_myDll->resolve("t_setdatetime");    //Ԯ�� add() ����
	if (Setdatetime == NULL)
	{
		LOG(ERROR) << "load t_setdatetime address fail!";
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
		std::cout << ip.toStdString() << "���ÿ�����ʱ��ɹ���\n";
		LOG(INFO) << ip.toStdString() << "���ÿ�����ʱ��ɹ���";
		return true;
	}
	else
	{
		std::cout << ip.toStdString() << "���ÿ�����ʱ��ʧ�ܣ�\n";
		LOG(INFO) << ip.toStdString() << "���ÿ�����ʱ��ʧ�ܣ�";
		return false;
	}

}



//��run�е�����������Ҳ�����߳���
void EVentthred::collectCardData()
{
	int err;

	for (int i = 0; i < g_controlInfoVec.size(); ++i)
	{
		m_clientip = g_controlInfoVec.at(i).first;
		m_addr = g_controlInfoVec.at(i).second;

		if (!m_setTimeIsValidMap[m_clientip])
		{
			//��ʼ������ʱ��  ֱ���ɹ�
			m_setTimeIsValidMap[m_clientip] = sdkSetTime(m_clientip, m_addr);

		}
		//��������12����������ʱ�� �������ǰ�ε��ַ����

		if (QTime::currentTime().hour() == 12 && QTime::currentTime().minute() < 1)
		{

			m_preCardDooraddrMap.clear();
			LOG(INFO) << "clear precarddooraddrmap!";

		}

		QByteArray byteIp = m_clientip.toLatin1();


		err = Gethisevent(49164, byteIp.data(), m_addr,
			m_BagevtMap[m_clientip], &(m_gevtlistMap[m_clientip]), 250);

		currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");


		if (err == 1)
		{
			gevtlist = m_gevtlistMap.value(m_clientip);
			//����֮ǰ�ļ�¼
			m_BagevtMap[m_clientip].EvtNum = gevtlist.EvtNum;
			m_BagevtMap[m_clientip].BagID = gevtlist.BagID;


			//�м�¼
			std::cout << m_clientip.toStdString() << "ȡ��¼�ɹ���ȡ����¼����" << (int)gevtlist.EvtNum << '\n';
			LOG(INFO) << m_clientip.toStdString() << "ȡ��¼�ɹ���ȡ����¼����" << (int)gevtlist.EvtNum << '\n';
			std::cout << "��ǰʱ�䣺" << currentDateTime.toStdString() << '\n';

			/************************************************************************/

			for (int i = 0; i < gevtlist.EvtNum; i++)
			{
				int hour = (int)(gevtlist.Evt[i].Time / 1800);
				int wtime = (int)(gevtlist.Evt[i].Time % 1800);
				int minute = (int)(wtime / 30);
				int second = (int)((wtime % 30) << 1);
				QDateTime datetime(QDate(2000, 1, 1), QTime(hour, minute, second));
				datetime = datetime.addDays(gevtlist.Evt[i].Date);

				m_clockInDataStream.clear();
				m_clockInDataStream.str("");

				QString cardNumStr = QString("%1-%2").arg(gevtlist.Evt[i].CardZone).arg(gevtlist.Evt[i].CardId);
				int nDoorAddr = (int)gevtlist.Evt[i].DotId;

				QByteArray  str = datetime.toString(Qt::SystemLocaleLongDate).toLocal8Bit();
				std::string timeStr(str.data());

				std::string hiseventInfo;
				/*ͬһ��ͬһ�������򿨻ᱻ����*/
				if (gevtlist.Evt[i].Code == 0x21 && m_preCardDooraddrMap[cardNumStr] != nDoorAddr)
				{

					m_preCardDooraddrMap[cardNumStr] = nDoorAddr;


					m_clockInDataStream << "ʱ�䣺" << timeStr
						<< "�����ַ��" << nDoorAddr
						<< "�����ţ�" << cardNumStr.toStdString()
						<< "\n";
					getline(m_clockInDataStream, hiseventInfo);
					std::cout << hiseventInfo << '\n';
					LOG(INFO) << hiseventInfo;


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
						m_errorStream.clear();
						m_errorStream.str("");
						std::string warringStr1, warringStr2;


						m_errorStream << m_clientip.toStdString() << " " << hiseventInfo;
						getline(m_errorStream, warringStr1);

						warringStr2 = mysql_error(m_pConn);
						getline(m_errorStream, warringStr2);
						warringStr1 += '\n';
						warringStr1 += warringStr2;
						LOG(ERROR) << warringStr1;

						/*
						* ���������ݿ�Ч�� �������ĸ���
						*/
						mysql_close(m_pConn);
						mysql_library_end();
						QThread::msleep(100);
						databaseInit();

					}
				}
				else
				{
					m_clockInDataStream << "ʱ�䣺" << timeStr
						<< "�����ַ��" << nDoorAddr
						<< "���¼���" << EvtStr[gevtlist.Evt[i].Code]
						<< "\n";
					getline(m_clockInDataStream, hiseventInfo);
					std::cout << hiseventInfo << '\n';
					LOG(INFO) << hiseventInfo;
				}
			}
		}//end if(err == 1)
		else if (err == 0)
		{
			//�޼�¼
			m_BagevtMap[m_clientip].EvtNum = 0;
			m_BagevtMap[m_clientip].BagID = 0;
		}



	}
}

void EVentthred::writeLogCollapse()
{
	QThread::msleep(100);
	LOG(ERROR) << "----------doorcontrol collapse-------------" << "\n";
	exit(-1);
}

void EVentthred::tryExceptCall()
{

	__try
	{
		collectCardData();
	}
	__except (MiniDumper::gpDumper->Handler(GetExceptionInformation()))
	{

		writeLogCollapse();

	}

}


void EVentthred::start()
{
	Gethisevent = (pGethisevent)m_myDll->resolve("t_gethisevent");
	if (Gethisevent == NULL)
	{
		LOG(INFO) << "load t_gethisevent address fail!";
		return;
	}

	while (m_bIsRunning)
	{

		//�����쳣ʱ����Ӧ��
		tryExceptCall();
	}// end for(;;)
}

