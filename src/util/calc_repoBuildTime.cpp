#include "calc_repoBuildTime.h"

calc_repoBuildTime::calc_repoBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

calc_repoBuildTime::~calc_repoBuildTime()
{
}

const char* calc_repoBuildTime::GetDateTime()
{
    return dateTime;
}

