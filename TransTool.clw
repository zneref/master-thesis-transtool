; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=cellparamdlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TransTool.h"

ClassCount=12
Class1=CTransToolApp
Class2=CTransToolDlg
Class3=CAboutDlg

ResourceCount=16
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MILLPTR_OY
Resource4=IDD_TRANSTOOL_DIALOG
Resource5=IDD_FORMVIEW (English (U.S.))
Class4=crossmatdlg
Resource6=IDD_MILLPTR_OX
Class5=millptrox
Resource7=IDD_VIEW_DLG
Class6=millptroy
Resource8=IDD_CELL_PARAM_DLG
Class7=millptroz
Resource9=IDD_MILLPTR_OZ
Class8=tensorelemdlg
Resource10=IDD_TRANSMAT_DLG
Class9=ViewDlg
Resource11=IDD_RESULT_DLG
Class10=EndMatDlg
Resource12=IDD_DIALOGBAR (English (U.S.))
Resource13=IDD_PROPPAGE_LARGE (English (U.S.))
Resource14=IDD_PROPPAGE_SMALL (English (U.S.))
Class11=crysclassdlg
Resource15=IDD_TENSOR_DLG
Class12=cellparamdlg
Resource16=IDD_ABOUTBOX (English (U.S.))

[CLS:CTransToolApp]
Type=0
HeaderFile=TransTool.h
ImplementationFile=TransTool.cpp
Filter=N

[CLS:CTransToolDlg]
Type=0
HeaderFile=TransToolDlg.h
ImplementationFile=TransToolDlg.cpp
Filter=D
LastObject=CTransToolDlg
BaseClass=CDialog
VirtualFilter=hWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TransToolDlg.h
ImplementationFile=TransToolDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_TRANSTOOL_DIALOG]
Type=1
Class=?
ControlCount=7
Control1=ID_VISUAL_WND,button,1342275584
Control2=IDCANCEL,button,1342275584
Control3=IDC_TURN_OX,button,1342275584
Control4=IDC_TURN_OY,button,1342275584
Control5=IDC_TURN_OZ,button,1342275584
Control6=IDC_TURN_OO,button,1342275584
Control7=IDC_STATIC,button,1342210055

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:crossmatdlg]
Type=0
HeaderFile=crossmatdlg.h
ImplementationFile=crossmatdlg.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=crossmatdlg
VirtualFilter=idWC

[DLG:IDD_MILLPTR_OX]
Type=1
Class=millptrox
ControlCount=8
Control1=IDC_HOX,edit,1350631552
Control2=IDC_KOX,edit,1350631552
Control3=IDC_LOX,edit,1350631552
Control4=IDOK,button,1342275585
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:millptrox]
Type=0
HeaderFile=millptrox.h
ImplementationFile=millptrox.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HOX
VirtualFilter=dWC

[DLG:IDD_MILLPTR_OY]
Type=1
Class=millptroy
ControlCount=8
Control1=IDC_HOY,edit,1350631552
Control2=IDC_KOY,edit,1350631552
Control3=IDC_LOY,edit,1350631552
Control4=IDOK,button,1342275585
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:millptroy]
Type=0
HeaderFile=millptroy.h
ImplementationFile=millptroy.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HOY
VirtualFilter=dWC

[DLG:IDD_MILLPTR_OZ]
Type=1
Class=millptroz
ControlCount=8
Control1=IDC_HOZ,edit,1350631552
Control2=IDC_KOZ,edit,1350631552
Control3=IDC_LOZ,edit,1350631552
Control4=IDOK,button,1342275585
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:millptroz]
Type=0
HeaderFile=millptroz.h
ImplementationFile=millptroz.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_HOZ

