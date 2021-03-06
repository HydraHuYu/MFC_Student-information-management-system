
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream> 
#include <vector>
#include <sstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int clk = 0;
struct Student
{
	CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies;
	bool flag;
}student[300];
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT10, &CMFCApplication1Dlg::OnEnChangeEdit10)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()//新建
{
	// TODO: 在此添加控件通知处理程序代码
	CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies; //获取信息；
	GetDlgItemText(IDC_EDIT1, Id);                                                          
	GetDlgItemText(IDC_EDIT2, Name); 
	GetDlgItemText(IDC_EDIT3, Gender); 
	GetDlgItemText(IDC_EDIT4, Department); 
	GetDlgItemText(IDC_EDIT5, ProfessionalClass); 
	GetDlgItemText(IDC_EDIT6, HomeAddress); 
	GetDlgItemText(IDC_EDIT7, Telephone); 
	GetDlgItemText(IDC_EDIT8, Hobbies); 
	bool flag = true;
	CString X = CString("");
	if (Id != X && Name != X && Gender != X && Department != X && ProfessionalClass != X && HomeAddress != X && Hobbies != X)
	{
		for (int i = 0; i < clk; i++)
		{
			if (student[i].flag) continue;//已删除的学生信息
			if (Id == student[i].Id)
			{
				flag = false;
			}
		}
	}
	if (flag)
	{
		student[clk++] = { Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies ,false };
		MessageBox(_T("新建学生信息成功！"));
	}
	else
	{
		MessageBox(_T("学号已存在或者信息填写不完整！"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()//修改学生（无法修改学号）
{
	// TODO: 在此添加控件通知处理程序代码
	CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies;
	GetDlgItemText(IDC_EDIT1, Id); //获取ID
	GetDlgItemText(IDC_EDIT2, Name); //获取Name
	GetDlgItemText(IDC_EDIT3, Gender); //获取Gender
	GetDlgItemText(IDC_EDIT4, Department); //获取Departent
	GetDlgItemText(IDC_EDIT5, ProfessionalClass); //获取
	GetDlgItemText(IDC_EDIT6, HomeAddress); //获取
	GetDlgItemText(IDC_EDIT7, Telephone); //获取
	GetDlgItemText(IDC_EDIT8, Hobbies); //获取
	bool flag = true;
	CString X = CString("");
	if (Id != X && Name != X && Gender != X && Department != X && ProfessionalClass != X && HomeAddress != X && Hobbies != X)
	{
		for (int i = 0; i < clk; i++)
		{
			if (student[i].flag) continue;//已删除的学生信息
			if (Id == student[i].Id &&  Name == student[i].Name)
			{
				flag = false;
				student[i] = { Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies ,false };
				MessageBox(_T("修改学生信息成功！"));
				break;
			}
		}
	}
	if (flag)
	{
		MessageBox(_T("修改学生信息失败！请重新检查学号！或者信息是否填写完整！"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton3()//查询
{
	// TODO: 在此添加控件通知处理程序代码
	CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies;
	GetDlgItemText(IDC_EDIT1, Id); //获取ID
	GetDlgItemText(IDC_EDIT2, Name); //获取Name
	GetDlgItemText(IDC_EDIT3, Gender); //获取Gender
	GetDlgItemText(IDC_EDIT4, Department); //获取Departent
	GetDlgItemText(IDC_EDIT5, ProfessionalClass); //获取
	GetDlgItemText(IDC_EDIT6, HomeAddress); //获取
	GetDlgItemText(IDC_EDIT7, Telephone); //获取
	GetDlgItemText(IDC_EDIT8, Hobbies); //获取
	bool flag = true;
	CString X = CString("");
	if (Id != X && Name != X)
	{
		for (int i = 0; i < clk; i++)
		{
			if (student[i].flag) continue;//已删除的学生信息
			if (Id == student[i].Id &&  Name == student[i].Name)
			{
				flag = false;
				SetDlgItemText(IDC_EDIT1, student[i].Id); //获取ID
				SetDlgItemText(IDC_EDIT2, student[i].Name); //获取Name
				SetDlgItemText(IDC_EDIT3, student[i].Gender); //获取Gender
				SetDlgItemText(IDC_EDIT4, student[i].Department); //获取Departent
				SetDlgItemText(IDC_EDIT5, student[i].ProfessionalClass); //获取
				SetDlgItemText(IDC_EDIT6, student[i].HomeAddress); //获取
				SetDlgItemText(IDC_EDIT7, student[i].Telephone); //获取
				SetDlgItemText(IDC_EDIT8, student[i].Hobbies); //获取
				MessageBox(_T("查询学生信息成功！"));
			}
		}
	}
	if (flag)
	{
		MessageBox(_T("查询学生信息失败！请重新检查学号！"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton4()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies; //获取信息；
	GetDlgItemText(IDC_EDIT1, Id);
	GetDlgItemText(IDC_EDIT2, Name);
	GetDlgItemText(IDC_EDIT3, Gender);
	GetDlgItemText(IDC_EDIT4, Department);
	GetDlgItemText(IDC_EDIT5, ProfessionalClass);
	GetDlgItemText(IDC_EDIT6, HomeAddress);
	GetDlgItemText(IDC_EDIT7, Telephone);
	GetDlgItemText(IDC_EDIT8, Hobbies);
	bool flag = true;
	CString X = CString("");
	if (Id != X && Name != X)
	{
		for (int i = 0; i < clk; i++)
		{
			if (student[i].flag) continue;//已删除的学生信息
			if (Id == student[i].Id && Name == student[i].Name)
			{
				flag = false;
				student[i].flag = true;
				MessageBox(_T("学生信息删除成功！"));
			}
		}
	}
	if (flag)
	{
		MessageBox(_T("删除学生信息失败！请重新检查学号或者姓名！"));
	}
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	CString Department,Information;
	CString X("  "), Y("\r\n");
	GetDlgItemText(IDC_EDIT9, Department); //获取ID
	bool flag = true;
	for (int i = 0; i < clk; i++)
	{
		if (student[i].flag) continue;//已删除的学生信息
		if (student[i].Department == Department)
		{
			flag = false;
			Information += student[i].Id + X + student[i].Name + X + student[i].Gender + X + student[i].Department + X + student[i].ProfessionalClass + X + student[i].HomeAddress + X + student[i].Telephone + X + student[i].Hobbies + Y;
		}

	}
	if (flag)
	{
		MessageBox(_T("查询学院信息失败！请重新检查拼写是否错误或者完整！"));
	}
	else
	{
		SetDlgItemText(IDC_EDIT10, Information);
		MessageBox(_T("查询学院信息成功！"));
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  Information;
	CString X("  "), Y("\r\n");
	bool flag = true;
	for (int i = 0; i < clk; i++)
	{
		if (student[i].flag) continue;//已删除的学生信息
		flag = false;
		Information += student[i].Id + X + student[i].Name + X + student[i].Gender + X + student[i].Department + X + student[i].ProfessionalClass + X + student[i].HomeAddress + X + student[i].Telephone + X + student[i].Hobbies + Y;
	}
	if (flag)
	{
		MessageBox(_T("查询学生信息失败！"));
	}
	else
	{
		SetDlgItemText(IDC_EDIT10, Information);
		MessageBox(_T("查询学生信息成功！"));
	}
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	ifstream in("mydata.txt");

	if (!in)
	{
		MessageBox(_T("学生信息读取失败！"));
	}
	else
	{
		vector<string> arr;
		string word;
		while (in>>word)
		{
			if (word == "不怕告诉你重修费在行政楼1楼交!");
			arr.push_back(word);
		}
		in.close();
		CString Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies; //获取信息；
		clk = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (i % 8 == 0) Id = arr[i].c_str();
			if (i % 8 == 1) Name  = arr[i].c_str();
			if (i % 8 == 2) Gender = arr[i].c_str();
			if (i % 8 == 3) Department = arr[i].c_str();
			if (i % 8 == 4) ProfessionalClass = arr[i].c_str();
			if (i % 8 == 5) HomeAddress = arr[i].c_str();
			if (i % 8 == 6) Telephone = arr[i].c_str();
			if (i % 8 == 7) Hobbies = arr[i].c_str();
			if (i % 8 == 7)  student[clk++] = { Id, Name, Gender, Department, ProfessionalClass, HomeAddress, Telephone, Hobbies ,false };
		}
		MessageBox(_T("学生信息读取成功！"));
	}
	//CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	ofstream out("mydata.txt");
	if (!out)
	{
		MessageBox(_T("学生信息写入失败！"));
	}
	else
	{
		string X = "", Y = "";
		for (int i = 0; i < clk; i++)
		{
			if (!student[i].flag) 
			{
				Y = string(CW2A(student[i].Id.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].Name.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].Gender.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].Department.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].ProfessionalClass.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].HomeAddress.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].Telephone.GetString()));
				X += Y + " ";
				Y = string(CW2A(student[i].Hobbies.GetString()));
				X += Y + "\r\n";
			}
		}
		out << X;
		out << "不怕告诉你重修费在行政楼1楼交!" << endl;
		out.close();
		MessageBox(_T("学生信息写入成功！"));
	}
	CDialogEx::OnCancel();
}


void CMFCApplication1Dlg::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
