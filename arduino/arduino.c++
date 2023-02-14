```c
#include "LedCube.h"                                                                              // Import the LedCube library

#define SIZE 5                                                                                    // Define the size of the CUBE
#define COLS (SIZE*SIZE)                                                                          // Define the columns number

byte levelPins[SIZE] = {47,48,49,50,51};                                                          // Level pins
byte colPins[COLS] = {46,41,36,31,26,45,40,35,30,25,44,39,34,29,24,43,38,33,28,23,42,37,32,27,22};// Column pins

LedCube cube(SIZE, levelPins, colPins);              // Make instance of the imported library

void setup ()
{
  delay(500);
}

void loop ()  // 1 2 3 4 7 8 9 12 15 16 18 19 21
{
    tout(500); delay(500);                    // 1 J'allume toutes les leds pour vérifier qu'elles sont toutes liées
    randomCube(100); delay(500);              // 2 This function will turn on and off random LEDs
    Tornado(); delay(500);                    // 3 This function will light on one LED in each ittiration to form a tornado
    Levels(); delay(500);                     // 4 We used this function to turn on the LEDs one by one starting from the first LEDs
    cube.randomColumn(25,20); delay(500);     // 5 Select a random column
    heart(5); delay(500);                     // 6 Make heart beats animations
    SpeedUpFan(1); delay(500);                // 7 This function will form a fan that spin
    Waves(3); delay(500);                     // 8 Display the movements of wave moving from left to right
    OneSpeedFan(3,5); delay(500);             // 9
    randomCube(20); delay(500);               // 10
    LightDrops(5,50); delay(500);             // 11 Display a rain drops
    Tornado(); delay(500);                    // 12
    LightDrops(30,55); delay(500);            // 13
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void tout(int times)
{
 for(int i=0;i<times;i++)
  {
    cube.light(random(5),random(25),HIGH);
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void randomCube(int times)
{
  for(int i=0;i<times;i++)
  {
    cube.light(random(5),random(25),HIGH);
    cube.light(random(5),random(25),LOW);
    delay(100);
  }
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,LOW);
    }
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void Tornado()
{
//This function allows you to light on the LEDs in a form of a tornado
//This function takes no arguments
//****************** As usual starting with the sequences to make **********************
  int n=0;
  int c=0;
  int m=0;
  int i=5;
  for(i=5;i>0;i--)
  {
    while (c<4)
    {
       byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
       cube.lightSequence(cadre, sizeof(cadre), i);
       m+=1;
        c+=1;
     }
   c=0;
   while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m+=5;
      c+=1;
    }
  c=0;
    while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m-=1;
      c+=1;
    }
  c=0;
    while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m-=5;
      c+=1;
    }
  n+=1;
  m=0;
  c=0;
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void Levels()
{
//This function allows you to light on the LEDs one by one moving from the first level to the last one then
//turn off the whole CUBE and start lighting on the LEDs strating from the last level
//****************** We start by lighting ON the LEDs **********************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,HIGH); // "light" function is similar to "digitalWrite" API but it takes three arguments which are the level,the column and the state(HIGH or LOW)
      delay(8);
    }
  }
//***************** We turn OFF all the LEDs *******************************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,LOW);
    }
  }
//***************** We turn ON again the LEDs *****************************
    for(int i=24;i>=0;i--)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,HIGH);
      delay(8);
    }
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void LedCube::randomColumn(byte numColumns, unsigned int wait)
{
    for (byte c=0; c < numColumns; c++) {
        lightColumn(random(1,cols+1), wait);
    }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void heart(int times)
{
//This function allows you to flick the whole CUBE like a heart tiks
//This function takes one argument which is the number of itirations
//****************** As usual starting with the sequences to make **********************
  byte heart [] = {2,12, };
  byte heart1 [] = {1,6, 1,7, 1,8, 1,11, 1,12, 1,13, 1,16, 1,17, 1,18, 2,6, 2,7, 2,8, 2,11, 2,13, 2,16, 2,17, 2,18, 3,6, 3,7, 3,8, 3,11, 3,12, 3,13, 3,16, 3,17, 3,18, };
  byte heart2 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7, 0,8, 0,9, 0,10, 0,11, 0,12, 0,13, 0,14, 0,15, 0,16, 0,17, 0,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, 1,0, 1,1, 1,2, 1,3, 1,4, 1,5, 1,9, 1,10, 1,14, 1,15, 1,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,9, 2,10, 2,14, 2,15, 2,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,3, 3,4, 3,5, 3,9, 3,10, 3,14, 3,15, 3,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 4,6, 4,7, 4,8, 4,9, 4,10, 4,11, 4,12, 4,13, 4,14, 4,15, 4,16, 4,17, 4,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };

  for(int i=0;i<times;i++)
  {
    cube.lightSequence(heart, sizeof(heart), 500);
    delay(50);
    cube.lightSequence(heart, sizeof(heart), 1);
    cube.lightSequence(heart1, sizeof(heart1), 1);
    cube.lightSequence(heart, sizeof(heart), 1);
    cube.lightSequence(heart1, sizeof(heart1), 1);
    cube.lightSequence(heart2, sizeof(heart2), 1);
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void SpeedUpFan(int executeTimes)
{
//This function allows you to light on the LEDs in a form of fan that speed up from each itiration
//This function takes one argument which is the execution times to identify how many times you want to execute this function
//****************** As usual starting with the sequences to make **********************
  byte aa2 [] = {0,10, 1,10, 2,10, 3,10, 4,10, 4,11, 3,11, 2,11, 1,11, 0,11, 0,12, 1,12, 2,12, 3,12, 4,12, 4,13, 3,13, 2,13, 1,13, 0,13, 0,14, 1,14, 2,14, 3,14, 4,14,};
  byte aa3 [] = {0,0, 1,0, 2,0, 3,0, 4,0, 4,6, 3,6, 2,6, 1,6, 0,6, 0,12, 1,12, 2,12, 3,12, 4,12, 4,18, 3,18, 2,18, 1,18, 0,18, 1,24, 2,24, 3,24, 4,24,};
  byte aa4 [] = {0,2, 1,2, 2,2, 3,2, 4,2, 4,7, 3,7, 2,7, 1,7, 0,7, 0,12, 1,12, 2,12, 3,12, 4,12, 4,17, 3,17, 2,17, 1,17, 0,17, 1,22, 2,22, 3,22, 4,22,};
  byte aa5 [] = {0,4, 1,4, 2,4, 3,4, 4,4, 4,8, 3,8, 2,8, 1,8, 0,8, 0,12, 1,12, 2,12, 3,12, 4,12, 4,16, 3,16, 2,16, 1,16, 0,16, 1,20, 2,20, 3,20, 4,20,};

//****************** And now we transfer the sequenses to our CUBE **********************
  int counter=0; //I used this counter to count how many times we already executed the function
  while ( counter<executeTimes)
  {
    int i=10;
    for(i=10;i>0;i--)
    {
      cube.lightSequence(aa2, sizeof(aa2), i);
      cube.lightSequence(aa3, sizeof(aa3), i);
      cube.lightSequence(aa4, sizeof(aa4), i);
      cube.lightSequence(aa5, sizeof(aa5), i);
      cube.lightSequence(aa2, sizeof(aa2), i);
      cube.lightSequence(aa3, sizeof(aa3), i);
      cube.lightSequence(aa4, sizeof(aa4), i);
      cube.lightSequence(aa5, sizeof(aa5), i);
    }
    counter+=1;
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void Waves(int times)
{
//This function allows you to light on the LEDs in a form of waves moving from left to right
//This function takes one argument which is the number of itirations
//****************** As usual starting with the sequences to make **********************
  byte wave [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, };
  byte wave1 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,5, 4,6, 4,7, 4,8, 4,9, };
  byte wave2 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,5, 3,6, 3,7, 3,8, 3,9, 4,10, 4,11, 4,12, 4,13, 4,14, };
  byte wave3 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,5, 2,6, 2,7, 2,8, 2,9, 3,10, 3,11, 3,12, 3,13, 3,14, 4,15, 4,16, 4,17, 4,18, 4,19, };
  byte wave4 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,5, 1,6, 1,7, 1,8, 1,9, 2,10, 2,11, 2,12, 2,13, 2,14, 3,15, 3,16, 3,17, 3,18, 3,19, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave5 [] = {0,5, 0,6, 0,7, 0,8, 0,9, 1,10, 1,11, 1,12, 1,13, 1,14, 2,15, 2,16, 2,17, 2,18, 2,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave6 [] = {0,10, 0,11, 0,12, 0,13, 0,14, 1,15, 1,16, 1,17, 1,18, 1,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave7 [] = {0,15, 0,16, 0,17, 0,18, 0,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave8 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave9 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,15, 4,16, 4,17, 4,18, 4,19, };
  byte wave10 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,15, 3,16, 3,17, 3,18, 3,19, 4,10, 4,11, 4,12, 4,13, 4,14, };
  byte wave11 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,15, 2,16, 2,17, 2,18, 2,19, 3,10, 3,11, 3,12, 3,13, 3,14, 4,5, 4,6, 4,7, 4,8, 4,9, };
  byte wave12 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,15, 1,16, 1,17, 1,18, 1,19, 2,10, 2,11, 2,12, 2,13, 2,14, 3,5, 3,6, 3,7, 3,8, 3,9, 4,0, 4,1, 4,2, 4,3, 4,4, };
  byte wave13 [] = {0,15, 0,16, 0,17, 0,18, 0,19, 1,10, 1,11, 1,12, 1,13, 1,14, 2,5, 2,6, 2,7, 2,8, 2,9, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, };
  byte wave14 [] = {0,10, 0,11, 0,12, 0,13, 0,14, 1,5, 1,6, 1,7, 1,8, 1,9, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, };
  byte wave15 [] = {0,5, 0,6, 0,7, 0,8, 0,9, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, };

  for(int i=0;i<times;i++)
  {
   cube.lightSequence(wave, sizeof(wave), 3);
   cube.lightSequence(wave1, sizeof(wave1), 3);
   cube.lightSequence(wave2, sizeof(wave2), 3);
   cube.lightSequence(wave3, sizeof(wave3), 3);
   cube.lightSequence(wave4, sizeof(wave4), 3);
   cube.lightSequence(wave5, sizeof(wave5), 3);
   cube.lightSequence(wave6, sizeof(wave6), 3);
   cube.lightSequence(wave7, sizeof(wave7), 3);
   cube.lightSequence(wave8, sizeof(wave8), 3);
   cube.lightSequence(wave9, sizeof(wave9), 3);
   cube.lightSequence(wave10, sizeof(wave10), 3);
   cube.lightSequence(wave11, sizeof(wave11), 3);
   cube.lightSequence(wave12, sizeof(wave12), 3);
   cube.lightSequence(wave13, sizeof(wave13), 3);
   cube.lightSequence(wave14, sizeof(wave14), 3);
   cube.lightSequence(wave15, sizeof(wave15), 3);
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void OneSpeedFan(int speedFan, int executionTimes)
{
//This function allows you to light on the LEDs in a form of fan that spin in one speed
//This function takes two arguments which are the execution times to identify how many times you want to execute this function and the speed fan to indicate the spining speed
//****************** As usual starting with the sequences to make **********************
  byte aa2 [] = {0,10, 1,10, 2,10, 3,10, 4,10, 4,11, 3,11, 2,11, 1,11, 0,11, 0,12, 1,12, 2,12, 3,12, 4,12, 4,13, 3,13, 2,13, 1,13, 0,13, 0,14, 1,14, 2,14, 3,14, 4,14,};
  byte aa3 [] = {0,0, 1,0, 2,0, 3,0, 4,0, 4,6, 3,6, 2,6, 1,6, 0,6, 0,12, 1,12, 2,12, 3,12, 4,12, 4,18, 3,18, 2,18, 1,18, 0,18, 1,24, 2,24, 3,24, 4,24,};
  byte aa4 [] = {0,2, 1,2, 2,2, 3,2, 4,2, 4,7, 3,7, 2,7, 1,7, 0,7, 0,12, 1,12, 2,12, 3,12, 4,12, 4,17, 3,17, 2,17, 1,17, 0,17, 1,22, 2,22, 3,22, 4,22,};
  byte aa5 [] = {0,4, 1,4, 2,4, 3,4, 4,4, 4,8, 3,8, 2,8, 1,8, 0,8, 0,12, 1,12, 2,12, 3,12, 4,12, 4,16, 3,16, 2,16, 1,16, 0,16, 1,20, 2,20, 3,20, 4,20,};
  int counter=0;
  while(counter<executionTimes)
  {
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa5, sizeof(aa5), speedFan);
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa5, sizeof(aa5), speedFan);
     counter+=1;
  }
}
 -----------------------------------------------------------------------------------------------------------------------------------------------
void LightDrops(int speedDrop,int times)
{
//This function allows you to light on the LEDs in a form rain drops
//This function takes two arguments which are the speed of drops and the execution itirations
//****************** As usual starting with the sequences to make **********************
  for(int i=0;i<times;i++)
  {
    cube.lightDrop(random(25),speedDrop);
  }
}
```
