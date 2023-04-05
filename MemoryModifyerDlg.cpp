
// MemoryModifyerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemoryModifyer.h"
#include "MemoryModifyerDlg.h"
#include "afxdialogex.h"
#include<stdio.h>
#include<Windows.h>
#include<iostream>

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
	DDX_Control(pDX, IDC_EDIT2, editaddress);
	DDX_Control(pDX, IDC_EDIT3, editcontent);
	DDX_Control(pDX, IDC_EDIT4, editbytes);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(CMemoryModifyerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoryModifyerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemoryModifyerDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST2, &CMemoryModifyerDlg::OnLbnSelchangeList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CMemoryModifyerDlg::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemoryModifyerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemoryModifyerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMemoryModifyerDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT4, &CMemoryModifyerDlg::OnEnChangeEdit4)
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
	InitList();
	ForTest();
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
void CMemoryModifyerDlg::ForTest()
{
	// 测试用
	//std::cout << "ForTest sizeof(DWORD)=" << sizeof(DWORD) << " sizeof(WORD)=" << sizeof(DWORD) << " sizeof(BYTE)=" << sizeof(BYTE) << " 1582835494 & 0x0ffff = " << GetValueByLength(1582835494, 2) << std::endl;
}

int CMemoryModifyerDlg::GetValueBytes(int value) {
	BYTE byte[4];
	byte[0] = value % 256;
	byte[1] = value >> 8 % 256;
	byte[2] = value >> 16 % 256;
	byte[3] = value >> 24 % 256;
	int length = 4;
	if (byte[3] != 0 || byte[2] != 0) length = 4;
	else if (byte[1] != 0) length = 2;
	else length = 1;
	return length;
}

SIZE_T CMemoryModifyerDlg::GetBytesSize(int value) {
	if (value == 1) return sizeof(BYTE);
	else if (value == 2) return sizeof(WORD);
	else if (value == 4) return sizeof(DWORD);
	else return sizeof(DWORD);
}
int CMemoryModifyerDlg::GetValueByLength(int value, int length) {
	if (length == 1) return value & 0x0ff;
	else if (length == 2) return value & 0x0ffff;
	else return value;
}

BOOL CMemoryModifyerDlg::ComparePage(DWORD dwBaseAddr, DWORD dwValue) {
	BYTE arBytes[4096];
	if (!::ReadProcessMemory(g_hProcess, (LPCVOID)dwBaseAddr, arBytes, 4096, NULL)) {
		return FALSE;
	}
	BYTE byte[4];
	byte[0] = dwValue % 256;
	byte[1] = dwValue >> 8 % 256;
	byte[2] = dwValue >> 16 % 256;
	byte[3] = dwValue >> 24 % 256;
	int length = GetValueBytes(dwValue);

	//一个DWORD4个字节，所以从头开始一次取4个字节长度的值进行对比
	for (int i = 0; i < 4093; i++) {
		int starti = i;
		for (int j = 0; j < length;j++) {
			if (arBytes[i + j] == byte[j]) {
				if (j == length - 1) {
					if (g_nListCnt >= 1024)
						return FALSE;
					g_arrList[g_nListCnt++] = dwBaseAddr + starti;
					if (j >= 1) i += j - 1;
				}
			}
			else{
				if (j >= 1) i += j - 1;
				break;
			}
		}
	}
	return TRUE;
}

BOOL CMemoryModifyerDlg::FindFirst(DWORD dwValue)
{
	BOOL bRet = FALSE;
	const DWORD dwOneGb = 1024 * 1024 * 1024; //定义一个GB的大小
	const DWORD dwOnePage = 4 * 1024; //定义4KB一页
	g_nListCnt = 0;
	if (g_hProcess == NULL)
		return FALSE;
	DWORD dwBase = 64 * 1024; //刚开始的64kb是不能访问的，直接跳过
	for (; dwBase < 2 * dwOneGb; dwBase += dwOnePage) {
		//在2gb的空间里每次在4kb的页中寻找
		ComparePage(dwBase, dwValue);
	}
	return TRUE;
}

