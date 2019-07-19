#pragma once
#ifndef DEF_ELS_SQUARE
#define DEF_ELS_SQUARE

#define WINDOW_WIDTH 500   //���ڸ߶�
#define WINDOW_HEIGHT 640  //���ڿ��
#define DEF_TIMER1 1234   //��ʱ�����
#define GAME_PLACE_WIDTH   300
#define GAME_PLACE_HEIGHT  600

#include<Windows.h>
#include<time.h>

void OnPaint(HDC hDc);
void OnCreate();
void OnTimer(HWND hWnd);  //��ʱ����Ӧ����
int OnKeyDown(HWND hWnd, DWORD vk);

void PaintSquare(HDC hMemDC);  //��ʾ����
void ShowSquare2(HDC HMemDC);  //��ʾ2
void ShowScore(HDC HMemDC);  //��ʾ����

int CreateRandomSquare();  //���������

void CopySquareToBack();//�������������


void OnReturn(HWND hWnd);  //�س���
void OnLeft(HWND hWnd);  //��������
void OnRight(HWND hWnd);  //��������
void OnChangeSquare(HWND hWnd);  //�ϼ�����
void OnDown(HWND hWnd);  //�¼���������
int OnSpace(HWND hWnd);

void SquareDown();  //��������
void SquareLeft();  //��������
void SquareRight();  //��������


int CanSquareDown();  //����ͣס
int CanSquareDown2();   //�жϷ�����û�������ײ��ķ���
int CanSquareLeft();  //�ܷ�����
int CanSquareLeft2();  //�жϷ�����û��������ߵķ���
int CanSquareRight();  //�ܷ�����
int CanSquareRight2();  //�жϷ�����û�������ұߵķ���
int CanSquareChange();
int CanLineSquareChange1();  //�жϳ����η���ɲ����Ա���
int CanLineSquareChange2();  //�жϳ����η����Ƿ��ڱ߽總��
int IsGameOver();


void Change1To2();  //1 to 2
void ChangeSquare(); //����
void ChangeLineSquare();


void DestoryFullLinesSquare();  //������������
void DestoryOneLineSquare(int LineNumber);  //����һ������
void DestorySquare();
int GetScore();


void GamePause(HWND hwnd);
void GameContinue(HWND hwnd);

#endif // !DEF_ELS_SQUARE