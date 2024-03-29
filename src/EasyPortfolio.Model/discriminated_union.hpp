#ifndef DISCRIMINATED_UNION_HPP
#define DISCRIMINATED_UNION_HPP

#include <cassert>

// Declaring the discriminated union
// from http://blogs.msdn.com/b/jaredpar/archive/2010/11/18/discriminated-unions-in-c.aspx

#define DU_DECLARE(name)						\
    struct name {                               \
    private:                                    \
        name() {}                               \
        unsigned int m_kind;					\
    public:

#define DECLARE_DU_WITH_NONE(name)							\
    struct name {                                           \
    private:                                                \
        unsigned int m_kind;								\
    public:                                                 \
        name() : m_kind(__LINE__) {}                        \
        bool IsNone() const {return m_kind == __LINE__;}

#define DU_VALUE(unionName, entryName, entryType)															\
        static unionName entryName(const entryType& value) {												\
            unionName unionValue;                                                                           \
            unionValue.m_kind = __LINE__;                                                                   \
            unionValue.m_##entryName = value;                                                               \
            return unionValue;  }                                                                           \
        bool Is##entryName() const { return m_kind == __LINE__;}                                            \
        const entryType& Get##entryName() const { assert(m_kind == __LINE__); return m_##entryName; }       \
        entryType Get##entryName() { assert(m_kind == __LINE__); return m_##entryName; }                    \
    private:                                                                                                \
        entryType m_##entryName;                                                                            \
    public:

#define DU_POINTER(unionName, entryName, entryType)															\
        static unionName entryName(entryType* value) {														\
            unionName unionValue;                                                                           \
            unionValue.m_kind = __LINE__;                                                                   \
            unionValue.m_##entryName = value;                                                               \
            return unionValue;  }                                                                           \
        bool Is##entryName() const { return m_kind == __LINE__;}                                            \
        entryType* Get##entryName() const { assert(m_kind == __LINE__); return m_##entryName; }             \
        entryType* Get##entryName() { assert(m_kind == __LINE__); return m_##entryName; }                   \
    private:                                                                                                \
        entryType* m_##entryName;                                                                           \
    public:

#define DU_FLAG(unionName, entryName)																		\
        static unionName entryName() {																		\
            unionName unionValue;                                                                           \
            unionValue.m_kind = __LINE__;                                                                   \
            return unionValue;  }                                                                           \
        bool Is##entryName() const { return m_kind == __LINE__;}                                            

#define DU_GET_KIND() unsigned int GetKind() const { return m_kind; }

#define DU_END() };

// Defining match-like syntax
#define DU_MATCH(unionName) if(false) {}

#define DU_CASE_TAG(unionName, entry, ...)			\
	else if(unionName.Is##entry()) {				\
		__VA_ARGS__									\
	}

#define DU_CASE(unionName, entry, ...)				\
	else if(unionName.Is##entry()) {				\
		auto value = unionName.Get##entry();		\
		__VA_ARGS__									\
	}
#define DU_DEFAULT(...)								\
	else { __VA_ARGS__}

#endif