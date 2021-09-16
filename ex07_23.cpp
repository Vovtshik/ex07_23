/*ex07_23.cpp*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
   const int vertical = 20;
   const int gorizontal = 20;

   int direction = 1;                        //1 - right; 2 - down; 3 - left; 4 - up.
   bool penCondition = 0;
   int location_v = 0;
   int location_g = 0;
   int temp_command = 0;
   int temp_number_steps;
   char temp_powered;

   int floor[gorizontal][vertical] = {0};

   while(temp_command != 9)
   {
      cout << "Enter the command for the turtle (1 - raise the pen; 2 - lower the pen; \n"
	   << "3 - turn right; 4 - turn left; \n"
	   << "5,10 - move forward 10 steps (or another number of steps) \n"
	   << "6 - print a 20x20 array; 9 - end of data (check value - exit)):\n";
      cin >> temp_command;
      if(temp_command == 5)
         cin >> temp_powered >> temp_number_steps;
      switch(temp_command)
      {
         case 1: 
		        penCondition = 0;
		        break;
	     case 2:
		        penCondition = 1;
		        floor[location_g][location_v] = 1;
		        break;
         case 3:
		        if(direction == 4)
		           direction = 1;
		        else
	               direction++;
		        break;
	     case 4:
                if(direction == 1)
		           direction = 4;
		        else
		           direction--;
		        break;
	     case 5:
		        if(direction == 1)
		        {
		           if(temp_number_steps < vertical - location_v)
		           {
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
			                location_v++;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_v++;
		              }
		           }
		           else
		           {
		              temp_number_steps = vertical - location_v - 1;
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
			                location_v++;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_v++;
		              }
		           }
		        }
		        else if(direction == 2)
		        {
		           if(temp_number_steps < gorizontal - location_g)
		           {
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
                            location_g++;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_g++;
		              }
		           }
		           else
		           {
		              temp_number_steps = gorizontal - location_g - 1;
                      for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
			                location_g++;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_g++;
		              }
		           }
		        }
		        else if(direction == 3)
		        {
		           if(temp_number_steps <= location_v)
		           {
		              for(int i = 0; i < temp_number_steps; i++)
	     	          {
			             if(penCondition)
		                 {
		                    location_v--;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_v--;
		              }
		           }
		           else
		           {
		              temp_number_steps = location_v;
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
			                location_v--;
							floor[location_g][location_v] = 1;
			             }
			             else
		                    location_v--;
		              }
		           }
		        }
		        else if(direction == 4)
		        {
		           if(temp_number_steps <= location_g)
		           {
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
                            location_g--;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_g--;
		              }
		           }
		           else
		           {
		              temp_number_steps = location_g;
		              for(int i = 0; i < temp_number_steps; i++)
		              {
		                 if(penCondition)
			             {
		                    location_g--;
							floor[location_g][location_v] = 1;
			             }
			             else
			                location_g--;
		              }
		           }
		        }
		        break;
         case 6: 
                for(int g = 0; g < 20; g++)
		        {
		           for(int v = 0; v < 20; v++)
		           {
		              cout << floor[g][v] << " ";
		           }
		           cout << endl;
		        }
		        break;
	    case 9:
		        break;
	    default:
		        cout << "Input Error! Enter the command from the list of suggestions.\n";
		        break;
      }
   }

   return 0;
}

