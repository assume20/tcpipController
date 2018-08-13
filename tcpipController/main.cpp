#include <QSharedMemory>
#include <QApplication>
#include "gloghelper.h"
#include <windows.h>
#include "vld.h"
#include "sdkcontrol.h"
#include "MiniDump.h"
#include <QProcess>
#include <QDir>


int main(int argc, char *argv[])
{

	QSharedMemory shared_memory;
	shared_memory.setKey("8888");
	if (shared_memory.attach())
	{
		return 0;
	}
	if (shared_memory.create(1))
	{

		QApplication app(argc, argv);

		// �����κ��쳣ʱ���������̣�ʵ�ֳ�����Զ��ָ�

		GLogHelper log;
		/*����dump*/
		MiniDumper(true);


		SDkcontrol win;
		win.show();

		int e = app.exec();
		if (e == 777)
		{

			QProcess::startDetached(qApp->applicationFilePath(), QStringList());

			return 0;

		}
		return e;
	}
}
