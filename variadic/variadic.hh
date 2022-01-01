#ifndef VARIADIC_HH
#define VARIADIC_HH

#include <string>

// This was added to put type on a variable.
// Seems a lot of code for this. But at the same time a nice quirk.
// Idea from Practical heuristics to improve precision for erroneous function
// argument swapping detection in C and C++
struct Index
{
public:
    explicit Index(size_t v)
        : value(v)
    {
    }
    explicit operator size_t() const
    {
        return value;
    }
    auto operator()() const -> size_t
    {
        return value;
    }
    size_t value; // NOLINT
};


struct Span
{
public:
    explicit Span(size_t v)
        : value(v)
    {
    }
    explicit operator size_t() const
    {
        return value;
    }
    auto operator()() const -> size_t
    {
        return value;
    }
    size_t value; // NOLINT
};


struct Width
{
public:
    explicit Width(std::string str)
        : value(std::move(str))
    {
    }
    explicit operator std::string() const
    {
        return value;
    }
    auto operator()() const -> std::string
    {
        return value;
    }
    std::string value; // NOLINT
};


struct Hidden
{
public:
    explicit Hidden(bool b)
        : value(b)
    {
    }
    explicit operator bool() const
    {
        return value;
    }
    auto operator()() const -> bool
    {
        return value;
    }
    bool value; // NOLINT
};

class tab
{
public:
    explicit tab(std::ostream& out, const std::string& tab_name);
    explicit tab(std::ostream& out, const std::string& tab_name, bool frozen);
    ~tab();
    tab() = delete;                               ///< Need ostream
    tab(tab&&) = delete;                          ///< No move contructor.
    tab(const tab& other) = delete;               ///< No copy constructor.
    auto operator=(tab& other) -> tab& = delete;  ///< No copy assignment.
    auto operator=(tab&& other) -> tab& = delete; ///< No move assignment.

    template <typename T, typename... Types>
    void Column(T var1, Types... var2);
    void Column();

private:
    std::ostream& output;
    bool frozen;
    void handle(Hidden value);
    void handle(const Width& value);
    void handle(Index value);
    void handle(Span value);

    bool got_hidden;
    bool got_width;
    bool got_index;
    bool got_span;

    bool hidden;
    std::string width;
    size_t index;
    size_t span;
};


/**
 * @brief Variadic template for Column.
 * Rest of the function is in variadic.cc. However this template
 * must be local the translation unit.
 *
 * Does this violate ODR?
 *
 * @tparam T
 * @tparam Types
 * @param var1 handle with defined types.
 * @param var2
 */
template <typename T, typename... Types>
void tab::Column(T var1, Types... var2)
{
    handle(var1);
    Column(var2...);
}

#endif
