#ifdef __RESHARPER__

class Base
{
public:
    void a();
    virtual void b();
    virtual void c();
    virtual void d(int = 0);
    virtual void e();

    template<class T> 
    virtual void f();

    virtual void g()
    {        
    }
};

class Derived : public Base
{
    void a() override;
    void b() const override; 
    bool c() override;
    void d(int) override;
    void e(int = 0) override;
    
    template<class T> 
    void f() override;

    virtual void g()
    {
    }
};

void usage(Base & b)
{
    b.g();
}

#endif