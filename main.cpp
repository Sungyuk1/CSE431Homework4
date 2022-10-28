#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int num; // Number of inputs

    std::cin >> num;

    vector<int> inputs;

    for (int i = 0; i<num; i++) {
        long long starting_num;
        long long ending_num;

        cin>>starting_num>>ending_num;

        if(starting_num == ending_num){
            cout<<"0"<<endl;
        }else{
            vector<int> power_2_stack;

            long long current_power_2 = 1;
            power_2_stack.push_back(current_power_2);

            //int count = 0;
            while(current_power_2 <= starting_num){
                //current_power_2 = pow(2,count);
                current_power_2 = current_power_2 <<1;
                if(current_power_2 <= starting_num){
                    power_2_stack.push_back(current_power_2);
                    //count++;
                }
            }
            int step_count = 0;
            while(starting_num > ending_num){
                int value = power_2_stack[power_2_stack.size()-1];
                power_2_stack.pop_back();
                if(starting_num - value >= ending_num){
                    starting_num = starting_num - value;
                    step_count++;
                }
            }

            if(starting_num == ending_num){
                cout<<step_count<<endl;
            }

        }





    }
}
