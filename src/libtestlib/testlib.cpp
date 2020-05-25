#include <testlib.h>
#include <log.h>

#include <boost/python.hpp>

namespace {

LoggerInitializer gLoggerInitializer;

} // anonymous namespace

namespace testlib {

std::string do_stuff(const std::string& param)
{
	spdlog::debug("do_stuff: {}", param);

	return param + "_do_stuff";
}

const char* greet() {
	return "Hello, world!";
}

using namespace boost::python;

BOOST_PYTHON_MODULE(libtestlib) {

	def("do_stuff", testlib::do_stuff);
	def("greet", testlib::greet);

	class_<Widget>("Widget")
		.def("getStringData", &Widget::getStringData)
		.def("setStringData", &Widget::setStringData)
	;
}

} // namespace testlib
