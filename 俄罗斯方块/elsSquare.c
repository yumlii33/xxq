#include"elsSquare.h"

//��������
char g_arrBackGround[20][10] = { 0 };  //char  1���ֽڣ���Լ�ռ�
char g_arrSquare[4][4] = { 0 };  //
int g_SquareID;  //
int g_nLine;
int g_nList;
int g_Score = 0;

//
void OnPaint(HDC hDc)
{
	//����������DC
	HDC hMemDC = CreateCompatibleDC(hDc);//����ֵ �ڴ��dc;����  ����dc;  dc:���
	//����һ��ֽ
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDc, WINDOW_WIDTH, GAME_PLACE_HEIGHT);
	//��������
	SelectObject(hMemDC, hBitmapBack);

	PaintSquare(hMemDC);
	ShowSquare2(hMemDC);
	ShowScore(hMemDC);

	//����      //����λ��  //����          //����������������      //���ݷ�ʽ��ֱ�Ӹ���
	BitBlt(hDc, 0, 0, WINDOW_WIDTH, GAME_PLACE_HEIGHT, hMemDC, 0, 0, SRCCOPY);

	//�ͷ���Դ
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);

	return;
}

//��ʾ2
void ShowSquare2(HDC hMemDC)
{
	int i = 0;
	int j = 0;
	HBRUSH hOldBrush;
	HBRUSH hNewBrush = CreateSolidBrush(RGB(130, 135, 230));
	hOldBrush = SelectObject(hMemDC, hNewBrush);

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 2)
			{
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}
	hNewBrush = SelectObject(hMemDC, hOldBrush);
	DeleteObject(hNewBrush);
}

void ShowScore(HDC hMemDC) //��ʾ����
{
	Rectangle(hMemDC, 300, 0, WINDOW_WIDTH, GAME_PLACE_HEIGHT);
	HFONT hNewFont, hOldFont;
	
	hNewFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, 0, 1, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Consolas"));

	// �����FONT�������DC��
	hOldFont = (HFONT)SelectObject(hMemDC, hNewFont);
	
	CHAR szSourceInfo[20];
	
	wsprintf(szSourceInfo, "score %d ", GetScore());
	// ���������ɫ
	SetTextColor(hMemDC, RGB(175, 215, 230));
	// ����ַ�����
	TextOut(hMemDC,350,50 ,szSourceInfo, lstrlen(szSourceInfo));


    // �����ɣ���ԭ�����������Ż�DC��
	hNewFont = SelectObject(hMemDC, hOldFont);
	DeleteObject(hNewFont);
}

//������
void PaintSquare(HDC hMemDC)
{
	int i = 0;
	int j = 0;

	HBRUSH hOldBrush;
	HBRUSH hNewBrush;

	//���󷽿�
	Rectangle(hMemDC, 0, 0, GAME_PLACE_WIDTH, GAME_PLACE_HEIGHT);  //�豸�����ľ�����������꣬��������

	////����   ָ��һ������
	//g_arrBackGround[2][4] = 1;
	//g_arrBackGround[3][3] = 1;

	hNewBrush = CreateSolidBrush(RGB(225, 225, 65));
	hOldBrush = SelectObject(hMemDC, hNewBrush);

	//���� ��С����
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 1)
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
		}
	}
	hNewBrush = SelectObject(hMemDC, hOldBrush);
	DeleteObject(hNewBrush);
}

//���������
int CreateRandomSquare()
{
	int nIndex = rand() % 7;

	switch (nIndex)
	{
	case 0:
		g_arrSquare[0][0] = 1, g_arrSquare[0][1] = 1, g_arrSquare[0][2] = 0, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 0, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 1, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;

	case 1:
		g_arrSquare[0][0] = 0, g_arrSquare[0][1] = 1, g_arrSquare[0][2] = 1, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 1, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 0, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;

	case 2:
		g_arrSquare[0][0] = 1, g_arrSquare[0][1] = 0, g_arrSquare[0][2] = 0, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 1, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 1, g_arrSquare[1][3] = 0; 
		g_nLine = 0;
		g_nList = 3;
		break;

	case 3:
		g_arrSquare[0][0] = 0, g_arrSquare[0][1] = 0, g_arrSquare[0][2] = 1, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 1, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 1, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;

	case 4:
		g_arrSquare[0][0] = 0, g_arrSquare[0][1] = 1, g_arrSquare[0][2] = 0, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 1, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 1, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;

	case 5:
		g_arrSquare[0][0] = 0, g_arrSquare[0][1] = 1, g_arrSquare[0][2] = 1, g_arrSquare[0][3] = 0;
		g_arrSquare[1][0] = 0, g_arrSquare[1][1] = 1, g_arrSquare[1][2] = 1, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 4;
		break;

	case 6:
		g_arrSquare[0][0] = 1, g_arrSquare[0][1] = 1, g_arrSquare[0][2] = 1, g_arrSquare[0][3] = 1;
		g_arrSquare[1][0] = 0, g_arrSquare[1][1] = 0, g_arrSquare[1][2] = 0, g_arrSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 4;//
		break;
	}

	g_SquareID = nIndex;

	return nIndex;
}

