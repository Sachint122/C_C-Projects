#include <jarvis.h>
#include <time.h>
int check(int n, int num[], int target)
{
  int flag = 0;
  for (int j = 0; j < n; j++)
    if (target == num[j] && n != 9)
      flag = 1;
  if (flag == 1)
    return 1;
  else
    return 0;
}
void pattern(int dotx[], int doty[])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      setcolor(WHITE);
      circle(dotx[i], doty[j], 3);
      setfillstyle(SOLID_FILL, RED);
      floodfill(dotx[i], doty[j], WHITE);
    }
  }
}
void swap(int num[], int k, int o, int neww)
{
  num[o] = num[k];
  num[k] = neww;
}
void main()
{
  clrscr();
  time_t t;
  srand((unsigned)time(&t));
  int old, neww, o, k, num[9], tempx, tempy, temx, temy, dotx[] = {500, 560, 620}, doty[] = {150, 210, 270};
  char c;
  textcolor(1);
  cprintf(" Do you write number manually or by AI(writen by devil) \r\n");
  cprintf(" Press a for AI \r\n");
  cprintf(" Press m for manually\r\n");
  c = getch();
  graph();
  pattern(dotx, doty);
  for (k = 0; k < 9; k++)
  {
  A:
    if (c == 'a')
      num[k] = rand() % 10;
    else
    {
      printf("plese enter the number betwween (1 to 9)=\n");
      scanf("%d", &num[k]);
    }
    if (num[k] == 0)
	  goto A;
    o = k;
    old = num[k - 1];
    neww = num[k];
    switch (old)
    {
    case 1:
      if (neww == 3 && (check(k, num, 2) == 0))
	num[++k] = 2;
      else if (neww == 7 && (check(k, num, 4) == 0))
	num[++k] = 4;
      else if (neww == 9 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    case 2:
      if (neww == 8 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    case 3:
      if (neww == 1 && (check(k, num, 2) == 0))
	num[++k] = 2;
      else if (neww == 7 && (check(k, num, 5) == 0))
	num[++k] = 5;
      else if (neww == 9 && (check(k, num, 6) == 0))
	num[++k] = 6;
      swap(num, k, o, neww);
      break;
    case 4:
      if (neww == 6 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    case 6:
      if (neww == 4 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    case 7:
      if (neww == 1 && (check(k, num, 4) == 0))
	num[++k] = 4;
      else if (neww == 3 && (check(k, num, 5) == 0))
	num[++k] = 5;
      else if (neww == 9 && (check(k, num, 8) == 0))
	num[++k] = 8;
      swap(num, k, o, neww);
      break;
    case 8:
      if (neww == 2 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    case 9:
      if (neww == 3 && (check(k, num, 6) == 0))
	num[++k] = 6;
      else if (neww == 7 && (check(k, num, 8) == 0))
	num[++k] = 8;
      else if (neww == 1 && (check(k, num, 5) == 0))
	num[++k] = 5;
      swap(num, k, o, neww);
      break;
    } // ending of testing
    if (check(k, num, neww))
      goto A;
    switch (neww)
    {
    case 1:
      tempx = dotx[0];
      tempy = doty[0];
      break;
    case 2:
      tempx = dotx[1];
      tempy = doty[0];
      break;
    case 3:
      tempx = dotx[2];
      tempy = doty[0];
      break;
    case 4:
      tempx = dotx[0];
      tempy = doty[1];
      break;
    case 5:
      tempx = dotx[1];
      tempy = doty[1];
      break;
    case 6:
      tempx = dotx[2];
      tempy = doty[1];
      break;
    case 7:
      tempx = dotx[0];
      tempy = doty[2];
      break;
    case 8:
      tempx = dotx[1];
      tempy = doty[2];
      break;
    case 9:
      tempx = dotx[2];
      tempy = doty[2];
      break;
    } // ending of asigining
    if (k == 0)
    {
      temx = tempx;
      temy = tempy;
    }
    else
    {
      setcolor(11);
      line(temx, temy, tempx, tempy);
      temx = tempx;
      temy = tempy;
    }
    cout << "if you to countinue press other key-->other wise press enter\n";
    if (13 == getch() && k >= 3)
      break;
  }
  settextstyle(7, 0, 4);
  outtextxy(0, 410, "your pattern is complete good byee");
  getch();
}
