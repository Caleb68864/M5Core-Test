#include <Arduino.h>
// #include "M5Stack.h"
#include "M5CoreInk.h"
#include <iostream>
#include <sstream> // for string streams
#include <string>  // for string
using namespace std;
Ink_Sprite InkPageSprite(&M5.M5Ink);

void WriteLine(String line, int row)
{
  // M5.M5Ink.clear();
  Serial.println(line);
  InkPageSprite.drawString(35, (15 * row), line.c_str());
  InkPageSprite.pushSprite();
  delay(1000);
}

void WriteColumn(String line, int row, int col, int starty)
{
  // M5.M5Ink.clear();
  Serial.println(line);
  InkPageSprite.drawString(((25 * col) + starty), (15 * row), line.c_str());
  InkPageSprite.pushSprite();
  delay(1000);
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  M5.begin();
  M5.M5Ink.isInit();
  M5.M5Ink.clear();
  delay(1000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  M5.M5Ink.clear();
  if (InkPageSprite.creatSprite(0, 0, 200, 200, true) != 0)
  {
    Serial.printf("Ink Sprite creat failed");
  }
  else
  {
    Serial.printf("creatSprite success\n");
  }
  WriteLine("Welcome", 1);
  WriteLine("To", 2);
  WriteLine("Logic", 3);
  WriteLine("We", 4);
  WriteLine("Build", 5);
  WriteLine("Cool", 6);
  WriteLine("Shit", 7);
  WriteLine("!!!", 8);
  int d = 5;
  for (int i = 0; i < d; i++)
  {
    ostringstream str1;
    str1 << (i + 1);
    String istr = str1.str().c_str();
    WriteColumn(istr, 9, i, 35);
  }
}