BOOL CMemoryModifyerDlg::FindNext(DWORD dwValue)
{
	BOOL bRet = FALSE;
	int nOrgCnt = g_nListCnt;
	g_nListCnt = 0;
	DWORD dwReadValue; //存储读取值的地址
	int length = GetValueBytes(dwValue);
	//std::cout << "FindNext length=" << (int)length << " g_nListCnt=" << nOrgCnt << " dwValue=" << dwValue << std::endl;
	for (int i = 0; i < nOrgCnt; i++) {
		if (::ReadProcessMemory(g_hProcess, (LPVOID)g_arrList[i], &dwReadValue, sizeof(DWORD), NULL)) {
			dwReadValue = GetValueByLength(dwReadValue, length);
			//std::cout << "ReadProcessMemory ReadAdress=0x" << std::hex << g_arrList[i] << " ReadValue=" << std::dec << dwReadValue << std::endl;
			if (dwReadValue == dwValue) {
				g_arrList[g_nListCnt++] = g_arrList[i];
				bRet = TRUE;
			}
		}
	}
	return bRet;
}

BOOL CMemoryModifyerDlg::WriteMemory(DWORD dwAddr, DWORD dwValue)
{
	return FALSE;
}

void CMemoryModifyerDlg::InitList()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_list.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加四列   
	m_list.InsertColumn(0, _T("地址"), LVCFMT_CENTER, (rect.Width() - 30) / 4);
	m_list.InsertColumn(1, _T("单字节"), LVCFMT_CENTER, (rect.Width() - 30) / 4);
	m_list.InsertColumn(2, _T("双字节"), LVCFMT_CENTER, (rect.Width() - 30) / 4);
	m_list.InsertColumn(3, _T("四字节"), LVCFMT_CENTER, (rect.Width() - 30) / 4);
}

void CMemoryModifyerDlg::ShowList()
{
	m_list.DeleteAllItems();	//清空所有表项
	// 在列表视图控件中插入列表项，并设置列表子项文本
	BYTE arBytes[4];
	for (int i = 0;i < g_nListCnt;i++){
		if (::ReadProcessMemory(g_hProcess, (LPCVOID)g_arrList[i], arBytes, sizeof(DWORD), NULL)) {
			CString str1;
			str1.Format(_T("%04x"), g_arrList[i]);
			m_list.InsertItem(i, str1);
			str1.Format(_T("%d"), arBytes[0]);
			m_list.SetItemText(i, 1, str1);
			str1.Format(_T("%d"), arBytes[0] + arBytes[1] * 256);
			m_list.SetItemText(i, 2, str1);
			str1.Format(_T("%d"), arBytes[0] + arBytes[1] * 256 + arBytes[2] * 65536 + arBytes[3] * 16777216);
			m_list.SetItemText(i, 3, str1);
		}
	}
}

void CMemoryModifyerDlg::ClearList()
{
	memset(g_arrList, 0, sizeof(g_arrList));
	g_nListCnt = 0;
	ShowList();
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

	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	PROCESS_INFORMATION pi;
	LPWSTR lpStr = (LPWSTR)(LPCTSTR)m_strFileName;
	BOOL bRet = ::CreateProcess(
		NULL,
		lpStr,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	);
	g_hProcess = pi.hProcess; //将目标进程的句柄保存在全局变量中

	ClearList();
}


void CMemoryModifyerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString editstr;
	editvalue.GetWindowText(editstr);
	DWORD dwValue = _tcstoul(editstr, NULL, 10);//把字符转成10位整数
	m_lastCheck = (int)dwValue;
	if (g_nListCnt == 0) {
		FindFirst(dwValue);
	}
	else {
		FindNext(dwValue);
	}
	ShowList();
}


void CMemoryModifyerDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMemoryModifyerDlg::OnNMClickList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int row = pNMItemActivate->iItem;
	CString str;
	str.Format(_T("%04x"), g_arrList[row]);
	editaddress.SetWindowText(str);
	str.Format(_T("%d"), m_lastCheck);
	editcontent.SetWindowText(str);
	int length = GetValueBytes(m_lastCheck);
	str.Format(_T("%d"), length);
	editbytes.SetWindowText(str);
	*pResult = 0;
}


void CMemoryModifyerDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ClearList();
}


void CMemoryModifyerDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowList();
}


void CMemoryModifyerDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMemoryModifyerDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString editstr;
	editbytes.GetWindowText(editstr);
	DWORD dwValue = _tcstoul(editstr, NULL, 10);//把字符转成10位整数
	if (dwValue != 1 && dwValue != 2 && dwValue != 4) {
		CString contentstr;
		editcontent.GetWindowText(contentstr);
		DWORD contentValue = _tcstoul(contentstr, NULL, 10);//把字符转成10位整数
		int length = GetValueBytes(contentValue);
		editstr.Format(_T("%d"), length);
		editbytes.SetWindowText(editstr);
	}
}
