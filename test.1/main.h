#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

std::vector<double> numericVals(std::string& eq);
std::vector<char> operate(std::string& oper);
int bracketCount(std::vector<char>& x);
double bracketSolve(std::vector<double>& x, std::vector<char>& y, int& z, std::string& a);
bool errorCheck(std::string& eq, std::vector<char> op);


#endif // MAIN_H_INCLUDED
