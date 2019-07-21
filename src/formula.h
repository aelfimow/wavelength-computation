#ifdef FORMULA_H
#error Already included
#else
#define FORMULA_H

class formula
{
    public:
        struct param_set1
        {
            double freq;
            double epsilon;
        };

        struct param_set2
        {
            double lambda;
            double epsilon;
        };

    public:
        formula(param_set1 const &param);
        formula(param_set2 const &param);
        ~formula();

        double frequency() const;
        double lambda() const;
        double epsilon() const;

    private:
        double const m_freq;
        double const m_lambda;
        double const m_epsilon;

    public:
        formula() = delete;
        formula(const formula &instance) = delete;
        formula(const formula &&instance) = delete;
        formula &operator=(const formula &instance) = delete;
        formula &operator=(const formula &&instance) = delete;
};

#endif
