void gcd_extend(long long a,long long b,long long &d,long long &x,long long &y)
{
     if(!b) {d=a;x=1;y=0;return;}
     gcd_extend(b,a%b,d,y,x);
     y-=a/b*x;
}
