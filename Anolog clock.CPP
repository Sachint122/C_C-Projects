/*** documaintion  part
   this program written by devil
   main work of this programm show the actual time in anlog form***/
#include <jarvis.h>   //headerfile
#include <fstream.h>
/*** global variable***/
char data[25];
int hour, min, sec,x = 320, y = 196;
/*** fill time data in variable***/
void fill_time_in_var()
{
  hour = (data[0] - 48) * 10 + (data[1] - 48);
  min = (data[3] - 48) * 10 + (data[4] - 48);
  sec = (data[6] - 48) * 10 + (data[7] - 48);
}
/*** file to data array***/
void file_data()
{
  char s;
  int i = 0;
  ifstream inputFile("student.txt");
  while (inputFile.get(s))
  {
    data[i] = s;
    i++;
  }
}
/*** rotation line ***/
void rotate(double x1, double y1, double degree)
{
  setcolor(RED);
  double radian = degree * 0.01745;
  int  x2 = (int)(x + ((x1 - x) * cos(radian) - (y1 - y) * sin(radian)));
  int y2 = (int)(y + ((x1 - x) * sin(radian) + (y1 - y) * cos(radian)));
  line(x, y, x2, y2);
  circle(x2, y2, 1);
  double radian1 = (degree-6) * 0.01745;
  int  x22 = (int)(x + ((x1 - x) * cos(radian1) - (y1 - y) * sin(radian1)));
  int y22 = (int)(y + ((x1 - x) * sin(radian1) + (y1 - y) * cos(radian1)));
  setcolor(0);
  line(x,y,x22,y22);
  circle(x22,y22,1);
  setcolor(1);
  circle(x,y,3);
}
/*** print clock number on postion***/
void number(double x1, double y1)
{
  setcolor(1);
  for (int degree = 30; degree <= 390;)
  {
    double radian = degree * 0.01745;
    int  x2 = (int)(x + ((x1 - x) * cos(radian) - (y1 - y) * sin(radian)));
    int y2 = (int)(y + ((x1 - x) * sin(radian) + (y1 - y) * cos(radian)));
    switch (degree)
    {
     case 30:
      settextstyle(1, 0, 1);
      outtextxy(x2 - 5, y2 - 10, "1");
      break;
     case 60:
      outtextxy(x2 - 3, y2 - 15, "2");
      break;
    case 90:
      outtextxy(x2, y2 - 11, "3");
      break;
    case 120:
      outtextxy(x2 - 5, y2 - 10, "4");
      break;
    case 150:
      outtextxy(x2 - 4, y2 - 10, "5");
      break;
    case 180:
      outtextxy(x2 - 4, y2 - 10, "6");
      break;
    case 210:
      outtextxy(x2 - 10, y2 - 5, "7");
      break;
    case 240:
      outtextxy(x2 - 5, y2 - 14, "8");
      break;
    case 270:
      outtextxy(x2 - 4, y2 - 13, "9");
      break;
    case 300:
      outtextxy(x2 - 10, y2 - 13, "10");
      break;
    case 330:
      outtextxy(x2 - 7, y2 - 13, "11");
      break;
    case 360:
      outtextxy(x2 - 10, y2 - 15, "12");
      break;
    }
    degree = degree + 30;
  }
}
/*** main function of clock***/
void main_clock()
{
  setcolor(1);
  circle(x, y, 180);
  circle(x, y, 160);
  setfillstyle(SOLID_FILL, 5);
  floodfill(320, 360, 1);
  number(321, 56);
}
/*** writer information***/
void writer()
{  setcolor(11);
  settextstyle(7,0,5);
  outtextxy(160,410,"Created By Devil");
}
/*** starting main function of program***/
void main()
{
  graph();
  ofstream fout("student.txt");
  fout<<__TIME__;
  fout.close();
  file_data();
  fill_time_in_var();
  main_clock();
  writer();
  int y1 = 56, s_y = 86, h_y = 116;
  while (!kbhit())
  {
    if (hour == 24)
      hour = 0;
    else if (min == 60)
    {
      hour++;
      min = 0;
    }
    else if (sec == 59)
    {
      min++;
      sec = 0;
    }
    else
    sec++;
    rotate(x,h_y,hour*30);//rotate hours led
    rotate(x, s_y, sec * 6); // rotate second led
    rotate(x,y1,min*6); //rotate minute led
    gotoxy(38,25);
    cout<<hour<<":"<<min<<":"<<sec<<endl;
    delay(1000);
  }
    getch();
}
