### this is recursive
```
lcs(s1[i:],s2[j:]){
    if(i>=s1.len || j>=s2.len){
        return 0;
    }
    else if(s1[i]==s2[j]){
        return 1+ lcs(s1[i+1:],s2[j+1:])
    }
    else{
        a = lcs(s1[i:],s2[j+1:])
        b = lcs(s1[i+1:],s2[j:])
        return max(a,b)
    }
}
main()
{
    lcs(s1,s2,i,j)
}
```
### this is memoized
the overall change in the below code is **easily visible**
we only changed where the value of that mat is already calculated or not calculated

```
lcs(s1[i:],s2[j:],DP mat){
    if(i>=s1.len || j>=s2.len){
        // remains same
        return 0;
    }
    if(mat[i][j]!=-1){ // this is for MEMO
        return mat[i][j];
    }
    else if(s1[i]==s2[j]){
        // here we added just "mat[i][j]=" in between
        return mat[i][j]=1+ lcs(s1[i+1:],s2[j+1:])
    }
    else{
        a = lcs(s1[i:],s2[j+1:])
        b = lcs(s1[i+1:],s2[j:])
        // here we added just "mat[i][j]=" in between
        return mat[i][j]=max(a,b)
    }
}
main()
{
    vector<vector<int>> mat(n+1,vector<int>(m+1,-1));
    // here we used -1 since using memoized
    // 2d is decided because two values are changing
    // the range is decided accordingly for dp

    //lcs(s1,s2,i,j,(ADD DP HERE))
    lcs(s1,s2,0,0,mat);
}
```
### this is memoized reverse
the overall change in the below code is **easily visible**
we only changed where the value of that mat is already calculated or not calculated

```
lcs(s1[:i],s2[:j],DP mat){
    if(i<0 || j<0){
        // remains same
        return 0;
    }
    if(mat[i][j]!=-1){ // this is for MEMO
        return mat[i][j];
    }
    else if(s1[i]==s2[j]){
        // here we added just "mat[i][j]=" in between
        // we are calculating the prefix part now
        return mat[i][j] = 1 + lcs(s1[:i-1],s2[:j-1])
    }
    else{
        a = lcs(s1[:i],s2[:j+1])
        b = lcs(s1[:i+1],s2[:j])
        // here we added just "mat[i][j]=" in between
        return mat[i][j]=max(a,b)
    }
}
main()
{
    vector<vector<int>> mat(n+1,vector<int>(m+1,-1));
    // here we used -1 since using memoized
    // 2d is decided because two values are changing
    // the range is decided accordingly for dp

    //lcs(s1,s2,i,j,(ADD DP HERE))
    lcs(s1,s2,s1.len,s2.len,mat);
}
```

### this is tabulation
tablulation is just opposite of recursion 
because in recursion the deepest call is solved first
*(while the shallowest call is solved later **but** shallowest
call creates the deeper calls)*
and hence in tabulation we need to solve the deepest
call first
**hence we call exactly opposite of recursion**
point is exactly difference between recursion and iteration
```
lcs(s1,s2,DP mat){
    if(){ // **MOST IMPORTANT PART**
        // remains same
        return 0;
    }
    // memoization part is not needed coz we already dealt with it
    for(int i=0;i<s1.len;i++){    // this part is added for iterative
        for(int j=0;j<s2.len;j++){
            // this part is similar in other solutions
            if(s1[i]==s2[j]){
                // return mat[i][j]=1+ lcs(s1[:i-1],s2[:j-1])
                mat[i+1][j+1] = 1 + mat[i][j];
            }
            else{
                //a = lcs(s1[:i],s2[:j-1])
                a = mat[i+1][j]
                //b = lcs(s1[:i-1],s2[:j])
                b = mat[i][j+1]
                mat[i+1][j+1] = max(a,b);
            }
        }
    }
    return mat[s1.len][s2.len];
}
main()
{
    vector<vector<int>> mat(n+1,vector<int>(m+1,0));
    //because we know that --> based on base condition

    //lcs(s1,s2,i,j,(ADD DP HERE))
    lcs(s1,s2,0,0,mat);
    //compare with memoized reverse
}
```