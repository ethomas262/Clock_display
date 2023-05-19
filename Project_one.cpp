#include <iostream>
#include <string>
#include <format>
#include <string_view>
#include <sstream>
#include <iomanip>


using namespace std;

class Clock{ // clock object contains functionality for program
    public:

        Clock(int hrs, int min, int secs){ //contructor uses user input to create a clock object 
            hours = hrs;
            minutes = min;
            seconds = secs;

            // determine hours in standard time
            if (hours > 12){
                hours_standard_time = hours % 12;
                timestate = "P.M";

            }else{
                hours_standard_time = hours;
                timestate = "A.M";
                if (hours_standard_time == 12){
                    timestate = "P.M";
                }
            }
            
        }
        
        void add_hour(){ // adds hour and makes sure the hours integers does not exceed 24 and 12
            hours += 1;
            hours_standard_time += 1;
            
            if (hours == 24){ 
                hours = 0;
                
            }
            
            if (hours_standard_time == 13){
                hours_standard_time = 1;
            }
            
            //change timestate when hours in standard time  = 12
            if (hours_standard_time == 12){
                if (timestate == "P.M"){
                    timestate = "A.M";
                }else{
                    timestate = "P.M";
                }

            }

        }
        void add_minute(){

            minutes += 1;
            // if minutes =  60 we call the add_hour() function
            if (minutes >= 60){
                this -> add_hour();
                minutes = 0;
            }


        }
        void add_second(){

            seconds += 1;
            // if seconds = 60 we call the add minutes function
            if(seconds >= 60){
                this -> add_minute();
                seconds = 0;

            }

        }
        void display(){
            // declare string variables to be used to convert integer hours, minutes, and seconds into strings
            string output_hours;
            string output_minutes;
            string output_seconds;
            string output_standard_hours;

            // if (int)hours is a single digit integer put a zero in front of it otherwise leave as is
            if (hours < 10){
                output_hours = "0" + std :: to_string(hours);
            }else{
                output_hours = std::to_string(hours);
            }

            // if (int)minutes is a single digit integer put a zero in front of it otherwise leave as is
            if (minutes < 10){
                output_minutes = "0" + std :: to_string(minutes);
            }else{
                output_minutes = std::to_string(minutes);
            }

            // if (int)seconds is a single digit integer put a zero in front of it otherwise leave as is
            if (seconds < 10){
                output_seconds = "0" + std :: to_string(seconds);
            }else{
                output_seconds = std::to_string(seconds);
            }

            // if (int)hours_standard_time is a single digit integer put a zero in front of it otherwise leave as is
            if (hours_standard_time < 10){
                output_standard_hours = "0" + std :: to_string(hours_standard_time);
            }else{
                output_standard_hours = std::to_string(hours_standard_time);
            }

            // combine output variables into a single string to simplify output 
            string inner_mil_clock = output_hours + ":" + output_minutes + ":" + output_seconds;
            string inner_standard_clock = output_standard_hours + ":" + output_minutes + ":" + output_seconds + " " + timestate;

            // format output and display
            cout << "**************************     **************************" << endl;
            cout << "*      12-Hour Clock     *     *      24-Hour Clock     *" <<endl;
            cout << "*      " << inner_standard_clock << "      *     *         " << inner_mil_clock << "       *" << endl;
            cout << "**************************     **************************" << endl;

            


            

        }
        
    private: // private variables used to keep track of time within the class object
        int hours;
        int minutes;
        int seconds;
        int hours_standard_time;
       

        
        string timestate;



};
void print_prompt(){  // function to prompt user input
    cout << endl;
    cout << "**************************" << endl;
    cout << setw(25) << left << "* 1 - Add One Hour" << "*" << endl;
    cout << setw(25) << left << "* 2 - Add One Minute" << "*" <<  endl;
    cout << setw(25) << left << "* 3 - Add One Second" << "*" << endl;
    cout << setw(25) << left << "* 4 - Exit Program" << "*" << endl;
    cout << "**************************" << endl;
    
}

int main(){
    
   // input variables for creating clock object
   int hours;
   int minutes;
   int seconds;

   
   int response; // variable that will hold user input

   bool continue_program = true; //boolean condition to check when to continue program

   bool valid_response = true; // boolean condition to check if user inputs a valid response

    // output program introduction and instructions
   cout << "Hello Welcome to the program! Please enter hours in military time to get started" << endl;
   cout << "Example: 5:24:30 P.M   ->    17 24 30" << endl;

    //get user input
   cin >> hours >> minutes >> seconds;

    //create clock object
   Clock newClock(hours,minutes,seconds);

    //execute until user response = 4
   while(continue_program){
       

       newClock.display(); // display clock

       print_prompt(); // prompt user input


       //get user input and validate
       cin >> response;
       while(response > 4 || response < 1){
           cout << "Error: Invalid input try again.";
           cin >> response;

       }
       // execute based on user input 
       switch(response){
        case 1:
            newClock.add_hour();
            break;
        case 2:
            newClock.add_minute();
            break;
        case 3:
            newClock.add_second();
            break;
        default: // user input already validated so default has to be 4
            continue_program = false;
            break;
       }
   }
    
      
      return 0;



   
}