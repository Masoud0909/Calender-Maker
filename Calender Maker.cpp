/*write a program that outputs a calendar for a given month in a given year, given the day of the week on which the 1st of the month fell. The user enters these 3 pieces of information in numeric format (months are: 1=Jan, 2=Feb, etc …, and days are 1=Sun, 2=Mon, etc …). The program outputs that month’s calendar, followed by a sentence indicating on which day the month ended.

For example, if the user enters 2 (for the month), 2012, and 4 (for the first of the month), your program outputs something like:


Here is the calendar for February of 2012:
         
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
  ---------------------------------
                  1    2    3    4
   5    6    7    8    9   10   11
  12   13   14   15   16   17   18  
  19   20   21   22   23   24   25
  26   27   28   29      
   
 The month ends on a Wednesday.
              .
As you can see, for the month of February, your program has to decide if the year is leap (29 days) or not.  Important: Your program MUST be simple. Points will be deducted for unnecessary complications! Other than i/o statements, all you need to use is some conditional  statements (if  & switch), and one loop. 
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int month, year, startDay;

    cout << "Enter month (1=Jan, 2=Feb, etc): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter start day of the month (1=Sun, 2=Mon, etc): ";
    cin >> startDay;

    int daysInMonth = 31; ///This is for regular months of the year

    if (month == 2) { /// THIS ONE i ADD for February because feb is 28 days
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30; /// I implement this here becausasse April, June, September and November have 30 days
    }

    cout << "\nSun Mon Tue Wed Thu Fri Sat\n";
    cout << "----------------------------------" << endl;

    ///This here Adjusts spacing for the first day of the week
    for (int i = 1; i < startDay; i++) {
        cout << "    ";
    }

    /// amnd this one prints all the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(3) << day << " ";


        if ((day + startDay - 1) % 7 == 0) { ///this moves to to next line every week
            cout << "\n";
        }
    }

    cout << "\nThe month ends on a "; ///to say whether the month's day ends in thursday,for example, or any other days of the week

    switch ((daysInMonth + startDay - 1) % 7) {
    case 1: cout << "Sunday.\n"; break;
    case 2: cout << "Monday.\n"; break;
    case 3: cout << "Tuesday.\n"; break;
    case 4: cout << "Wednesday.\n"; break;
    case 5: cout << "Thursday.\n"; break;
    case 6: cout << "Friday.\n"; break;
    case 0: cout << "Saturday.\n"; break;
    }

    return 0;
}