//���Ʒ��鵽����
void CopySquareToBack()
{
	int i = 0;
	int j = 0;
	for (i; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			g_arrBackGround[i][j + 3] = g_arrSquare[i][j];
		}
	}
}




//������Ϸ
void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSquare();
	CopySquareToBack();
}



//�س�������
void OnReturn(HWND hWnd)
{
	//�򿪶�ʱ��
	SetTimer(hWnd, DEF_TIMER1, 300, NULL);
}


//���Ƽ���������
void OnLeft(HWND hWnd)  
{
	if (CanSquareLeft() == 1&& CanSquareLeft2()==1)
	{
		HDC hDc = GetDC(hWnd);

		//����
		g_nList--;
		SquareLeft();
		
		//��ʾ
		OnPaint(hDc);

		ReleaseDC(hWnd, hDc);
	}
}

//���Ƽ���������
void OnRight(HWND hWnd)
{
	if (CanSquareRight() == 1 && CanSquareRight2() == 1)
	{
		HDC hDc = GetDC(hWnd);

		//����
		g_nList++;
		SquareRight();

		//��ʾ
		OnPaint(hDc);

		ReleaseDC(hWnd, hDc);
	}
}

//��������
void SquareLeft()
{
	int i = 0;
	int j = 0;
	for (j = 1; j < 10; j++)
	{
		for (i = 0; i < 20; i++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j - 1] = 1;
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

//��������
void SquareDown()
{
	int i = 0;
	int j = 0;
	for (i = 18; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i + 1][j] = 1;
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

//��ʱ����Ӧ����
void OnTimer(HWND hWnd)
{
	//2*4����ľ��
	HDC hDc = GetDC(hWnd);  //�ں˶����˹��ͷ�


	if (CanSquareDown() == 1&& CanSquareDown2()==1)
	{
		SquareDown();
		g_nLine++;
	}
	else
	{
		//1 to 2

		Change1To2();
		//OnPaint(hDc);
		DestoryFullLinesSquare();
		if (IsGameOver() == 1)
		{
			OnPaint(hDc);

			ReleaseDC(hWnd, hDc);
			// ���ȹرռ�ʱ���������ڼ�ʱ�����������ٴε��ñ�����
			KillTimer(hWnd, DEF_TIMER1);
			// Ȼ��֪ͨ��ң�Game Over�ˣ��˳����̡�
			MessageBox(0, "Game Over", "Game Over", 0);
			ExitProcess(0);
		}
		CreateRandomSquare();
		CopySquareToBack();

	}
	
    ////��ʾ����
	//PaintSquare(hDc);
	OnPaint(hDc);

	ReleaseDC(hWnd, hDc);
}

int IsGameOver()
{
	int i = 0,
		j = 0;
	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			if (g_arrBackGround[i][j + 3] == 2)
				return 1;
		}
	}
	return 0;
}

//����ͣס
int CanSquareDown()
{
	int i = 0;
	for (i; i < 10; i++)
	{
		if (g_arrBackGround[19][i] == 1)
		{
			return 0;
		}
	}
	return 1;
}


int CanSquareLeft()
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (g_arrBackGround[i][0] == 1)
			return 0;
	}
	return 1;
}

int CanSquareLeft2()
{
	int i = 0;
	int j = 0;

	for (j = 1; j < 10; j++)
	{
		for (i = 0; i < 20; i++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				if (g_arrBackGround[i][j - 1] == 2)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void Change1To2()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j] = 2;
			}
		}
	}
}



int CanSquareDown2()
{
	int i = 0;
	int j = 0;
	for (i = 18; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				if (g_arrBackGround[i + 1][j] == 2)
				{
					return 0;  //���������ƶ�
				}
			}
		}
	}
	return 1;  //���������ƶ�
}

void SquareRight() //��������
{
	int i = 0;
	int j = 0;
	for (j = 8; j >=0; j--)
	{
		for (i = 0; i < 20; i++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				g_arrBackGround[i][j + 1] = 1;
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

int CanSquareRight()  //�ܷ�����
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (g_arrBackGround[i][9] == 1)
			return 0;
	}
	return 1;
}
int CanSquareRight2()  //�жϷ�����û�������ұߵķ���
{
	int i = 0;
	int j = 0;

	for (j = 8; j >=0; j--)
	{
		for (i = 0; i < 20; i++)
		{
			if (g_arrBackGround[i][j] == 1)
			{
				if (g_arrBackGround[i][j + 1] == 2)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//�ϼ�����
void OnChangeSquare(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);

	switch (g_SquareID)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		//��ͨ����
		if (CanSquareChange() == 1)
		{
			ChangeSquare();
		}
		else
		{
			return;
		}
		break;
	case 5:
		//������
		return;
	case 6:
		//������
		if (CanLineSquareChange1() == 1 && CanLineSquareChange2() == 1)
		{
			ChangeLineSquare();
		}
		else
		{
			return;
		}
		break;
	}

	OnPaint(hDc);
	ReleaseDC(hWnd, hDc);
}

void OnDown(HWND hWnd)  //�¼���������
{
	OnTimer(hWnd);
}


void ChangeSquare() //��ͨ����
{
	int i = 0;
	int j = 0;

	int nTemp = 2;

	char arrSquare[3][3] = { 0 };


	//�����鸴��
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arrSquare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			g_arrBackGround[g_nLine + i][g_nList + j] = arrSquare[nTemp][i];
			nTemp--;
		}
		nTemp = 2;
	}
}


int CanSquareChange()
{
	int i = 0;
	int j = 0;

	if (g_nList < 0)
	{
		g_nList = 0;
	}
	if (g_nList + 2 > 9)
	{
		g_nList = 7;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (g_arrBackGround[g_nLine+i][g_nList+j] == 2)
				return 0;
		}
	 }

	return 1;
}

