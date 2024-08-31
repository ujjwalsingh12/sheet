class Solution {
public:

    unsigned long long co(long long n,int p){
                if(p==1){ return n;}
        else    if(p==0){ return 1;}
        long long r = co(n,p/2);
        if(p%2==0){ return (r*r)%1000000007; }
        else{ return (r*r*n)%1000000007; }
    }
    int countGoodNumbers(long long n) {
        cout << n << endl;
        int d = 0;
        if(n%2!=0){ d = 1;}
        //find all the distinct good digit strings and then 
        return ((unsigned long long)co(5,n/2)*(unsigned long long)co(4,n/2)*co(5,d))%1000000007;
    }
};