using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 0;
    
    if (w == 1 || h == 1)
        return 0;
    
    int g = gcd(w, h);
    
    int x = w / g;
    int y = h / g;
    
    // 하나의 패턴 당 잘려지는 사각형의 개수
    int square = (x + y - 1);
    
    answer += ((long long)w * (long long)h) - (g * square);    
    
   
    return answer;
}