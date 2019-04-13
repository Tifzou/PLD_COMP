int sum()
{
    int a;
    a=1+2*3+4;
    return a;
}

int main()
{
    int a,b,c;
    a=5;
    b=7;
    c=5+(b-a)*2;
    a=sum();
    if(a==11)
    {
        a=11;
    }
    else
    {
        a=22;
    }
    return a;
}