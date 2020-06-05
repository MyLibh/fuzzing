#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <string>
#include <vector>
#include <cctype>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    if(!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        std::vector<std::string> seq;
        boost::algorithm::split(seq, str, boost::algorithm::is_any_of("+-^"), boost::token_compress_on);
    }
    catch(...) { }

    return 0;
}
