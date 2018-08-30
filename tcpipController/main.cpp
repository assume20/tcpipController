#include <QSharedMemory>
#include <QCoreApplication>
#include "gloghelper.h"
#include <windows.h>
#include <QProcess>
#include <iostream>
//#include "vld.h"
#include "sdkcontrol.h"
#include "MiniDump.h"
#include "glog/logging.h"


int main(int argc, char *argv[])
{

	//QSharedMemory shared_memory;
	//shared_memory.setKey("8888");
	//if (shared_memory.attach())
	//{
	//	return 0;
	//}
	//if (shared_memory.create(1))
	//{

		QCoreApplication app(argc, argv);

		// �����κ��쳣ʱ���������̣�ʵ�ֳ�����Զ��ָ�

		GLogHelper log;
		/*����dump*/
		MiniDumper(true);

		LOG(INFO) << "--------------------doorController start!--------------------";
		std::cout << "--------------------doorController start!------------------\n";
		SDkcontrol win;

		int e = app.exec();
		if (e == 777)
		{

			QProcess::startDetached(qApp->applicationFilePath(), QStringList());

			return 0;

		}
		return e;
	//}
}
