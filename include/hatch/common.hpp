#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <istream>
#include <ostream>

namespace Hatch {

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;
using usize = size_t;
using uptr = uintptr_t;
using f32 = float;
using f64 = double;

using magic_t = u32;

template <typename T> constexpr T invalid() {
    return std::numeric_limits<T>::max();
}

inline constexpr u32 make_magic4(const char c0, const char c1, const char c2,
                                 const char c3) {
    return (u32)c0 | (u32)c1 << 8 | (u32)c2 << 16 | (u32)c3 << 24;
}

class StreamReader {
  public:
    StreamReader(std::istream& stream_, u64 offset_ = 0,
                 usize size_ = invalid<usize>())
        : stream{stream_}, offset{offset_}, size{size_} {
        if (size == invalid<usize>()) {
            stream.seekg(0, std::ios::end);
            size = Tell();
        }
        Seek(0);
    }

    StreamReader CreateSubReader(usize new_size = invalid<usize>()) {
        return StreamReader(stream, stream.tellg(),
                            std::min<usize>(new_size, size - Tell()));
    }

    u64 Tell() const { return static_cast<u64>(stream.tellg()) - offset; }
    void Seek(u64 pos) { stream.seekg(offset + pos, std::ios::beg); }

    template <typename T> T Read() {
        T result;
        stream.read(reinterpret_cast<char*>(&result), sizeof(T));

        return result;
    }

    template <typename T> void ReadPtr(T* ptr, usize count) {
        stream.read(reinterpret_cast<char*>(ptr), count * sizeof(T));
    }

    // Getters
    u64 GetOffset() const { return offset; }

    usize GetSize() const { return size; }

  private:
    std::istream& stream;
    u64 offset;
    usize size;
};

class StreamWriter {
  public:
    StreamWriter(std::ostream& stream_, u64 offset_ = 0,
                 usize size_ = invalid<usize>())
        : stream{stream_}, offset{offset_}, size{size_} {
        if (size == invalid<usize>()) {
            stream.seekp(0, std::ios::end);
            size = Tell();
        }
        Seek(0);
    }

    u64 Tell() { return static_cast<u64>(stream.tellp()) - offset; }
    void Seek(u64 pos) { stream.seekp(offset + pos, std::ios::beg); }

    template <typename T> void Write(const T& value) {
        stream.write(reinterpret_cast<const char*>(&value), sizeof(T));
    }

    template <typename T> void WritePtr(const T* write_ptr, usize count) {
        stream.write(reinterpret_cast<const char*>(write_ptr),
                     count * sizeof(T));
    }

    // Getters
    u64 GetOffset() const { return offset; }

    usize GetSize() const { return size; }

  private:
    std::ostream& stream;
    u64 offset;
    usize size;
};

} // namespace Hatch
