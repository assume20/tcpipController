#include "gloghelper.h"
#include "glog/logging.h"
#include <QString>
#include <fstream>
#include <QDir>
#include <QApplication>
#include <QProcess>
#include <QThread>

#if 0
void SignalHandle(const char* data, int size)
{
	std::ofstream fs("log/glog_dump.log", std::ios::app);
	std::string str = std::string(data, size);
	fs << str;
	fs.close();

	//qApp->exit(777);
	//QThread::msleep(10000);

	LOG(FATAL) << str;


}
#endif

GLogHelper::GLogHelper()
{
	//��־���ó�ʼ��
	QString filePath(QDir::currentPath() + "/log");
	QDir dir;
	if (!dir.exists(filePath))
	{
		dir.mkpath(filePath);
	}
	google::InitGoogleLogging("doorcontrol");
	google::SetLogDestination(google::GLOG_INFO, "log/info_");
	google::SetLogDestination(google::GLOG_WARNING, "log/warning_");
	google::SetLogDestination(google::GLOG_ERROR, "log/error_");
	google::SetLogDestination(google::GLOG_FATAL, "log/fatal_");



	FLAGS_logbufsecs = 0; //������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
	FLAGS_max_log_size = 100; //�����־��СΪ 100MB
	FLAGS_stop_logging_if_full_disk = true; //�����̱�д��ʱ��ֹͣ��־���
	FLAGS_alsologtostderr = false;

	//google::InstallFailureSignalHandler();

	//google::InstallFailureWriter(&SignalHandle);


}

GLogHelper::~GLogHelper()
{
	google::ShutdownGoogleLogging();
}


