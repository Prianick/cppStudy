#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    Visitor() {};

    virtual void visitNumber(Number const *number) = 0;

    virtual void visitBinaryOperation(BinaryOperation const *operation) = 0;

    virtual ~Visitor() {}
};

struct Expression {
    virtual double evaluate() const = 0;

    virtual void visit(Visitor *visitor) const = 0;

    virtual ~Expression() {};
};

struct Number : Expression {
    explicit Number(double value) : value(value) {}

    double evaluate() const override {
        return value;
    }

    double get_value() const { return value; }

    void visit(Visitor *visitor) const override { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), op(op), right(right) {}

    ~BinaryOperation() override {
        delete left;
        delete right;
    }

    double evaluate() const override {
        double res;
        switch (op) {
            case '+':
                res = left->evaluate() + right->evaluate();
                break;
            case '-':
                res = left->evaluate() - right->evaluate();
                break;
            case '*':
                res = left->evaluate() * right->evaluate();
                break;
            case '/':
                res = left->evaluate() / right->evaluate();
                break;
        }
        return res;
    }

    Expression const *get_left() const { return left; }

    Expression const *get_right() const { return right; }

    char get_op() const { return op; }

    void visit(Visitor *visitor) const override { visitor->visitBinaryOperation(this); }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    PrintVisitor() {};

    void visitNumber(Number const *number) {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const *bop) {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ")";
    }

//    void visitBinaryOperation(BinaryOperation const *bop) {
//        std::cout << "(";
//        Expression const *left = bop->get_left();
//        if (*(int *) (new Number(0)) == *(int *) left) {
//            left->visit(this);
//        } else {
//            left->visit(this);
//        }
//        std::cout << bop->get_op();
//        Expression const *right = bop->get_right();
//        if (*(int *) (new Number(0)) == *(int *) right) {
//            right->visit(this);
//        } else {
//            right->visit(this);
//        }
//        std::cout << ")";
//    }

    ~PrintVisitor() {};
};

int main() {
    Expression *num1 = new Number(3);
    Expression *sube1 = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *sube2 = new BinaryOperation(new Number(4), '+', sube1);
    Visitor *pVis1 = new PrintVisitor();
    sube1->visit(pVis1);
    sube2->visit(pVis1);
}
