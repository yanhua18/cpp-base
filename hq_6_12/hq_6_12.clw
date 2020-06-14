; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHQDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "hq_6_12.h"
LastPage=0

ClassCount=10
Class1=CHq_6_12App
Class2=CHq_6_12Doc
Class3=CHq_6_12View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_HQ_6_12_FORM
Class5=CHq_6_12Set
Resource3=IDD_DIALOG1
Class7=CHQDlg
Resource4=IDR_MAINFRAME
Class8=CLoginDlg
Class9=CLoginDlg1
Class10=CUserRS
Resource5=IDD_DIALOG2

[CLS:CHq_6_12App]
Type=0
HeaderFile=hq_6_12.h
ImplementationFile=hq_6_12.cpp
Filter=N

[CLS:CHq_6_12Doc]
Type=0
HeaderFile=hq_6_12Doc.h
ImplementationFile=hq_6_12Doc.cpp
Filter=N

[CLS:CHq_6_12View]
Type=0
HeaderFile=hq_6_12View.h
ImplementationFile=hq_6_12View.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=IDC_COMBO1


[CLS:CHq_6_12Set]
Type=0
HeaderFile=hq_6_12Set.h
ImplementationFile=hq_6_12Set.cpp
Filter=N

[DB:CHq_6_12Set]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[BookID], 12, 100
Column2=[BookName], 12, 100
Column3=[Price], 5, 2


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
HeaderFile=hq_6_12.cpp
ImplementationFile=hq_6_12.cpp
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
Command13=ID_SORT_ID
Command14=ID_SORT_PRICE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

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

[DLG:IDD_HQ_6_12_FORM]
Type=1
Class=CHq_6_12View
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ADD,button,1342242816
Control10=IDC_EDIT,button,1342242816
Control11=IDC_DELETE,button,1342242816
Control12=IDC_SEARCH,button,1342242816
Control13=IDC_COMBO1,combobox,1344340226
Control14=IDC_EDIT4,edit,1350631552

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
Class=CHQDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552

[CLS:CHQDlg]
Type=0
HeaderFile=HQDlg.h
ImplementationFile=HQDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHQDlg

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[DLG:IDD_DIALOG2]
Type=1
Class=CLoginDlg1
ControlCount=6
Control1=ID_LOGIN,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552

[CLS:CLoginDlg1]
Type=0
HeaderFile=LoginDlg1.h
ImplementationFile=LoginDlg1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_LOGIN

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

