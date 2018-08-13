/************************************

公  司：
名	称：门禁控制器动态链接库(drrs.dll)
作	者：lwf
日	期：2006-7-3
最后更新：2014-7-21

************************************/
#pragma once
#include <windows.h>

typedef unsigned char			uint8;
typedef unsigned short	  uint16;
typedef unsigned long			uint32;

/*网络通讯协议代码表开始*/
/*参数传递: 0 - 0x3F*/
#define CMD_GET_UNITID                    0x01                          /*取控制器识别码*/
#define CMD_GET_DCU_CONFIG                0x02                          /*取控制器参数表*/
#define CMD_GET_CHECKOUT                  0x03                          /*取控制器校验表*/
#define CMD_GET_POINT_CONFIG              0x04                          /*取控制器输入点参数表*/
#define CMD_GET_DOOR_CONFIG               0x06                          /*取控制器门参数表*/
#define CMD_GET_TIME                      0x07                          /*取控制器时间*/
#define CMD_GET_REGISTER                  0x08                          /*取系统注册表*/
#define CMD_GET_USER_TIMEZONE             0x09                          /*取用户门禁权限表*/
#define CMD_GET_PASSWORD                  0x0a                          /*取系统用户密码*/
#define CMD_GET_TEMP_ZONE                 0x0b                          /*取系统临时时间表*/
#define CMD_GET_SPECIAL_ZONE              0x0c                          /*取系统特殊时间表*/
#define CMD_GET_ACCESS_SCHEDULE           0x0d                          /*取控制器门禁时间组*/
#define CMD_GET_DOOR_MODE_SCHEDULE        0x0e                          /*取控制器门模式时间组*/
#define CMD_GET_EVENT                     0x11                          /*取控制器历史事件*/
#define CMD_GET_LINKAGE                   0x12                          /*取控制器连动参数表*/
#define CMD_GET_LIFTZONE                  0x18                          /*取电梯权限组*/
#define CMD_GET_USER_LIFTZONE             0x19                          /*取用户电梯权限组*/

#define CMD_SET_IN_OPENDOOR               0x05                          /*远程开门-进*/
#define CMD_SET_OUT_OPENDOOR              0x20                          /*远程开门-出*/

#define CMD_SET_UNITID                    0x21                          /*下载控制器识别码*/
#define CMD_SET_DCU_CONFIG                0x22                          /*下载控制器参数表*/
#define CMD_SET_POINT_CONFIG              0x24                          /*下载制器点参数表*/
#define CMD_SET_DOOR_CONFIG               0x26                          /*下载控制器门参数表*/
#define CMD_SET_TIME                      0x27                          /*下载系统时间*/
#define CMD_SET_REGISTER                  0x28                          /*下载系统卡注册表*/
#define CMD_SET_USER_TIMEZONE             0x29                          /*下载用户门禁权限表*/
#define CMD_SET_PASSWORD                  0x2a                          /*下载系统用户密码*/
#define CMD_SET_TEMP_ZONE                 0x2b                          /*下载系统临时时间表*/
#define CMD_SET_SPECIAL_ZONE              0x2c                          /*下载系统特殊时间表*/
#define CMD_SET_ACCESS_SCHEDULE           0x2d                          /*下载门禁时间组*/
#define CMD_SET_DOOR_MODE_SCHEDULE        0x2e                          /*下载门模式时间组*/
#define CMD_SET_LINKAGE                   0x32                          /*下载控制器连动参数表*/
#define CMD_SET_LIFTZONE                  0x38                          /*下载电梯权限组*/
#define CMD_SET_USER_LIFTZONE             0x39                          /*下载用户电梯权限表*/
/*网络通讯协议代码表结束*/
#define CTL_GET_UNIT_STATUS               0x40                          /*取控制器状态*/
#define CTL_GET_USER_ZONE                 0x41                          /*取用户区域标志*/
#define CTL_GET_POINT_STATUS              0x42                          /*取入点状态*/
#define CTL_GET_DOOR_STATUS               0x43                          /*取门状态*/
#define CTL_SET_UNIT_STATUS               0x60                          /*设置控制器状态*/
#define CTL_SET_USER_ZONE                 0x61                          /*设置用户区域标志*/
#define CTL_SET_POINT_STATUS              0x62                          /*设置门点状态*/
#define CTL_RESET_UNIT                    0x64                          /*复位控制器*/
#define CTL_SYSTEM_LINKAGE                0x65                          /*系统连动*/
#define CTL_LOCK_NET                      0x66                          /*打开网络*/
#define CTL_UNLOCK_NET                    0x67                          /*关闭网络*/
#define CTL_LOCK_DOOR                     0x68                          /*关闭所有门*/
#define CTL_UNLOCK_DOOR                   0x69                          /*打开所有门*/

