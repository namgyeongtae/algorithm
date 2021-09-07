// MineSweeper.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pos
{
    int _x, _y;

    Pos (int x, int y) : _x(x), _y(y) {}

    enum Dir
    {
        LEFT,
        LEFTUP,
        UP,
        RIGHTUP,
        RIGHT,
        RIGHTDOWN,
        DOWN,
        LEFTDOWN
    };

    bool sizeCheck(int h, int s)
    {
        if (_x < 0 || _x > s - 1 || _y < 0 || _y > h - 1)
            return false;
        return true;
    }

    vector<Pos> saveDir()
    {
        vector<Pos> ret;

        for (int i = 0; i < 8; i++)
        {
            switch (i)
            {   
                case (int) LEFT:
                    ret.push_back(Pos(_x - 1, _y));
                    break;
                case (int) LEFTUP:
                    ret.push_back(Pos(_x - 1, _y - 1));
                    break;
                case (int) UP:
                    ret.push_back(Pos(_x, _y - 1));
                    break;
                case (int)RIGHTUP:
                    ret.push_back(Pos(_x + 1, _y - 1));
                    break;
                case (int)RIGHT:
                    ret.push_back(Pos(_x + 1, _y));
                    break;
                case (int)RIGHTDOWN:
                    ret.push_back(Pos(_x + 1, _y + 1));
                    break;
                case (int)DOWN:
                    ret.push_back(Pos(_x, _y + 1));
                    break;
                case (int)LEFTDOWN:
                    ret.push_back(Pos(_x - 1, _y + 1));
                    break;
            }
        }

        return ret;
    }
};

struct Maze
{
    int _h, _s;
    vector<vector<char>> _mazeVec;
    Pos start = { 0, 0 };

    Maze (int h, int s) : _h(h), _s(s) {}

    void Init()
    {
        vector<char> vec;
        _mazeVec.assign(_h, vec);

        for (int i = 0; i < _h; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < _s; j++)
            {
                _mazeVec[i].push_back(s[j]);
            }
        }
    }
};

int main()
{
    int h, s;
    cin >> h >> s;
    int count = 0;

    Maze maze(h, s);

    maze.Init();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < s; j++)
        {
            count = 0;
            maze.start = Pos(j, i);
            if (maze._mazeVec[i][j] == '.')
            {
                vector<Pos> directors = maze.start.saveDir();
                for (Pos pos : directors)
                {
                    if (pos.sizeCheck(h, s))
                        if (maze._mazeVec[pos._y][pos._x] == '#')
                            count++;
                }
                maze._mazeVec[i][j] = (char) (count + 48);
            }
        }
        
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << maze._mazeVec[i][j];
        }
        cout << endl;
    }
    
}


