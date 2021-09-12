/*
StarPattern1:
*
**
***
****
*****

StarPattern2:
*****
*****
*****
*****
*****

StarPattern3:
*****
****
***
**
*

StarPattern4:
1
12
123
1234
12345

StarPattern5:
*
**
***
****
*****
****
***
**
*

StarPattern6:
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *  

Pattern7:
        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4 
5 4 3 2 1 2 3 4 5 
*/

#include <iostream>
using namespace std;

void StarPattern1(int n)
{
    for(int rows=1;rows<=n;rows++)
    {
        for(int cols=1; cols<=rows;cols++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void StarPattern2(int n)
{
    for(int rows=1;rows<=n;rows++)
    {
        for(int cols=1; cols<=n;cols++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void StarPattern3(int n)
{
    for(int rows=1;rows<=n;rows++)
    {
        for(int cols=1; cols<=(n-rows+1);cols++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void StarPattern4(int n)
{
    for(int rows=1;rows<=n;rows++)
    {
        int iCount = 0;
        for(int cols=1;cols<=rows; cols++)
        {
            cout << ++iCount <<" ";
        }
        cout << endl;
    }
}

void StarPattern5(int n)
{
    int nCols = 0;
    int negV = 0;
    cout << endl;
    for(int rows=1;rows<=(2 * n)-1;rows++)
    {
        if ((rows > n) && (n>0)) {
            negV++;
            nCols = n-negV;
        }
        else
            nCols = rows;
        for(int cols=1;cols<=nCols;cols++)
        {
            cout << "* " ;
        }
        cout << endl;
    }
}

void StarPattern6(int n)
{
    int nCols = 0;
    int newSpace = 1;
    int starStart = 0;
    for(int rows=1;rows<=(2 * n)-1;rows++)
    {
        if ((rows > n) && (starStart > 1)) {
            //Lower Triangle
            newSpace++;
            nCols = newSpace;
            starStart = rows - (2*(newSpace-1));
        }
        else {
            //Upper Triangle
            nCols = (n-rows+1);
            starStart = rows;
        }
        for(int cols=1;cols<=n;cols++)
        {
            if(cols == nCols) {
                int temp =0;
                while(temp != starStart)
                {
                    cout << "* ";
                    temp++;
                }
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}

void Pattern7(int n)
{
    int nCol = 0;
    for (int row=1;row<=n;row++)
    {
        int count=0;
        nCol = (((2*n)-1)-row)+1;
        int tempRow = row;
        for(int col=1;col<=((2*n)-1);col++)
        {
            int x = 1;
            if(col == nCol) {
                while(tempRow > 0)
                {
                    cout << tempRow << " ";
                    tempRow -= x;
                }
                if(row > 1)
                    cout << row << " ";
            }
            else
                cout << "_";
        }
        cout << endl;
    }
}

int main()
{
    int nLines = 0;
    cout << "How many Rows should pattern be printed" << endl;
    cin >> nLines;
    Pattern7(nLines);
}