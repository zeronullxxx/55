#define STACK_SIZE 10
#include <cmath> 
#include <iostream> 
using namespace std;

template <class T>

class Stack
{
public:

    bool is_empty() {
        if (_top == -1)
            return 1;
        else
            return 0;
    }

    bool is_full() {
        return _top == STACK_SIZE - 1;
    }

    void push(T value) {
        if (!is_full())
            _arr[++_top] = value;
        cout << "push " << value << ": work" << endl;
    }

    void pop() {
        if (!is_empty())
            cout << _arr[_top--] << endl;
        else
            throw exception("Empty stack");
    }

    T peek() {
        if (!is_empty()) {
            cout << "peek: ";
            return _arr[_top];
        }
        else {
            throw exception("Empty stack");
        }
    }

    void clear() {
        _top = -1;
        cout << "clear: work" << endl;
    }

    void get_count() {
        cout << _top + 1 << endl;
        cout << "get_count: work" << endl;
    }



private:
    T _arr[STACK_SIZE];
    int _top = -1;

};

double heron(double a, double b, double c) {
    double p = (a + b + c) / 2;
    if ((a <= 0) || (b <= 0) || (c <= 0))
    {
        throw exception("side < 0");
    }
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int convert_to_sec(int hours) {
    if (hours < 0)
    {
        throw exception("time < 0");
    }
    return hours * 60 * 60;
}
int convert_to_sec(int hours, int min) {
    if ((hours || min) < 0)
    {
        throw exception("time < 0");
    }
    return convert_to_sec(hours) + min * 60;
}
bool palindrome_check(const char* word) {
    for (int i = 0; i < sizeof(word) - 1; i++)
    {
        if ((word[i] >= 0) && (word[i] <= 9))
        {

            throw exception("number in text!");
        }
    }

    for (int i = 0; i < (sizeof(word) - 1) / 2;)
    {
        for (int j = sizeof(word) + 1; j > (sizeof(word) - 1) / 2; j--)
        {
            if (word[i] != word[j])
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int main() {
    try {

        cout << heron(2, -5, -1) << endl;


    }
    catch (exception& error) {
        cout << error.what() << endl;
    }

    try
    {
        cout << convert_to_sec(-21) << endl;
    }
    catch (exception& error) {
        cout << error.what() << endl;
    }

    try
    {
        cout << convert_to_sec(-1, -1) << endl;
    }
    catch (exception& error) {
        cout << error.what() << endl;
    }

    try {
        cout << palindrome_check("asddsa");
    }
    catch (exception& error) {
        cout << error.what() << endl;
    }


}