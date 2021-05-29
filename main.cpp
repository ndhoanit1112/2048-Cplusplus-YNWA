#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <iostream>
#include <windows.h>

int logow, logoh;
int logo[100][100];

void gotoxy(int x, int y) //dinh nghia ham gotoxy
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void LoadLogo(int *logow,int *logoh)
{
	FILE *f;
	
	int i,j,c,x,y,t;
	if(((f=fopen("data\\logo.txt","r"))==NULL))
	{
		printf("khong the mo file");
		return ;
	}
//	clrscr(0);
	i=-1;
	j=0;
	
	while ((c=fgetc(f))!=EOF)
	{
	
		i=i+1;
		logo[i][j]=c;
			if(c=='\n')
		{
			i=-1;
			j++;
		}				
	}
	j++;
	i=i+1;
	*logow=i;
	*logoh=j;
	fclose(f);
}

void WelcomScreen()
{
	int i,j,t;
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	system("MODE CON COLS=100 LINES=42");
//	SetFontApp(8,16);
	for(j=0;j<logoh;j++)
		{
			printf("\n");
			for(i=0;i<logow;i++)
			{
				t=logo[i][j];
				switch (t)
				{
					case 'x': case 'X':
						{
        					SetConsoleTextAttribute(hConsoleColor,14);
							printf("%c",219);
							break;
						}
					case ' ': case '.':
						{
        					SetConsoleTextAttribute(hConsoleColor,4);	
							printf("%c",219);
							break;
						}
					case 'B':
						{
        					SetConsoleTextAttribute(hConsoleColor,14);
							printf("%c",219);
							break;
						}
				}
			}
		}
	SetConsoleTextAttribute(hConsoleColor,14);	
	gotoxy(58,5); printf(" ___     ___    _  _      ___  ");
	gotoxy(58,6); printf("|__ \\   / _ \\  | || |    / _ \\ ");
	gotoxy(58,7); printf("   ) | | | | | | || |_  | (_) |");
	gotoxy(58,8); printf("  / /  | | | | |__   _|  > _ < "); 
	gotoxy(58,9); printf(" / /_  | |_| |    | |   | (_) |");
	gotoxy(58,10);printf("|____|  \\___/     |_|    \\___/ ");
	SetConsoleTextAttribute(hConsoleColor,9);
	gotoxy(53,13);printf("*               Game 2048              *");
	SetConsoleTextAttribute(hConsoleColor,10);
	gotoxy(53,14);printf("*         Programming language C++     *");
	SetConsoleTextAttribute(hConsoleColor,13);
	gotoxy(53,15);printf("*            Version 1.0 beta          *");
	SetConsoleTextAttribute(hConsoleColor,15);
	gotoxy(53,16);printf("*        Date Release: 21/2/2016       *");
	SetConsoleTextAttribute(hConsoleColor,11);
	gotoxy(53,17);printf("*  Nguyen Dinh Hoan YNWA - 15T1 - BKDN *");
	SetConsoleTextAttribute(hConsoleColor,14);
	gotoxy(53,25);printf("                MENU GAME");
	gotoxy(53,26);printf("               1. New Game");
	gotoxy(53,27);printf("               2. Continue");
	gotoxy(53,28);printf("               3. Exit");
	gotoxy(53,30);printf("            Enter your selection: ");
}                                

void khungnen(){ 
	setbkcolor(11);
	cleardevice(); 
	setfillstyle(1,8);
	bar(46,46,454,454);	
	settextstyle(3,0,4);
	settextjustify(1,1);
	setcolor(0);
	setbkcolor(11);
	outtextxy(530,110,"SCORE");
	outtextxy(530,190,"BEST");
	settextstyle(3,0,2);
	settextjustify(0,0);
	setcolor(6);
	outtextxy(480,300,"Key T: UP");
	outtextxy(480,330,"Key G: DOWN");
	outtextxy(480,360,"Key F: LEFT");
	outtextxy(480,390,"Key H: RIGHT");
	outtextxy(480,420,"Key ESC: SAVE AND EXIT");
}

