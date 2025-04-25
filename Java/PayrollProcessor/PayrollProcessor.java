/*  Program by Jessa K. West
    Payroll & Tax Processing Program: Main Code
    
    Concepts: object-oriented program using inheritance and encapsulation to extend generic superclass; 
            implements efficient O(n) calculations and user input validation
*/

import java.util.Scanner;

public class PayrollProcessor {
    public static void main(String[] args) {
        System.out.printf("%nPayroll Processing Program by Jessa K. West%n");

        PayrollProcessor payrollProcessor = new PayrollProcessor();

        payrollProcessor.inputEmployeeInfo();

        System.out.printf("End of Program.%n");
    }

    public void inputEmployeeInfo() {
        Scanner input = new Scanner(System.in);
        String tempFirst;
        String tempLast;
        double tempPayRate;
        double tempHours;

        System.out.println("Input the Employee's Info: ");
        System.out.print("First Name: ");
        tempFirst = input.nextLine();
        System.out.print("Last Name: ");
        tempLast = input.nextLine();
        System.out.print("Hourly Pay Rate: ");
        tempPayRate = input.nextDouble();

        HourlyEmployee employee = new HourlyEmployee(tempFirst, tempLast, tempPayRate);

        for (int i = 0; i <4; i++) {
            System.out.printf("%s%d%s", "Week ", i+1, "'s Hours: ");
            tempHours = input.nextDouble();

            employee.setHoursWorked(tempHours);
        }

        input.close();

        //Call methods to calculate pays & taxes based on the month's hours
        employee.setRegularPay();
        employee.setOvertimePay();
        employee.setGrossPay();
        employee.setTaxesPaid();
        employee.setNetPay();

        System.out.println(employee.toString());
    }
}
