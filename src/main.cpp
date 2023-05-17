#include <stdio.h>
#include "pico/stdlib.h"
#include "ros.h"

ros::NodeHandle nh;

int main()
{
       stdio_init_all();

       nh.initNode();

       while (true)
       {
              nh.spinOnce();
       }
}
