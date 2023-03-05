
// MemoryModifyerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemoryModifyer.h"
#include "MemoryModifyerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define _ID_DYN_CREATE_EDIT_ 10000

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMemoryModifyerDlg 对话框



CMemoryModifyerDlg::CMemoryModifyerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMORYMODIFYER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoryModifyerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC, textfile);
	DDX_Control(pDX, IDC_EDIT1, editvalue);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(CMemoryModifyerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoryModifyerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemoryModifyerDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMemoryModifyerDlg::OnLbnSelchangeList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CMemoryModifyerDlg::OnNMClickList2)
END_MESSAGE_MAP()


// CMemoryModifyerDlg 消息处理程序

BOOL CMemoryModifyerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMemoryModifyerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemoryModifyerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemoryModifyerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 内存修改相关
void CMemoryModifyerDlg::OpenExe()
{
	// m_strFileName
	g_arrList[0] = 1;
	g_arrList[1] = 2;
	g_arrList[2] = 3;
	g_arrList[3] = 4;
	g_arrList[4] = 5;
	g_arrList[5] = 6;
	g_arrList[6] = 7;
	g_arrList[7] = 8;
	g_arrList[8] = 9;
	g_arrList[9] = 10;
	g_nListCnt = 10;
	ShowList();
}

BOOL CMemoryModifyerDlg::FindFirst(DWORD dwValue)
{
	//
}

BOOL CMemoryModifyerDlg::FindNext(DWORD dwValue)
{
	//
}

BOOL CMemoryModifyerDlg::WriteMemory(DWORD dwAddr, DWORD dwValue)
{
	//
}

void CMemoryModifyerDlg::InitList()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_list.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_list.InsertColumn(0, _T("addr"), LVCFMT_CENTER, rect.Width()/2);
	m_list.InsertColumn(1, _T("value"), LVCFMT_CENTER, rect.Width()/2);
}

void CMemoryModifyerDlg::ShowList()
{
	m_list.DeleteAllItems();	//清空所有表项
	InitList();
	// 在列表视图控件中插入列表项，并设置列表子项文本   
	for (int i = 0;i < g_nListCnt;i++){
		CString str1;
		str1.Format(_T("%d"), i);
		m_list.InsertItem(i, str1);
		str1.Format(_T("%d"), g_arrList[i]);
		m_list.SetItemText(i, 1, str1);
	}
}

void CMemoryModifyerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFileName[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szFileName, MAX_PATH);
	CString Filter_file = L"Supported Files(*.exe)|*.exe|All Files(*.*)|*.*||";
	CFileDialog file_Open(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, Filter_file, NULL);
	file_Open.m_ofn.lpstrInitialDir = szFileName;
	if (file_Open.DoModal() == IDOK)
	{
		m_strFileName = file_Open.GetPathName();
	}

	textfile.SetWindowText(m_strFileName);

	OpenExe();
}


void CMemoryModifyerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMemoryModifyerDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMemoryModifyerDlg::OnNMClickList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int col = 0;
	int row = 0;
	row = pNMItemActivate->iItem;
	col = pNMItemActivate->iSubItem;
	CString str;
	str.Format(_T("row=%d col=%d"), row, col);
	editvalue.SetWindowText(str);
	*pResult = 0;
}
