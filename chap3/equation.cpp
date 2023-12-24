/*
求一个可能包含加、减、乘、除、乘方运算的中缀表达式的值。

在计算机中，我们常用栈来解决这一问题。首先将中缀表达式转换到后缀表达式，然后对后缀表达式求值。

加、减、乘、除、乘方分别用+，-，*, /, ^来表示。表达式可以有圆括号()。

输入
第一行为测试数据的组数N。
接下来的N行，每行是一个中缀表达式。

每个表达式中，圆括号、运算符和运算数相互之间都用空格分隔，运算数是整数。一般运算数可正可负（负数的符号和数字之间无空格），指数一定为自然数(0和正整数)。不必考虑除0的情况。每个运算数均可由int放下。不必考虑溢出。中缀表达式的字符串长度不超过600。乘方的优先级比乘除都高，结合性是向左结合，如2 ^ 3 ^ 4表示( 2 ^ 3 ) ^ 4 = 4096。除法的商向下取整。
输出
对每一组测试数据输出一行，为表达式的值
样例输入
2
31 * ( 5 - ( -3 + 25 ) ) + 70 ^ 2
2 * 5 + 6 * ( 7 - 8 ) + 6
样例输出
4373
10

*/



#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <cctype>
#include <cmath>

// 定义运算符的优先级
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;  // 默认优先级为0，用于括号
}

// 将中缀表达式转换为后缀表达式
std::vector<std::string> infixToPostfix(const std::string& infix) {
    std::vector<std::string> postfix;
    std::stack<char> operatorStack;
    std::istringstream iss(infix);

    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            postfix.push_back(token);
        } else if (token == "(") {
            operatorStack.push('(');
        } else if (token == ")") {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix.push_back(std::string(1, operatorStack.top()));
                operatorStack.pop();
            }
            operatorStack.pop();  // 弹出左括号
        } else {
            while (!operatorStack.empty() &&
                   getPrecedence(operatorStack.top()) >= getPrecedence(token[0])) {
                postfix.push_back(std::string(1, operatorStack.top()));
                operatorStack.pop();
            }
            operatorStack.push(token[0]);
        }
    }

    while (!operatorStack.empty()) {
        postfix.push_back(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }

    return postfix;
}

// 计算后缀表达式的值
int evaluatePostfix(const std::vector<std::string>& postfix) {
    std::stack<int> operandStack;

    for (const std::string& token : postfix) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            operandStack.push(std::stoi(token));
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (token[0]) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(static_cast<int>(std::pow(operand1, operand2)));
                    break;
            }
        }
    }

    return operandStack.top();
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();  // Clear the newline character

    for (int i = 0; i < N; ++i) {
        std::string infixExpression;
        std::getline(std::cin, infixExpression);
        
        std::vector<std::string> postfix = infixToPostfix(infixExpression);
        int result = evaluatePostfix(postfix);

        std::cout << result << std::endl;
    }

    return 0;
}
