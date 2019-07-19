#include"elsSquare.h"

//函数声明
/**************************************************************************/
LRESULT CALLBACK PElouSI(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
 

/**************************************************************************/

int _stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreInstance,
	LPTSTR lpCmdLine,
	int nCmdShow)
{
	//声明变量
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	//初始化窗口类
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = NULL;  // LoadCursor(NULL,)加载系统光标；LoadCursor(hInstance,)加载自定义光标；
	wc.hIcon = NULL;  //
	wc.hIconSm = NULL;  //
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PElouSI;  //回调函数地址
	wc.lpszClassName = "els";  //窗口类的名字
	wc.lpszMenuName = NULL;  //菜单名
	wc.style = CS_HREDRAW | CS_VREDRAW;  //垂直刷新和水平刷新


	//注册窗口类
	if (0 == RegisterClassEx(&wc))
	{
		int a = GetLastError();//函数返回错误码值
		return 0;
	}
	
	//创建窗口
	hWnd = CreateWindowEx(
		WS_EX_TOPMOST,
		"els",
		"俄罗斯方块",
		WS_OVERLAPPEDWINDOW,
		100,  //像素 position
		100,
		WINDOW_WIDTH,  //size
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance, //实例句柄， 包含窗口句柄？？？
		NULL
	);

	//显示窗口
	ShowWindow(hWnd, nCmdShow);  //默认  SW_SHOWNORMAL
	//返回值：隐藏显示返回0，正常显示返回非0

	if (hWnd == NULL)  //窗口句柄, 一个数， 当前窗口的唯一标识  
	{
		return 0;
	}

	//消息循环
	//第二个参数：所有窗口的消息都可以收到   hWnd,  //指的是一个窗口
	//第三四个参数：消息ID范围，0，0是所有

	while (GetMessage(&msg, NULL, 0, 0))
	{
		//

		TranslateMessage(&msg);  //翻译消息  按下按键--电信号--操作系统--字符消息
		//

		DispatchMessage(&msg);  //分发消息  标准消息 命令消息  通知消息 自定义消息

	}

	return 0;
}


//回调函数   返回值 LONG
LRESULT CALLBACK PElouSI(HWND hWnd,  //窗口句柄，每一个窗口都对应着自己的回调函数
	UINT nMsg,  //消息ID : unsigned int
	WPARAM wParam,  //unsigned int  //区分键值
	LPARAM lParam)  //long
{
	HDC hDC;
	PAINTSTRUCT pt;

	switch (nMsg)
	{
	case WM_CREATE://窗口创建初期只产生一次
		//GetLastError();//优化
		//初始化数据
		OnCreate();
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pt);//getDC, 窗口可操作区域的标识  客户区
		OnPaint(hDC);
		EndPaint(hWnd, &pt);  //
		break;

	case WM_TIMER:
		//GetLastError();//优化
		OnTimer(hWnd);
		break;
	case WM_CLOSE:
		//应该先暂停
		GamePause(hWnd);
		if (MessageBox(hWnd, "Really quit?", "My application", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			//如果不是，就继续
			GameContinue(hWnd);
		}
		return 0;


	case WM_DESTROY:
		ExitProcess(0);
		KillTimer(hWnd, DEF_TIMER1);
		PostQuitMessage(0); //WM_CLOSE, WM_DESTORY, WM_QUIT(由此程序产生的消息)
		break;

	case WM_KEYDOWN:
		//GetLastError();//优化
		
		switch (OnKeyDown(hWnd, wParam))
		{
		case 0:
			//正常
			break;

		case 1:
			//重开一局
			OnCreate();
			break;
		case 2:
			//结束
			DestroyWindow(hWnd);
			return 0;

		case 3:
			//继续
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);  //功能
}

