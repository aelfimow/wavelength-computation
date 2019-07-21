#include <cmath>

#include "formula.h"
#include "light.h"


formula::formula(param_set1 const &param) :
    m_freq { param.freq },
    m_lambda { light::c / (param.freq * std::sqrt(param.epsilon)) },
    m_epsilon { param.epsilon }
{
}

formula::formula(param_set2 const &param) :
    m_freq { light::c / (param.lambda * std::sqrt(param.epsilon)) },
    m_lambda { param.lambda },
    m_epsilon { param.epsilon }
{
}

formula::~formula()
{
}

double formula::frequency() const
{
    return m_freq;
}

double formula::lambda() const
{
    return m_lambda;
}

double formula::epsilon() const
{
    return m_epsilon;
}
