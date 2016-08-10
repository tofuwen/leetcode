#include <cstdio>
#include <vector>
using namespace std;


class Solution {
public:
    bool isExist(int i, int j, vector<vector<int> >& board){
        return i>=0 && i<board.size() && j>=0 && j<board[i].size();
    }

    void gameOfLife(vector<vector<int> >& board) {
        int x[] = {1,1,1,-1,-1,-1,0,0};
        int y[] = {1,-1,0,1,-1,0,1,-1};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int num = 0;
                for(int k=0;k<8;k++)
                    if(isExist(i+x[k], j+y[k], board) && (board[i+x[k]][j+y[k]] & 1))
                        num++;
               // printf("%d\n", num);
                if(board[i][j] & 1){
                    if(num == 2 || num == 3){
                  //      printf("before: %d\n", board[i][j]);
                        board[i][j] = board[i][j] | 2;
                   //     printf("after: %d\n", board[i][j]);
                    }
                }
                else
                    if(num == 3)
                        board[i][j] = board[i][j] | 2;
            }
        }
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[i].size();j++)
        //         printf("%d ", board[i][j]);
        //     printf("\n");
        // }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j] & 2)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
    }
};

int main()
{
    Solution mySolution;
    vector<vector<int> > board;
    for(int i=0;i<2;i++){
        vector<int> v;
        for(int j=0;j<2;j++)
            v.push_back(1);
        board.push_back(v);
    }
    board[1][0] = 0;
    mySolution.gameOfLife(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}