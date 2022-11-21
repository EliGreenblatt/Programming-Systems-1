int isPalindrome(int x)
{
    int holdX = x;
    int xBackwards = 0;
    int lastXDigit = 0;

    while(x>0)
    {
        lastXDigit = x % 10;
        xBackwards = xBackwards * 10 + lastXDigit;
        x = x / 10;
    }

    if(xBackwards != holdX)
    {
        return 0;
    }        

    return 1;
}

int isArmstrong(int x)
{
    int holdX = x;
    int holdNum = x;
    int cnt = 0;
    int sum = 0;

    while (x > 0)
    {
        x = x / 10;
        cnt++;
    }
    
    x = holdX;

    while (x > 0)
    {
        holdX = x % 10;
        int holdDigit = holdX;
        for (int i = 1; i < cnt; i++)
        {
            holdX = holdX * holdDigit;
        }
        sum = sum + holdX;
        x = x / 10;
        
    }

    if(sum == holdNum)
    {
        return 1;
    }

    return 0;
}
