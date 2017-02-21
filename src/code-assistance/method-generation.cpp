#include <string>

struct Customer
{
    std::string first_name, last_name;
    std::uint64_t phone;

    // TODO: write hash function

    // TODO: write operator <<

};

// ----------------------------------------------------------------------------------------------------------------- //

struct Base
{
protected:
    ~Base() = default;
    
public:
    virtual void foo() = 0;
    virtual bool bar(); // TODO: make something with `bar`
};

struct Derived final : Base
{
    // TODO: Generate missing members
    // TODO: Generate overriding members
};

// ----------------------------------------------------------------------------------------------------------------- //

template<class T1>
struct X
{
    template<class T2>
    void foo() const; // TODO: implement X::foo
};
