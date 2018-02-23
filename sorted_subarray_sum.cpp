//Sorted array's sub-array sum using backtracking
#include<iostream>
using namespace std;
int top=-1;
void push(int num,int *st)
{
    st[++top]=num;
}
int pop(int *st)
{
    return(st[top--]);
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n],i,j,sum,cp=0,st[n]={0},k;
    /*for(i=0;i<n;i++)
        cout<<st[i]<<' ';*/
    cout<<"Enter array: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter sum: ";
    cin>>sum;
    for(i=0;i<n;i++)
    {
        cp+=arr[i];
        push(i,st);
        cout<<"push "<<st[top]<<endl;
        if(i==n-1&&cp<sum)
            {
                cout<<"when cp<sum last index reached popped ";
                cp-=arr[pop(st)];
                i=pop(st);
                cp-=arr[i];
                cout<<i<<endl;
                cout<<arr[i]<<endl;
                cout<<cp<<endl;
            }
        if(cp==sum)
        {
            cout<<"final sum "<<cp<<endl;
            cout<<"done\n";
            break;
        }
        else if(cp>sum)
        {
            i=pop(st);
            cp-=arr[i];
            cout<<"popped "<<i<<endl;
            i=pop(st);
            cp-=arr[i];
            cout<<i<<endl;
        }
        cout<<"sum= "<<cp<<endl<<"\nstack:";
         for(k=0;k<=top;k++)
            cout<<st[k]<<' ';
        cout<<endl;
    }
    for(i=0;i<=top;i++)
            cout<<st[i]<<' ';
}
