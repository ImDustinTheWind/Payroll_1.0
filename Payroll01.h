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
// 
//***********************************************************************************************************


#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Employee
{
	private:
		int employeeID;
		std::string employeeName;
		float payPerHour;
		bool isManager;

	public:

		Employee()
		{
			employeeID = 0;
			employeeName = "";
			payPerHour = 0;
			isManager = false;
		};

		void setEmployeeID(int eid);
		void setEmployeeName(std::string name);
		void setPayPerHour(float hourlyPay);
		void setIsManager(bool ismanager);
		int getEmployeeID() { return employeeID; }
		std::string getEmployeeName() { return employeeName; }
		float getPayPerHour() { return payPerHour; }
		bool getIsManager() { return isManager; }
};

int main();
void PayrollReport(Employee roster[]);
void FormatToDollar(float dollarAmount);
std::string AskName();
