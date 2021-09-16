import java.util.Scanner;
import java.awt.*;

public class Mosaic{
  
  static Scanner scnr = new Scanner(System.in);
  
  public static void main(String[] args){
    System.out.println("Spring 2021 - CS1083 - Section002 - Project 3 - Mosaic - written by Shane Perry");
    System.out.println();
    
    drawMosaic();
  }
  
  public static void drawMosaic(){
    DrawingPanel panel = new DrawingPanel(600, 600);
    int[] xPosition = new int[10];
    int[] yPosition = new int[10];
    Color[] colors = new Color[10];
    
    
    //Gets the number of times to move and the number of circles from the user input
    System.out.print("How many times do you want the circles to move (max 1000)?");
    int numMoves = scnr.nextInt();
    
    System.out.print("How many circles do you want to show in teh mosaic (max 9)?");
    int numCircles = scnr.nextInt();
    
    initialPosition(xPosition, yPosition, numCircles); 
    initialColor(colors, numCircles); 
    
    //Shows message to get the movements (only the message)
    System.out.print("Please, input the different moves");
    
    
    
    moveCircles(panel, xPosition, yPosition, colors, numCircles, numMoves); 
    
    //Displays the graphic signature
  }
  
  public static void initialPosition(int[] xCoords, int[] yCoords, int circles){
    //will be assigning the positions X and Y to the circles (the number selected by the user)
    int circleSize = 50;
    int coordX = 150;
    //C1 - Real: 125, 425:::::150,450

    for(int i = 0; i < circles; i++){
      xCoords[i] = coordX - (circleSize / 2);
      
      if(coordX <= 450){
        coordX += 150;
      }
      else{
        coordX = 150;
      }
    }
    
    int coordY = 450;
    for(int i = 0; i < circles; i++){
      int counter = 0;
      yCoords[i] = coordY - (circleSize / 2);
      counter++;
      
      if(counter >= 2){
        coordY -= 150;
        counter = 0;
      }
    }
    
  }
  
  public static void initialColor(Color[] colors, int circles){
    //will be assigning the color to the circles (the number selected by the user)
    
    if(0 < circles){
      colors[0] = Color.BLACK;
    }
    if(1 < circles){
      colors[1] = Color.RED;
    }
    if(2 < circles){
      colors[2] = Color.BLUE;
    }
    if(3 < circles){
      colors[3] = Color.YELLOW;
    }
    if(4 < circles){
      colors[4] = Color.PINK;
    }
    if(5 < circles){
      colors[5] = Color.GREEN;
    }
    if(6 < circles){
      colors[6] = Color.ORANGE;
    }
    if(7 < circles){
      colors[7] = Color.GRAY;
    }
    if(8 < circles){
      colors[8] = Color.DARK_GRAY;
    }
    //Only assign up to int circles
  }
  
  public static void moveCircles(DrawingPanel panel, int[] xPosition, int[] yPosition, Color[] colors, int circles,
                                int moves){
    // will have the loop to all the moves, this method will also call other methods to change the
    // position of the circles based on the "orientation" or "direction" that the user inputs and 
    // will also call another method to show circles
    
    //loop that asks for movements: based on int moves
    for(int i = 0; i < circles; i++){
      showCircle(panel, xPosition[i], yPosition[i], colors[i], 50);
    }
    moveCircle(xPosition, yPosition);
  }
  
  public static void showCircle(DrawingPanel panel, int xPosition, int yPosition, Color colors, int size){
    //Will display the circle filled with the characterisitcs received as parameters
    //Outline black
    
    Graphics g = panel.getGraphics();
    g.setColor(Color.colors);
    g.fillOval(xPosition, yPosition, size, size);
    
  }
  
  public static void moveCircle(int[] xPosition, int[] yPosition){
    
  }
  
}

