#include <jarvis.h>//Include nessary header file (Author add all nessary header in a singal header file like jarvis.h)
int x = 20, gx = 574;
char pas[6];
int pasword_check()
{        outtextxy(100,100,"check()");
  int i, flag = 0;
  for (i = 0; i < 6; i++)
  {
    if (pas[i] == main_pas[i])
    {
      flag = 1;
    }
    else
      flag = 0;
  }
  return flag;
}
void enter_pas()
{
  int i = 0;
  setcolor(11);
  settextstyle(1, 0, 1);
  outtextxy(0, 0, "Please enter your pasword :");
  for (i = 0; i < 6; i++)
  {
    pas[i] = getch();
    outtextxy(260 + (i * 10), 5, "*");
  }
}
void hert(int x, int y, int color)
{
  setcolor(color);
  arc(x + 12, y - 5, 40, 220, 5); // left
  line(x + 9, y - 1, x + 16, y + 6);
  arc(x + 20, y - 5, -40, 140, 5);
  line(x + 23, y - 1, x + 16, y + 6);
  if (color <= 9 && color >= 1)
    setfillstyle(SOLID_FILL, color);
  else
    setfillstyle(SOLID_FILL, BLACK);
  floodfill(x + 15, y, color);
}
void boy_face()
{
  setcolor(9);
  circle(x, 320, 15);
  circle(x - 6, 315, 2);
  circle(x + 7, 315, 2);
  line(x, 335, x, 390);      // pet
  line(x, 360, x + 30, 335); // left hand
  line(x, 360, x + 42, 360); // right hand
  line(x, 390, x - 20, 415); // left leg
  line(x, 390, x + 20, 415); // right leg
  if (x != 255)
  {
    ellipse(x, 325, 0, 180, 3, 2); // face
    arc(x + 35, 345, 40, 220, 10); // left
    line(x + 25, 350, x + 42, 360);
    line(x + 42, 360, x + 42, 338);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 30, 350, 9);
  }
  else
  {
    ellipse(x, 325, 180, 0, 3, 2); // face
    arc(x + 35, 345, 40, 220, 10); // left
    line(x + 25, 350, x + 42, 360);
    arc(gx - 35, 345, -40, 140, 10);
    line(gx - 25, 350, gx - 42, 360);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 35, 355, 9);
  }
}
void girl_face()
{
  setcolor(13);
  circle(gx, 320, 15);
  circle(gx - 6, 315, 2);
  circle(gx + 7, 315, 2);
  line(gx, 335, gx, 390);      // pet
  line(gx, 360, gx - 30, 335); // left hand
  line(gx, 360, gx - 42, 360); // right hand
  line(gx, 390, gx + 20, 415); // left leg
  line(gx, 390, gx - 20, 415); // right leg
  if (x != 255)
  {
    ellipse(gx, 325, 0, 180, 3, 2); // face
    arc(gx - 35, 345, -40, 140, 10);
    line(gx - 25, 350, gx - 42, 360);
    line(gx - 42, 360, gx - 42, 338);
    setfillstyle(SOLID_FILL, RED);
    floodfill(gx - 30, 350, 13);
  }
  else
    ellipse(gx, 325, 180, 0, 3, 2); // face
}
void logic(int m, int n, int j)
{
  if (n % 10 == 0)
  {
    hert(m, n + j, 4);
    hert(m, n + j - 1, 0);
    hert(m, n + j, 4);
  }
  if (n % 10 == 5)
  {
    hert(m + 22, n + j, 4);
    hert(m + 22, n + j - 1, 0);
    hert(m + 22, n + j, 4);
  }
}
void logic2(int x, int maxx, int maxy, int j, int danger)
{
  int m, n;
  for (m = x; m <= maxx;)
  {
    for (n = 0; n <= maxy;)
    {
      n += 35;
      if ((n + j) >= danger)
	continue;
      logic(m, n, j);
    }
    m += 45;
  }
}
void frame()
{
  int i, j;
  for (i = 20; i <= 450;)
  {
    hert(10, i, 1);
    i += 20;
  }
  for (j = 10; j <= 620;)
  {
    hert(j, i, 1);
    j += 20;
  }
  for (; i >= 10;)
  {
    hert(j - 20, i, 1);
    i -= 20;
  }
}
void frame_boy()
{
  int i, j, k;
  for (i = 295; i <= 410;)
  {
    hert(205, i, 4);
    hert(363, i, 4);
    i += 20;
  }
}
void writer()
{
  setcolor(11);
  settextstyle(7, 0, 5);
  outtextxy(140, 400, "Created By Devil");
}
void main()
{
  graph();
A:
  cleardevice();
  boy_face();
  girl_face();
  enter_pas();
  if (0 == pasword_check())
  {
    cleardevice();
    outtextxy(0, 0, "Pasword incorrect");
    delay(2000);
    goto A;
  }
  while (1)
  {
    cleardevice();
    if (x == 255)
      break;
    x++;
    gx--;
    boy_face();
    girl_face();
    delay(10);
  }
  boy_face();
  girl_face();
  frame();
  frame_boy();
  int i, j, k;
  while (!kbhit())
  {
    writer();
    for (j = -200; j <= 100; j++)
    {
      logic2(30, 205, 600, j, 410);  // left
      logic2(382, 582, 600, j, 410); // right
      logic2(205, 340, 600, j, 295); // top
      if (kbhit())
	break;
    }
  }
    getch();
}
