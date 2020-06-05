#include <boost/lexical_cast.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    if(!size)
        return 0;

    std::string str(reinterpret_cast<const char*>(data), size);

    try
    {
        auto r1{ boost::lexical_cast<int>(str) };
        auto r2{ boost::lexical_cast<double>(str) };

        auto s1{ boost::lexical_cast<std::string>(r1) };
        auto s2{ boost::lexical_cast<std::string>(r2) };
    }
    catch(...) { }

    return 0;
}
