#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<string> board) {
    int answer = -1;
    int o = 0, x = 0, xwin = 0, owin = 0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            if(board[i][j] == 'O')
            {
                ++o;
            }
            else if (board[i][j] == 'X')
            {
                ++x;
            }
        }
    }
    if(!(x+1 == o || x == o))
    {
        return 0;
    }
    for(int i=0; i<3; ++i)
    {
        if('.' != board[i][0] && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if(board[i][0] == 'X')
            {
                ++xwin;
            }
            else
            {
                ++owin;
            }
        }
        if('.' != board[0][i] && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if(board[0][i] == 'X')
            {
                ++xwin;
            }
            else
            {
                ++owin;
            }
        }
    }
        
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        if (board[0][0] == 'X')
        {
            ++xwin;
        }
        else
        {
            ++owin;
        }
            
    }
    if (board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) 
    {
        if (board[2][0] == 'X')
        {
            ++xwin;
        }
        else
        {
            ++owin;
        }
    }   
    
    if(xwin > 0 && owin > 0 )
    {
        return 0;
    }
    
    if(abs(x - o) > 1)
    {
        return 0;
    }
    if(owin > 0 && o != x + 1)
    {
        return 0;
    }
    if(xwin > 0 && o != x)
    {
        return 0;
    }
    return 1;
}