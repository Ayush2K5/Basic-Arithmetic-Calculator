#include <vector>
#include <string>
#include <cmath>
#include <iostream>



bool errorCheck(std::string& eq, std::vector<char> op)
{
    bool x{true};
    int counter{0};

    for(int i{0}; i < eq.size();++i)
        {
            if(eq[i] == '(' && eq[i-1] >= '0' && eq[i-1] <= '9')
            {
                ++counter;
                std::cout << " Error-" << counter << ": Was expecting an operator before the bracket! \n";
                std::cout << "          ..." << eq[i-2] <<  eq[i-1] << eq[i] << eq[i+1] << eq[i+2] << "... \n";
                x = false;
            }

            if(eq[i] < '0' || eq[i] > '9')
            {
                if(eq[i] != '+' && eq[i] != '-' && eq[i] != '*' && eq[i] != '/' && eq[i] != '^' && eq[i] != ')' && eq[i] != '(')
                {
                    ++counter;
                    std::cout << " Error-" << counter << ": Encountered an undefined character! Please use chars b/w 0-9 & specified operators only! \n";
                    std::cout << "          ..." <<eq[i-2] <<  eq[i-1] << eq[i] << eq[i+1] << eq[i+2] << "... \n";
                    x=false;
                }
            }

            if(eq[i] == ')' && eq[i+1] >= '0' && eq[i+1] <= '9')
            {
                ++counter;
                std::cout << " Error-" << counter << ": Was expecting an operator after the bracket! \n";
                std::cout << "          ..." << eq[i-2] <<  eq[i-1] << eq[i] << eq[i+1] << eq[i+2] << "... \n";
                x = false;
            }

            if(eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/' || eq[i] == '^')

            {
                if(eq[i-1] == '+' && eq[i-1] == '-' && eq[i-1] == '*' && eq[i-1] == '/' && eq[i-1] == '^')
                {
                    ++counter;
                    std::cout << " Error-" << counter << ": Invalid use of consecutive signs in the expression  \n";
                    std::cout << "          ..." << eq[i-2] <<  eq[i-1] << eq[i] << eq[i+1] << eq[i+2] << "... \n";
                    x = false;
                }
            }

        }



    return x;

}




std::vector<double> numericVals(std::string& eq)
{
    std::vector<double> values;


    for (int i{0}; i < eq.length(); ++i)
    {
        int count{0};

        if (eq[i] >= '0' && eq[i] <= '9')
        {
            if (i != eq.length() - 1)
            {
                for (int j{i + 1}; j < eq.length(); ++j)
                {
                    if (eq[j] >= '0' && eq[j] <= '9')
                    {
                        ++count;
                    } else {
                        break;
                    }
                }
            }

            int val{0};
            int power{count};
            for (int k{0}; k <= count; ++k)
            {
                val += (eq[i + k] - '0') * std::pow(10, power);
                --power;
            }

            if(eq[0] == '-' && i==1)
            {
                val = -1 * val;
                eq.erase(eq.begin());
            }

            else if(eq[i-1] == '-' && eq[i-2] == '(' && i > 1)
            {
                val = -1 * val;
                eq.erase(eq.begin()+(i-1));
            }


            values.push_back(val);

            i += count;


        }
        else
        {
            continue;
        }
    }

    return values;
}


std::vector<char> operate(std::string& oper)
{
    std::vector<char> x{};

    for(int i{0}; i < oper.length(); ++i)
    {
        if(oper[i] == '+' || oper[i] == '-' || oper[i] == '*' || oper[i] == '/' || oper[i] == '^' || oper[i] == '!' || oper[i] == '(' || oper[i] == ')')
        {
            x.push_back(oper[i]);
        }
    }

    return x;
}
