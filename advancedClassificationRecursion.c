
int checkPalindrome(int);
int digitPow(int,int,int);
int numOfDigit(int);

//global variable for is palindrome
int sum = 0;

int isPalindrome(int x)
{
    sum = 0;
    int num = 0;
    num = checkPalindrome(x);

    if(x == num)
    {
        return 1;
    }
    return 0;
}

int checkPalindrome(int x) //recursively adds digits from begging to end with a global variable sum
{
    if(x!= 0)
    {
        int holdX = x % 10;
        sum = sum * 10 + holdX;
        checkPalindrome(x/10);
    }

    return sum;
}

//global variables for is armstrong
int cnt = 0;
int cnt2 = 0;
int sum2 = 0;

int isArmstrong(int x)
{
    int digitNum = 0;
   
    digitNum = numOfDigit(x); //returns number of digits on this specific recursion call
   
    sum2 = sum2 + digitPow(x%10, digitNum + cnt, 1); //global variable sum2 will get the digit to the nth power
   
    if(x != 0)
    {
        cnt++; // since we call the recursive function with one less number we need to add one to our digit counter
        cnt2 = 0;
        isArmstrong(x/10);
    }

    

    if(x == sum2)
    {
        sum2 = 0;
        return 1;
    }

    if(cnt == 0)
    {
        sum2 = 0;
        cnt2 = 0;
    }

    if(cnt > 0)
    {
        cnt--;
    }
    return 0;

}

int numOfDigit(int x)//recursively will return number of digits in a number
{
    if (x == 0)
    {
        return cnt2;
    }
    else
    {
        cnt2++;
        numOfDigit(x/10);
    } 
    
    return cnt2;
}

int number = 0;
int digitPow(int x, int y, int z) // function will return x to the power of y , x is the base number , y is the amount of times
{                                 // we want to multiply and z is what we return
    if(y == 0)
    {
        number = z;
    }
    else
    {
        digitPow(x,y-1,z * x);
    }
    
    return number;
}