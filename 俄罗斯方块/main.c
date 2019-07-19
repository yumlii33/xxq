#include"elsSquare.h"

//��������
/**************************************************************************/
LRESULT CALLBACK PElouSI(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
 

/**************************************************************************/

int _stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreInstance,
	LPTSTR lpCmdLine,
	int nCmdShow)
{
	//��������
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	//��ʼ��������
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = NULL;  // LoadCursor(NULL,)����ϵͳ��ꣻLoadCursor(hInstance,)�����Զ����ꣻ
	wc.hIcon = NULL;  //
	wc.hIconSm = NULL;  //
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PElouSI;  //�ص�������ַ
	wc.lpszClassName = "els";  //�����������
	wc.lpszMenuName = NULL;  //�˵���
	wc.style = CS_HREDRAW | CS_VREDRAW;  //��ֱˢ�º�ˮƽˢ��


	//ע�ᴰ����
	if (0 == RegisterClassEx(&wc))
	{
		int a = GetLastError();//�������ش�����ֵ
		return 0;
	}
	
	//��������
	hWnd = CreateWindowEx(
		WS_EX_TOPMOST,
		"els",
		"����˹����",
		WS_OVERLAPPEDWINDOW,
		100,  //���� position
		100,
		WINDOW_WIDTH,  //size
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance, //ʵ������� �������ھ��������
		NULL
	);

	//��ʾ����
	ShowWindow(hWnd, nCmdShow);  //Ĭ��  SW_SHOWNORMAL
	//����ֵ��������ʾ����0��������ʾ���ط�0

	if (hWnd == NULL)  //���ھ��, һ������ ��ǰ���ڵ�Ψһ��ʶ  
	{
		return 0;
	}

	//��Ϣѭ��
	//�ڶ������������д��ڵ���Ϣ�������յ�   hWnd,  //ָ����һ������
	//�����ĸ���������ϢID��Χ��0��0������

	while (GetMessage(&msg, NULL, 0, 0))
	{
		//

		TranslateMessage(&msg);  //������Ϣ  ���°���--���ź�--����ϵͳ--�ַ���Ϣ
		//

		DispatchMessage(&msg);  //�ַ���Ϣ  ��׼��Ϣ ������Ϣ  ֪ͨ��Ϣ �Զ�����Ϣ

	}

	return 0;
}


//�ص�����   ����ֵ LONG
LRESULT CALLBACK PElouSI(HWND hWnd,  //���ھ����ÿһ�����ڶ���Ӧ���Լ��Ļص�����
	UINT nMsg,  //��ϢID : unsigned int
	WPARAM wParam,  //unsigned int  //���ּ�ֵ
	LPARAM lParam)  //long
{
	HDC hDC;
	PAINTSTRUCT pt;

	switch (nMsg)
	{
	case WM_CREATE://���ڴ�������ֻ����һ��
		//GetLastError();//�Ż�
		//��ʼ������
		OnCreate();
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pt);//getDC, ���ڿɲ�������ı�ʶ  �ͻ���
		OnPaint(hDC);
		EndPaint(hWnd, &pt);  //
		break;

	case WM_TIMER:
		//GetLastError();//�Ż�
		OnTimer(hWnd);
		break;
	case WM_CLOSE:
		//Ӧ������ͣ
		GamePause(hWnd);
		if (MessageBox(hWnd, "Really quit?", "My application", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			//������ǣ��ͼ���
			GameContinue(hWnd);
		}
		return 0;


	case WM_DESTROY:
		ExitProcess(0);
		KillTimer(hWnd, DEF_TIMER1);
		PostQuitMessage(0); //WM_CLOSE, WM_DESTORY, WM_QUIT(�ɴ˳����������Ϣ)
		break;

	case WM_KEYDOWN:
		//GetLastError();//�Ż�
		
		switch (OnKeyDown(hWnd, wParam))
		{
		case 0:
			//����
			break;

		case 1:
			//�ؿ�һ��
			OnCreate();
			break;
		case 2:
			//����
			DestroyWindow(hWnd);
			return 0;

		case 3:
			//����
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);  //����
}

