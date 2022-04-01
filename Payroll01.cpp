//***********************************************************************************************************
//Programming Assignment 05
//Programmer: Dustin Sherer
//Completed: 03/05/2022
//Status: Completed
//
//In this assignment you must create and use a struct to hold the general employee information for one employee.
//  1. The employee master information consists of the following data:
// 		-employee ID number(integer value)
// 		-employee name(your program should handle names of up to 20 characters - may contain spaces)
// 		-pay rate per hour(floating - point value)
// 		-type of employee(0 for union, 1 for management)
//  2. Time-sheet information
// 		-number of hours worked for the week(floating - point value)
//		-use a separate loop to do the payroll processing for each employee (input the employee's hours 
//			worked and calculate their pay (see the example program dialog below).
//  3. Calculations 
// 		-Gross Pay - Union members are paid their normal pay rate for the first 40 hours worked, and 1.5 times their normal pay rate for any 
//			hours worked over 40. Management employees are paid their normal pay rate for all hours worked(they are paid for overtime hours, but 
//			they are paid at their normal hourly rate).
// 		-Tax - All employees pay a flat 15 % income tax.
// 		-Net Pay is Gross Pay - Tax.
//  4. Input validation
// 		-The input should be checked for reasonable values.If a value is not reasonable, your program should print 
//			an informative error message and ask the user to re - enter the value.
// 		-The following data should be positive numbers(greater than 0) : employee id and pay rate.
// 		-The following data should be non - negative(0 or larger) : hours worked.
// 		-Employee type should be 0 or 1.
//  5. Program output - Payroll Report
// 		-Your program should gather all the required input before the payroll report is printed.The input prompts must not be 
// 			mixed in with the report.If necessary, you can print the payroll report to an output file.
// 		-The payroll report should be formatted in a tabular(row and column) format with each column clearly labeled with a 
// 			column heading.All dollar amounts should be formatted with 2 decimal places.Note: do not use tabs between the 
// 			columns - use the setw manipulator to set the column width so that you can line up columns of numbers on the 
// 			decimal point.Print one line for each transaction that contains :
// 				-employee ID number
// 				-name
// 				-gross pay
// 				-tax
// 				-net pay
//  6. The final lines of the payroll report should print the total amount of gross pay and total amount of net pay for the week (the total for all employees). 
//***********************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include "Payroll01.h"



