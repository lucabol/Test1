#ifndef RECORD_HPP
#define RECORD_HPP

    // Helpers for functional types, i.e. records, tuples, variant, option
    #ifdef __cplusplus
        #define RECORD(Record)                                                                       \
               bool operator==(Record& other) const {                                          \
                      static_assert(std::is_trivial<Record>::value, "Not trivially copyable");       \
                      return memcmp(this, &other, sizeof(Record)) == 0;}                             \
               bool operator!=(Record& other) const { return !(*this == other);}
    #else
        #define RECORD(Record)
    #endif

#endif // guard