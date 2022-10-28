#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int main()
{
    int num; // Number of inputs

    std::cin >> num;

    //vector<int> inputs;

    unsigned long long starting_num;
    unsigned long long ending_num;

    for (int i = 0; i<num; i++) {

        cin>>starting_num>>ending_num;

        if(starting_num == ending_num){
            cout<<"0"<<endl;
        }else{
            //vector<unsigned long long> power_2_stack;

            unsigned long long current_power_2 = 1;
            //power_2_stack.push_back(current_power_2);

            //int count = 0;
            while(current_power_2 <= starting_num){
                //current_power_2 = pow(2,count);
                current_power_2 = current_power_2 <<1;

                //if(current_power_2 <= starting_num){
                  //  power_2_stack.push_back(current_power_2);
                    //count++;
                //}
            }
            current_power_2 = current_power_2 >> 1;
            int step_count = 0;
            while(starting_num > ending_num){
                //unsigned long long value = power_2_stack[power_2_stack.size()-1];
                //power_2_stack.pop_back();
                //be careful of overflow here if u choose to use unsigned
                bool underflowcheck = (ULLONG_MAX - current_power_2 >= ULLONG_MAX - starting_num) ;// `a - x` would overflow
                if(underflowcheck && starting_num - current_power_2 >= ending_num){
                    starting_num = starting_num - current_power_2;
                    step_count++;
                }
                current_power_2 = current_power_2>>1;
            }

            if(starting_num == ending_num){
                cout<<step_count<<endl;
            }

        }





    }
}