void gameover(int score,int best){
	char s[10];
	setfillstyle(1,12);
	bar(100,180,400,360);
	settextstyle(3,0,4);
	settextjustify(1,1);
	setcolor(14);
	setbkcolor(12);
	itoa(score,s,10);
	outtextxy(250,220,"GAME OVER");
	if (score<=best) outtextxy(250,260,"Your Score");
	else outtextxy(250,260,"New Best !!!");
	outtextxy(250,300,s);
	settextstyle(3,0,3);
	outtextxy(250,340,"Press 'R' to try again");
}

void gamepause(int score){
	char s[10];
	setfillstyle(1,12);
	bar(100,180,400,320);
	settextstyle(3,0,4);
	settextjustify(1,1);
	setcolor(14);
	setbkcolor(12);
	itoa(score,s,10);
	outtextxy(250,220,"Saving...");
	outtextxy(250,260,"Your Score");
	outtextxy(250,300,s);
	delay(3000);
}

void readbest( int *best )//doc best score tu tep tin
{
	FILE *fs;
	
	int tmp;
	if((fs=fopen("data\\best.txt","rt"))==NULL)
	{
		printf("khong mo duoc tap tin best.txt");
		getch();
		return;
	}
	fscanf(fs,"%d",best);
	fclose(fs);	
}

void readscore( int *score )//doc score tu tep tin
{
	FILE *fs;
	
	int tmp;
	if((fs=fopen("data\\scoresave.txt","rt"))==NULL)
	{
		printf("khong mo duoc tap tin scoresave.txt");
		getch();
		return;
	}
	fscanf(fs,"%d",score);
	fclose(fs);	
}

void savebest(int best)//ghi best score ra tep tin
{
	FILE *f;
	if((f=fopen("data\\best.txt","wt"))==NULL)
	{
		printf("khong mo duoc tap tin best.txt");
		getch();
		return;
	}
	fprintf(f,"%d",best);
	fclose(f);	
}

void savescore(int score)//save score vao tep tin
{
	FILE *f;
	remove("data\\scoresave.txt");
	if((f=fopen("data\\scoresave.txt","wt"))==NULL)
	{
		printf("khong mo duoc tap tin scoresave.txt");
		getch();
		return;
	}
	fprintf(f,"%d",score);
	fclose(f);	
}

void savegame(int A[4][4])//luu game
{
	FILE *f;
	int i,j;
	if((f=fopen("data\\save.txt","wt"))==NULL)
	{
		printf("khong mo duoc tap tin save.txt");
		getch();
		return;
	}
	for(i=0;i<4;i++)
	for(j=0;j<4;j++){
	fprintf(f,"%d ",A[i][j]);
}
}

void loadgame(int A[4][4]){
	FILE *f;
	int i=0,j=0,c;
	if(((f=fopen("data\\save.txt","r"))==NULL))
	{
		printf("khong the mo file");
		return ;
	}
	for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++) fscanf(f,"%d",&A[i][j]);
	}
	fclose(f);
}

void drawscore(int score){
	char s[20];
	settextstyle(3,0,4);
	settextjustify(1,1);
	setcolor(0);
	setbkcolor(11);
	itoa(score,s,10);
	outtextxy(530,140,s);
}

void drawbest(int best){
	char s[20];
	settextstyle(3,0,4);
	settextjustify(1,1);
	setcolor(0);
	setbkcolor(11);
	itoa(best,s,10);
	outtextxy(530,230,s);
}

