#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "expense.h"
#include "income.h"

using namespace std;

//Allows user to create expenses
void setExpenses(vector<Expense*> & _expenses);

int main(){
    cout << "______________________________________________________________________________" << endl;
    cout << "Throughout this program, when prompted with a yes/no choice, " << endl;
    cout << "enter either a non-negative integer for \"yes\" or a negtive integer for \"no.\" " << endl;
    cout << "______________________________________________________________________________" << endl;
    //Vector stores all expenses
    //It gets initialized by setExpenses()
    vector<Expense*> expenses;
    setExpenses(expenses);

    return 0;
}

///FUNCTION DEFINITIONS///

//Allows user to create expenses
void setExpenses(vector<Expense*> & _expenses){
    ofstream expensesFile(".\\output_files\\expenses.txt");
    int loop_index = 0;//Counts times loop repeats
                   // and functions as index for
                   // vector _expenses
    cout << "Let's gather expense data, " << endl;
    int choice = 0;//User uses as yes/no
    while(choice>-1){
        cout << "Would you like to add an expense? yes/no: ";
        //User chooses
        cin >> choice;
        //Break if no is chosen
        if(choice<0){
            cout << "No chosen. " << endl << "Expenses finished." << endl;
            break;
        } else {
            cin.ignore();
            cout << "Yes chosen. " << endl << "Adding expense." << endl;
            //Prompt for preset expenses
            cout << "____________________________________" << endl;
            cout << "Expense types: " << endl;
            cout << "1: College Expenses" << endl;
            cout << "2: Recreation Expense" << endl;
            cout << "3: Miscellaneous expense " << endl;
            cout << endl;
            cout << "Enter the number of the expense you would like to add, " << endl;
            cout << "or enter a negative number to exit without adding: ";
            cin >> choice;
            if(choice<0){
                //Break expenses loop
                cout << choice << " chosen. " << endl;
                cout << "Exiting expenses. " << endl;
                break;
            } else {
                switch (choice) {
                    case 1:{
                        expensesFile << "College Expenses " << endl;
                        expensesFile << "______________________________________________" << endl;
                        College_Expenses* col = new College_Expenses;
                        _expenses.push_back(col);
                        break;
                    }
                    case 2:{
                        expensesFile << "Recreation Expense " << endl;
                        expensesFile << "______________________________________________" << endl;
                        Recreation_Expense* rec = new Recreation_Expense;
                        _expenses.push_back(rec);
                        break;
                    }
                    case 3:{
                        expensesFile << "Miscellaneous Expense " << endl;
                        expensesFile << "______________________________________________" << endl;
                        Expense* ex = new Expense;
                        _expenses.push_back(ex);
                        break;
                    }
                    default:{
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
            }
        }
        expensesFile << _expenses[loop_index]->toString() << endl;
        loop_index++;
    }
}

//Allows user to create expenses
void setIncomes(vector<Income*> & _incomes){
    ofstream incomesFile(".\\output_files\\incomes.txt");
    int loop_index = 0;//Counts times loop repeats
                   // and functions as index for
                   // vector _expenses
    cout << "Let's gather income data, " << endl;
    int choice = 0;//User uses as yes/no
    while(choice>-1){
        cout << "Would you like to add an income? yes/no: ";
        //User chooses
        cin >> choice;
        //Break if no is chosen
        if(choice<0){
            cout << "No chosen. " << endl << "Incomes finished." << endl;
            break;
        } else {
            cin.ignore();
            cout << "Yes chosen. " << endl << "Adding income." << endl;
            //Prompt for preset expenses
            cout << "____________________________________" << endl;
            cout << "Income types: " << endl;
            cout << "1: Photo/Video " << endl;
            cout << "2: Silverwood " << endl;
            cout << "3: Misc " << endl;
            cout << endl;
            cout << "Enter the number of the income you would like to add, " << endl;
            cout << "or enter a negative number to exit without adding: ";
            cin >> choice;
            if(choice<0){
                //Break expenses loop
                cout << choice << " chosen. " << endl;
                cout << "Exiting incomes. " << endl;
                break;
            } else {
                cout << choice << "chosen. " << endl;
                cout << "Adding income. " << endl;
                switch (choice) {
                    case 1:{
                        incomesFile << "Photo/Video " << endl;
                        incomesFile << "______________________________________________" << endl;
                        PV* pv = new PV();
                        _incomes.push_back(pv);
                        break;
                    }
                    case 2:{
                        incomesFile << "Silverwood " << endl;
                        incomesFile << "______________________________________________" << endl;
                        Silverwood* s = new Silverwood();
                        _incomes.push_back(s);
                        break;
                    }
                    case 3:{
                        incomesFile << "Miscellaneous " << endl;
                        incomesFile << "______________________________________________" << endl;
                        Income* m = new Income();
                        _incomes.push_back(m);
                    }
                    default:{
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
            }
        }
        incomesFile << _incomes[loop_index]->toString() << endl;
        loop_index++;
    }
}

