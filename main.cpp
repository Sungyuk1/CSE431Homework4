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

    vector<vector<unsigned long long>> inputs;

    for (int i = 0; i<num; i++) {
        cin>>starting_num>>ending_num;
        vector<unsigned long long> input;
        input.push_back(starting_num);
        input.push_back(ending_num);
        inputs.push_back(input);
    }

    for (int i = 0; i<num; i++) {

        if(i == 63){
            int debg = 0;
        }
        //cin>>starting_num>>ending_num;
        starting_num = inputs[i][0];
        ending_num = inputs[i][1];

        if(starting_num == ending_num){
            cout<<"0"<<endl;
        }else{
            //vector<unsigned long long> power_2_stack;

            unsigned long long current_power_2 = 1;

            int overflow2 = false;
            while(!overflow2 && current_power_2 <= starting_num){
                if(ULLONG_MAX - current_power_2 > current_power_2){
                    current_power_2 = current_power_2 <<1;
                }else{
                    overflow2 = true;
                }
            }
            if(!overflow2){
                current_power_2 = current_power_2 >> 1;
            }
            int step_count = 0;
            while(starting_num > ending_num){
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
