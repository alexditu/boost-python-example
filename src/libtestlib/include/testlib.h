#ifndef __TEST_LIB_H_INCLUDED__
#define __TEST_LIB_H_INCLUDED__

#include <string>

namespace testlib {

std::string do_stuff(const std::string& param);

class Widget {
public:
	Widget() {}
	Widget(const std::string& stringData)
		: stringData_ {stringData}
	{
	}

	std::string getStringData() const {
		return stringData_;
	}

	void setStringData(const std::string& data) {
		stringData_ = data;
	}

private:
	std::string stringData_;
};

} // namespace testlib

#endif // __TEST_LIB_H_INCLUDED__