[DLG:IDD_TENSOR_DLG]
Type=1
Class=tensorelemdlg
ControlCount=98
Control1=IDC_CC11,edit,1350631552
Control2=IDC_CC12,edit,1350631552
Control3=IDC_CC13,edit,1350631552
Control4=IDC_CC14,edit,1350631552
Control5=IDC_CC15,edit,1350631552
Control6=IDC_CC16,edit,1350631552
Control7=IDC_CC22,edit,1350631552
Control8=IDC_CC23,edit,1350631552
Control9=IDC_CC24,edit,1350631552
Control10=IDC_CC25,edit,1350631552
Control11=IDC_CC26,edit,1350631552
Control12=IDC_CC33,edit,1350631552
Control13=IDC_CC34,edit,1350631552
Control14=IDC_CC35,edit,1350631552
Control15=IDC_CC36,edit,1350631552
Control16=IDC_CC44,edit,1350631552
Control17=IDC_CC45,edit,1350631552
Control18=IDC_CC46,edit,1350631552
Control19=IDC_CC55,edit,1350631552
Control20=IDC_CC56,edit,1350631552
Control21=IDC_CC66,edit,1350631552
Control22=IDC_M11,edit,1350631552
Control23=IDC_M12,edit,1350631552
Control24=IDC_M13,edit,1350631552
Control25=IDC_M21,edit,1350631552
Control26=IDC_M22,edit,1350631552
Control27=IDC_M23,edit,1350631552
Control28=IDC_M31,edit,1350631552
Control29=IDC_M32,edit,1350631552
Control30=IDC_M33,edit,1350631552
Control31=IDC_RADIO_TRI,button,1342242825
Control32=IDC_RADIO_MONO,button,1342242825
Control33=IDC_RADIO_ORTHO,button,1342242825
Control34=IDC_RADIO_TETRA,button,1342242825
Control35=IDC_RADIO_CUB,button,1342242825
Control36=IDC_RADIO_HEKSA,button,1342242825
Control37=IDC_RADIO_TRIG,button,1342242825
Control38=IDC_FROM_FILE,button,1342275584
Control39=IDC_TRANSF,button,1342275584
Control40=IDC_SAVE,button,1342275584
Control41=IDC_MAT_FROM_FILE,button,1342275584
Control42=IDC_MAT_SAVE,button,1342275584
Control43=IDC_CL11,edit,1350568064
Control44=IDC_CL12,edit,1350568064
Control45=IDC_CL13,edit,1350568064
Control46=IDC_CL14,edit,1350568064
Control47=IDC_CL15,edit,1350568064
Control48=IDC_CL16,edit,1350568064
Control49=IDC_CL21,edit,1350568064
Control50=IDC_CL22,edit,1350568064
Control51=IDC_CL23,edit,1350568064
Control52=IDC_CL24,edit,1350568064
Control53=IDC_CL25,edit,1350568064
Control54=IDC_CL26,edit,1350568064
Control55=IDC_CL31,edit,1350568064
Control56=IDC_CL32,edit,1350568064
Control57=IDC_CL33,edit,1350568064
Control58=IDC_CL34,edit,1350568064
Control59=IDC_CL35,edit,1350568064
Control60=IDC_CL36,edit,1350568064
Control61=IDC_CL41,edit,1350568064
Control62=IDC_CL42,edit,1350568064
Control63=IDC_CL43,edit,1350568064
Control64=IDC_CL44,edit,1350568064
Control65=IDC_CL45,edit,1350568064
Control66=IDC_CL46,edit,1350568064
Control67=IDC_CL51,edit,1350568064
Control68=IDC_CL52,edit,1350568064
Control69=IDC_CL53,edit,1350568064
Control70=IDC_CL54,edit,1350568064
Control71=IDC_CL55,edit,1350568064
Control72=IDC_CL56,edit,1350568064
Control73=IDC_CL61,edit,1350568064
Control74=IDC_CL62,edit,1350568064
Control75=IDC_CL63,edit,1350568064
Control76=IDC_CL64,edit,1350568064
Control77=IDC_CL65,edit,1350568064
Control78=IDC_CL66,edit,1350568064
Control79=IDC_CC21,edit,1350566016
Control80=IDC_CC31,edit,1350566016
Control81=IDC_CC32,edit,1350566016
Control82=IDC_CC41,edit,1350566016
Control83=IDC_CC42,edit,1350566016
Control84=IDC_CC43,edit,1350566016
Control85=IDC_CC51,edit,1350566016
Control86=IDC_CC52,edit,1350566016
Control87=IDC_CC53,edit,1350566016
Control88=IDC_CC54,edit,1350566016
Control89=IDC_CC61,edit,1350566016
Control90=IDC_CC62,edit,1350566016
Control91=IDC_CC63,edit,1350566016
Control92=IDC_CC64,edit,1350566016
Control93=IDC_CC65,edit,1350566016
Control94=IDC_STATIC,static,1342308353
Control95=IDC_STATIC,static,1342308353
Control96=IDC_STATIC,button,1342210055
Control97=IDC_STATIC,static,1342308352
Control98=IDC_STATIC,button,1342210055

