/************************************

��  ˾��
��	�ƣ��Ž���������̬���ӿ�(drrs.dll)
��	�ߣ�lwf
��	�ڣ�2006-7-3
�����£�2014-7-21

************************************/
#pragma once
#include <windows.h>

typedef unsigned char			uint8;
typedef unsigned short	  uint16;
typedef unsigned long			uint32;

/*����ͨѶЭ������ʼ*/
/*��������: 0 - 0x3F*/
#define CMD_GET_UNITID                    0x01                          /*ȡ������ʶ����*/
#define CMD_GET_DCU_CONFIG                0x02                          /*ȡ������������*/
#define CMD_GET_CHECKOUT                  0x03                          /*ȡ������У���*/
#define CMD_GET_POINT_CONFIG              0x04                          /*ȡ����������������*/
#define CMD_GET_DOOR_CONFIG               0x06                          /*ȡ�������Ų�����*/
#define CMD_GET_TIME                      0x07                          /*ȡ������ʱ��*/
#define CMD_GET_REGISTER                  0x08                          /*ȡϵͳע���*/
#define CMD_GET_USER_TIMEZONE             0x09                          /*ȡ�û��Ž�Ȩ�ޱ�*/
#define CMD_GET_PASSWORD                  0x0a                          /*ȡϵͳ�û�����*/
#define CMD_GET_TEMP_ZONE                 0x0b                          /*ȡϵͳ��ʱʱ���*/
#define CMD_GET_SPECIAL_ZONE              0x0c                          /*ȡϵͳ����ʱ���*/
#define CMD_GET_ACCESS_SCHEDULE           0x0d                          /*ȡ�������Ž�ʱ����*/
#define CMD_GET_DOOR_MODE_SCHEDULE        0x0e                          /*ȡ��������ģʽʱ����*/
#define CMD_GET_EVENT                     0x11                          /*ȡ��������ʷ�¼�*/
#define CMD_GET_LINKAGE                   0x12                          /*ȡ����������������*/
#define CMD_GET_LIFTZONE                  0x18                          /*ȡ����Ȩ����*/
#define CMD_GET_USER_LIFTZONE             0x19                          /*ȡ�û�����Ȩ����*/

#define CMD_SET_IN_OPENDOOR               0x05                          /*Զ�̿���-��*/
#define CMD_SET_OUT_OPENDOOR              0x20                          /*Զ�̿���-��*/

#define CMD_SET_UNITID                    0x21                          /*���ؿ�����ʶ����*/
#define CMD_SET_DCU_CONFIG                0x22                          /*���ؿ�����������*/
#define CMD_SET_POINT_CONFIG              0x24                          /*���������������*/
#define CMD_SET_DOOR_CONFIG               0x26                          /*���ؿ������Ų�����*/
#define CMD_SET_TIME                      0x27                          /*����ϵͳʱ��*/
#define CMD_SET_REGISTER                  0x28                          /*����ϵͳ��ע���*/
#define CMD_SET_USER_TIMEZONE             0x29                          /*�����û��Ž�Ȩ�ޱ�*/
#define CMD_SET_PASSWORD                  0x2a                          /*����ϵͳ�û�����*/
#define CMD_SET_TEMP_ZONE                 0x2b                          /*����ϵͳ��ʱʱ���*/
#define CMD_SET_SPECIAL_ZONE              0x2c                          /*����ϵͳ����ʱ���*/
#define CMD_SET_ACCESS_SCHEDULE           0x2d                          /*�����Ž�ʱ����*/
#define CMD_SET_DOOR_MODE_SCHEDULE        0x2e                          /*������ģʽʱ����*/
#define CMD_SET_LINKAGE                   0x32                          /*���ؿ���������������*/
#define CMD_SET_LIFTZONE                  0x38                          /*���ص���Ȩ����*/
#define CMD_SET_USER_LIFTZONE             0x39                          /*�����û�����Ȩ�ޱ�*/
/*����ͨѶЭ���������*/
#define CTL_GET_UNIT_STATUS               0x40                          /*ȡ������״̬*/
#define CTL_GET_USER_ZONE                 0x41                          /*ȡ�û������־*/
#define CTL_GET_POINT_STATUS              0x42                          /*ȡ���״̬*/
#define CTL_GET_DOOR_STATUS               0x43                          /*ȡ��״̬*/
#define CTL_SET_UNIT_STATUS               0x60                          /*���ÿ�����״̬*/
#define CTL_SET_USER_ZONE                 0x61                          /*�����û������־*/
#define CTL_SET_POINT_STATUS              0x62                          /*�����ŵ�״̬*/
#define CTL_RESET_UNIT                    0x64                          /*��λ������*/
#define CTL_SYSTEM_LINKAGE                0x65                          /*ϵͳ����*/
#define CTL_LOCK_NET                      0x66                          /*������*/
#define CTL_UNLOCK_NET                    0x67                          /*�ر�����*/
#define CTL_LOCK_DOOR                     0x68                          /*�ر�������*/
#define CTL_UNLOCK_DOOR                   0x69                          /*��������*/

