#include <boost/algorithm/string/replace.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        boost::algorithm::replace_first(str, "aaaaaa", "bbbbbb");
        boost::algorithm::replace_last(str, "bb", "aa");
    }
    catch(...) { }
    
    return 0;
}