/************************************

  说明：门参数表

************************************/
typedef struct DOORCONF{
    uint8                                  DoorType;                                      /*门类型*/
    uint8                                  ReaderType;                                   /*读卡器类型*/
    uint8                                  LEDPolarity;                                   /*读卡器指示灯属性*/
    uint8                                  ReadInterval;                                 /*读卡间隔*/
    uint8                                  ReleaseType;                                  /*出门按钮类型*/
    uint8                                  SenseType;                                    /*门磁类型*/
    uint8                                  StrikeType;                                     /*门锁类型*/
    uint8                                  StrikeDuration;                                /*门锁动作时间*/
    uint8                                  DoorOpenOverTime;                        /*门开超时报警时间*/
    uint8                                  ChainDoorType;                               /*连锁门类型*/
    uint8                                  ReadKeyMode;                                 /*读卡方式*/
    uint8                                  MultiCardNumber;                            /*多卡开门数*/
    uint8                                  UseDiplexAPB;                                 /*双向防跟随*/
    uint8                                  UseGlobalAPB;                                 /*区域防跟随*/
    uint8                                  EntryZone;                                      /*进入区号*/
    uint8                                  ExitZone;                                        /*退出区号*/
    uint8                                  FirstKeyUnlock;                               /*首卡开门*/
    uint16                                 ForcedPassword;                            /*协迫码*/
    uint32                                 SuperPassword;                              /*超级密码*/
    uint8                                  StrikeDuration1;                               /*门锁动作时间1*/
    uint8                                  LockDelay;                                      /*门磁回锁*/
    uint8                                  Reserve[15];                                   /*保留*/
}DOORCONF;

typedef struct DOORCONFTBL{
        uint8                    DoorNum;           /*门的数量*/
        DOORCONF							   DoorConf[4];
}DOORCONFTBL;


/************************************

  说明：特殊时间组表结构

************************************/
typedef struct SPECIALTIMETBL{
        uint8 specialtime[12][32];//按每月32天，位0到位6表示这一天是否属于7组中的哪些组
} specitaltimetbl;

/************************************

  说明：临时时间组表结构

************************************/
typedef struct TEMPTIMETBL{
        unsigned char temptime[7];//用一个字节表示某一天，位0到位1分别表示是否属于2组中的哪些组，
} temptimetbl;

/************************************

  说明：门禁时间表

************************************/
typedef struct TIMEGROUP{
        char name[51];//时间组名称
        unsigned char temptime[2];//临时时间组有效标志
        unsigned char specialtime[7];//特殊时间组有效标志
        unsigned char week[7];//普通日期组有效标志
        struct{
                unsigned char shour;//起始时间：时
                unsigned char sminute;//起始时间：分
                unsigned char ehour;//结束时间：时
                unsigned char eminute;// 结束时间：分
        }timezone[7];//七个时间段
}TIMEGROUP;

typedef struct TIMEGROUPTBL{
        TIMEGROUP Group[15];
}TIMEGROUPTBL;

typedef struct TIMEGROUPATG{
        uint8        DoorNum;           /*门的数量*/
        TIMEGROUPTBL DoorATG[4];
}TIMEGROUPATG;
/************************************

  说明：门状态时间表

************************************/
typedef struct DOORTIMEGROUP{
        unsigned short temptime[2];//临时时间组有效标志
        unsigned short specialtime[7];//特殊时间组有效标志
        unsigned short week[7];//普通日期组有效标志
        struct{
                unsigned char ahour;//动作时间：时
                unsigned char aminute;//动作时间：分
                unsigned char action;// 动作类型
        }actionzone[15];//十五个动作段
}DOORTIMEGROUP;