/************************************

  ˵�����Ų�����

************************************/
typedef struct DOORCONF{
    uint8                                  DoorType;                                      /*������*/
    uint8                                  ReaderType;                                   /*����������*/
    uint8                                  LEDPolarity;                                   /*������ָʾ������*/
    uint8                                  ReadInterval;                                 /*�������*/
    uint8                                  ReleaseType;                                  /*���Ű�ť����*/
    uint8                                  SenseType;                                    /*�Ŵ�����*/
    uint8                                  StrikeType;                                     /*��������*/
    uint8                                  StrikeDuration;                                /*��������ʱ��*/
    uint8                                  DoorOpenOverTime;                        /*�ſ���ʱ����ʱ��*/
    uint8                                  ChainDoorType;                               /*����������*/
    uint8                                  ReadKeyMode;                                 /*������ʽ*/
    uint8                                  MultiCardNumber;                            /*�࿨������*/
    uint8                                  UseDiplexAPB;                                 /*˫�������*/
    uint8                                  UseGlobalAPB;                                 /*���������*/
    uint8                                  EntryZone;                                      /*��������*/
    uint8                                  ExitZone;                                        /*�˳�����*/
    uint8                                  FirstKeyUnlock;                               /*�׿�����*/
    uint16                                 ForcedPassword;                            /*Э����*/
    uint32                                 SuperPassword;                              /*��������*/
    uint8                                  StrikeDuration1;                               /*��������ʱ��1*/
    uint8                                  LockDelay;                                      /*�ŴŻ���*/
    uint8                                  Reserve[15];                                   /*����*/
}DOORCONF;

typedef struct DOORCONFTBL{
        uint8                    DoorNum;           /*�ŵ�����*/
        DOORCONF							   DoorConf[4];
}DOORCONFTBL;


/************************************

  ˵��������ʱ�����ṹ

************************************/
typedef struct SPECIALTIMETBL{
        uint8 specialtime[12][32];//��ÿ��32�죬λ0��λ6��ʾ��һ���Ƿ�����7���е���Щ��
} specitaltimetbl;

/************************************

  ˵������ʱʱ�����ṹ

************************************/
typedef struct TEMPTIMETBL{
        unsigned char temptime[7];//��һ���ֽڱ�ʾĳһ�죬λ0��λ1�ֱ��ʾ�Ƿ�����2���е���Щ�飬
} temptimetbl;

/************************************

  ˵�����Ž�ʱ���

************************************/
typedef struct TIMEGROUP{
        char name[51];//ʱ��������
        unsigned char temptime[2];//��ʱʱ������Ч��־
        unsigned char specialtime[7];//����ʱ������Ч��־
        unsigned char week[7];//��ͨ��������Ч��־
        struct{
                unsigned char shour;//��ʼʱ�䣺ʱ
                unsigned char sminute;//��ʼʱ�䣺��
                unsigned char ehour;//����ʱ�䣺ʱ
                unsigned char eminute;// ����ʱ�䣺��
        }timezone[7];//�߸�ʱ���
}TIMEGROUP;

typedef struct TIMEGROUPTBL{
        TIMEGROUP Group[15];
}TIMEGROUPTBL;

typedef struct TIMEGROUPATG{
        uint8        DoorNum;           /*�ŵ�����*/
        TIMEGROUPTBL DoorATG[4];
}TIMEGROUPATG;
/************************************

  ˵������״̬ʱ���

************************************/
typedef struct DOORTIMEGROUP{
        unsigned short temptime[2];//��ʱʱ������Ч��־
        unsigned short specialtime[7];//����ʱ������Ч��־
        unsigned short week[7];//��ͨ��������Ч��־
        struct{
                unsigned char ahour;//����ʱ�䣺ʱ
                unsigned char aminute;//����ʱ�䣺��
                unsigned char action;// ��������
        }actionzone[15];//ʮ���������
}DOORTIMEGROUP;

