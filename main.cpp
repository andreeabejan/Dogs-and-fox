
#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
using namespace std;

#define MAX 20
#define FUNDAL WHITE

int stanga,sus,width,height,latura, numar;
bool gata;
int caine;
int TablaDeJoc[MAX][MAX];
int cinemuta=1;
int lvulpe=0,cvulpe=0;
void asezarePieseInitial()
{
//notam vulpea cu 1 si cainii cu 2
    int linia,coloana,x,y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
//introduc vulpea initiala pe tabla
    linia=1;
    coloana=4;
    TablaDeJoc[linia][coloana]=1;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
    readimagefile("ich.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
//afisez cainii initiali pe tabla, asezati pe linia 8
    linia=8;
    for(int q=1; q<=8; q=q+2)
    {
        coloana=q;
        TablaDeJoc[linia][1]=10;
        TablaDeJoc[linia][3]=11;
        TablaDeJoc[linia][5]=12;
        TablaDeJoc[linia][7]=13;
        x1=stanga+latura*(coloana-1);
        y1=sus+latura*(linia-1);
        x2=x1+latura;
        y2=y1+latura;
        xmijloc=(x1+x2)/2;
        ymijloc=(y1+y2)/2;
        if(q==1)readimagefile("10.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
        if(q==3)readimagefile("11.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
        if(q==5)readimagefile("12.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
        if(q==7)readimagefile("13.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
    }

//bordez tabla de joc cu caini
    for(int q=0; q<=9; q++)
    {
        TablaDeJoc[0][q]=14;
        TablaDeJoc[q][0]=14;
        TablaDeJoc[9][q]=14;
        TablaDeJoc[q][9]=14;
    }
}

void stergePiesaInitiala(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    TablaDeJoc[linia][coloana]=0;
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    bar(xmijloc-21,ymijloc-21,xmijloc+21,ymijloc+21);
}

void alegerePiesa()
{
    int linia,coloana,x,y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (!(x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height))
            gata=true;
        else
        {
            linia=(y-sus)/latura+1;
            coloana=(x-stanga)/latura+1;
            if (TablaDeJoc[linia][coloana]==1&&cinemuta==1)
            {
                //click pe vulpe

                //daca o posibilitate de miscare nu este caine, o notam cu 3
                if(TablaDeJoc[linia+1][coloana+1]!=10&&TablaDeJoc[linia+1][coloana+1]!=11&&TablaDeJoc[linia+1][coloana+1]!=12&&TablaDeJoc[linia+1][coloana+1]!=13&&TablaDeJoc[linia+1][coloana+1]!=14)
                {
                    TablaDeJoc[linia+1][coloana+1]=3;
                }
                if(TablaDeJoc[linia+1][coloana-1]!=10&&TablaDeJoc[linia+1][coloana-1]!=11&&TablaDeJoc[linia+1][coloana-1]!=12&&TablaDeJoc[linia+1][coloana-1]!=13&&TablaDeJoc[linia+1][coloana-1]!=14)
                {
                    TablaDeJoc[linia+1][coloana-1]=3;

                }
                if(TablaDeJoc[linia-1][coloana+1]!=10&&TablaDeJoc[linia-1][coloana+1]!=11&&TablaDeJoc[linia-1][coloana+1]!=12&&TablaDeJoc[linia-1][coloana+1]!=13&&TablaDeJoc[linia-1][coloana+1]!=14)
                {
                    TablaDeJoc[linia-1][coloana+1]=3;

                }
                if(TablaDeJoc[linia-1][coloana-1]!=10&&TablaDeJoc[linia-1][coloana-1]!=11&&TablaDeJoc[linia-1][coloana-1]!=12&&TablaDeJoc[linia-1][coloana-1]!=13&&TablaDeJoc[linia-1][coloana-1]!=14)
                {
                    TablaDeJoc[linia-1][coloana-1]=3;

                }

                //evidentiez patratelele pe care se poate muta vulpea
                if(TablaDeJoc[linia+1][coloana+1]==3)
                {
                    //setcolor(FUNDAL);
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*((coloana+1)-1);
                    y1=sus+latura*((linia+1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                    setcolor(YELLOW);
                }
                if(TablaDeJoc[linia+1][coloana-1]==3)
                {
                    setfillstyle(SOLID_FILL,FUNDAL);
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                    x1=stanga+latura*((coloana-1)-1);
                    y1=sus+latura*((linia+1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                    setcolor(YELLOW);
                }
                if(TablaDeJoc[linia-1][coloana+1]==3)
                {
                    setcolor(FUNDAL);
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*((coloana+1)-1);
                    y1=sus+latura*((linia-1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                    setcolor(FUNDAL);
                }
                if(TablaDeJoc[linia-1][coloana-1]==3)
                {
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*((coloana-1)-1);
                    y1=sus+latura*((linia-1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                }

            }
            else if (TablaDeJoc[linia][coloana]==3)
            {
                lvulpe=linia;
                cvulpe=coloana;
                //click pe posibilitate mutare vulpe
                if(linia==8)
                {
                    int midx,x,y;
                    initwindow(800, 600);
                    setbkcolor(CYAN);
                    midx = getmaxx() / 2;

                    settextstyle(10, HORIZ_DIR, 7);
                    settextjustify(1,1);
                    outtextxy(midx, 150, "Vulpea a castigat!");
                }
                ///setcolor(RED);
                ///setfillstyle(SOLID_FILL,RED);
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1+latura;
                xmijloc=(x1+x2)/2;
                ymijloc=(y1+y2)/2;
                bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                readimagefile("ich.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                TablaDeJoc[linia][coloana]=1;
                //sterg afisarea celorlalte posibilitati de mutare
                for(int a=1; a<=8; a++)
                    for(int b=1; b<=8; b++)
                    {
                        if(TablaDeJoc[a][b]==3)
                        {
                            stergePiesaInitiala(a,b);
                            TablaDeJoc[a][b]=0;
                        }
                    }
                cinemuta=2;
                if(TablaDeJoc[lvulpe-1][cvulpe-1]==1)
                {
                    stergePiesaInitiala(linia-1,coloana-1);
                }
                if(TablaDeJoc[lvulpe-1][cvulpe+1]==1)
                {
                    stergePiesaInitiala(linia-1,coloana+1);
                }
                if(TablaDeJoc[lvulpe+1][cvulpe-1]==1)
                {
                    stergePiesaInitiala(linia+1,coloana-1);
                }
                if(TablaDeJoc[lvulpe+1][cvulpe+1]==1)
                {
                    stergePiesaInitiala(linia+1,coloana+1);
                }

            }
            else if (cinemuta==2&&(TablaDeJoc[linia][coloana]==10||TablaDeJoc[linia][coloana]==11||TablaDeJoc[linia][coloana]==12||TablaDeJoc[linia][coloana]==13))
            {
                //click pe caine
                caine=TablaDeJoc[linia][coloana];
                //daca o posibilitate de miscare nu este vulpe sau alt caine, o notam cu numele cainelui+10
                if(TablaDeJoc[linia-1][coloana+1]!=1 && TablaDeJoc[linia-1][coloana+1]!=10&&TablaDeJoc[linia-1][coloana+1]!=11&&TablaDeJoc[linia-1][coloana+1]!=12&&TablaDeJoc[linia-1][coloana+1]!=13 ) TablaDeJoc[linia-1][coloana+1]=caine+10;
                if(TablaDeJoc[linia-1][coloana-1]!=1 && TablaDeJoc[linia-1][coloana-1]!=10&&TablaDeJoc[linia-1][coloana-1]!=11&&TablaDeJoc[linia-1][coloana-1]!=12&&TablaDeJoc[linia-1][coloana-1]!=13) TablaDeJoc[linia-1][coloana-1]=caine+10;
                //evidentiez patratelele pe care se poate muta cainele, daca nu sunt ocupate de vulpe sau alt caine
                if(TablaDeJoc[linia-1][coloana+1]==caine+10)
                {
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*((coloana+1)-1);
                    y1=sus+latura*((linia-1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                    setcolor(FUNDAL);
                }
                if(TablaDeJoc[linia-1][coloana-1]==caine+10)
                {
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*((coloana-1)-1);
                    y1=sus+latura*((linia-1)-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                }

            }

            else if (TablaDeJoc[linia][coloana]==caine+10)
            {
                cinemuta=1;
                //click pe posibilitate mutare caine
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1+latura;
                xmijloc=(x1+x2)/2;
                ymijloc=(y1+y2)/2;
                //bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                if(caine==10)readimagefile("10.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                if(caine==11)readimagefile("11.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                if(caine==12)readimagefile("12.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                if(caine==13)readimagefile("13.jpg",xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                TablaDeJoc[linia][coloana]=caine;
                int l=linia,c=coloana;
                //sterg afisarea celorlalte posibilitati de mutare si cainele initial
                for(int a=1; a<=8; a++)
                    for(int b=1; b<=8; b++)
                    {
                        if(a!=l&&b!=c&&TablaDeJoc[a][b]==caine)
                        {
                            stergePiesaInitiala(a,b);
                        }
                        if(TablaDeJoc[a][b]==caine+10)
                        {
                            stergePiesaInitiala(a,b);
                        }
                    }
                //verificãm dacã dupã mutarea câinelui vulpea este înconjuratã de câini,inclusiv cei din bordarea tablei
                 for(int x=1; x<=8; x++)
                       for(int y=1; y<=8; y++)
                       {
                           if(TablaDeJoc[x][y]==1)
                           {
                               if(TablaDeJoc[x-1][y-1]==10||TablaDeJoc[x-1][y-1]==11||TablaDeJoc[x-1][y-1]==12||TablaDeJoc[x-1][y-1]==13||TablaDeJoc[x-1][y-1]==14)
                               {
                                   if(TablaDeJoc[x+1][y-1]==10||TablaDeJoc[x+1][y-1]==11||TablaDeJoc[x+1][y-1]==12||TablaDeJoc[x+1][y-1]==13||TablaDeJoc[x+1][y-1]==14)
                                   {
                                       if(TablaDeJoc[x+1][y+1]==10||TablaDeJoc[x+1][y+1]==11||TablaDeJoc[x+1][y+1]==12||TablaDeJoc[x+1][y+1]==13||TablaDeJoc[x+1][y+1]==14)
                                       {
                                           if(TablaDeJoc[x-1][y+1]==10||TablaDeJoc[x-1][y+1]==11||TablaDeJoc[x-1][y+1]==12|TablaDeJoc[x-1][y+1]==13||TablaDeJoc[x-1][y+1]==14)
                                           {
                                               int midx,x,y;
                                               initwindow(800, 600);
                                               setbkcolor(CYAN);
                                               midx = getmaxx() / 2;

                                               settextstyle(10, HORIZ_DIR, 5);
                                               settextjustify(1,1);
                                               outtextxy(midx, 150, "Cainii au castigat!");
                                           }
                                       }
                                   }
                               }

                           }
                       }
            }
        }

    }

}


void desen()
{
    int i,j;
    numar=8;
    width=400;
    height=400;
    latura=width/numar;

    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;

    setbkcolor(FUNDAL);
    clearviewport();
    setcolor(BLACK);
    for (i=1; i<=numar; i++)
        for (j=1; j<=numar; j++)
        {
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
            if(j%2!=0&&i%2==0 || j%2==0 && i%2!=0) floodfill(stanga+latura*(i-1)+1,sus+latura*(j-1)+1, BLACK);
        }

}
void menu()
{
    int midx,x,y;
    initwindow(800, 600);
    setbkcolor(CYAN);
    readimagefile("background.jpg", 0, 0 , 800, 600);
    midx = getmaxx() / 2;

    settextstyle(10, HORIZ_DIR, 7);
    settextjustify(1,1);
    outtextxy(midx, 150, "CAINII SI VULPEA");

    settextstyle(9, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(midx, 300, "START");

    settextstyle(9, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(midx, 400, " EXIT ");

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
       {
            x=mousex();
            y=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
              //getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x >240 && x<467 && y>258 && y<312) //start
            {
                cleardevice();
                desen();
                asezarePieseInitial();
                break;
            }
            if(x >240 && x<467 && y>358 && y<412)
                exit(1);
        }
    }
}
int main()
{
    menu();
    gata=false;
    do
    {
        alegerePiesa();
    }
    while (!gata);
    getch();
    closegraph();
    return 0;
}