typedef struct DOORTIMEGROUPTBL{
        uint8                      DoorNum;           /*门的数量*/
        DOORTIMEGROUP						   DOORTIME[4];
}DOORTIMEGROUPTBL;
/************************************

  说明：系统卡注册表

************************************/
typedef struct _CARDSET               /*系统注册表*/
{
  unsigned short  Count;                        /*已注册批次*/
  unsigned short  CardsCount;                   /*已注册用户数量*/
  struct                              /*批次表*/
  {
    unsigned short Cardzn;                      /*区号*/
    unsigned short Cardid;                      /*起始卡号*/
    unsigned short CardCount;                   /*卡注册数量*/
    unsigned short Rev2;
  } Sets[3000];
} CARDSET;

/************************************

  说明：历史记录数据结构

************************************/
typedef struct HISEVTRECORD
{
    WORD                        Date;    /*日期表示：长度2 byte的整数，起始日期是2000年01月01日，数值为0。*/
    WORD                        Time;    /*时间表示：长度2 byte的整数，00:00:00的时间为0。按2秒为计时单位。*/
    BYTE                        Code;    /*事件代码*/
    BYTE                        DotId;   /*点地址*/
    WORD                        CardZone;/*卡区号*/
    WORD                        CardId;  /*卡号*/
}HISEVTRECORD;

typedef struct HISEVTLIST
{
        BYTE      EvtNum;//记录数
        BYTE			BagID;//包编号

  HISEVTRECORD      Evt[204];
}HISEVTLIST;

typedef struct HBagEvt
{
        BYTE      EvtNum;//记录数
        BYTE			BagID;//包编号
}HBagEvt;

/************************************

  说明：控制器校验表

************************************/
typedef struct CHECKOUTTBL{
        unsigned short resvere1;	//保留
        unsigned short doorparamstbl;		//门参数表
        unsigned short SysRegTable;		//系统卡片库注册表
        unsigned short cardreggroup;		//系统特殊时间组
        unsigned short doortimegroup[4];	//四张门门禁时间组,对应1-4号门
        unsigned short doormodetimegroup;	//门模式时间组
        unsigned short dooruserdata[4];		//四张门用户资料,对应1-4号门
        unsigned short userpwd;			//用户密码
        unsigned short linktbl;			   //连动参数表
        unsigned short resvere2;          //保留
}checkouttbl;

/************************************

  说明：点状态结构

************************************/
typedef struct DOTSTATUSINFOSTRUCT{
        unsigned char btn1;//按钮１，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char sensor1;//门磁１，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char btn2;//按钮2，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char sensor2;//门磁2，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char btn3;//按钮3，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char sensor3;//门磁3，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char btn4;//按钮4，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char sensor4;//门磁4，状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char lock[4];//4个门锁状态：0＝UNKNOW，１＝OFF；２＝ON
        unsigned char door[4]; //４个门状态：0＝UNKNOW，１＝休眠，２＝锁常开，３＝安全，４＝密码，５＝APB安全，６＝APB密码
} DOTSTATUSINFOSTRUCT;

//设置点状态
typedef struct SetDotStatusInfoStruct
{
    int DotNum;			//需要设置状态的点的数量
        unsigned char DotId[8];		//点的地址 数组
    unsigned char Status[8];		//点的状态数组
}SetDotStatusInfoStruct;

/************************************

  说明：板内连动表结构

************************************/
typedef struct DOTLINKTBL{
        unsigned char dotid; //连动输出点地址
        unsigned char Reserve1;
        unsigned char dotstatus; //连动输出点状态
        unsigned char Reserve2;
        struct{
                unsigned char conditiondotid; //连动条件点地址
                unsigned char conditiondotstatus; //连动条件点状态
        }dotlink[4]; //连动条件,可同时设置四组条件满足
} DOTLINKTBL;

typedef struct DOTLINKOFSTRUCT{
        int dotlinknum;
        DOTLINKTBL dotlinkgroup[8];
}DOTLINKOFSTRUCT;