int main()
{
    static const int EMPLOYEES = 4;
    Employee employeeRoster[EMPLOYEES];

	// **************************************************************************************************************************
	//      Main Employee info data entering Loop
	//      -responsible for allowing the user to add the required data for each employee for the size of the array of Employee()     
	// **************************************************************************************************************************

	//declare variables to temp store values
	int iD;
	std::string name;
	float payph;
	bool manager;

	//main loop
	for (int i = 0; i < EMPLOYEES; i++)
	{
		//information to fill Employee Constructor
		employeeRoster[i];
		std::cout << "\nEnter information for employee " << (i + 1) << "\n";

		//ask and set employeeID
		std::cout << "Employee id : ";
		std::cin >> iD;
		employeeRoster[i].setEmployeeID(iD);

		//ask and set employee name
		std::cin.ignore();
		std::cout << "Employee name : ";
		std::getline(std::cin, name);
		employeeRoster[i].setEmployeeName(name);

		//ask and set hourly pay rate
		std::cout << "Pay rate : ";
		std::cin >> payph;
		employeeRoster[i].setPayPerHour(payph);

		//ask and set isManager
		std::cout << "Type : ";
		std::cin >> manager;
		employeeRoster[i].setIsManager(manager);

	} //end main data loop

	//Calling Payroll report function
	std::cout << "\nEnter timecard information for each employee:\n";
	PayrollReport(employeeRoster);

	system("pause");
    return 0;
}
// **************************************************************************************************************************
//  CalculatePay()
// 		-Gross Pay - Union members are paid their normal pay rate for the first 40 hours worked, and 1.5 times their normal pay rate for any 
//			hours worked over 40. Management employees are paid their normal pay rate for all hours worked(they are paid for overtime hours, but 
//			they are paid at their normal hourly rate).
// 		-Tax - All employees pay a flat 15 % income tax.
// 		-Net Pay is Gross Pay - Tax.
// **************************************************************************************************************************
void PayrollReport(Employee roster[])
{
	const int rosterLength = 4;
	float gross;
	float tax;
	float net;
	float hoursWorked;
	float employeeHours[rosterLength];
	float empHours;
	float allGross=0;
	float allNet=0;

	//Ask for the user to enter hours worked for each employee
	for (int i = 0; i < rosterLength; i++)
	{
		std::cout << "Hours worked for " << roster[i].getEmployeeName() << " : ";
		std::cin >> hoursWorked;
		employeeHours[i] = hoursWorked;
	}

	std::cout << "\n";
	std::cout << "Payroll Report";
	std::cout << "\n\n";

	//Calculate, then print out in rows, each of the employee's pay information
// 	std::cout << std::setw(6);
	std::cout << std::left << std::setw(7) << "ID";
	std::cout << std::left << std::setw(22)<< "Name";
	std::cout << std::right << std::setw(15) << "Gross Pay";
	std::cout << std::right << std::setw(10) << "Tax";
	std::cout << std::right << std::setw(11) << "Net Pay\n";

	for (int i = 0 ; i < rosterLength ; i++)
	{
		//instantiate subscript of array of hours for pay calculations
		empHours = employeeHours[i];

		//gross pay calculations
		if (empHours >= 0 && empHours <= 40 )
		{
			gross = empHours * roster[i].getPayPerHour();
		}
		else if (empHours > 40)
		{
			gross = (roster[i].getPayPerHour() * 40.0) + ((empHours - 40.0)*(roster[i].getPayPerHour()*1.5));
		}
		else
		{
			std::cout << "Please enter valid number of hours worked.";
			gross = 0;
		}

		//tax and net pay calculations
		tax = gross * .15;
		net = gross - tax;

		//gross and net accumulators
		allGross += gross;
		allNet += net;

		//print row of pay calculations for each employee
		std::cout << std::left << std::setw(7) << roster[i].getEmployeeID();
		std::cout << std::left << std::setw(22) << roster[i].getEmployeeName();
		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::right << std::setw(15) << gross;
		std::cout << std::right << std::setw(10) << tax;
		std::cout << std::right << std::setw(10) << net << std::endl;
	}

	std::cout << "\n";
	// 	Total Gross Pay & Total Net Pay  
	std::cout << "\nTotal Gross Pay $ ";
	FormatToDollar(allGross);
	std::cout << "\nTotal Net Pay   $ ";
	FormatToDollar(allNet);
	std::cout << "\n\n";

}
// **************************************************************************************************************************
// void FormatToDollar()
//      takes float and prints out in dollar format, then returns to function who called it
// **************************************************************************************************************************
void FormatToDollar(float dollarAmount)
{
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	std::cout << dollarAmount;
	return;
}

std::string AskName()
{
	std::string name;
	std::cout << "Employee name : ";
	std::getline(std::cin, name);

	return name;
}

// **************************************************************************************************************************
// setter for employeeID private member variable 
//		-must be positive integer
// **************************************************************************************************************************
void Employee::setEmployeeID(int eid)
{
	if (eid > 0)
	{
		employeeID = eid;
	}
	else
	{
		std::cout << "Please enter a valid ID number.";
	}
}
// **************************************************************************************************************************
// setter for employeeName private member variable 
// **************************************************************************************************************************
void Employee::setEmployeeName(std::string name)
{
	employeeName = name;
}
// **************************************************************************************************************************
// setter for payPerHr private member variable 
//		-must be positive float
// **************************************************************************************************************************
void Employee::setPayPerHour(float hourlyPay)
{
	if (hourlyPay > 0)
	{
		payPerHour = hourlyPay;
	}
	else
	{
		std::cout << "Please enter a valid amount for hourly pay rate.";
	}
}
// **************************************************************************************************************************
// setter for isManager private member variable 
//		-Employee type should be 0 or 1.
// **************************************************************************************************************************
void Employee::setIsManager(bool ismanager)
{
	if (ismanager == 1 || ismanager == 0)
	{
		isManager = ismanager;
	}
	else
	{
		std::cout << "Please enter a valid 'Type' code.";
	}
}
