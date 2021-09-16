import java.util.Scanner;

public class WorkoutBuddy{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    
    /* This program takes the amount of time a user works out each day and then a chart is generated showing
     * the amount of minutes the person worked out each day. A weekly total of minutes the person
     * worked out is calculated along with the total minutes the person worked out for the month. 
     */
    
    
    System.out.println("Spring 2021 - CS1083 - Section 002 - Project 1 - written by Shane Perry\n");
    
    
    //Asks the user for the minutes he/she worked out each day
    System.out.print("Minutes of Sunday workout: ");
    int sunTime = scan.nextInt();
    
    System.out.print("Minutes of Monday workout: ");
    int monTime = scan.nextInt();
    
    System.out.print("Minutes of Tuesday workout: ");
    int tuesTime = scan.nextInt();
    
    System.out.print("Minutes of Wednesday workout: ");
    int wedsTime = scan.nextInt();
    
    System.out.print("Minutes of Thursday workout: ");
    int thursTime = scan.nextInt();
    
    System.out.print("Minutes of Friday workout: ");
    int friTime = scan.nextInt();
    
    System.out.print("Minutes of Saturday workout: ");
    int satTime = scan.nextInt(); 
    
    
    
    //Heading of Chart
    System.out.println();
    System.out.println("Week\tSunday\tMonday\tTuesday\tWednesday\tThursday\tFriday\tSaturday\tTotal/Week");
    
    //Body of Chart
    
    int day = 1;
    int week = 1;
    int totalMonthlyWorkout = 0;
    int weeklyTotal = 0;
    int dayTime = 0;
    
    for(int i = 1; i <= 5; i++){ //Generates weeks
      System.out.print(week + "\t");
      for(int j = 1; j<= 7; j++){ //Generates days
        
        //This block of if/else if statements sets the workout minutes to the calendar day
        if(day == 1 || day == 8 || day == 15 || day == 22 || day == 29){
          dayTime = sunTime;
          weeklyTotal += sunTime;
        }
        else if(day == 2 || day == 9 || day == 16 || day == 23 || day == 30){
          dayTime = monTime;
          weeklyTotal += monTime;
        }
        else if(day == 3 || day == 10 || day == 17 || day == 24){
          dayTime = tuesTime;
          weeklyTotal += tuesTime;
        }
        else if(day == 4 || day == 11 || day == 18 || day == 25){
          dayTime = wedsTime;
          weeklyTotal += wedsTime;
        }
        else if(day == 5 || day == 12 || day == 19 || day == 26){
          dayTime = thursTime;
          weeklyTotal += thursTime;
        }
        else if(day == 6 || day == 13 || day == 20 || day == 27){
          dayTime = friTime;
          weeklyTotal += friTime;
        }
        else if(day == 7 || day == 14 || day == 21 || day == 28){
          dayTime = satTime;
          weeklyTotal += satTime;
        }
        else{
          dayTime = 0;
        }
        
        //Formats calendar to meet requirements "1-9, 2-15, etc"
        if(day <= 30){
          System.out.print(day + "-" + dayTime + "\t");
        }
        else{
          System.out.print("0-" + dayTime + "\t");
        }
        
        day++;
        
        totalMonthlyWorkout += dayTime; //Total number of minutes spent working out in the month
      }
      
      
      System.out.print("W" + week + "-" + weeklyTotal); //Prints out total for the week
      weeklyTotal = 0; //Resets weeklyTotal for the next week
      
      week++;
      System.out.println();
    }
    
    System.out.println("Month minutes workout total: " + totalMonthlyWorkout);
    
  }
  
}