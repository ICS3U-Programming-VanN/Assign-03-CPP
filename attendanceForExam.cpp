// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on : October 12, 2022
// This program asks the user to input the number of classes they attended and
// the number of classes held and then
// displays whether or not they can write the final exam


#include <iomanip>
#include <iostream>


// This function returns the percentage (with decimal places)
float calculatePercentage(float numerator, float denominator) {
    // Calculates percentage (with decimals, to later be rounded)
    float percentageDecimal = numerator / denominator * 100;

    // Returns the percentage (with decimals)
    return percentageDecimal;
}

int main() {
    // Initializes Variables
    bool keepRunning = true;
    std::string runAgain, numClassesString, numClassesAttendedString;
    int numClasses, numClassesAttended, attendancePercentage;

    // Keeps running program until user ends it
    while (keepRunning == true) {
        // Checks for exceptions (such as VERY extraordinary inputs)
        try {
            // Displays the Title of the Program
            std::cout << "ATTENDANCE FOR EXAM CALCULATOR" << std::endl;

            // Displays to user that decimal places of input will be cut off
            std::cout << "DECIMALS FOLLOWING A PERIOD WILL BE IGNORED"
            << " (You cannot possibly hold parts of a class.)" << std::endl;

            // Asks user for the number of classes held
            std::cout << "Number of classes held: ";
            std::cin >> numClassesString;

            // Asks the user for the number of classes they attended
            std::cout << "Number of classes attended: ";
            std::cin >> numClassesAttendedString;

        // In the event of an exception in the input
        } catch (std::out_of_range) {
            std::cout << "Please enter WHOLE numbers ABOVE ZERO!" << std::endl;
        }

        // Checks for exceptions
        try {
            // Attempts to cast user input into integers
            numClasses = std::stoi(numClassesString);
            numClassesAttended = std::stoi(numClassesAttendedString);

            // Calls calculatePercentage() function to calculate the percentage
            attendancePercentage = calculatePercentage(
                numClassesAttended, numClasses);

            // IF the user enters numbers higher than zero
            if (numClasses >= 0 && numClassesAttended >= 0) {
                // IF the user inputs that they attend more classes
                // than the number of classes held
                if (attendancePercentage > 100) {
                    std::cout << "You cannot have more classes attended"
                              << " than classes held!" << std::endl;

                // IF the user can attend the exam
                // (Attendance rate = 75% or higher)
                } else if (attendancePercentage >= 75) {
                    std::cout << "\nYour attendance percentage is "
                              << std::fixed << std::setprecision(0)
                              << attendancePercentage << "%" << std::endl;
                    std::cout << "You may attend the exam, as your attendance"
                              << " is equal to or over 75%" << std::endl;

                // IF the user cannot attend the exam
                // (Attendance rate = lower than 75%)
                } else if (attendancePercentage >= 0) {
                    std::cout << "\nYour attendance percentage is "
                              << std::fixed << std::setprecision(0)
                              << attendancePercentage << "%" << std::endl;
                    std::cout << "You may NOT attend the exam, as your"
                              << " attendance is under 75%" << std::endl;

                // IF the user entered negative numbers
                // (failsafe ELSE statement)
                } else {
                    std::cout << "Please enter WHOLE numbers ABOVE ZERO!"
                    << std::endl;
                }

            // IF the user entered negative numbers
            } else {
                std::cout << "Please enter numbers OVER zero!" << std::endl;
            }

            // Asks the user if they want to run the program again
            std::cout << "\nWould you like to run the program again?"
                      << " (Enter anything to run again"
                      << " or 'n' to end the program): ";
            std::cin >> runAgain;

            // IF the user wants to end the program
            if (runAgain == "n") {
                keepRunning = false;
            }

        // In the event of an exception
        // (display error message with instructions)
        } catch (std::exception) {
            std::cout << "Please enter WHOLE NUMBERS OVER ZERO!\n"
                      << std::endl;
        }
    }
}
