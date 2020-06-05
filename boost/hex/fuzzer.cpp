#include <boost/algorithm/hex.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;

    std::string out;
    try
    {
        auto r1 = boost::algorithm::hex(reinterpret_cast<const char*>(data), boost::begin(out));
    }
    catch(...) { }
    
    return 0;
}