#include <iostream>
using namespace std;

class Clock
{
private:
	float Minutes;
	float Hour;
	string Meridiem;

public:
	Clock()
	{
		Minutes=0;
		Hour=0;
		Meridiem="";
	}
	Clock(float Minutes,float Hour,string Meridiem)
	{
		this->Minutes=Minutes;
		this->Hour=Hour;
		this->Meridiem=Meridiem;
	}

	void setMins(float mins)
	{
		Minutes=mins;
	}
	void setHour(float hrs)
	{
		Hour=hrs;
	}

	void setMeridiem(string meri)
	{
		Meridiem=meri;
	}
	float getMins()
	{
		return Minutes;
	}

	float getHour()
	{
		return Hour;
	}

	string getMeridiem()
	{
		return Meridiem;
	}

	void display_tim()
	{
		cout<<"Time in 12 hr format: "<<Hour<<":";
		if(getMins() < 10)
			cout<<"0";
		cout<<Minutes<<" "<<Meridiem<<endl;

	}
};

class Clock_angle:public Clock
{
private:
	int angle;
public:
	Clock_angle()
	{
		angle=0;
	}
	Clock_angle(int angle)
	{
		this-> angle = angle;
	}

	void setAngle(int angle)
	{
		this->angle=angle;
	}
	int getAngle()
	{
		return angle;
	}

	void display_tim()
	{
		cout<<"Time in 24 hr format: ";
		if (getMeridiem() == "AM") 
		{
			if (getHour() == 12)
			{
				cout<<"00";
				if (getMins() < 10)
					cout<<"0";
				cout<<getMins()<<" hrs";

			}
			else
			{
				if (getHour() < 10)
				cout<<"0";
				cout<<getHour();
				if (getMins() < 10)
					cout<<"0";
				cout<<getMins()<<" hrs";
			}
		}	
		else 
		{
			if (getHour() == 12)
			{
				cout<<"12";
				if (getMins() < 10)
					cout<<"0";
				cout<<getMins()<<" hrs";
			}
			else
			{
				cout<<getHour()+12;
				if(getMins() < 10) 
					cout<<"0";
				cout<<getMins()<<" hrs";
			}	
		}
	}

	void calculate_clock_angle(float minutes_elapsed )
	{
		setHour(getHour() + getMins()/60);
		if (getHour() * 5 >= getMins())
		{
			angle = (getHour()*30) - (getMins()*6);
		}
		else if (getHour()*5 < getMins())
		{
			angle = getMins()*6 - (getHour()*30);
		} 
		if (angle > 180)
		{
			angle = 360-angle;
		}
		cout<<"The angle between clock hour and clock minute: "<<angle<<endl;
		float totalMins;
		totalMins = getMins() + minutes_elapsed;
		if (totalMins >= 60)
		{
			setHour(getHour()+1);
			totalMins = totalMins - 60;
		}
		setMins(totalMins);
		if (getHour() * 5 >= getMins())
		{
			angle = (getHour()*30) - (getMins()*6);
		}
		else if (getHour()*5 < getMins())
		{
			angle = getMins()*6 - (getHour()*30);
		} 
		if (angle > 180)
		{
			angle = 360-angle;
		}
		cout<<"The angle between clock hour and minutes_elapsed: "<<angle<<endl;

	}


};

int main()
{
	int tim;
	float minElapsed;
	string Meridiem;
	Clock_angle obj;

	Clock *ptr;

	ptr = &obj;

	

	cout<<"Enter time in 12 hr format: ";
	cin>>tim;
	while ((tim%100 < 0 || tim%100 > 60) || (tim/100 < 1 || tim/100 >12))

	{
		cout<<"Enter time in 12 hr format: ";
		cin>>tim;
	}
	
	if (tim%100 > 59)
	{
		if (tim/100 != 12)
		{
			tim = ((tim/100) + 1) * 100; 
		}
		else if (tim / 100 == 12)
		{
			tim = 100;
		}
	}


cout<<"Enter AM/PM: ";
cin>>Meridiem; 
	

	ptr->setHour(tim/100);
	ptr->setMins(tim%100);

	ptr->setMeridiem(Meridiem);
	ptr->display_tim();

	cout<<endl;

	obj.display_tim();

	cout<<endl;

	cout<<"Enter minutes elapsed: ";
	cin>>minElapsed;

	obj.calculate_clock_angle(minElapsed);


	return 0;
}