void drawnumber(int n,int i,int j){
	char s[6];
	int a,b;
	a=100*(j+1);
	b=100*(i+1);
	if ((n==2) || (n==4)){
		setfillstyle(1,15);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,4);
		settextjustify(1,1);
		setcolor(0);
		setbkcolor(15);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if ((n==8) || (n==16)){
		setfillstyle(1,6);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,4);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(6);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if ((n==32) || (n==64)){
		setfillstyle(1,12);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,4);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(12);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if ((n==128) || (n==256)){
		setfillstyle(1,14);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,4);
		settextjustify(1,1);
		setcolor(0);
		setbkcolor(14);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if (n==512){
		setfillstyle(1,10);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,4);
		settextjustify(1,1);
		setcolor(0);
		setbkcolor(10);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if ((n==2048) || (n==1024)){
		setfillstyle(1,2);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,3);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(2);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if (n==4096){
		setfillstyle(1,9);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,3);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(9);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if (n==8192){
		setfillstyle(1,1);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,3);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(1);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if (n>8196){
		setfillstyle(1,4);
		bar(a-45,b-45,a+45,b+45);
		settextstyle(3,0,3);
		settextjustify(1,1);
		setcolor(15);
		setbkcolor(4);
		itoa(n,s,10);
		outtextxy(a,b+10,s);
	}
	
	if (n==0){
		setfillstyle(1,7);
		bar(a-45,b-45,a+45,b+45);
	}
}

void shownumber(int A[4][4]){
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++) 
			drawnumber(A[i][j],i,j);
}


int random(int b){ 
	srand((unsigned) time(NULL));
	return rand()%b;
	}
	
int creatnumber(){
	int a=random(10);
	if (a) return 2;
	return 4;
}

void randomnumber1(int A[4][4]){
	int x1,x2,y1,y2;
	x1=random(4);
	y1=random(4);
	A[x1][y1]=creatnumber();
	do{
		x2=random(4);
		y2=random(4);
		A[x2][y2]=creatnumber();
	}while((x1==x2) && (y1==y2));
}

int check(int A[4][4]){
	int i,j;
	for(i=0;i<4;i++){
	for(j=0;j<3;j++)
		if (A[i][j]==A[i][j+1]) return 1;
	}
	for(j=0;j<4;j++){
	for(i=0;i<3;i++)
		if (A[i][j]==A[i+1][j]) return 1;
	}
	return 0;
}

int check2(int A[4][4]){
	int i,j;
	for(i=0;i<4;i++){
	for(j=0;j<4;j++)
		if (A[i][j]==0) return 1;
	}
	return 0;
}

void copynumber(int A[4][4],int B[4][4]){
	int i,j;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++) B[i][j]=A[i][j];
}

int sosanh(int A[4][4],int B[4][4]){
	int i,j;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++) 
		if (A[i][j] != B[i][j]) return 1;
	return 0;
}

void randomnumber2(int A[4][4]){
	int i,j,vitri=0,vt=0,vt1=0,vt2=0;
	int dong[16],cot[16];
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
		if (A[i][j]==0){
			dong[vitri]=i;
			cot[vitri]=j;
			vitri++;
			}
	if(vitri != 0){
	vt=random(vitri);
	vt1=dong[vt];
	vt2=cot[vt];
	A[vt1][vt2]=creatnumber();
	}
}

void hoandoi(int *x, int *y){
	int tam;
	tam=*x;
	*x=*y;
	*y=tam;
}

void dichuyenRIGHT(int A[4][4]){
	int i,j,a;
	for(i=0;i<4;i++)
	for(j=3;j>0;j--){
		a=j;
		while((A[i][j]==0) && (a>0)){
			a--;
			hoandoi(&A[i][j],&A[i][a]);
		}
	}
}

void dichuyenLEFT(int A[4][4]){
	int i,j,a;
	for(i=0;i<4;i++)
	for(j=0;j<3;j++){
		a=j;
		while((A[i][j]==0) && (a<3)){
			a++;
			hoandoi(&A[i][j],&A[i][a]);
		}
	}
}

