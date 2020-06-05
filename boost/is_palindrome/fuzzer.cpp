#include <boost/algorithm/is_palindrome.hpp>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, const std::size_t size)
{
    try
    {
        boost::algorithm::is_palindrome(reinterpret_cast<const char*>(data));
    }
    catch(...) { }

    return 0;
}
