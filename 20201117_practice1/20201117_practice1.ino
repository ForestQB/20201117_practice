#include <driver/dac.h>
#include <BluetoothSerial.h>
BluetoothSerial BTYU;
void setup()
{
  dac_output_enable(DAC_CHANNEL_1);//GPIO25
  Serial.begin(115200);
  BTYU.begin("20201113_YU");//記得改名
}
int i = 100;
int X, flag;
void loop()
{
  if (BTYU.available())
  {
    char data = BTYU.read();
    BTYU.println("ESP GET");
    if (data == '1')//light up
    {
      flag = 1;
    }
    else if (data == '2')//light down
    {
      flag = 2;
    }
    else if (data == '3')//light all on
    {
      flag = 3;
    }
    else if (data == '4')//light all off
    {
      flag = 4;
    }
    else if (data == '5')//light change stop
    {
      flag = 5;
    }
  }
  if (flag == 1)
  {
    if (i < 240 && i <= 100)
    {
      i += 5;
      delay(500);
    }
  }
  else if (flag == 2)
  {
    if (i > 100 && i >= 240)
    {
      i -= 5;
      delay(500);
    }
  }
  else if (flag == 3)
  {
    i = 240;
    delay(500);
  }
  else if (flag == 4)
  {
    i = 100;
    delay(500);
  }
  else if (flag == 5)
  {
    i = i;
    delay(500);
  }
  else if (i >= 241)
  {
    i = 240;
    delay(500);
  }
  else if (i <= 101)
  {
    i = 100;
    delay(500);
  }
  dac_output_voltage(DAC_CHANNEL_1, i);

  //  if (BTYU.available())
  //  {
  //    BTYU.println("ESP GET");
  //    char data2 = BTYU.read();
  //    if (data2 == '1')
  //    {
  //      dac_output_voltage(DAC_CHANNEL_1, 150);
  //      BTYU.println("LED 50");
  //    }
  //    else if (data2 == '2')
  //    {
  //      dac_output_voltage(DAC_CHANNEL_1, 170);
  //      BTYU.println("LED 100");
  //    }
  //    else if (data2 == '3')
  //    {
  //      dac_output_voltage(DAC_CHANNEL_1, 190);
  //      BTYU.println("LED 150");
  //    }
  //    else if (data2 == '4')
  //    {
  //      dac_output_voltage(DAC_CHANNEL_1, 225);
  //      BTYU.println("LED 225");
  //    }
  //  }
  //  delay(1000);
}
