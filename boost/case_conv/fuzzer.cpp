#include <boost/algorithm/string/case_conv.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    if(!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        boost::algorithm::to_lower(str);
        boost::algorithm::to_upper(str);
    }
    catch(...) { }

    return 0;
}
