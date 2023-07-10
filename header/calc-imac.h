// something need to figure out
//
//
//https://www.codewars.com/kata/52a78825cdfc2cfc87000005/train/cpp


#include <string>
#include <vector>
using namespace std;

double calc(std::string expression) {
    std::string target;
    for (size_t i = 0; i < expression.size(); i ++) {
        if (expression[i] != ' ')
        {
            target += expression[i];
        }
    }
    expression = target;

    int value = 0;
    vector<double>nums;
    int left_bracket = 0;
    string left_bracket_str;
    for (size_t i = 0; i < expression.size(); i ++)
    {
        switch (expression[i]) {

            case '(':
                left_bracket ++;
                for (size_t j = i; j < expression.size(); j ++)
                {
                    switch (expression[j])
                    {
                        case '(':
                            left_bracket ++;
                        case ')':
                            if (--left_bracket == 0)
                                 return calc(expression.substr(0, i) ) +calc(expression.substr(i, j-i)) + calc(expression.substr(j));

                    }
                }
                break;
            case ')':
                break;
            case '*':

                break;
            case '/':
                break;
            case '+':

                break;
            case '-':
                break;
            default:
//                cout << expression[i] << ":" <<  expression[i] - '0' << endl;

                nums.push_back((expression[i] - '0'));
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << "nums:" << nums[i] << endl;

    }
    return 0;
}

// define a function that can calc number of
double calc_number(double left, double right, char op) {
    switch(op) {
        case '*':
            return left*right;
            break;
        case '/':

        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
    }

    return 0;
}
double calc_str(std::string ss) {
    

    // 3 + 5 * 2 * 3
    for (size_t i = 0; i < ss.size(); i++) {
        switch (ss[i]) {
            case '*':
                // multi two num into one.

            case '/':
            case '+':
                string left ;
                left = (1, ss[0]);
                string right = ss.substr(i)  ;
                return calc_str(left) + calc_str(right);
            case '-':
                return 0;
        }
    }
    return 0;
}
// how to calc 3 num that * at the end of this string
// if string contain a plus and multi. how can I multi fist.
// this give me an answer that I should come fist cal * and / first

// return switch-case(*) that operate left and right.
// if meet * return left num and right string of func.

// input is string, output is double;
