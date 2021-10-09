/*
    Base.cpp

    Investigation of virtual methods and overriding
*/

#include <string>
#include <cassert>

class Base {
public:
    std::string m1() const { return "Base::m1()"; }
    virtual std::string m2() const { return "Base::m2()"; }
};

class Derived : public Base {
public:
    std::string m1() const { return "Derived::m1()"; }
    std::string m2() const { return "Derived::m2()"; }
};

std::string m1BValue(Base b) {
    return b.m1();
}

std::string m2BValue(Base b) {
    return b.m2();
}

std::string m1BPtr(Base* pb) {
    return pb->m1();
}

std::string m2BPtr(Base* pb) {
    return pb->m2();
}

std::string m1BRef(Base& b) {
    return b.m1();
}

std::string m2BRef(Base& b) {
    return b.m2();
}

int main() {

    {
        Base b;

        Base* pb = &b;

        Base& rb = b;

        assert(m1BValue(b) == "Base::m1()");
        assert(m2BValue(b) == "Base::m2()");

        assert(m1BPtr(pb) == "Base::m1()");
        assert(m2BPtr(pb) == "Base::m2()");

        assert(m1BRef(rb) == "Base::m1()");
        assert(m2BRef(rb) == "Base::m2()");
    }

    {
        Derived d;

        Base* pb = &d;

        Base& rb = d;

        assert(m1BValue(d) == "Base::m1()");
        assert(m2BValue(d) == "Base::m2()");

        assert(m1BPtr(pb) == "Base::m1()");
        assert(m2BPtr(pb) == "Derived::m2()");

        assert(m1BRef(rb) == "Base::m1()");
        assert(m2BRef(rb) == "Derived::m2()");

        Derived* pd = &d;

        Derived& rd = d;

        assert(m1BValue(d) == "Base::m1()");
        assert(m2BValue(d) == "Base::m2()");

        assert(m1BPtr(pd) == "Base::m1()");
        assert(m2BPtr(pd) == "Derived::m2()");

        assert(m1BRef(rd) == "Base::m1()");
        assert(m2BRef(rd) == "Derived::m2()");
    }

    return 0;
}