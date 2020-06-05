#include <boost/algorithm/gather.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        boost::algorithm::gather(std::begin(str), std::end(str), std::begin(str) + str.size() / 2, [](const auto& x) { return std::isalpha(x); });
    }
    catch(...) { }
    
    return 0;
}