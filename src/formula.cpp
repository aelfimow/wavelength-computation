#include <cmath>

#include "formula.h"


formula::formula(param_set1 const &param) :
    m_freq { param.freq },
    m_lambda { 0.0 },
    m_epsilon { param.epsilon }
{
}

formula::~formula()
{
}
