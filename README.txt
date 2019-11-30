Airline ticketing system 

Command to compile this program - make all
Command to execute the program - ./airlines
Command to clear the .o files - make clean

This takes the user to the login page, where they have two options for login, either as user to book/cancel/print  flight ticket or as admin to add or delete flights.
For user - If you do not have an account in our ‘IIITB airlines’ service you need to signup and make an account. For booking a new ticket we display all flights and provide filter options to the using basing on takeoff destination, landing destination, departure time, arrival time and price. After choosing a flight, user is asked to provide his details. Program then, takes the user to a seat selection page displaying all the seats in that flight, allowing the user to choose one. Subsequently, after seat selection booking ID is allotted and ticket is printed. To cancel an existing ticket user needs to provide only the booking ID. 
For admin - admin has two options either to add or delete flights. For adding a flight all information regarding the flight such as Flight number, company’s name, take off and landing destinations, time of arrival and departure, travel time, number of seats and price of ticket is needed. For deleting a flight only the flight number is needed.

Team members :
IMT2019003 - Aditya Vardhan           - Deleting Ticket, Checking of Deleted Ticket, Deleting the Seat after deleting the Ticket
IMT2019012 - Archit Sangal            - Debugging The Code, Creating Main, Creating User Login, Creating Admin Login
IMT2019021 - C Karthik                - Print The Boarding Pass Or Ticket In A Proper Format By Storing it in a ".txt" file
IMT2019060 - Nikhil Agrawal           - Sorting The Flights According To Different Parameter
IMT2019503 - Bangari Amulya           - Storing The booked Ticket In A File and Generating a Random Booking ID
IMT2019511 - Manaswitha Reddy Kauluri - Seat booking, Admin, Readme

