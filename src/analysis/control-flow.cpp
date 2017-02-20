#include <cassert>
#include <iostream>

/// dead code example
int slow_abs(int x)
{
    if (x >= 0)
        return x;
    else
        return -x;
    assert("hopefully not reachable");
}

struct S1
{
    int field;
};

struct S2
{
    int field;

    S2();
};

struct S3
{
    int field;

    S3();

private:
    int _field;
};

S3::S3()
    : _field(0)
    , field(1)
{
}

void foo()
{
    S1 s1;
    S2 s2;
    S3 s3;
    std::cout 
        << s1.field << std::endl
        << s2.field << std::endl;
}