void dichuyenUP(int A[4][4]){
	int i,j,a;
	for(j=0;j<4;j++)
	for(i=0;i<3;i++){
		a=i;
		while((A[i][j]==0) && (a<3)){
			a++;
			hoandoi(&A[i][j],&A[a][j]);
		}
	}
}

void dichuyenDOWN(int A[4][4]){
	int i,j,a;
	for(j=0;j<4;j++)
	for(i=3;i>0;i--){
		a=i;
		while((A[i][j]==0) && (a>0)){
			a--;
			hoandoi(&A[i][j],&A[a][j]);
		}
	}
}

void xulyRIGHT(int A[4][4],int *score){
	int i,j;
	for(i=0;i<4;i++)
	for(j=3;j>0;j--)
	if (A[i][j]==A[i][j-1]){
		A[i][j]+=A[i][j-1];
		A[i][j-1]=0;
		*score+=A[i][j];
	}
}

void xulyLEFT(int A[4][4],int *score){
	int i,j;
	for(i=0;i<4;i++)
	for(j=0;j<3;j++)
	if (A[i][j]==A[i][j+1]){
		A[i][j]+=A[i][j+1];
		A[i][j+1]=0;
		*score+=A[i][j];
	}
}

void xulyUP(int A[4][4],int *score){
	int i,j;
	for(j=0;j<4;j++)
	for(i=0;i<3;i++)
	if (A[i][j]==A[i+1][j]){
		A[i][j]+=A[i+1][j];
		A[i+1][j]=0;
		*score+=A[i][j];
	}
}

void xulyDOWN(int A[4][4],int *score){
	int i,j;
	for(j=0;j<4;j++)
	for(i=3;i>0;i--)
	if (A[i][j]==A[i-1][j]){
		A[i][j]+=A[i-1][j];
		A[i-1][j]=0;
		*score+=A[i][j];
	}
}

int main(){
	int A[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int C[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int B[4][4];
	int d=1,d2,c=0,best,score=0,k;
	char ch;
//	hidecursor();
	LoadLogo(&logow,&logoh);
	WelcomScreen();
	do{
		gotoxy(87,30);
		printf("    ");
		gotoxy(87,30);
		scanf("%d",&k);
	}while((k != 1) && (k != 2) && (k != 3));
//	savegame(A);
	switch (k){
		case 3: exit(1);
				break;
		case 1: randomnumber1(A);
				break;
		case 2: loadgame(A);
				readscore(&score);
	}
	initwindow(800,500);
	setwindowtitle("Hope You Enjoy :)");
	while(d){
		khungnen();
		readbest(&best);
		drawscore(score);
		drawbest(best);
		shownumber(A);
		while((c!=27) && ((d) || (d2))){
			copynumber(A,B);
            c=getch();
            switch(c){
                case 't': case 'T':
                	dichuyenUP(A);
					xulyUP(A,&score);
					dichuyenUP(A);
                    break;
                case 'g': case 'G':
                	dichuyenDOWN(A);
					xulyDOWN(A,&score);
					dichuyenDOWN(A);
                    break;
                case 'f': case 'F':
                    dichuyenLEFT(A);
					xulyLEFT(A,&score);
					dichuyenLEFT(A);
                    break;
                case 'h': case 'H':
                    dichuyenRIGHT(A);
					xulyRIGHT(A,&score);
					dichuyenRIGHT(A);
                    break;
            }
            drawscore(score);
            if (sosanh(A,B)) randomnumber2(A);
            else d2=0;
            shownumber(A);
            if ((check(A)==0) && (check2(A)==0)) d=0;
	}
	if (c==27) {
		gamepause(score);
		savescore(score);
		savegame(A);
		d=0;
	}
	else 
	{
		gameover(score,best);
		if (score>best) savebest(score);
		copynumber(C,A);
		randomnumber1(A);
		score=0;
		savegame(A);
		savescore(score);
		ch=getch();
		if ((ch=='r') || (ch='R')) d=1;
		else d=0;
	}
}
	exit(0);
	getch();
	closegraph();
}    
