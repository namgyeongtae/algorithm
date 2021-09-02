// BitwiseXOR.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string ToBinary(int num)
{
    string r = "";
    while (num != 0)
    {
        r = (num % 2 == 0 ? "0" : "1") + r;
        num /= 2;
    }

    //r.reserve();
    
    return r;
}

int ToDecimal(string str)
{
    int size = str.size();
    int num = 0;
    int cnt = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        if (str[i] != '0')
        {
            int insu = 1;
            for (int j = 0; j < cnt; j++)
            {
                insu *= 2;
            }
            num += insu;
        }
        cnt += 1;
    }

    return num;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    string a = ToBinary(num1);
    string c = ToBinary(num2);

    int sizeA = a.size();
    int sizeC = c.size();

    int cha = abs(sizeA - sizeC);

    if (a.size() < c.size())
    {
        for (int i = 0; i < cha; i++)
            a = "0" + a;
    }
    else
        for (int i = 0; i < cha; i++)
            c = "0" + c;

    string b = "";

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == c[i])
            b += "0";
        else
            b += "1";
    }

    cout << ToDecimal(b) << endl;
}

