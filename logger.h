#ifndef LOGGER
#define LOGGER
#include<string>
#include<fstream>

class logger
{
public:
	logger(std::string);
	~logger();
	void error(std::string &&);
	void info(std::string &&);
private:
	void open();
	void close();
	void pattern_print(std::string &&, std::string &&);
	std::string filename;
	std::ofstream ofs;
};
#endif
