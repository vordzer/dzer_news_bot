#include"logger.h"
#include<ctime>
#include<iomanip>

logger::logger(std::string fname) :filename(fname), ofs(fname.data(), std::fstream::app)
{
}
logger::~logger()
{
	close();
}

void logger::open()
{
	ofs.open(filename.data(), std::fstream::app);
}

void logger::close()
{
	ofs.close();
}

void logger::error(std::string &&msg)
{
	pattern_print(std::move(msg), "error");
}

void logger::info(std::string &&msg)
{
	pattern_print(std::move(msg), "info");
}

void logger::pattern_print(std::string &&msg, std::string &&lvl)
{
	time_t t;
	struct tm * ltm;
	std::time(&t);
	ltm = std::localtime ( &t );
	ofs.fill('0');
	ofs << "[" << std::setw(2) << ltm->tm_mday << "-" << std::setw(2) << ltm->tm_mon
			<< "-" << ltm->tm_year + 1900 << " " << std::setw(2) << ltm->tm_hour << ":"
			<< std::setw(2) << ltm->tm_min << ":" << std::setw(2) << ltm->tm_sec << "]"
			<< " " << lvl << ": "<< msg << std::endl;
}
