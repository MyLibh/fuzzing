#include <boost/tokenizer.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, const std::size_t size)
{
    if (!size)
        return 0;
  
    std::string str(reinterpret_cast<const char*>(data), size);
    
    boost::tokenizer<> t(str);
    for (auto&& x : t) 
        auto _ = std::move(x);

    return 0;
}