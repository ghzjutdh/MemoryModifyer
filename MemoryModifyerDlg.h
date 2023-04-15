
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
	CEdit editprocessmem;
	CEdit editvalue;
	CEdit editaddress;
	CEdit editcontent;
	CEdit editbytes;
	CString m_strFileName;
	CListCtrl m_list;
	int m_iCurRow;		//鼠标单击的行
	int m_iCurColunm;	//鼠标单击的列
	int m_lastCheck;    //记录上次查询的数值v
	unsigned int m_workingSetSize;

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

	// 测试用
	void ForTest();

	// 功能函数
	int GetValueBytes(int value); // 获取value的字节数，只能是1，2，4中的一种
	SIZE_T GetBytesSize(int value); // 获取不同字节数对应的sizeof返回，value只能是1，2，4中的一种
	int GetValueByLength(int value, int length);

	// 内存修改API
	BOOL ComparePage(DWORD dwBaseAddr, DWORD dwValue);
	BOOL FindFirst(DWORD dwValue);
	BOOL FindNext(DWORD dwValue);

	// 刷新list列表
	void InitList();
	void ShowList();
	void ClearList();
	void UpdateProcesasInfo();

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
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEdit4();
};
