#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

// 0 -> Unmarked :: 1 -> Player 1 (RED) :: 2 -> Player 2 (BLUE)

// Player 1 -> left to right :: Player 2 -> top to bottom

vector < vector<int> > board(11, vector <int>(11, 0));

bool check_edge(int x,int y)
{
    if(x<0 || x>10 || y<0 || y>10)
        return false;
    else
        return true;
}

void DFSRe(int x, int y, bool visited[][11],int color)
{
    visited[x][y]=true;
    if(color==1 && y==10)
    {
            cout<<"Player 1 wins!"<<endl;
            exit(0);
    }
    else if(color==2 && x==10)
    {
            cout<<"Player 2 wins!"<<endl;
            exit(0);
    }
    if(check_edge(x-1,y) && board[x-1][y]==color && visited[x-1][y]==false)
    {
        DFSRe(x-1,y,visited,color);
    }
    if(check_edge(x,y-1) && board[x][y-1]==color && visited[x][y-1]==false)
    {
        DFSRe(x,y-1,visited,color);
    }
    if(check_edge(x,y+1) && board[x][y+1]==color && visited[x][y+1]==false)
    {
        DFSRe(x,y+1,visited,color);
    }
    if(check_edge(x+1,y) && board[x+1][y]==color && visited[x+1][y]==false)
    {
        DFSRe(x+1,y,visited,color);
    }
    if(check_edge(x-1,y+1) && board[x-1][y+1]==color && visited[x-1][y+1]==false)
    {
        DFSRe(x-1,y+1,visited,color);
    }
    if(check_edge(x+1,y-1) && board[x+1][y-1]==color && visited[x+1][y-1]==false)
    {
        DFSRe(x+1,y-1,visited,color);
    }
}

void DFS(int x,int y, int color)
{
    bool (*visited)[11] = new bool[11][11]();
    DFSRe(x,y,visited,color);
}

int check_win(int color)
{
    if(color==1)
    {
        for(int i=0; i<11; i++)
        {
            if(board[i][0]==1)
                DFS(i,0,color);
        }
    }
    else
    {
        for(int j=0;j<11;j++)
        {
            if(board[0][j]==2)
                DFS(0,j,color);
        }
    }
}

bool is_valid_move(int x, int y)
{
    if(x>=0 && x<11 && y>=0 && y<11 && board[x][y]==0)
        return true;
    else
        return false;
}

void move_color(int x, int y, int color)
{
    if(is_valid_move(x,y))
    {
        board[x][y]=color;
        check_win(color);
    }
    else
    {
        int t= color==1?2:1;
        cout<<"\nInvalid move by Player "<<color;
        cout<<", Player "<<t<<" wins!";
        exit(0);
    }
}

int main()
{
    int a,i,j,k=1,x,y;
    do
    {
        cout<<endl;
        for(i=0;i<11;i++)
        {
            for(a=0;a<=i;a++)
            {
                cout<<" ";
            }
            for(j=0;j<11;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\nPlayer "<<k<<"'s : \n";
        cout<<"Enter X coordinate = ";
        cin>>x;
        cout<<"Enter Y coordinate = ";
        cin>>y;
        move_color(x,y,k);
        if(k==1)
            k=2;
        else if(k==2)
            k=1;
    }while(1);
    return 0;
}
