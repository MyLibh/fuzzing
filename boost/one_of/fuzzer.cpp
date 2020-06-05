#include <boost/algorithm/cxx11/one_of.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);
    
    try
    {
        boost::algorithm::one_of(std::begin(str), std::end(str), [] (const auto& x) { return x == 0xDEADBEAF; });
        boost::algorithm::one_of_equal(std::begin(str), std::end(str), 0xFF);
    }
    catch(...) { }
    
    return 0;
}