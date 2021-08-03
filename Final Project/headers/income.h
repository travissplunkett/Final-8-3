#include <string>
#include <iostream>
#include <vector>
#include "expense.h"

using namespace std;

class Income{
    protected:
    string name;//Name of income
    float amount;//Amount of income
    bool perHour;
    float hourly;
    int hours;
    bool flatPayment;
    float flatAmount;
    public:
    //Default constructor
    Income();
    //Constructor
    Income(string _name, float _amount);
    float getAmount() const;
    string getName() const;
    string toString() const;
};

class Fee : public Income{
    public:
    Fee(){
        cout << "Enter name: ";
        cin >> name;
        cin.ignore();
        cout << "Enter amount: ";
        cin >> amount;
        perHour = 0;
        hourly = 0;
        hours = 0;
    }
    Fee(string _name, float _amount){
        name = _name;
        amount = _amount;
        perHour = 0;
        hourly = 0;
        hours = 0;
    }
};

class PV : public Income{
    private:
    vector<Fee *> fees;//Holds misc fees
    vector<Expense *> costs;//Holds misc expenses
    bool pv;//Determines photo or video
    float profit;
    public:
    //Constructor
    PV();
};

class Silverwood : public Income{
    private:
    int weeksPerYear;
    int daysPerWeek;
    float tipAvg;
};

