; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "hq13_1.h"
LastPage=0

ClassCount=8
Class1=CHq13_1App
Class2=CHq13_1Doc
Class3=CHq13_1View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=4
Resource1=IDD_HQ13_1_FORM
Resource2=IDD_ABOUTBOX
Class5=CHq13_1Set
Resource3=IDR_MAINFRAME
Class7=CLoginDlg
Class8=CUserRS
Resource4=IDD_DIALOG1

[CLS:CHq13_1App]
Type=0
HeaderFile=hq13_1.h
ImplementationFile=hq13_1.cpp
Filter=N

[CLS:CHq13_1Doc]
Type=0
HeaderFile=hq13_1Doc.h
ImplementationFile=hq13_1Doc.cpp
Filter=N

[CLS:CHq13_1View]
Type=0
HeaderFile=hq13_1View.h
ImplementationFile=hq13_1View.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=ID_RECOED_SEARCH


[CLS:CHq13_1Set]
Type=0
HeaderFile=hq13_1Set.h
ImplementationFile=hq13_1Set.cpp
Filter=N

[DB:CHq13_1Set]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[StudentID], 12, 100
Column2=[Name], 12, 100
Column3=[age], 5, 2


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=hq13_1.cpp
ImplementationFile=hq13_1.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_RECORD_ADD
Command14=ID_RECOED_SEARCH
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
Command18=ID_LOGIN_IN
Command19=ID_LOGIN_OUT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_HQ13_1_FORM]
Type=1
Class=CHq13_1View
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=ID_LOGIN,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[CLS:CUserRS]
Type=0
HeaderFile=UserRS.h
ImplementationFile=UserRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CUserRS]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[UserName], 12, 100
Column2=[Password], 12, 100
Column3=[authority], 12, 100

