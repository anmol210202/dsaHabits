class Solution {
public:
    int distMoney(int m, int c) {
if(c>m)
        return -1;
    if(c==m)
        return 0;
    int ans=0;
    m=m-c;
    if(m<7)
        return 0;
    if(m%7==3 && m/7==c-1)
    {
        return m/7-1;
    }
    if(m%7==0&&m/7==c)
        return c;
    if(m%7==0&&m/7>c)
        return c-1;
    if(m%7>0 && m/7>=c)
    {
        return c-1;
    }
    
        
    return m/7;
    }
};
