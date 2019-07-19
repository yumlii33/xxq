#pragma once
#ifndef DEF_ELS_SQUARE
#define DEF_ELS_SQUARE

#define WINDOW_WIDTH 500   //窗口高度
#define WINDOW_HEIGHT 640  //窗口宽度
#define DEF_TIMER1 1234   //计时器标号
#define GAME_PLACE_WIDTH   300
#define GAME_PLACE_HEIGHT  600

#include<Windows.h>
#include<time.h>

void OnPaint(HDC hDc);
void OnCreate();
void OnTimer(HWND hWnd);  //定时器响应函数
int OnKeyDown(HWND hWnd, DWORD vk);

void PaintSquare(HDC hMemDC);  //显示方块
void ShowSquare2(HDC HMemDC);  //显示2
void ShowScore(HDC HMemDC);  //显示分数

int CreateRandomSquare();  //创建随机块

void CopySquareToBack();//随机块贴进背景


void OnReturn(HWND hWnd);  //回车键
void OnLeft(HWND hWnd);  //处理左移
void OnRight(HWND hWnd);  //处理右移
void OnChangeSquare(HWND hWnd);  //上键变形
void OnDown(HWND hWnd);  //下键加速下落
int OnSpace(HWND hWnd);

void SquareDown();  //方块下落
void SquareLeft();  //方块左移
void SquareRight();  //方块右移


int CanSquareDown();  //方块停住
int CanSquareDown2();   //判断方块有没有碰到底部的方块
int CanSquareLeft();  //能否左移
int CanSquareLeft2();  //判断方块有没有碰到左边的方块
int CanSquareRight();  //能否右移
int CanSquareRight2();  //判断方块有没有碰到右边的方块
int CanSquareChange();
int CanLineSquareChange1();  //判断长条形方块可不可以变形
int CanLineSquareChange2();  //判断长条形方块是否在边界附近
int IsGameOver();


void Change1To2();  //1 to 2
void ChangeSquare(); //变形
void ChangeLineSquare();


void DestoryFullLinesSquare();  //消除所有满行
void DestoryOneLineSquare(int LineNumber);  //消除一行满行
void DestorySquare();
int GetScore();


void GamePause(HWND hwnd);
void GameContinue(HWND hwnd);

#endif // !DEF_ELS_SQUARE