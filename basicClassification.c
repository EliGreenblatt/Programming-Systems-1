
int isPrime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
        
    }
    
    return 1;
}

int isStrong(int x)
{
    int digitNum;
    int sum = 0;
    int holdX = x;
    while(x > 0)
    {
        digitNum = x % 10;
        int y = 1;
        
        for (int i = 1; i <= digitNum; i++)
        {
            y = i * y;    
        }

        sum = sum + y;
        x = x/10;
    }
    
    if(holdX == sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
