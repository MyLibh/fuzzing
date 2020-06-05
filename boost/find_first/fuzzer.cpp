#include <boost/algorithm/string/find.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        auto r1 = boost::algorithm::find_first(str, "aaaa");
    }
    catch(...) { }
    
    return 0;
}