/************************************

  说明：用户门禁权限表

************************************/
typedef struct USERCARDATG
{
        uint8 DoorNum;	//门的数量
        struct{
                uint16 UserNum;					/*已注册卡数量*/
                uint8 Atg[7500];			/*每一个字节就表示该名用户在这张门的门禁权限。定义如下：0	没有权限;1..15 该门的用户时间组号*/
        }DoorCardATG[4];				/*四张门的权限表*/

}USERCARDATG;


/************************************

  说明：系统用户密码

************************************/
typedef struct USERPWD               /*系统用户密码*/
{
        uint16       UserNum;                /*用户数*/
        uint16       Pwd[7500];        /*每两个字节就表示一名用户的密码*/
}USERPWD;

/************************************

  说明：时间

************************************/
typedef struct _StructOfDateTime
{
        unsigned short RDate;
        unsigned short RTime;
}StructOfDateTime;

typedef struct TEMPDATATBL{
        unsigned char tempdata[24];
} tempdatatbl;

/************************************

函 数 名：dcu_getnameandver()
功    能：取控制器名称和版本号
说    明：
参    数：

返 回 值：
                    0          成功
                   -1          失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getnameandver(int serverport, char *clientip, uint8 dcuid, tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);

/************************************

函 数 名：
功    能：取历史记录
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_gethisevent(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);

/************************************

函 数 名：
功    能：设置控制器门参数表
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdoortable(int serverport, char *clientip, uint8 dcuid, DOORCONFTBL doortbl, int delay);

/************************************

函 数 名：
功    能：取控制器系统时间
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getdatetime(int serverport, char *clientip, uint8 dcuid, StructOfDateTime *DateTimeStruct, int delay);

/************************************

函 数 名：
功    能：设置控制器系统时间
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdatetime(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);

/************************************

函 数 名：
功    能：广播设置控制器系统时间
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_radiosetdatetime(int serverport, char *clientip, uint16 date, uint16 time, int delay);

/************************************

函 数 名：
功    能：下载系统特殊时间表
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setspecialtimetable(int serverport, char *clientip, uint8 dcuid, SPECIALTIMETBL stime, int delay);

/************************************

函 数 名：
功    能：下载控制器系统临时时间表
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_settemptimetable(int serverport, char *clientip, uint8 dcuid, TEMPTIMETBL ttime, int delay);

/************************************

函 数 名：
功    能：下载门禁时间组
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setaccesstimegroup(int serverport, char *clientip, unsigned char dcuid, TIMEGROUPATG timeg, int delay);

/************************************

函 数 名：
功    能：下载门状态时间组
说    明：
参    数：
返 回 值： 0 成功
                  -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdoortimegroup(int serverport, char *clientip, unsigned char dcuid, DOORTIMEGROUPTBL doortime, int delay);

/************************************

函 数 名：
功    能：设置控制器系统卡注册表
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setcardregtable(int serverport, char *clientip, uint8 dcuid, CARDSET cset, int delay);

/************************************

函 数 名：
功    能：取控制器点状态
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getdotstatus(int serverport, char *clientip, unsigned char dcuid, DOTSTATUSINFOSTRUCT* dotstatus, int delay);

/************************************

函 数 名：
功    能：设置点状态
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdotstatus(int serverport, char *clientip, unsigned char dcuid, SetDotStatusInfoStruct dotstatusinfo, int delay);

/************************************

函 数 名：
功    能：下载控制器板内连动表
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdotlinktable(int serverport, char *clientip, unsigned char dcuid, DOTLINKOFSTRUCT dotlinktbl, int delay);

/************************************

函 数 名：
功    能：设置控制器用户门禁权限表
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setuseraccess(int serverport, char *clientip, uint8 dcuid, USERCARDATG atg, int delay);

/************************************

函 数 名：
功    能：设置控制器系统用户密码
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setuserpwd(int serverport, char *clientip, uint8 dcuid, USERPWD pwd, int delay);

/************************************

函 数 名：
功    能：远程开门1
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setopendoor_in(int serverport, char *clientip, unsigned char dcuid, int delay);

/************************************

函 数 名：
功    能：远程开门2
说    明：
参    数：

返 回 值：
                         0 成功
                        -1 失败

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setopendoor_out(int serverport, char *clientip, unsigned char dcuid, int delay);