[CLS:tensorelemdlg]
Type=0
HeaderFile=tensorelemdlg.h
ImplementationFile=tensorelemdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_CC11

[DLG:IDD_VIEW_DLG]
Type=1
Class=ViewDlg
ControlCount=0

[CLS:ViewDlg]
Type=0
HeaderFile=ViewDlg.h
ImplementationFile=ViewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ViewDlg
VirtualFilter=dWC

[CLS:EndMatDlg]
Type=0
HeaderFile=endmatdlg.h
ImplementationFile=endmatdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_A11

[DLG:IDD_PROPPAGE_LARGE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:crysclassdlg]
Type=0
HeaderFile=crysclassdlg.h
ImplementationFile=crysclassdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=crysclassdlg
VirtualFilter=dWC

[DLG:IDD_CELL_PARAM_DLG]
Type=1
Class=cellparamdlg
ControlCount=15
Control1=IDC_A,edit,1350631552
Control2=IDC_B,edit,1350631552
Control3=IDC_C,edit,1350631552
Control4=IDC_ALPHA,edit,1350631552
Control5=IDC_BETA,edit,1350631552
Control6=IDC_GAMMA,edit,1350631552
Control7=IDOK,button,1342275585
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342210055
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,button,1342210055

[CLS:cellparamdlg]
Type=0
HeaderFile=cellparamdlg.h
ImplementationFile=cellparamdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_GAMMA

[DLG:IDD_TRANSMAT_DLG]
Type=1
Class=crossmatdlg
ControlCount=8
Control1=IDC_STATIC,button,1342210055
Control2=IDC_STATIC,static,1342308352
Control3=IDC_RESETDATA,button,1342275584
Control4=IDC_FIND_MATRIX,button,1342275585
Control5=IDC_CLASS_LIST,combobox,1344340291
Control6=IDC_STATIC,button,1342210055
Control7=IDC_CELL_PARAM,button,1342275584
Control8=IDC_SYSTEM_LIST,combobox,1344340227

[DLG:IDD_RESULT_DLG]
Type=1
Class=EndMatDlg
ControlCount=38
Control1=IDOK,button,1342275585
Control2=IDCANCEL,button,1342275584
Control3=IDC_A11,edit,1350633600
Control4=IDC_A12,edit,1350633600
Control5=IDC_A13,edit,1350633600
Control6=IDC_A21,edit,1350633600
Control7=IDC_A22,edit,1350633600
Control8=IDC_A31,edit,1350633600
Control9=IDC_A32,edit,1350633600
Control10=IDC_A23,edit,1350633600
Control11=IDC_A33,edit,1350633600
Control12=IDC_T11,edit,1350633600
Control13=IDC_T12,edit,1350633600
Control14=IDC_T13,edit,1350633600
Control15=IDC_T21,edit,1350633600
Control16=IDC_T22,edit,1350633600
Control17=IDC_T31,edit,1350633600
Control18=IDC_T32,edit,1350633600
Control19=IDC_T23,edit,1350633600
Control20=IDC_T33,edit,1350633600
Control21=IDC_E11,edit,1350633600
Control22=IDC_E12,edit,1350633600
Control23=IDC_E13,edit,1350633600
Control24=IDC_E21,edit,1350633600
Control25=IDC_E22,edit,1350633600
Control26=IDC_E31,edit,1350633600
Control27=IDC_E32,edit,1350633600
Control28=IDC_E23,edit,1350633600
Control29=IDC_E33,edit,1350633600
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,button,1342210055
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,button,1342210055
Control38=IDC_STATIC,button,1342210055

