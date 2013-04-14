/*		 #####                              
		#     # #####    ##   #####  #    # 
		#       #    #  #  #  #    # #    # 
		#  #### #    # #    # #    # ###### 
		#     # #####  ###### #####  #    # 
		#     # #   #  #    # #      #    # 
		 #####  #    # #    # #      #    # 

	######                                          
	#     # #       ####  ##### ##### ###### #####  
	#     # #      #    #   #     #   #      #    # 
	######  #      #    #   #     #   #####  #    # 
	#       #      #    #   #     #   #      #####  
	#       #      #    #   #     #   #      #   #  
	#       ######  ####    #     #   ###### #    #  
 
GraphPlotter: 2D Graph plotting tool for *nix OS.
Copyright (C) 2011-2013 Shubham Jain, Saksham Agarwal & Tarun Gehlaut.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vga.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <vgagl.h>
using namespace std;

int const PI = 3.1416;
int MidX = 320;
int MidY = 240;
char ans, ans_s;
void outtextxy(int x, int y, char * text) {
    gl_setcontextvga(vga_getcurrentmode());
    gl_setfont(8, 8, gl_font8x8);
    gl_setwritemode(FONT_COMPRESSED + WRITEMODE_OVERWRITE);
    gl_setfontcolors(0, vga_white());
    gl_write(x, y, text);
}
void gotoxy(int x, int y) {
    x = x + 80;
    y = y + 10;
    printf("%c[%d;%df", 0x1B, y, x);
}
void readme() {
    ofstream file("ReadMe.txt");
    file << "\n\n\t\t\t\t\tWelcome to the GRAPH PLOTTER - ReadMe\n";
    file << "\n\n\t\t\t\t\tIn the Main Menu, there are 3 options : ";
    file << "\n\n\t\t\t\t\t\t1.\tPlot Graphs\n\n\t\t\t\t\t\t2.\tReadme";
    file << "\n\n\t\t\t\t\t\t3.\tExit";
    file << "\n\n\t\t\t\t\t1.\tChoosing the 'Plot Graphs' option will lead you to a";
    file << " new set of options\n\n\t\t\t\t\t\tto choose from, each of which represents a";
    file << " different function and is\n\n\t\t\t\t\t\tvery well explained within.";
    file << "\n\n\t\t\t\t\t2.\tThe 'Readme' option leads you to this page.";
    file << "\n\n\t\t\t\t\t3.\tThe 'Exit' option will lead to the termination of the program.";
    file << "\n\n\n\t\t\t\t\tThe GRAPH PLOTTER was programmed by Saksham(308/CO/10), Shubham(327/CO/10),
Tarun(336/CO/10)";
    file << "\n\n\t\t\t\t\tThank you for using it.";
    file.close();
}
void display(char text[30], int y, int x, int t) {
    vga_clear();
    system("clear");
    for (int i = 1; i < 80; i++) {
        usleep(4000);
        gotoxy(i, y);
        cout << ".";
    }
    for (int i = 0; i < 50; i++) {
        usleep(4000);
        gotoxy(x, i);
        cout << ".";
    }
    for (int j = 0, k = x + 1; j < strlen(text); k++, j++) {
        gotoxy(k, t);
        usleep(4000);
        cout << text[j];
    }
}
void show(char text[10], int y1, int x1, int y2, int x2) {
    vga_clear();
    system("clear");
    for (int i = x1 - 3; i <= x1 + 7; i++) {
        usleep(4000);
        gotoxy(i, y1);
        cout << ".";
    }
    for (int i = y1 - 3; i <= y1 + 7; i++) {
        usleep(4000);
        gotoxy(x1, i);
        cout << ".";
    }
    for (int i = x2 - 7; i < x2 + 3; i++) {
        usleep(4000);
        gotoxy(i, y2);
        cout << ".";
    }
    for (int i = y2 - 7; i <= y2 + 3; i++) {
        usleep(4000);
        gotoxy(x2, i);
        cout << ".";
    }
    for (int j = 0, k = x1 + 1; j < strlen(text); k += 2, j++) {
        gotoxy(k, y1 + 2);
        usleep(4000);
        cout << text[j];
    }
}
void trigaxes() {
    vga_clear();
    vga_setcolor(15);
    system("clear");
    vga_drawline(0, MidY, 640, MidY);
    vga_drawline(MidX, 0, MidX, 480);
    for (int i = 0; i < 320; i += (PI / 2) * 78.7)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + i, MidY + j);
    for (int i = 0; i > -320; i = i - (PI / 2) * 79.0)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + i, MidY + j);
    for (int j = -320; j < 320; j += 10)
        vga_drawpixel(MidX + j, MidY + 100);
    for (int j = -320; j < 320; j += 10)
        vga_drawpixel(MidX + j, MidY - 100);
    outtextxy(MidX + ((PI / 2) * 78.7) - 20, MidY + 5, "1.57");
    outtextxy(MidX + ((PI / 2) * 78.7) * 2 - 20, MidY + 5, "3.14");
    outtextxy(MidX + ((PI / 2) * 78.7) * 3 - 20, MidY + 5, "4.71");
    outtextxy(MidX + ((PI / 2) * 78.7) * 4 - 20, MidY + 5, "6.28");
    outtextxy(MidX - ((PI / 2) * 78.7) - 5, MidY + 5, "-1.57");
    outtextxy(MidX - ((PI / 2) * 78.7) * 2 - 5, MidY + 5, "-3.14");
    outtextxy(MidX - ((PI / 2) * 78.7) * 3 - 5, MidY + 5, "-4.71");
    outtextxy(MidX - ((PI / 2) * 78.7) * 4 - 5, MidY + 5, "-6.28");
}
void axes() {
    vga_drawline(0, MidY, 640, MidY);
    vga_drawline(MidX, 0, MidX, 480);
    for (int i = -320; i < 320; i += 10)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + i, MidY + j);
    for (int i = -240; i < 240; i += 10)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + j, MidY + i);
    for (int i = -300; i < 301; i += 50)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + i, MidY + j);
    for (int i = -200; i < 201; i += 50)
        for (int j = -2; j < 4; j++)
            vga_drawpixel(MidX + j, MidY + i);
    outtextxy(MidX + 3, MidY + 5, "0");
    outtextxy(MidX + 48, MidY + 5, "5");
    outtextxy(MidX + 95, MidY + 5, "10");
    outtextxy(MidX + 145, MidY + 5, "15");
    outtextxy(MidX + 195, MidY + 5, "20");
    outtextxy(MidX + 245, MidY + 5, "25");
    outtextxy(MidX + 295, MidY + 5, "30");
    outtextxy(MidX - 60, MidY + 5, "-5");
    outtextxy(MidX - 115, MidY + 5, "-10");
    outtextxy(MidX - 165, MidY + 5, "-15");
    outtextxy(MidX - 215, MidY + 5, "-20");
    outtextxy(MidX - 265, MidY + 5, "-25");
    outtextxy(MidX - 315, MidY + 5, "-30");
    outtextxy(MidX - 5, MidY - 55, "5");
    outtextxy(MidX - 5, MidY - 105, "10");
    outtextxy(MidX - 5, MidY - 155, "15");
    outtextxy(MidX - 5, MidY - 205, "20");
    outtextxy(MidX - 5, MidY + 45, "-5");
    outtextxy(MidX - 5, MidY + 95, "-10");
    outtextxy(MidX - 5, MidY + 145, "-15");
    outtextxy(MidX - 5, MidY + 195, "-20");
}
void loop() {
    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
    vga_getch();
    vga_setmode(TEXT);
    vga_clear();
    system("clear");
    show("", 15, 9, 25, 63);
    gotoxy(10, 20);
    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
    cin >> ans;
}
class graph {
    float a, b, c, d;
    float x;
    public: int deg,
    form,
    n;
    void init_linear() {
        display("LINEAR EQUATION", 18, 51, 17);
        gotoxy(11, 22);
        cout << "General Form : ax + by + c = 0";
        gotoxy(11, 24);
        cout << "Give a : ";
        cin >> a;
        gotoxy(11, 26);
        cout << "Give b : ";
        cin >> b;
        gotoxy(11, 28);
        cout << "Give c : ";
        cin >> c;
    }
    void init_quadratic() {
        display("QUADRATIC EQUATION", 18, 51, 17);
        gotoxy(11, 22);
        cout << "General Form : ax^2 + bx + c = 0";
        gotoxy(11, 24);
        cout << "Give a : ";
        cin >> a;
        gotoxy(11, 26);
        cout << "Give b : ";
        cin >> b;
        gotoxy(11, 28);
        cout << "Give c : ";
        cin >> c;
    }
    void init_cubic() {
        display("CUBIC EQUATION", 18, 51, 17);
        gotoxy(11, 22);
        cout << "General Form : ax^3 + bx^2 + cx + d = 0";
        gotoxy(11, 24);
        cout << "Give a : ";
        cin >> a;
        gotoxy(11, 26);
        cout << "Give b : ";
        cin >> b;
        gotoxy(11, 28);
        cout << "Give c : ";
        cin >> c;
        gotoxy(11, 30);
        cout << "Give d : ";
        cin >> d;
    }
    void plot_linear(int col) {
        axes();
        if (b == 0) {
            for (int x = -240; x < 240; x++) {
                vga_drawpixel(MidX + ((-c / a) * 10), MidY - x);
                usleep(3000);
            }
        } else {
            float x;
            for (x = -32; x < 34; x += 0.05) {
                vga_drawpixel(MidX + x * 10, MidY - ((-(a * x) - c) / b) * 10);
                usleep(3000);
            }
        }
    }
    void plot_quadratic(int col) {
        axes();
        float x;
        for (x = -15; x < 15; x = x + 0.005) {
            vga_drawpixel(MidX + x * 10, MidY - ((a * pow(x, 2)) + (b * x) + c) * 10);
            usleep(3000);
        }
    }
    void plot_cubic(int col) {
        axes();
        float x;
        for (x = -10; x < 10; x = x + 0.005) {
            vga_drawpixel(MidX + x * 10, MidY - ((a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d) * 10);
            usleep(3000);
        }
    }
    void init_para1() {
        display("PARABOLA", 18, 51, 17);
        gotoxy(11, 22);
        cout << "General Form : y^2 = 4ax";
        gotoxy(11, 24);
        cout << "Give a : ";
        cin >> a;
    }
    void init_para2() {
        display("PARABOLA", 18, 51, 17);
        gotoxy(11, 22);
        cout << "General Form : y^2 = 4ax";
        gotoxy(11, 24);
        cout << "Give a : ";
        cin >> a;
    }
    void plot_para1() {
        axes();
        float x;
        for (x = 0; x < 320.0; x += 0.1) {
            if (a > 0) {
                vga_drawpixel(MidX + x, MidY - (sqrt(4 * a * x)) * 2);
                vga_drawpixel(MidX + x, MidY + (sqrt(4 * a * x)) * 2);
                usleep(3000);
            } else {
                vga_drawpixel(MidX - x, MidY - (sqrt(-4 * a * x)) * 2);
                vga_drawpixel(MidX - x, MidY + (sqrt(-4 * a * x)) * 2);
                usleep(3000);
            }
        }
    }
    void plot_para2() {
        axes();
        float x;
        for (x = 0; x < 320.0; x += 0.1) {
            if (a > 0) {
                vga_drawpixel(MidX + (sqrt(4 * a * x)) * 2, MidY - x);
                vga_drawpixel(MidX - (sqrt(4 * a * x)) * 2, MidY - x);
                usleep(3000);
            } else {
                vga_drawpixel(MidX + (sqrt(-4 * a * x)) * 2, MidY + x);
                vga_drawpixel(MidX - (sqrt(-4 * a * x)) * 2, MidY + x);
                usleep(3000);
            }
        }
    }
};
int main() {
    vga_setmode(G640x480x256);
    int deg, choice;
    for (int i = 0; i < MidX - 120; i++) {
        vga_clear();
        system("clear");
        outtextxy(500 - i, MidY, "GRAPH PLOTTER");
        outtextxy(i, MidY - 75, "WELCOME TO");
        usleep(4000);
    }
    outtextxy(MidX + 20, MidY + 200, "Press any key to continue.");
    vga_getch();
    readme();
    vga_setmode(TEXT);
    do {
        show("MENU", 15, 22, 29, 53);
        gotoxy(30, 20);
        cout << "1. Plot graphs";
        gotoxy(30, 23);
        cout << "2. View Readme";
        gotoxy(30, 26);
        cout << "3. Exit";
        gotoxy(30, 29);
        cout << "Your choice : ";
        cin >> choice;
        if (choice == 1) {
            display("WELCOME TO GRAPH PLOTTER", 18, 51, 17);
            gotoxy(10, 22);
            cout << "1. Polynomial";
            gotoxy(10, 24);
            cout << "2. Trigonometric Function";
            gotoxy(10, 26);
            cout << "3. Parabola";
            gotoxy(10, 28);
            cout << "4. Solve multiple polynomials graphically";
            gotoxy(10, 30);
            cout << "5. Exit";
            gotoxy(10, 32);
            cout << "Your choice : ";
            cin >> choice;
            if (choice == 1) {
                graph a[10];
                a[0].n = 1;
                show("", 15, 8, 25, 72);
                gotoxy(9, 20);
                cout << "Give the degree of the polynomial you want to plot (max 3) : ";
                cin >> a[0].deg;
                if (a[0].deg == 1) {
                    a[0].init_linear();
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    vga_clear();
                    system("clear");
                    a[0].plot_linear(123);
                    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                    vga_getch();
                    vga_setmode(TEXT);
                    vga_clear();
                    system("clear");
                    show("", 15, 9, 25, 63);
                    show("", 15, 9, 25, 63);
                    gotoxy(10, 20);
                    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                    cin >> ans;
                } else if (a[0].deg == 2) {
                    a[0].init_quadratic();
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    vga_clear();
                    system("clear");
                    a[0].plot_quadratic(123);
                    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                    vga_getch();
                    vga_setmode(TEXT);
                    vga_clear();
                    system("clear");
                    show("", 15, 9, 25, 63);
                    gotoxy(10, 20);
                    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                    cin >> ans;
                } else if (a[0].deg == 3) {
                    a[0].init_cubic();
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    vga_clear();
                    system("clear");
                    a[0].plot_cubic(1);
                    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                    vga_getch();
                    vga_setmode(TEXT);
                    vga_clear();
                    system("clear");
                    show("", 15, 9, 25, 63);
                    gotoxy(10, 20);
                    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                    cin >> ans;
                }
            } else if (choice == 2) {
                int trigchoice;
                display("TRIGONOMETRIC FUNCTIONS", 18, 51, 17);
                gotoxy(11, 22);
                cout << "Choose one of the following options";
                gotoxy(11, 24);
                cout << "1. Sine";
                gotoxy(11, 26);
                cout << "2. Cosine";
                gotoxy(11, 28);
                cout << "3. Tangent";
                gotoxy(11, 30);
                cout << "Your choice : ";
                cin >> trigchoice;
                if (trigchoice == 1) {
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    trigaxes();
                    float t = -6.3;
                    while (t < 6.3) {
                        vga_drawpixel(MidX + (t * 50), MidY - (sin(t)) * 100);
                        usleep(500);
                        t += 0.005;
                    }
                    loop();
                } else if (trigchoice == 2) {
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    trigaxes();
                    float t = -6.3;
                    while (t < 6.3) {
                        vga_drawpixel(MidX + (t * 50), MidY - (cos(t)) * 100);
                        usleep(500);
                        t += 0.005;
                    }
                    loop();
                } else if (trigchoice == 3) {
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    trigaxes();
                    float t = -6.3;
                    while (t < 6.3) {
                        vga_drawpixel(MidX + (t * 50), MidY - (tan(t)) * 100);
                        usleep(500);
                        t += 0.005;
                    }
                    loop();
                }
            } else if (choice == 3) {
                graph para[10];
                para[0].n = 1;
                show("PARABOLA", 15, 8, 30, 72);
                gotoxy(9, 20);
                cout << "Choose one of the following forms of parabola : ";
                gotoxy(15, 22);
                cout << "1. y^2=4ax";
                gotoxy(15, 24);
                cout << "2. x^2=4ay";
                gotoxy(15, 26);
                cout << "Your choice : ";
                cin >> para[0].form;
                if (para[0].form == 1) {
                    para[0].init_para1();
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    vga_clear();
                    system("clear");
                    para[0].plot_para1();
                    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                    vga_getch();
                    vga_setmode(TEXT);
                    vga_clear();
                    system("clear");
                    show("", 15, 9, 25, 63);
                    gotoxy(10, 20);
                    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                    cin >> ans;
                } else if (para[0].form == 2) {
                    para[0].init_para2();
                    vga_setmode(G640x480x256);
                    vga_clear();
                    system("clear");
                    vga_clear();
                    system("clear");
                    para[0].plot_para2();
                    outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                    vga_getch();
                    vga_setmode(TEXT);
                    vga_clear();
                    system("clear");
                    show("", 15, 9, 25, 63);
                    gotoxy(10, 20);
                    cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                    cin >> ans;
                } else exit(0);
            } else if (choice == 4) {
                int num;
                graph poly[10];
                show("", 15, 15, 25, 65);
                gotoxy(17, 20);
                cout << "How many polynomials would you like to plot : ";
                cin >> num;
                for (int i = 0; i < num; i++) {
                    poly[i].n = num;
                }
                for (int i = 0; i < num; i++) {
                    show("", 15, 15, 25, 62);
                    gotoxy(17, 20);
                    cout << "Give the degree of polynomial " << i + 1 << " (max 3) : ";
                    cin >> poly[i].deg;
                    if (poly[i].deg == 1)
                        poly[i].init_linear();
                    else if (poly[i].deg == 2)
                        poly[i].init_quadratic();
                    else if (poly[i].deg == 3)
                        poly[i].init_cubic();
                }
                vga_setmode(G640x480x256);
                vga_clear();
                system("clear");
                vga_getch();
                vga_clear();
                system("clear");
                int j = 1;
                for (int i = 1; i <= num; i++) {
                    if (poly[i - 1].deg == 1) {
                        poly[i - 1].plot_linear(j);
                    } else if (poly[i - 1].deg == 2) {
                        poly[i - 1].plot_quadratic(j);
                    } else if (poly[i - 1].deg == 3) {
                        poly[i - 1].plot_cubic(j);
                    }
                    j++;
                }
                outtextxy(MidX + 100, MidY + 200, "Press any key to continue...");
                vga_getch();
                vga_setmode(TEXT);
                vga_clear();
                system("clear");
                show("", 15, 9, 25, 63);
                gotoxy(10, 20);
                cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
                cin >> ans;
            } else break;
        } else if (choice == 2) {
            vga_clear();
            system("clear");
            char string[100];
            ifstream file("ReadMe.txt");
            while (!file.eof()) {
                file.getline(string, 150);
                cout << string << endl;
            }
            file.close();
            gotoxy(10, 300);
            cout << "Do you want to continue using GRAPH PLOTTER (Y/N) : ";
            cin >> ans;
        } else break;
    } while (ans == 'y' || ans == 'Y');
    vga_clear();
    system("clear");
}