/*  Program by Jessa K. West
    Tax Calculator Program: Class HourlyEmployee Code; Subclass of the Superclass Employee
    
    Concepts: object-oriented program using inheritance and encapsulation to extend generic superclass; 
            implements efficient O(n) calculations and user input validation
*/

public class HourlyEmployee extends Employee{
    //Class Variables
    //Inherits firstName, lastName, and payRate from superclass Employee
    
    double hoursWorked; //aka total hours
    double regularHours;
    double overtimeHours;

    double regularPay;
    double overtimePay;
    double grossPay;
    double taxesPaid;
    double netPay;

    //Constructor for subclass
    HourlyEmployee(String firstName, String lastName, double payRate) {
        super(firstName, lastName, payRate);
    }

    //Setters
    public void setHoursWorked(double hoursWorked) {
        if (hoursWorked < 0.0)
            throw new IllegalArgumentException("Hours worked must be >= 0.0");
        
        this.hoursWorked += hoursWorked;

        if (hoursWorked > 40.0) {
            regularHours += 40.0;
            overtimeHours += (hoursWorked - 40.0);
        }
        else{ // hoursWorked <= 40
            regularHours += hoursWorked;
            overtimeHours += 0.0;
        }
    }
    public void setRegularPay() {
        regularPay = regularHours * super.getPayRate();
    }
    public void setOvertimePay() {
        overtimePay = overtimeHours * (1.5 * super.getPayRate());
    }
    public void setGrossPay() {
        grossPay = regularPay + overtimePay;
    }
    public void setTaxesPaid() {
        if (grossPay >= 0.0 && grossPay <= 1200.00)
            taxesPaid = 0.0;
        else if (grossPay > 1200.00 && grossPay <= 2500.00)
            taxesPaid = grossPay * 0.10;
        else if (grossPay > 2500.00 && grossPay <= 4500.00)
            taxesPaid = grossPay * 0.15;
        else if (grossPay > 4500.00 && grossPay <= 8000.00)
            taxesPaid = grossPay * 0.22;
        else if (grossPay > 8000.00 && grossPay <= 10000.00)
            taxesPaid = grossPay * 0.28;
        else if (grossPay > 10000.00 && grossPay <= 15000.00)
            taxesPaid = grossPay * 0.31;
        else // grossPay > 1500.00
            taxesPaid = grossPay * 0.36;
    }
    public void setNetPay() {
        netPay = grossPay - taxesPaid;
    }

    //Getters
    public double getHoursWorked() { return hoursWorked; }
    public double getRegularHours() { return regularHours; }
    public double getOvertimeHours() { return overtimeHours; }
    public double getRegularPay() { return regularPay; }
    public double getOvertimePay() { return overtimePay; }

    //toString override for string representation of an HourlyEmployee Object
    @Override
    public String toString() {
        return String.format("%n%s%n%n%s: %,.2f%n%s: %,.2f%n%s: %,.2f%n%n%s: $%,.2f%n%s: $%,.2f%n%s: $%,.2f%n%s: $%,.2f%n%n%s: $%,.2f%n",
            super.toString(), 
            "Total Regular Hours", regularHours, 
            "Total Overtime Hours", overtimeHours,
            "Total Hours Worked", hoursWorked,
            "Monthly Regular Pay", regularPay,
            "Monthly Overtime Pay", overtimePay,
            "Monthly Gross Pay", grossPay,
            "Monthly Taxes", taxesPaid,
            "Monthly Net Pay", netPay);
    }

}
