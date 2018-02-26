# Microsoft Developer Studio Generated NMAKE File, Based on TransTool.dsp
!IF "$(CFG)" == ""
CFG=TransTool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to TransTool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "TransTool - Win32 Release" && "$(CFG)" != "TransTool - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TransTool - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\TransTool.exe"


CLEAN :
	-@erase "$(INTDIR)\cellparamdlg.obj"
	-@erase "$(INTDIR)\crossmatdlg.obj"
	-@erase "$(INTDIR)\endmatdlg.obj"
	-@erase "$(INTDIR)\matrix.obj"
	-@erase "$(INTDIR)\millptrox.obj"
	-@erase "$(INTDIR)\millptroy.obj"
	-@erase "$(INTDIR)\millptroz.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tensor.obj"
	-@erase "$(INTDIR)\tensorelemdlg.obj"
	-@erase "$(INTDIR)\TransTool.obj"
	-@erase "$(INTDIR)\TransTool.pch"
	-@erase "$(INTDIR)\TransTool.res"
	-@erase "$(INTDIR)\TransToolDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\ViewDlg.obj"
	-@erase "$(OUTDIR)\TransTool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\TransTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x415 /fo"$(INTDIR)\TransTool.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TransTool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=OPENGL32.LIB GLU32.LIB GLAUX.LIB /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\TransTool.pdb" /machine:I386 /out:"$(OUTDIR)\TransTool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cellparamdlg.obj" \
	"$(INTDIR)\crossmatdlg.obj" \
	"$(INTDIR)\endmatdlg.obj" \
	"$(INTDIR)\matrix.obj" \
	"$(INTDIR)\millptrox.obj" \
	"$(INTDIR)\millptroy.obj" \
	"$(INTDIR)\millptroz.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tensor.obj" \
	"$(INTDIR)\tensorelemdlg.obj" \
	"$(INTDIR)\TransTool.obj" \
	"$(INTDIR)\TransToolDlg.obj" \
	"$(INTDIR)\ViewDlg.obj" \
	"$(INTDIR)\TransTool.res" \
	"$(INTDIR)\vector.obj"

"$(OUTDIR)\TransTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TransTool - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\TransTool.exe"


CLEAN :
	-@erase "$(INTDIR)\cellparamdlg.obj"
	-@erase "$(INTDIR)\crossmatdlg.obj"
	-@erase "$(INTDIR)\endmatdlg.obj"
	-@erase "$(INTDIR)\matrix.obj"
	-@erase "$(INTDIR)\millptrox.obj"
	-@erase "$(INTDIR)\millptroy.obj"
	-@erase "$(INTDIR)\millptroz.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tensor.obj"
	-@erase "$(INTDIR)\tensorelemdlg.obj"
	-@erase "$(INTDIR)\TransTool.obj"
	-@erase "$(INTDIR)\TransTool.pch"
	-@erase "$(INTDIR)\TransTool.res"
	-@erase "$(INTDIR)\TransToolDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\ViewDlg.obj"
	-@erase "$(OUTDIR)\TransTool.exe"
	-@erase "$(OUTDIR)\TransTool.ilk"
	-@erase "$(OUTDIR)\TransTool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\TransTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x415 /fo"$(INTDIR)\TransTool.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TransTool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=OPENGL32.LIB GLU32.LIB GLAUX.LIB /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\TransTool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\TransTool.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cellparamdlg.obj" \
	"$(INTDIR)\crossmatdlg.obj" \
	"$(INTDIR)\endmatdlg.obj" \
	"$(INTDIR)\matrix.obj" \
	"$(INTDIR)\millptrox.obj" \
	"$(INTDIR)\millptroy.obj" \
	"$(INTDIR)\millptroz.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tensor.obj" \
	"$(INTDIR)\tensorelemdlg.obj" \
	"$(INTDIR)\TransTool.obj" \
	"$(INTDIR)\TransToolDlg.obj" \
	"$(INTDIR)\ViewDlg.obj" \
	"$(INTDIR)\TransTool.res" \
	"$(INTDIR)\vector.obj"

"$(OUTDIR)\TransTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("TransTool.dep")
!INCLUDE "TransTool.dep"
!ELSE 
!MESSAGE Warning: cannot find "TransTool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TransTool - Win32 Release" || "$(CFG)" == "TransTool - Win32 Debug"
SOURCE=.\cellparamdlg.cpp

"$(INTDIR)\cellparamdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\crossmatdlg.cpp

"$(INTDIR)\crossmatdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\endmatdlg.cpp

"$(INTDIR)\endmatdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\translib\matrix.cpp

"$(INTDIR)\matrix.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\millptrox.cpp

"$(INTDIR)\millptrox.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\millptroy.cpp

"$(INTDIR)\millptroy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\millptroz.cpp

"$(INTDIR)\millptroz.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TransTool - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\TransTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TransTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TransTool - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\TransTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TransTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\translib\tensor.cpp

"$(INTDIR)\tensor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\tensorelemdlg.cpp

"$(INTDIR)\tensorelemdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\TransTool.cpp

"$(INTDIR)\TransTool.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\TransTool.rc

"$(INTDIR)\TransTool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\TransToolDlg.cpp

"$(INTDIR)\TransToolDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"


SOURCE=.\translib\vector.cpp

"$(INTDIR)\vector.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\ViewDlg.cpp

"$(INTDIR)\ViewDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TransTool.pch"



!ENDIF 

