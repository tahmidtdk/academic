#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define sf scanf
#define pf printf

#define debug(x) cerr << #x << " : " << x << endl


using namespace std;

//global variable declear

int board_size=0;

#define MAX 2000
int grid[MAX][MAX];





HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);  //global variable
void gotoxy(int x,int y)
{
	COORD Coord;
	Coord.X=x;
	Coord.Y=y;

	SetConsoleCursorPosition(con,Coord);
}

void textattr(int color)
{
	SetConsoleTextAttribute(con, color);
}


char menu_dy(string *menu_list, int MaxNo_Menu){
    //


    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );

    int i,
      xpos = 10,
      ypos[MaxNo_Menu];
      int j=3;
      for(int i=0; i<MaxNo_Menu; i++){
        ypos[i] = j;
        j+=3;
      }
      for (i=0; i< MaxNo_Menu; ++i){
		gotoxy(xpos, ypos[i] );
		textattr(14);
//		printf("%s",menu_list[i] );
		cout<<menu_list[i];
	}

	i=0;
	while(1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(12 );
//		printf("%s",menu_list[i] );

		cout<<menu_list[i];

		/* note : 72 -> UP button
			75 -> RIGHT button
            77 -> LEFT button
            80 -> DOWN button
		*/

	switch( _getch() )
    {
		case 72: if(i>0) {
       		gotoxy(xpos,ypos[i] );
            textattr(14);
//            printf("%s", menu_list[i] );
            cout<<menu_list[i];
            --i;
            }
            break;

		case 80: if(i< MaxNo_Menu-1 )
			{
       			gotoxy(xpos,ypos[i] );
                textattr(14);
//                printf("%s", menu_list[i] );
                cout<<menu_list[i];
                ++i;
                }
        break;

		case 13:
            for(int k=0; k<MaxNo_Menu; k++){
                if(i==k){
                    int chr=0;
                    gotoxy (10,1);
                    return 'A'+i;

                }
            }
            break;
	}
	}

}
