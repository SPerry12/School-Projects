import java.util.*;

public class DifferentShapes{
  
  //Scanner that can be utilized by all methods
  public static Scanner scnr = new Scanner(System.in);
  
  public static void main(String[] arg){
    System.out.println("Spring 2021 - CS1083 - Section 002 - Project 2 - DifferentShapes - written by Shane Perry");
    
    getMenuSelection();
  }
  
  //Input validation and user input
  public static void getMenuSelection(){
    printMenu();
    
    int userSelection = scnr.nextInt();
    boolean isValid = false;
    
    while(isValid != true){
      if (userSelection == 0){
        System.out.println("Thank you for using this program, Good bye !");
        isValid = true;
      }
      else if (userSelection == 1){
        makeTriangle(scnr);
        isValid = true;
      }
      else if (userSelection == 2){
        makeDiamond(scnr);
        isValid = true;
      }
      else if (userSelection == 3){
        makeRectangle(scnr);
        isValid = true;
      }
      else{
        System.out.println("Incorrect selection, please try again");
        isValid = false;
        printMenu();
        userSelection = scnr.nextInt();
      }
    }
  }
  
  //Prints menu options
  public static void printMenu(){ 
    System.out.println("Please, select one of the following options");
    System.out.print("0. Exit\n1. Print a Triangle\n2. Print a Diamond\n3. Print a Rectangle\n");
  }
  
  public static void makeTriangle(Scanner scnr){
    System.out.println("Please enter the width of the triangle");
    System.out.println("Please enter an even number between 0 and 80");
    int width = scnr.nextInt();
    boolean isValid = false;
    
    while(isValid != true){
      if(width <= 80 && width % 2 == 0 && width >= 1){
        isValid = true;
      }
      else{
        isValid = false;
        System.out.println("Incorrect selection, please, try again");
        System.out.println("Please enter the width of the triangle");
        System.out.println("Please enter an even number between 0 and 80");
        width = scnr.nextInt();
      }
    }
    
    printTriangle(width);
    
    getMenuSelection(); //Takes user back to menu
  }
  
  //Creates sides of triangle
  public static void printTriangle(int width){
    int x = 2;
    for(int i = 1; i <= width * 0.5; i++){
      for(int j = i; j <= width * 0.5; j++){
        System.out.print(" ");
      }
      for(int j = 1; j <= x; j++){
        if(j==1){
          System.out.print("/");
        }
        else if(j==x){
          System.out.print("\\");
        }
        else{
          System.out.print(" ");
        }
      }
      System.out.println();
      x += 2;
    }
    
    System.out.print(" "); //Added to make bottom seem more aligned to center
    
    //Bottom of the triangle
    for(int i = 0; i < width; i++){
      System.out.print("-");
    }
    System.out.println();
  }
  
  public static void makeDiamond(Scanner scnr){
    boolean isValid = false;
    
    System.out.println("What size do you want the diamond to be drawn?");
    System.out.println("Please enter an even number between 0 and 80");
    int size = scnr.nextInt();
    
    while(isValid != true){
      if(size <= 80 && size % 2 == 0 && size >= 1){
        isValid = true;
      }
      else{
        isValid = false;
        System.out.println("Incorrect selection, please, try again");
        System.out.println("Please enter the width of the diamond");
        System.out.println("Please enter an even number between 0 and 80");
        size = scnr.nextInt();
      }    
    }  
    
    System.out.println("Please enter the char that you would like to be used as the edge of the diamond");
    char edgeChar = scnr.next().charAt(0);
    System.out.println("Please enter the char that you would like to be used to fill the diamond");
    char fillChar = scnr.next().charAt(0);
    
    printDiamond(size, edgeChar, fillChar);
    getMenuSelection();
  }
  
  //Prints diamond shape
  public static void printDiamond(int size, char edgeChar, char fillChar){ //fixme
    for (int i = 1; i <= size * 0.5; i++) {
      for (int j = 1; j <= size * 0.5 - i; j++) {
        System.out.print(" ");
      }
      
      System.out.print("/");
      
      for (int q = 1; q <= 2 * i - 2; q++) {
        System.out.print(fillChar);
      }
      System.out.println("\\");
    }
    
    for (int i = 1; i <= size * 0.5; i++) {
      for (int j = 1; j <= i - 1; j++) {
        System.out.print(" ");
      }
      
      System.out.print("\\");
   
      for (int q = 1; q <= size * 0.5 * 2 - (2 * i); q++) {
        System.out.print(fillChar);
      }
      System.out.println("/");
    }
    
  }
  
  public static void printNChars(int n, char c){
    //I did not understand the point of this method.
  }
 
  //Asks user for the parameters for the rectangle
  public static void makeRectangle(Scanner scnr){
    boolean isValid = false;
    
    System.out.println("What size do you want the diamond to be drawn?");
    System.out.println("Please enter an even number between 0 and 80");
    int size = scnr.nextInt();
    
    while(isValid != true){
      if(size <= 80 && size > 0){
        isValid = true;
      }
      else{
        isValid = false;
        System.out.println("Incorrect selection, please, try again");
        System.out.println("Please enter the width of the rectangle");
        System.out.println("Please enter a number between 0 and 80");
        size = scnr.nextInt();
      }
  }
    
    System.out.println("Please write the char you would like to use as the contour of the rectangle");
    char fillChar = scnr.next().charAt(0);
    
    printRectangle(size, fillChar); 
}
  
  public static void printRectangle(int size, char fillChar){
    boolean filled = false;
    
    
    printRectangleLine(size, fillChar, true);
    
    for(int i = 0; i < size - 2; i++){
      printRectangleLine(size, fillChar, false);
    }
    
    printRectangleLine(size, fillChar, true);
    
    getMenuSelection();
  }
  
  
  //Prints each row of the rectangle based on whether the boolean "filled" is true or false
  public static void printRectangleLine(int size, char fillChar, Boolean filled){ 
    String worked = "NO";

    if(filled == true){
      for(int i = 0; i < size; i++){
        System.out.print(fillChar);
      }
      System.out.println();
    }
    else{
      for(int i = 0; i < 1; i++){
        System.out.print(fillChar);
        for(int j = 0; j < size - 2; j++){
          System.out.print(" ");
        }
        System.out.println(fillChar);
      }
    }
  }
}