void ChangeLineSquare()
{
	if (g_arrBackGround[g_nLine-1][g_nList] == 1)
	{
		g_arrBackGround[g_nLine - 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 2][g_nList] = 0;

		g_arrBackGround[g_nLine][g_nList - 1] = 1;
		g_arrBackGround[g_nLine][g_nList + 1] = 1;
		g_arrBackGround[g_nLine][g_nList + 2] = 1;
	}
	else
	{
		g_arrBackGround[g_nLine - 1][g_nList] = 1;
		g_arrBackGround[g_nLine + 1][g_nList] = 1;
		g_arrBackGround[g_nLine + 2][g_nList] = 1;

		g_arrBackGround[g_nLine][g_nList - 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 2] = 0;
	}
}

int CanLineSquareChange1()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (g_arrBackGround[g_nLine + i][g_nList + j] == 2)
				return 0;
		}
	}
	return 1;
}

int CanLineSquareChange2()
{
	if (g_arrBackGround[g_nLine + 1][g_nList] == 1 && g_nList > 7)
	{
		return 0;
	}
	else if (g_arrBackGround[g_nLine][g_nList + 1] == 1 && g_nLine < 1)
	{
		return 0;
	}
	return 1;
}

//������������
void DestoryFullLinesSquare()
{
	int i = 0;
	int j = 0;

	for (i = 19; i >= 0; i--)
	{
		int nSum = 0;
		for (j = 0; j < 10; j++)
		{
			nSum += g_arrBackGround[i][j];
		}
		if (nSum == 20)
		{
			DestoryOneLineSquare(i);
			g_Score += 1;
			i++;
		}
	}
}

//����һ������
void DestoryOneLineSquare(int LineNumber)
{
	int i = 0;
	int j = 0;
	
	for (i = LineNumber; i >= 1; i--)
	{
		for (j = 0; j < 10; j++)
		{
			g_arrBackGround[i][j] = g_arrBackGround[i - 1][j];
		}
	}
	for (j = 0; j < 10; j++)
	{
		g_arrBackGround[0][j] = 0;
	}
	
}


int GetScore()
{
	return g_Score;
}

//��Ϸ��ͣ
void GamePause(HWND hwnd)
{
	KillTimer(hwnd, DEF_TIMER1);
}

//��Ϸ����
void GameContinue(HWND hwnd)
{
	SetTimer(hwnd, DEF_TIMER1, 300, NULL);
}

int OnKeyDown(HWND hWnd, DWORD vk)
{
	switch (vk)
	{
	case VK_RETURN:
		//����
		OnReturn(hWnd);
		break;

	case VK_LEFT:
		//����
		OnLeft(hWnd);
		break;

	case VK_RIGHT:
		//����
		OnRight(hWnd);
		break;

	case VK_UP:
		//����
		OnChangeSquare(hWnd);
		break;

	case VK_SPACE:
		//��ͣ
		return OnSpace(hWnd);


	case VK_DOWN:
		//��������
		OnDown(hWnd);
		break;

	case VK_BACK:

		break;

	default:
		break;
	}
	return 0;//����
}

int OnSpace(HWND hWnd)
{
	int tag;
	GamePause(hWnd);
	int msgboxID = MessageBox(
		NULL,
		(LPCSTR)"Resource not available\nDo you want to try again?",
		(LPCSTR)"Account Details",
		MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
	);

	switch (msgboxID)
	{
	case IDTRYAGAIN:
		// TODO: add code
		DestorySquare();
		g_Score = 0;
		SetTimer(hWnd, DEF_TIMER1, 300, NULL);
		tag = 1;//�ؿ�һ��
		break;
	case IDCANCEL:
		// TODO: add code
		tag = 2;//�˳���Ϸ
		break;

	case IDCONTINUE:
		// TODO: add code
		tag = 3;//����
		GameContinue(hWnd);
		break;
	}
	return tag;
}    


void DestorySquare()
{
	int i = 0,
		j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			g_arrBackGround[i][j] = 0;
		}
	}
}