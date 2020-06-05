#include <boost/algorithm/string/trim.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    if(!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        boost::algorithm::trim_right(str);
    }
    catch(...) { }

    return 0;
}
