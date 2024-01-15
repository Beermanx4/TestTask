#pragma once
#include <vector>
#include <memory>

using uint = unsigned int;

template<typename T>
class IPrinter
{
public:
	virtual void printVal(const T& value) = 0;
};

template<typename T>
void calcSma(const std::vector<T>& data, uint winLen, std::shared_ptr<IPrinter<T>> printer)
{
	if (data.empty() || data.size() < winLen)
		throw std::exception("Not enough data.");

	if (winLen == 0)
		throw std::exception("WinLen cannot be zero.");

	if (printer == nullptr)
		throw std::exception("Printer cannot be nullptr.");

	T prevVal = data[0];
	for (size_t i = 1; i < winLen; i++)
		prevVal += data[i];

	prevVal /= winLen;
	printer->printVal(prevVal);

	for (size_t i = winLen; i < data.size(); i++)
	{
		prevVal += (data[i] - data[i - winLen]) / winLen;
		printer->printVal(prevVal);
	}

}
