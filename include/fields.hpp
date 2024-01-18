#ifndef FIELDS_H
#define FIELDS_H

class Field
{
public:
    virtual ~Field() = default;
    virtual void print() const;
    bool can_go() const;
    void can_go(bool a);
    void go_out();
    void go_in();
    virtual void set_is_barrel(bool is_barrel);
    bool is_barrel() const;

protected:
    bool _can_go;
    bool _man;
    bool _is_barrel;
};

class Wall : public Field
{
public:
    Wall();
    virtual ~Wall()=default;
    void print() const override;
};
class Floor : public Field
{
public:
    Floor(bool is_barrel);
    virtual ~Floor()=default;
    void print() const override;
};
class Goal : public Field
{
public:
    Goal();
    virtual ~Goal()=default;
    void print() const override;
    void set_is_barrel(bool is_barrel) override;

    static unsigned int remain; 
};

#endif // FIELDS_H