typedef struct DOORTIMEGROUPTBL{
        uint8                      DoorNum;           /*�ŵ�����*/
        DOORTIMEGROUP						   DOORTIME[4];
}DOORTIMEGROUPTBL;
/************************************

  ˵����ϵͳ��ע���

************************************/
typedef struct _CARDSET               /*ϵͳע���*/
{
  unsigned short  Count;                        /*��ע������*/
  unsigned short  CardsCount;                   /*��ע���û�����*/
  struct                              /*���α�*/
  {
    unsigned short Cardzn;                      /*����*/
    unsigned short Cardid;                      /*��ʼ����*/
    unsigned short CardCount;                   /*��ע������*/
    unsigned short Rev2;
  } Sets[3000];
} CARDSET;

/************************************

  ˵������ʷ��¼���ݽṹ

************************************/
typedef struct HISEVTRECORD
{
    WORD                        Date;    /*���ڱ�ʾ������2 byte����������ʼ������2000��01��01�գ���ֵΪ0��*/
    WORD                        Time;    /*ʱ���ʾ������2 byte��������00:00:00��ʱ��Ϊ0����2��Ϊ��ʱ��λ��*/
    BYTE                        Code;    /*�¼�����*/
    BYTE                        DotId;   /*���ַ*/
    WORD                        CardZone;/*������*/
    WORD                        CardId;  /*����*/
}HISEVTRECORD;

typedef struct HISEVTLIST
{
        BYTE      EvtNum;//��¼��
        BYTE			BagID;//�����

  HISEVTRECORD      Evt[204];
}HISEVTLIST;

typedef struct HBagEvt
{
        BYTE      EvtNum;//��¼��
        BYTE			BagID;//�����
}HBagEvt;

/************************************

  ˵����������У���

************************************/
typedef struct CHECKOUTTBL{
        unsigned short resvere1;	//����
        unsigned short doorparamstbl;		//�Ų�����
        unsigned short SysRegTable;		//ϵͳ��Ƭ��ע���
        unsigned short cardreggroup;		//ϵͳ����ʱ����
        unsigned short doortimegroup[4];	//�������Ž�ʱ����,��Ӧ1-4����
        unsigned short doormodetimegroup;	//��ģʽʱ����
        unsigned short dooruserdata[4];		//�������û�����,��Ӧ1-4����
        unsigned short userpwd;			//�û�����
        unsigned short linktbl;			   //����������
        unsigned short resvere2;          //����
}checkouttbl;

/************************************

  ˵������״̬�ṹ

************************************/
typedef struct DOTSTATUSINFOSTRUCT{
        unsigned char btn1;//��ť����״̬��0��UNKNOW������OFF������ON
        unsigned char sensor1;//�Ŵţ���״̬��0��UNKNOW������OFF������ON
        unsigned char btn2;//��ť2��״̬��0��UNKNOW������OFF������ON
        unsigned char sensor2;//�Ŵ�2��״̬��0��UNKNOW������OFF������ON
        unsigned char btn3;//��ť3��״̬��0��UNKNOW������OFF������ON
        unsigned char sensor3;//�Ŵ�3��״̬��0��UNKNOW������OFF������ON
        unsigned char btn4;//��ť4��״̬��0��UNKNOW������OFF������ON
        unsigned char sensor4;//�Ŵ�4��״̬��0��UNKNOW������OFF������ON
        unsigned char lock[4];//4������״̬��0��UNKNOW������OFF������ON
        unsigned char door[4]; //������״̬��0��UNKNOW���������ߣ�������������������ȫ���������룬����APB��ȫ������APB����
} DOTSTATUSINFOSTRUCT;

//���õ�״̬
typedef struct SetDotStatusInfoStruct
{
    int DotNum;			//��Ҫ����״̬�ĵ������
        unsigned char DotId[8];		//��ĵ�ַ ����
    unsigned char Status[8];		//���״̬����
}SetDotStatusInfoStruct;

/************************************

  ˵��������������ṹ

************************************/
typedef struct DOTLINKTBL{
        unsigned char dotid; //����������ַ
        unsigned char Reserve1;
        unsigned char dotstatus; //���������״̬
        unsigned char Reserve2;
        struct{
                unsigned char conditiondotid; //�����������ַ
                unsigned char conditiondotstatus; //����������״̬
        }dotlink[4]; //��������,��ͬʱ����������������
} DOTLINKTBL;

typedef struct DOTLINKOFSTRUCT{
        int dotlinknum;
        DOTLINKTBL dotlinkgroup[8];
}DOTLINKOFSTRUCT;


/************************************

  ˵�����û��Ž�Ȩ�ޱ�

************************************/
typedef struct USERCARDATG
{
        uint8 DoorNum;	//�ŵ�����
        struct{
                uint16 UserNum;					/*��ע�Ῠ����*/
                uint8 Atg[7500];			/*ÿһ���ֽھͱ�ʾ�����û��������ŵ��Ž�Ȩ�ޡ��������£�0	û��Ȩ��;1..15 ���ŵ��û�ʱ�����*/
        }DoorCardATG[4];				/*�����ŵ�Ȩ�ޱ�*/

}USERCARDATG;


