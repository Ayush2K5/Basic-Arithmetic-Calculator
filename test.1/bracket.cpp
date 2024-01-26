#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int bracketCount(std::vector<char>& x) //will count number of brackets
{
    int counter{0};

    for(int i{0}; i < x.size(); ++i)
        {

                if(x[i] == '(')
                {
                    ++counter;
                }
        }

    return counter;

}

double bracketSolve(std::vector<double>& x, std::vector<char>& y, int& z, std::string& a) //will solve the entire eq
{
    if(z > 0) //only if there are bracket
    {



        for(int i{0}; i < z; ++i)
        {


            int open{0}; //bracket open index
            int close{0};//bracket close index
            int counter{0};// counter+1 = index of first number in bracket


            for(int i{0}; i < y.size(); ++i)
                {
                    if(y[i] == '(')
                    {
                        open = i;
                    }

                    else if(y[i] == ')')
                    {
                        close = i;
                        break;
                    }
                }


            for(int i{0}; i <= open; ++i)
                {
                    if(y[i] == '+' || y[i] == '-' || y[i] == '*' || y[i] == '/' || y[i] == '^')
                    {
                        ++counter;
                    }


                    if(y[i] == '(')
                    {
                        if(y[i-1] == '+' || y[i-1] == '-' || y[i-1] == '*' || y[i-1] == '/' || y[i-1] == '^' || y[i-1] == y[i] && i > 0)
                        {
                            --counter;
                        }
                    }
                }
            int start{counter};

            for(int i{open}; i < close; ++i)
                {
                    if(y[i] == '^')
                    {
                        x[start] = std::pow(x[start],x[start+1]);

                        x.erase(x.begin()+(start+1));
                        y.erase(y.begin()+i);
                        --i;
                    }

                    ++start;
                }

            start = counter;

            for(int i{open}; i < close; ++i)
                {
                    if(y[i] == '/')
                    {
                        x[start] = x[start]/x[start+1];

                        x.erase(x.begin()+(start+1));
                        y.erase(y.begin()+i);
                        --i;
                    }


                    ++start;
                }

            start = counter;

            for(int i{open}; i < close; ++i)
                {
                    if(y[i] == '*')
                    {
                        x[start] = x[start]*x[start+1];

                        x.erase(x.begin()+(start+1));
                        y.erase(y.begin()+i);
                        --i;
                    }

                    ++start;
                }

            start = counter;


            for(int i{open}; i < close; ++i)
                {
                    if(y[i] == '+')
                    {
                        x[start] = x[start]+x[start+1];

                        x.erase(x.begin()+(start+1));
                        y.erase(y.begin()+i);
                        --i;
                    }


                    else if(y[i] == '-')
                    {
                        x[start] = x[start]-x[start+1];

                        x.erase(x.begin()+(start+1));
                        y.erase(y.begin()+i);
                        --i;
                    }

                    ++start;
                }
            y.erase(y.begin()+close);
            y.erase(y.begin()+open);

        } //bracket solved
    }

        for(int i{0}; i < y.size(); ++i)
        {
            if(y[i] == '^')
            {
                x[i] = std::pow(x[i],x[i+1]);
                x.erase(x.begin()+(i+1));
                y.erase(y.begin()+i);
                --i;

            }
        }



        for(int i{0}; i < y.size(); ++i)
        {
            if(y[i] == '/')
            {
                x[i] = x[i]/x[i+1];
                x.erase(x.begin()+(i+1));
                y.erase(y.begin()+i);
                --i;

            }
        }


        for(int i{0}; i < y.size(); ++i)
        {
            if(y[i] == '*')
            {
                x[i] = x[i]*x[i+1];
                x.erase(x.begin()+(i+1));
                y.erase(y.begin()+i);
                --i;

            }
        }


        for(int i{0}; i < y.size(); ++i)
        {
            if(y[i] == '+')
            {
                x[i] = x[i]+x[i+1];
                x.erase(x.begin()+(i+1));
                y.erase(y.begin()+i);
                --i;

            }
        }

        for(int i{0}; i < y.size(); ++i)
        {
            if(y[i] == '-')
            {
                x[i] = x[i]-x[i+1];
                x.erase(x.begin()+(i+1));
                y.erase(y.begin()+i);
                --i;

            }
        }

        return x[0];


}

