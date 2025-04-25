/*  Program by Jessa K. West
    Tax Calculator Program: Class Employee Code; Superclass
    
    Concepts: object-oriented program using inheritance and encapsulation to extend generic superclass; 
            implements efficient O(n) calculations and user input validation
*/

public class Employee {
    //Class Variables
    private String firstName;
    private String lastName;
    private double payRate;

    //Constructor to instantiate new employee object w defaults
    public Employee() {
        this.firstName = "";
        this.lastName = "";
        this.payRate = 0.0;
    }

    //Constructor to instantiate new employee object w specified values
    public Employee(String firstName, String lastName, double payRate) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.payRate = payRate;
    }

    //Setters for individual class variables
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    public void setPayRate(double payRate) {
        //input validation
        if (payRate < 0.0)
            throw new IllegalArgumentException("Pay rate must be >= 0.0");
        else if (payRate < 7.25) //must be at least minimum wage
            this.payRate = 7.25;
        else
            this.payRate = payRate;
    }

    //Getters for individual class variables
    public String getFirstName() {
        return firstName;
    }
    public String getLastName() {
        return lastName;
    }
    public double getPayRate() {
        return payRate;
    }

    //toString override for string representation of an Employee Object
    //format specified for all variables to be listed
    @Override
    public String toString() {
        return String.format("%s: %s %s%n%s: $%.2f",
            "Employee", firstName, lastName,
            "Pay Rate", payRate);
    }
}
