# Microsoft Developer Studio Project File - Name="TransTool" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TransTool - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TransTool.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TransTool.mak" CFG="TransTool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TransTool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TransTool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TransTool - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x415 /d "NDEBUG"
# ADD RSC /l 0x415 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 OPENGL32.LIB GLU32.LIB GLAUX.LIB /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TransTool - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x415 /d "_DEBUG"
# ADD RSC /l 0x415 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 OPENGL32.LIB GLU32.LIB GLAUX.LIB /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TransTool - Win32 Release"
# Name "TransTool - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cellparamdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\transmatdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\resultdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\translib\matrix.cpp
# End Source File
# Begin Source File

SOURCE=.\millptrox.cpp
# End Source File
# Begin Source File

SOURCE=.\millptroy.cpp
# End Source File
# Begin Source File

SOURCE=.\millptroz.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\translib\tensor.cpp
# End Source File
# Begin Source File

SOURCE=.\tensorelemdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TransTool.cpp
# End Source File
# Begin Source File

SOURCE=.\TransTool.rc
# End Source File
# Begin Source File

SOURCE=.\TransToolDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\translib\vector.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cellparamdlg.h
# End Source File
# Begin Source File

SOURCE=.\transmatdlg.h
# End Source File
# Begin Source File

SOURCE=.\resultdlg.h
# End Source File
# Begin Source File

SOURCE=.\listelem.h
# End Source File
# Begin Source File

SOURCE=.\translib\matrix.h
# End Source File
# Begin Source File

SOURCE=.\millptrox.h
# End Source File
# Begin Source File

SOURCE=.\millptroy.h
# End Source File
# Begin Source File

SOURCE=.\millptroz.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\translib\tensor.h
# End Source File
# Begin Source File

SOURCE=.\tensorelemdlg.h
# End Source File
# Begin Source File

SOURCE=.\TransTool.h
# End Source File
# Begin Source File

SOURCE=.\TransToolDlg.h
# End Source File
# Begin Source File

SOURCE=.\translib\vector.h
# End Source File
# Begin Source File

SOURCE=.\ViewDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\bmp\triclin\1.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\triclin\1_inv.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\monoclin\2.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\orthoro\222.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\23_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\23_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\32_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\32_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_C.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_D.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_C.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_D.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_m_C.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3_inv_m_D.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3m_C.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\trigonal\3m_D.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\422_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\432.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_2m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_2m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\4_inv_3m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\4_inv_3m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_C.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_inv_D.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\monoclin\4_per_m.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_per_m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_per_m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4_per_mmm_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4mm_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\tetrag\4mm_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\622.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_inv_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_inv_m2_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_inv_m2_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_per_m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_per_m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6_per_mmm.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6mm_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\hexag\6mm_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\m3_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\m3_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\cubic\m3m.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\monoclin\m_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\monoclin\m_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\orthoro\mm2_A.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\orthoro\mm2_B.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\orthoro\mmm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TransTool.ico
# End Source File
# Begin Source File

SOURCE=.\res\TransTool.rc2
# End Source File
# End Group
# End Target
# End Project
