#include <iostream>

class Calculator
{
public:
	Calculator()
	{
	}

	Calculator(float startValue)
	{
		memory = startValue;
	}

	Calculator& calculate(char op, float value2)
	{
		if (op == '+')
		{
			memory = memory + value2;
		}
		if (op == '-')
		{
			memory = memory - value2;
		}
		if (op == '*')
		{
			memory = memory * value2;
		}
		if (op == '/')
		{
			if (!value2)
			{
				std::cout << "You cannot divide by 0\n";
				return *this;
			}
			memory = memory / value2;
		}
		return *this;
	}

	float getCurrentValue() const
	{
		return memory;
	}

	void setStartValue(float start)
	{
		memory = start;
	}

	static float calculate(float value1, float value2, char op)
	{
		float result = 0;
		if (op == '+')
		{
			result = value1 + value2;
		}
		if (op == '-')
		{
			result = value1 - value2;
		}
		if (op == '*')
		{
			result = value1 * value2;
		}
		if (op == '/')
		{
			if (!value2)
			{
				std::cout << "You cannot divide by 0\n";
				return 0;
			}
			result = value1 / value2;
		}
		return result;
	}

	Calculator& operator+(int value)
	{
		memory += value;
		return *this;
	}

	Calculator& operator-(int value)
	{
		memory -= value;
		return *this;
	}

	Calculator& operator*(int value)
	{
		memory *= value;
		return *this;
	}

	Calculator& operator/(int value)
	{
		if (!value)
		{
			std::cout << "You cannot divide by 0\n";
			return *this;
		}
		memory /= value;
		return *this;
	}

	Calculator& operator+=(int value)
	{
		memory += value;
		return *this;
	}

	Calculator& operator-=(int value)
	{
		memory -= value;
		return *this;
	}

	Calculator& operator*=(int value)
	{
		memory *= value;
		return *this;
	}

	Calculator& operator/=(int value)
	{
		if (!value)
		{
			std::cout << "You cannot divide by 0\n";
			return *this;
		}
		memory /= value;
		return *this;
	}

private:
	float memory = 0;
};

int main()
{
	Calculator calc0;

	std::cout << "Default constructor:\n";
	std::cout << "0 + 5 = " << calc0.calculate('+', 5).getCurrentValue() << "\n";
	std::cout << "5 * 3 = " << calc0.calculate('*', 3).getCurrentValue() << "\n";

	Calculator calc1 = 10;

	std::cout << "Constructor with start value 10:\n";
	std::cout << "10 - 10 = " << calc1.calculate('-', 10).getCurrentValue() << "\n";
	std::cout << "0 + 7 = " << calc1.calculate('+', 7).getCurrentValue() << "\n";

	Calculator calc2(100);

	std::cout << "Constructor with start value 100:\n";
	std::cout << "100 / 4 = " << calc2.calculate('/', 4).getCurrentValue() << "\n";

	Calculator calcChain;

	std::cout << "Chain:\n";
	std::cout << "((0 + 2) - 4) * 5 = "
		<< calcChain.calculate('+', 2).calculate('-', 4).calculate('*', 5).getCurrentValue()
		<< "\n";

	std::cout << "Static method (no object needed):\n";
	std::cout << "10 + 10 = " << Calculator::calculate(10, 10, '+') << "\n";

	Calculator calcOp;
	std::cout << "Operator overload:\n";
	std::cout << "0 + 5 = " << (calcOp + 5).getCurrentValue() << "\n";
	std::cout << "5 - 3 = " << (calcOp - 3).getCurrentValue() << "\n";
	std::cout << "2 * 2 = " << (calcOp * 2).getCurrentValue() << "\n";
	std::cout << "4 / 2 = " << (calcOp / 2).getCurrentValue() << "\n";

	calcOp += 5;
	std::cout << "2 += 5 = " << calcOp.getCurrentValue() << "\n";
	calcOp -= 3;
	std::cout << "7 -= 3 = " << calcOp.getCurrentValue() << "\n";
	calcOp *= 2;
	std::cout << "4 *= 2 = " << calcOp.getCurrentValue() << "\n";
	calcOp /= 2;
	std::cout << "8 /= 2 = " << calcOp.getCurrentValue() << "\n";
	calcOp /= 0;
	std::cout << "4 /= 0 = " << calcOp.getCurrentValue() << "\n";

	Calculator calc3;

	float startValue;
	std::cout << "Enter start value: ";
	std::cin >> startValue;
	calc3.setStartValue(startValue);

	std::cout << "Memory: " << startValue << "\n";
	std::cout << "Enter operations, or q to quit:\n";

	char operation;
	float value;
	while (std::cin >> operation)
	{
		if (operation == 'q')
		{
			break;
		}

		std::cin >> value;
		std::cout << "= " << calc3.calculate(operation, value).getCurrentValue() << "\n";
	}

	return 0;
}
