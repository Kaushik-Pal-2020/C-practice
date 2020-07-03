#include<iostream>
#include<conio.h>
using namespace std;
class hotel
{
	private:
		char name[40],surname[20];
		float tariff,calc,tot;
		int days;
		public:
			 void setcustomer();
			 void displaycustomer();
			 void displaytotalamount();
};
		void hotel::setcustomer()
		{
			cout<<"**************WELCOME TO SHITTY HOTEL**************\n";
			cout<<"name of the customer\n";
			cin>>name>>surname;
			cout<<"room rate\n";
			cin>>tariff;
			cout<<"the nnumber of days the room was booked\n";
			cin>>days;
		}
		void hotel::displaycustomer()
		{
			setcustomer();
			cout<<"\nname of the customer- "<<name<<" "<<surname;
			cout<<"\nroom rate- "<<" "<<tariff;
			cout<<"\nthe nnumber of days the room was booked- "<<" "<<days;
		}
		void hotel::displaytotalamount()
		{
		
			tot=days*tariff;
			calc=(tot/10)+tot;
			cout<<"\ntotal amount to play is \n"<<calc<<"\n**************THANK YOU****************************";
			
		}
	 main()
		{
			hotel S;
			S.displaycustomer();
			S.displaytotalamount();
		}