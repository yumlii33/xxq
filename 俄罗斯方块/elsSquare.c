#include"elsSquare.h"

//背景数组
char g_arrBackGround[20][10] = { 0 };  //char  1个字节，节约空间
char g_arrSquare[4][4] = { 0 };  //
int g_SquareID;  //
int g_nLine;
int g_nList;
int g_Score = 0;

//
void OnPaint(HDC hDc)
{
	//创建兼容性DC
	HDC hMemDC = CreateCompatibleDC(hDc);//返回值 内存的dc;参数  窗口dc;  dc:标号
	//创建一张纸
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDc, WINDOW_WIDTH, GAME_PLACE_HEIGHT);
	//关联起来
	SelectObject(hMemDC, hBitmapBack);

	PaintSquare(hMemDC);
	ShowSquare2(hMemDC);
	ShowScore(hMemDC);

	//传递      //贴的位置  //宽，高          //传递区域左上坐标      //传递方式：直接复制
	BitBlt(hDc, 0, 0, WINDOW_WIDTH, GAME_PLACE_HEIGHT, hMemDC, 0, 0, SRCCOPY);

	//释放资源
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);

	return;
}

//显示2
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

void ShowScore(HDC hMemDC) //显示分数
{
	Rectangle(hMemDC, 300, 0, WINDOW_WIDTH, GAME_PLACE_HEIGHT);
	HFONT hNewFont, hOldFont;
	
	hNewFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, 0, 1, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Consolas"));

	// 将这个FONT对象放入DC中
	hOldFont = (HFONT)SelectObject(hMemDC, hNewFont);
	
	CHAR szSourceInfo[20];
	
	wsprintf(szSourceInfo, "score %d ", GetScore());
	// 设置输出颜色
	SetTextColor(hMemDC, RGB(175, 215, 230));
	// 输出字符串。
	TextOut(hMemDC,350,50 ,szSourceInfo, lstrlen(szSourceInfo));


    // 输出完成，将原来的字体对象放回DC中
	hNewFont = SelectObject(hMemDC, hOldFont);
	DeleteObject(hNewFont);
}

//画方块
void PaintSquare(HDC hMemDC)
{
	int i = 0;
	int j = 0;

	HBRUSH hOldBrush;
	HBRUSH hNewBrush;

	//画大方块
	Rectangle(hMemDC, 0, 0, GAME_PLACE_WIDTH, GAME_PLACE_HEIGHT);  //设备上下文句柄，左上坐标，右下坐标

	////测试   指定一个方块
	//g_arrBackGround[2][4] = 1;
	//g_arrBackGround[3][3] = 1;

	hNewBrush = CreateSolidBrush(RGB(225, 225, 65));
	hOldBrush = SelectObject(hMemDC, hNewBrush);

	//遍历 画小方块
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

//创建随机块
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

//复制方块到背景
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




//创建游戏
void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSquare();
	CopySquareToBack();
}



//回车键开局
void OnReturn(HWND hWnd)
{
	//打开定时器
	SetTimer(hWnd, DEF_TIMER1, 300, NULL);
}


//左移键处理左移
void OnLeft(HWND hWnd)  
{
	if (CanSquareLeft() == 1&& CanSquareLeft2()==1)
	{
		HDC hDc = GetDC(hWnd);

		//左移
		g_nList--;
		SquareLeft();
		
		//显示
		OnPaint(hDc);

		ReleaseDC(hWnd, hDc);
	}
}

//右移键处理右移
void OnRight(HWND hWnd)
{
	if (CanSquareRight() == 1 && CanSquareRight2() == 1)
	{
		HDC hDc = GetDC(hWnd);

		//右移
		g_nList++;
		SquareRight();

		//显示
		OnPaint(hDc);

		ReleaseDC(hWnd, hDc);
	}
}

//方块左移
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

//方块下落
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

//定时器响应函数
void OnTimer(HWND hWnd)
{
	//2*4方格的句柄
	HDC hDc = GetDC(hWnd);  //内核对象，人工释放


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
			// 首先关闭计时器，避免在计时器的驱动下再次调用本函数
			KillTimer(hWnd, DEF_TIMER1);
			// 然后通知玩家，Game Over了，退出进程。
			MessageBox(0, "Game Over", "Game Over", 0);
			ExitProcess(0);
		}
		CreateRandomSquare();
		CopySquareToBack();

	}
	
    ////显示方块
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

//方块停住
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
					return 0;  //不能向下移动
				}
			}
		}
	}
	return 1;  //可以向下移动
}

void SquareRight() //方块右移
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

int CanSquareRight()  //能否右移
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (g_arrBackGround[i][9] == 1)
			return 0;
	}
	return 1;
}
int CanSquareRight2()  //判断方块有没有碰到右边的方块
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

//上键变形
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
		//普通变形
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
		//正方形
		return;
	case 6:
		//长条形
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

void OnDown(HWND hWnd)  //下键加速下落
{
	OnTimer(hWnd);
}


void ChangeSquare() //普通变形
{
	int i = 0;
	int j = 0;

	int nTemp = 2;

	char arrSquare[3][3] = { 0 };


	//背景块复制
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

//消除所有满行
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

//消除一行满行
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

//游戏暂停
void GamePause(HWND hwnd)
{
	KillTimer(hwnd, DEF_TIMER1);
}

//游戏继续
void GameContinue(HWND hwnd)
{
	SetTimer(hwnd, DEF_TIMER1, 300, NULL);
}

int OnKeyDown(HWND hWnd, DWORD vk)
{
	switch (vk)
	{
	case VK_RETURN:
		//开局
		OnReturn(hWnd);
		break;

	case VK_LEFT:
		//左移
		OnLeft(hWnd);
		break;

	case VK_RIGHT:
		//右移
		OnRight(hWnd);
		break;

	case VK_UP:
		//变形
		OnChangeSquare(hWnd);
		break;

	case VK_SPACE:
		//暂停
		return OnSpace(hWnd);


	case VK_DOWN:
		//加速下落
		OnDown(hWnd);
		break;

	case VK_BACK:

		break;

	default:
		break;
	}
	return 0;//正常
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
		tag = 1;//重开一局
		break;
	case IDCANCEL:
		// TODO: add code
		tag = 2;//退出游戏
		break;

	case IDCONTINUE:
		// TODO: add code
		tag = 3;//继续
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