/************************************

  ˵����ϵͳ�û�����

************************************/
typedef struct USERPWD               /*ϵͳ�û�����*/
{
        uint16       UserNum;                /*�û���*/
        uint16       Pwd[7500];        /*ÿ�����ֽھͱ�ʾһ���û�������*/
}USERPWD;

/************************************

  ˵����ʱ��

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

�� �� ����dcu_getnameandver()
��    �ܣ�ȡ���������ƺͰ汾��
˵    ����
��    ����

�� �� ֵ��
                    0          �ɹ�
                   -1          ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getnameandver(int serverport, char *clientip, uint8 dcuid, tempdatatbl* tdata, uint8* dcuname, uint8* version, int delay);

/************************************

�� �� ����
��    �ܣ�ȡ��ʷ��¼
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_gethisevent(int serverport, char *clientip, uint8 dcuid, HBagEvt Bagevt, HISEVTLIST *gevtlist, int delay);

/************************************

�� �� ����
��    �ܣ����ÿ������Ų�����
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdoortable(int serverport, char *clientip, uint8 dcuid, DOORCONFTBL doortbl, int delay);

/************************************

�� �� ����
��    �ܣ�ȡ������ϵͳʱ��
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getdatetime(int serverport, char *clientip, uint8 dcuid, StructOfDateTime *DateTimeStruct, int delay);

/************************************

�� �� ����
��    �ܣ����ÿ�����ϵͳʱ��
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdatetime(int serverport, char *clientip, uint8 dcuid, uint16 date, uint16 time, int delay);

/************************************

�� �� ����
��    �ܣ��㲥���ÿ�����ϵͳʱ��
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_radiosetdatetime(int serverport, char *clientip, uint16 date, uint16 time, int delay);

/************************************

�� �� ����
��    �ܣ�����ϵͳ����ʱ���
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setspecialtimetable(int serverport, char *clientip, uint8 dcuid, SPECIALTIMETBL stime, int delay);

/************************************

�� �� ����
��    �ܣ����ؿ�����ϵͳ��ʱʱ���
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_settemptimetable(int serverport, char *clientip, uint8 dcuid, TEMPTIMETBL ttime, int delay);

/************************************

�� �� ����
��    �ܣ������Ž�ʱ����
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setaccesstimegroup(int serverport, char *clientip, unsigned char dcuid, TIMEGROUPATG timeg, int delay);

/************************************

�� �� ����
��    �ܣ�������״̬ʱ����
˵    ����
��    ����
�� �� ֵ�� 0 �ɹ�
                  -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdoortimegroup(int serverport, char *clientip, unsigned char dcuid, DOORTIMEGROUPTBL doortime, int delay);

/************************************

�� �� ����
��    �ܣ����ÿ�����ϵͳ��ע���
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setcardregtable(int serverport, char *clientip, uint8 dcuid, CARDSET cset, int delay);

/************************************

�� �� ����
��    �ܣ�ȡ��������״̬
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_getdotstatus(int serverport, char *clientip, unsigned char dcuid, DOTSTATUSINFOSTRUCT* dotstatus, int delay);

/************************************

�� �� ����
��    �ܣ����õ�״̬
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdotstatus(int serverport, char *clientip, unsigned char dcuid, SetDotStatusInfoStruct dotstatusinfo, int delay);

/************************************

�� �� ����
��    �ܣ����ؿ���������������
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setdotlinktable(int serverport, char *clientip, unsigned char dcuid, DOTLINKOFSTRUCT dotlinktbl, int delay);

/************************************

�� �� ����
��    �ܣ����ÿ������û��Ž�Ȩ�ޱ�
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setuseraccess(int serverport, char *clientip, uint8 dcuid, USERCARDATG atg, int delay);

/************************************

�� �� ����
��    �ܣ����ÿ�����ϵͳ�û�����
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setuserpwd(int serverport, char *clientip, uint8 dcuid, USERPWD pwd, int delay);

/************************************

�� �� ����
��    �ܣ�Զ�̿���1
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setopendoor_in(int serverport, char *clientip, unsigned char dcuid, int delay);

/************************************

�� �� ����
��    �ܣ�Զ�̿���2
˵    ����
��    ����

�� �� ֵ��
                         0 �ɹ�
                        -1 ʧ��

************************************/
extern "C" _declspec(dllexport) int __stdcall t_setopendoor_out(int serverport, char *clientip, unsigned char dcuid, int delay);
