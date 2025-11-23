int fun (int n) 
{
    int count=0;
    
    for(int i=n; i>0; i/=2)
    {
        for(int j=0; j<i; j++)
        {
            count+=1
        }
    }
    return count
}// Time Complexity O(n)



int a=0, b=0;
for (i=0; i<N; i++) // Time Complexity O(N)
{
    a=a+rand();
}

for(j=0;j<M;j++) // Time Complexity O(M)
{
    b=b+rand();
}
// Total Time Complexity O(N)+O(M)=O(N+M)



for(int i=n; i>0; i=i/2) // Time Complexity 0(logn)
{
    for(int j=1; j<n; j=j*2) // Time Complexity 0(logn)
    {
        for(int k=0; k<n; k=k+2) // Time Complexity 0(n)
    }
}// Total Time Complexity 0(n.logn^2)



for(int i=0; i<n; i++)
{
    i*=k;
}// Time Complexity O(logn)



int i,j,k=0;
for(i=n/2; i<=n;i++) // Time Complexity O(n)
{
    for(j=2; j<n; j=j*2) // Time Complexity O(logn)
    {
        k=k+n/2;
    }
}// Time Complexity O(n.logn)



int a=0, i=N;
while(i>0)
{
    a+=i;
    i/=2;
} // Time Complexity O(logn)



int value=0;
for(int i=0; i<n; i++) // Time Complexity O(n)
{
    for(int j=0; j<i; j++) // Time Complexity O(n)
    {
        value+=1
    }
}// Total Time Complexity O(n).O(n)=0(n^2)