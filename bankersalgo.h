#include<iostream>
using namespace std;

class bankers_alg
 {
    protected:
        int p,r,seq[20],al[20][20],rn[20][20],avl[20],ed;
        int com_pr();
    public:
        bankers_alg()
            {
               p=0;
               r=0;
            }
    void getdata();
        ~bankers_alg()
            {
              cout<<"\n\nProgram has ended\n"<<endl;
            }
    
 };

class safes:public bankers_alg
 {
    public:
        void safe_seq()
         {
            int temp,flag=0;
            ed=0;
          for(int i=0;i<p;i++)
           {
              temp=com_pr();
              if(temp!=-1)
               {
                 for(int y=0;y<r;y++)
                 avl[y]+=al[temp][y];
                 seq[ed++]=temp;
               }
             else
              {
                cout<<"\nThe system is in unsafe state ";
                flag=1;
                break;
              }
           }
          if(flag!=1)
           {
            cout<<"\nThe safe sequence is : ";
            for(int i=0;i<ed;i++)
            cout<<"p["<<seq[i]<<"]  ";
           }
         }   
 };

void bankers_alg::getdata()
{
    cout<<"\nEnter the number of processes : ";
    cin>>p;
    cout<<"Enter the number of resources : ";
    cin>>r;
    cout<<"\n\nEnter the number of instances available of each resource : ";
    for(int i=0;i<r;i++)
        cin>>avl[i];
		cout<<"\n"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"Enter the no. of instances of resources allocated to process p["<<i<<"] : ";
        for(int y=0;y<r;y++)
            cin>>al[i][y];
    }
	cout<<"\n"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"Enter the max no. of instances of resources process p["<<i<<"] needs : ";
        for(int y=0;y<r;y++)
            cin>>rn[i][y];
    }
}

int bankers_alg::com_pr()
{
    int flag=0,fl=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<ed;j++)
            if(i==seq[j])
            {
                fl=1;
                break;
            }
           
        if(fl!=1)
        {
            for(int j=0;j<r;j++)
            {
                if(avl[j]-rn[i][j]+al[i][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return i;
            flag=0;
        }
        fl=0;
    }
    return -1;
}
