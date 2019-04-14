int main(){

    int res = 1;
    if(res==1)
    {
        res=3;
        if(1 == 2)
        {
            res = 4;
        }
        else
        {
            res = 7;
            if(1 == 1)
            {
                res = 8;
            }
        }

    }
    else
    {
        res = 2;
    }
    return res;
}
