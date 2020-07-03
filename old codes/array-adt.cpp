#include<iostream>
#include<string>
using namespace std;
class Array
{
private:
    int *arr;
    int size;
    int count;
public:
    Array(int size=0)
    {
        this->size=size;
        arr=new int[size]();
        count=0;
    } 
    void insert_value(int value)
    {
        if(count<size&&value!=0)
     arr[count++]=value;
     else
     {
         throw "ERROR CODE : 101";
     }
    }
    void deletion()
    {
        if(count>=0)
        arr[count--]=0;
        else
        {
            throw "ERROR CODE : 102";
        }
    }
    void insert(int value,int index)
    {
        if(count<size && value!=0)
        {
            for(int i=count;i>index;i--)
            arr[i]=arr[i-1];
            arr[index]=value;
            count++;
        }
        else
        {
            throw "ERROR CODE : 103";
        }
    }
    void deletion(int index)
    {
        if(index>=0&&index<=count)
        {
            for(int i=index;i<count;i++)
            arr[i]=arr[i+1];
        }
        else
        {
            throw "ERROR CODE : 104";
        }
        
    }
    ~Array()
    {
        for(int i=size-1;i>=0;i--)
        delete &arr[i];
    }
    void display()
    {
        cout<<"displaying"<<endl;
        for(int i=0;i<size;i++)
        cout<<&arr[i]<<" --> "<<arr[i]<<endl;
        cout<<endl;
    }
};
int main()
{
    Array a(10);
    try{
    a.insert_value(35);
    a.insert_value(20);
    a.insert_value(98);
    a.insert_value(70);
    a.insert_value(16);
    a.insert_value(55);
    a.display();
    a.insert(15,0);
    a.display();
    a.deletion(0);
    a.display();
    }
    catch(...)
    {
        cout<<"error"<<endl;
        system("pause");
    }
    system("pause");

}