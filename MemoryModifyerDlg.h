
// MemoryModifyerDlg.h: 头文件
//

#pragma once


// CMemoryModifyerDlg 对话框
class CMemoryModifyerDlg : public CDialogEx
{
// 构造
public:
	CMemoryModifyerDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CStatic textfile;
	CEdit editvalue;
	CString m_strFileName;
	CListCtrl m_list;
	int m_iCurRow;		//鼠标单击的行
	int m_iCurColunm;	//鼠标单击的列

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMORYMODIFYER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 内存修改相关
	DWORD g_arrList[1024]; //存储找到的地址，只存1024个
	int g_nListCnt; //有效的地址个数
	HANDLE g_hProcess; //目标进程的句柄

	void OpenExe();
	BOOL FindFirst(DWORD dwValue);
	BOOL FindNext(DWORD dwValue);
	BOOL WriteMemory(DWORD dwAddr, DWORD dwValue);
	void InitList();
	void ShowList();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnNMClickList2(NMHDR* pNMHDR, LRESULT* pResult);
};
