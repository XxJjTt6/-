#include<stdio.h>
#include<time.h>
#include<stdlib.h>  //�����������ͷ�ļ��н�һЩ����game.c��test.cҪ������ͷ�ļ�д���⣬������game.c��test.c��ֻҪ����game.h�����ˣ���Ϊgame.h�ѽ���game.c��test.cҪ������ͷ�ļ�������ȥ��


#define ROW 3   //define ���治��Ҫ�ӷֺ�
#define COL 3   //��������Ŀ���Ƿ����Ժ�ı����̵Ĵ�С
void initborad(char borad[ROW][COL], int row, int col); //��Ϊchar borad[][]�����飬�������������borad��д������Ϊchar borad [row][col]����Ϊ[]����Ҫ��һ����������
void Displayborad(char borad[ROW][COL], int row, int col);
void player(char borad[ROW][COL], int row, int col);
void computerplay(char borad[ROW][COL], int row, int col);
char check(char borad[ROW][COL], int row, int col);
char full(char borad[ROW][COL], int row, int col);