#include <boost/convert.hpp>
#include <boost/convert/strtol.hpp>

struct boost::cnv::by_default : boost::cnv::strtol {};

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    try
    {
        boost::convert<int>(reinterpret_cast<const char*>(data));
    }
    catch(...) { }

    return 0;
}
