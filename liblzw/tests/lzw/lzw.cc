#include "lzw/lzw.hh"
#include "foreign/catch.hpp"

#include <iostream>

TEST_CASE("example usage") {
}

TEST_CASE("example encoding") {
    lzw::Word words[] { 'b', 'b', 'b', 'b', 'a', 'a', 'b', 'b', 'b', 'a', 'a', 'a', 'a', 'a',
                        'b', 'b', 'b', 'b', 'b', 'a', 'b', 'a', 'a', 'a', 'b', 'b', 'b', 'b' };

    lzw::DictionaryData dictionary_data;
    lzw::CodeBufferData code_buffer_data;
    lzw::CodeBuffer code_buffer { code_buffer_data };
    lzw::Dictionary dictionary { dictionary_data };
    lzw::Encoder encoder { dictionary };

    std::cout << "Example encoding: ";
    for (std::size_t i { 0 }; i < sizeof(words) / sizeof(lzw::Word); ++i) {
        if (encoder.step(words[i], code_buffer)) {
            lzw::Code code { code_buffer.read() };
            code_buffer.reset(); // For more data!
            std::cout << code << ' ';
        }
    }

    if (encoder.finish(code_buffer)) {
        lzw::Code code { code_buffer.read() };
        std::cout << code << std::endl;
    }
}

TEST_CASE("example decoding") {
    lzw::Code codes[] { 98, 256, 98, 97, 97, 257, 259,
                       262, 257, 256, 260, 263, 257 };

    lzw::DictionaryData dictionary_data;
    lzw::WordBufferData word_buffer_data;
    lzw::WordBuffer word_buffer { word_buffer_data };
    lzw::Dictionary dictionary { dictionary_data };
    lzw::Decoder decoder { dictionary };

    std::cout << "Example decoding: ";
    for (std::size_t i { 0 }; i < sizeof(codes) / sizeof(lzw::Code); ++i) {
        std::size_t words { decoder.step(codes[i], word_buffer) };
        while (words > 0) {
            lzw::Word word { word_buffer.read() };
            std::cout << word;
            words -= 1;
        } std::cout << ' ';
        word_buffer.reset();
    }

    std::cout << std::endl;
}
